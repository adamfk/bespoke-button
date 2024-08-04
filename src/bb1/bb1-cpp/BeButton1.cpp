#include "BeButton1.hpp"
#include <stdint.h>

void BeButton1::setup(const BeButton1Pin pin) {
    this->pin = pin;
    BeButton1Sm_ctor(&this->sm);  // construct button state machine
    BeButton1Sm_start(&this->sm);
}

/**
 * Reads button pin, updates button state machine and timer.
 */
void BeButton1::update(uint32_t elapsed_time_ms) {
    // read pin status and set input to state machine
    this->sm.vars.input_active = is_pin_active(this->pin);

    // update button timer
    this->sm.vars.timer_ms += elapsed_time_ms;

    // run state machine
    BeButton1Sm_dispatch_event(&this->sm, BeButton1Sm_EventId_DO);
}

///////////////// events //////////////////////

bool BeButton1::pop_press_event() {
    bool result = this->sm.vars.output_press_event;
    this->sm.vars.output_press_event = false;
    return result;
}

bool BeButton1::pop_long_event() {
    bool result = this->sm.vars.output_long_event;
    this->sm.vars.output_long_event = false;
    return result;
}

bool BeButton1::pop_repeat_event() {
    bool result = this->sm.vars.output_repeat_event;
    this->sm.vars.output_repeat_event = false;
    return result;
}

bool BeButton1::pop_release_event() {
    bool result = this->sm.vars.output_release_event;
    this->sm.vars.output_release_event = false;
    return result;
}

///////////////// conditions //////////////////////

bool BeButton1::is_released() {
    return !BeButton1::is_pressed();
}

bool BeButton1::is_pressed() {
    return this->sm.vars.output_press;
}

bool BeButton1::is_long_pressed() {
    return this->sm.vars.output_long;
}

bool BeButton1::is_repeating() {
    return this->sm.vars.output_repeat;
}
