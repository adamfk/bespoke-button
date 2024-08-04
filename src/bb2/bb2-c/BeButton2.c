#include "BeButton2.h"
#include <stdint.h>

void BeButton2_setup(BeButton2 * button, const BeButton2Pin pin) {
    button->pin = pin;
    BeButton2Sm_ctor(&button->sm);  // construct button state machine
    BeButton2Sm_start(&button->sm);
}

/**
 * Reads button pin, updates button state machine and timer.
 */
void BeButton2_update(BeButton2 * button, uint32_t elapsed_time_ms) {
    // read pin status and set input to state machine
    button->sm.vars.input_active = BeButton2Platform_is_pin_active(button->pin);

    // update button timer
    button->sm.vars.timer_ms += elapsed_time_ms;

    // run state machine
    BeButton2Sm_dispatch_event(&button->sm, BeButton2Sm_EventId_DO);
}

///////////////// events //////////////////////

bool BeButton2_pop_press_event(BeButton2 * button) {
    bool result = button->sm.vars.output_press_event;
    button->sm.vars.output_press_event = false;
    return result;
}

bool BeButton2_pop_long_event(BeButton2 * button) {
    bool result = button->sm.vars.output_long_event;
    button->sm.vars.output_long_event = false;
    return result;
}

bool BeButton2_pop_repeat_event(BeButton2* button) {
    bool result = button->sm.vars.output_repeat_event;
    button->sm.vars.output_repeat_event = false;
    return result;
}

bool BeButton2_pop_release_event(BeButton2* button) {
    bool result = button->sm.vars.output_release_event;
    button->sm.vars.output_release_event = false;
    return result;
}

///////////////// conditions //////////////////////

bool BeButton2_is_released(BeButton2* button) {
    return !BeButton2_is_pressed(button);
}

bool BeButton2_is_pressed(BeButton2* button) {
    return button->sm.vars.output_press;
}

bool BeButton2_is_long_pressed(BeButton2* button) {
    return button->sm.vars.output_long;
}

bool BeButton2_is_repeating(BeButton2* button) {
    return button->sm.vars.output_repeat;
}
