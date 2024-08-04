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
    button->sm.vars.input_active = BeButton2_is_pin_active(button->pin);

    // Handle special events from previous state machine run.
    // MUST happen before updating timer.
    if (button->sm.vars.output_release_event) {
        button->sm.vars.output_release_event = false;
        // we need to clear timer 2 as it is used for release state timing.
        button->sm.vars.t2_ms = 0;
    } else if (button->sm.vars.output_press_event) {
        button->sm.vars.output_press_event = false;
        // we need to clear timer 1 as it is used for press state timing.
        button->sm.vars.t1_ms = 0;
    } else if (button->sm.vars.output_seq_end_event) {
        button->sm.vars.output_seq_end_event = false;
        button->sm.vars.press_count = 0;
    }

    // update button timers
    button->sm.vars.t1_ms += elapsed_time_ms;
    button->sm.vars.t2_ms += elapsed_time_ms;

    // saturate timers on roll over
    if (button->sm.vars.t1_ms < elapsed_time_ms) {
        button->sm.vars.t1_ms = UINT16_MAX;
    }
    if (button->sm.vars.t2_ms < elapsed_time_ms) {
        button->sm.vars.t2_ms = UINT16_MAX;
    }

    // run state machine
    BeButton2Sm_dispatch_event(&button->sm, BeButton2Sm_EventId_DO);
}


