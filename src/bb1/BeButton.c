#include "BeButton.h"

#include <stdint.h>

#include "arduino.h"

/**
 * Setup the button state machine and pin.
 */
void BeButton_setup(BeButton* button, const BeButtonPin pin) {
    button->pin = pin;
    BeButtonSm_ctor(&button->sm);  // construct button state machine
    BeButtonSm_start(&button->sm);
}

/**
 * Reads button pin, updates button state machine and timer.
 */
void BeButton_update(BeButton* button, uint32_t elapsed_time_ms) {
    // read pin status and set input to state machine
    button->sm.vars.input_active = BeButtonPlatform_is_pin_active(button->pin);

    // update button timer
    button->sm.vars.timer_ms += elapsed_time_ms;

    // run state machine
    BeButtonSm_dispatch_event(&button->sm, BeButtonSm_EventId_DO);
}

bool BeButton_pop_press_event(BeButton* button) {
    bool result = button->sm.vars.output_press_event;
    button->sm.vars.output_press_event = false;
    return result;
}

bool BeButton_pop_long_event(BeButton* button) {
    bool result = button->sm.vars.output_long_event;
    button->sm.vars.output_long_event = false;
    return result;
}

bool BeButton_pop_repeat_event(BeButton* button) {
    bool result = button->sm.vars.output_repeat_event;
    button->sm.vars.output_repeat_event = false;
    return result;
}

bool BeButton_pop_release_event(BeButton* button) {
    bool result = button->sm.vars.output_release_event;
    button->sm.vars.output_release_event = false;
    return result;
}
