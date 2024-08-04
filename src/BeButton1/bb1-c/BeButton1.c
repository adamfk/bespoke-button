#include "BeButton1.h"
#include <stdint.h>

void BeButton1_setup(BeButton1 * button, const BeButton1Pin pin) {
    button->pin = pin;
    BeButton1Sm_ctor(&button->sm);  // construct button state machine
    BeButton1Sm_start(&button->sm);
}

/**
 * Reads button pin, updates button state machine and timer.
 */
void BeButton1_update(BeButton1 * button, uint32_t elapsed_time_ms) {
    // read pin status and set input to state machine
    button->sm.vars.input_active = BeButton1Platform_is_pin_active(button->pin);

    // update button timer
    button->sm.vars.timer_ms += elapsed_time_ms;

    // run state machine
    BeButton1Sm_dispatch_event(&button->sm, BeButton1Sm_EventId_DO);
}

///////////////// events //////////////////////

bool BeButton1_pop_press_event(BeButton1 * button) {
    bool result = button->sm.vars.output_press_event;
    button->sm.vars.output_press_event = false;
    return result;
}

bool BeButton1_pop_long_event(BeButton1 * button) {
    bool result = button->sm.vars.output_long_event;
    button->sm.vars.output_long_event = false;
    return result;
}

bool BeButton1_pop_repeat_event(BeButton1* button) {
    bool result = button->sm.vars.output_repeat_event;
    button->sm.vars.output_repeat_event = false;
    return result;
}

bool BeButton1_pop_release_event(BeButton1* button) {
    bool result = button->sm.vars.output_release_event;
    button->sm.vars.output_release_event = false;
    return result;
}

///////////////// conditions //////////////////////

bool BeButton1_is_released(BeButton1* button) {
    return !BeButton1_is_pressed(button);
}

bool BeButton1_is_pressed(BeButton1* button) {
    return button->sm.vars.output_press;
}

bool BeButton1_is_long_pressed(BeButton1* button) {
    return button->sm.vars.output_long;
}

bool BeButton1_is_repeating(BeButton1* button) {
    return button->sm.vars.output_repeat;
}
