#include "BeButton.hpp"
#include <stdint.h>

void BeButton::setup(const BeButtonPin pin) {
    this->pin = pin;
    BeButtonSm_ctor(&this->sm);  // construct button state machine
    BeButtonSm_start(&this->sm);
}

/**
 * Reads button pin, updates button state machine and timer.
 */
void BeButton::update(uint32_t elapsed_time_ms) {
    // read pin status and set input to state machine
    this->sm.vars.input_active = is_pin_active(this->pin);

    // update button timer
    this->sm.vars.timer_ms += elapsed_time_ms;

    // run state machine
    BeButtonSm_dispatch_event(&this->sm, BeButtonSm_EventId_DO);
}

///////////////// events //////////////////////

bool BeButton::pop_press_event() {
    bool result = this->sm.vars.output_press_event;
    this->sm.vars.output_press_event = false;
    return result;
}

bool BeButton::pop_long_event() {
    bool result = this->sm.vars.output_long_event;
    this->sm.vars.output_long_event = false;
    return result;
}

bool BeButton::pop_repeat_event() {
    bool result = this->sm.vars.output_repeat_event;
    this->sm.vars.output_repeat_event = false;
    return result;
}

bool BeButton::pop_release_event() {
    bool result = this->sm.vars.output_release_event;
    this->sm.vars.output_release_event = false;
    return result;
}

///////////////// conditions //////////////////////

bool BeButton::is_released() {
    return !BeButton::is_pressed();
}

bool BeButton::is_pressed() {
    return this->sm.vars.output_press;
}

bool BeButton::is_long_pressed() {
    return this->sm.vars.output_long;
}

bool BeButton::is_repeating() {
    return this->sm.vars.output_repeat;
}
