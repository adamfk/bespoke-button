#include <assert.h>
#include "src/BeButton1/BeButton1.h"

////////////////////////////////////////////////////////////////////////////////
// global vars
////////////////////////////////////////////////////////////////////////////////

// button state machines
static BeButton1 left_button;
static BeButton1 right_button;

// Millisecond time when loop() was ran last.
// This is used to calculate the elapsed time between loops.
// Tracking this value here instead of inside of each button state machine
// allows us to save some RAM. Important if you have lots of buttons.
// You could easily add this to the button state machine if you prefer.
static uint32_t last_loop_ms = 0;


////////////////////////////////////////////////////////////////////////////////
// extern "C" functions
////////////////////////////////////////////////////////////////////////////////

extern "C" bool BeButton1Platform_is_pin_active(const BeButton1Pin pin)
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

static void setup_button(BeButton1 * button, const uint8_t pin)
{
  pinMode(pin, INPUT_PULLUP);
  BeButton1_setup(button, pin);
}



void loop()
{
  // calculate milliseconds since the last time our loop ran.
  const uint32_t now_ms = millis();
  const uint32_t elapsed_time_ms = now_ms - last_loop_ms;
  last_loop_ms = now_ms;

  // update buttons
  BeButton1_update(&left_button, elapsed_time_ms);
  BeButton1_update(&right_button, elapsed_time_ms);

  // check for and print button events
  print_button_events(&left_button, "left");
  print_button_events(&right_button, "right");

  delay(10);  // a small delay eases simulation CPU usage.
}


/**
 * Checks if a button event occurred, clears the event and prints it to serial.
 */
static void print_button_events(BeButton1 * button, const char *button_name)
{
  if (BeButton1_pop_press_event(button))
  {
    print_button_event(button_name, "press");
  }

  if (BeButton1_pop_long_event(button))
  {
    print_button_event(button_name, "long");
  }

  if (BeButton1_pop_repeat_event(button))
  {
    print_button_event(button_name, "repeat");
  }

  if (BeButton1_pop_release_event(button))
  {
    print_button_event(button_name, "release");
    Serial.println();
  }
}


/**
 * Simply prints button and event to serial.
 */
static void print_button_event(const char *button_name, const char *event)
{
  Serial.print(button_name);
  Serial.print(": ");
  Serial.print(event);
  Serial.println("");
}
