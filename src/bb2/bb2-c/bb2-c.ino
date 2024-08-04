#include <assert.h>
#include "BeButton2.h"
// #include "src/BeButton2/BeButton2.h"


#ifndef ARDUINO
#define __FlashStringHelper  const char
#define F(x) x
#endif

////////////////////////////////////////////////////////////////////////////////
// global vars
////////////////////////////////////////////////////////////////////////////////

// button state machines
static BeButton2 left_button;
static BeButton2 right_button;

// Millisecond time when loop() was ran last.
// This is used to calculate the elapsed time between loops.
// Tracking this value here instead of inside of each button state machine
// allows us to save some RAM. Important if you have lots of buttons.
// You could easily add this to the button state machine if you prefer.
static uint32_t last_loop_ms = 0;


////////////////////////////////////////////////////////////////////////////////
// extern "C" functions
////////////////////////////////////////////////////////////////////////////////

extern "C" bool BeButton2_is_pin_active(const BeButton2Pin pin)
{
    return (digitalRead(pin) == LOW);
}


////////////////////////////////////////////////////////////////////////////////
// functions
////////////////////////////////////////////////////////////////////////////////

void setup()
{
  Serial.begin(115200);
  Serial.println(F("Keyboard keys left/right have a binding to switches above when simulation pane has focus."));
  Serial.println(F("NOTE! up and down buttons are not yet wired up."));
  Serial.println(F("See if you can modify the code to make them work!"));
  Serial.println();

  setup_button(&left_button, 7);
  setup_button(&right_button, 4);
}

static void setup_button(BeButton2 * button, const uint8_t pin)
{
  pinMode(pin, INPUT_PULLUP);
  BeButton2_setup(button, pin);
}



void loop()
{
  // calculate milliseconds since the last time our loop ran.
  const uint32_t now_ms = millis();
  const uint32_t elapsed_time_ms = now_ms - last_loop_ms;
  last_loop_ms = now_ms;

  // update buttons
  BeButton2_update(&left_button, elapsed_time_ms);
  BeButton2_update(&right_button, elapsed_time_ms);

  // check for and print button events
  print_button_events(&left_button, F("left"));
  print_button_events(&right_button, F("right"));

  delay(10);  // a small delay eases simulation CPU usage.
}


/**
 * Checks if a button event occurred, clears the event and prints it to serial.
 */
static void print_button_events(BeButton2 * button, const __FlashStringHelper *button_name)
{
  if (BeButton2_get_press_event(button))
  {
    print_button_event(button_name, F("press"));
    Serial.print(F("  Press count: "));
    Serial.println(button->sm.vars.press_count);
    Serial.print(F("  Prev release time: "));
    Serial.println(BeButton2_get_release_timer_ms(button));
    Serial.print(F("  Prev press time: "));
    Serial.println(BeButton2_get_press_timer_ms(button));
  }

  if (BeButton2_get_long_event(button))
  {
    print_button_event(button_name, F("long"));
  }

  if (BeButton2_get_repeat_event(button))
  {
    print_button_event(button_name, F("repeat"));
  }

  if (BeButton2_get_release_event(button))
  {
    print_button_event(button_name, F("release"));
    Serial.print(F("  Prev press time: "));
    Serial.println(BeButton2_get_press_timer_ms(button));
    // we don't print previous release time here because the repeat state uses the same timer (unless repeat is disabled).
    Serial.println();
  }

  if (BeButton2_get_seq_end_event(button))
  {
    print_button_event(button_name, F("seq end"));
    Serial.print(F("  Press count: "));
    Serial.println(BeButton2_get_seq_press_count(button));
    Serial.println();
  }
}


/**
 * Simply prints button and event to serial.
 */
static void print_button_event(const __FlashStringHelper *button_name, const __FlashStringHelper *event)
{
  Serial.print(button_name);
  Serial.print(": ");
  Serial.print(event);
  Serial.println("");
}
