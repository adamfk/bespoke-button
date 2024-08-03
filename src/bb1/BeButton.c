#include "BeButtonSm.h"
#include <stdint.h>
#include "arduino.h"

/**
 * Setup the button state machine and pin.
 */
void BeButton_setup(BeButton * button, uint8_t pin) {
    button->pin = pin;
    pinMode(pin, INPUT_PULLUP);

    ButtonSm_ctor(&button->sm);  // construct button state machine
    ButtonSm_start(&button->sm);
}

/**
 * Reads button pin, updates button state machine and timer.
 */
void BeButton_update(BeButton * button, uint32_t elapsed_time_ms)
{
  // read pin status and set input to state machine
  const uint8_t pin = button->pin;
  button->sm.vars.input_active = (digitalRead(pin) == LOW);

  // update button timer
  button_sm->vars.timer_ms += elapsed_time_ms;

  // run state machine
  ButtonSm_dispatch_event(button_sm, ButtonSm_EventId_DO);
}
