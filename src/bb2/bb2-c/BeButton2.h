#pragma once
#include "BeButton2Sm.h"
#include <stdbool.h>

#ifdef __cplusplus
extern "C" {
#endif

///////////////// platform specific section //////////////////////

#ifdef ARDUINO
// for Arduino
typedef uint8_t BeButton2Pin;
#else
// just assume uint8_t for now
typedef uint8_t BeButton2Pin;
#endif

// returns true if pin is "active"
// must be implemented by user
bool BeButton2_is_pin_active(const BeButton2Pin pin);


///////////////// structures //////////////////////

typedef struct BeButton2 {
    BeButton2Sm sm;
    BeButton2Pin pin;
} BeButton2;


///////////////// basic functions //////////////////////

/**
 * @brief Setup the button state machine.
 * @note NOTE! You must initialize the pin before calling this function.
 */
void BeButton2_setup(BeButton2 * button, const BeButton2Pin pin);

/**
 * @brief Reads button pin, updates button state machine and timer.
 */
void BeButton2_update(BeButton2 * button, uint32_t elapsed_time_ms);


///////////////// events //////////////////////

// MUST be read after update function or the event may be lost.
// Feel free to ignore the event if you don't need it.
inline static bool BeButton2_get_press_event(BeButton2 * button) {
    bool result = button->sm.vars.output_press_event;
    return result;
}

// MUST be read after update function or the event may be lost.
// Feel free to ignore the event if you don't need it.
inline static bool BeButton2_get_long_event(BeButton2 * button) {
    bool result = button->sm.vars.output_long_event;
    return result;
}

// MUST be read after update function or the event may be lost.
// Feel free to ignore the event if you don't need it.
inline static bool BeButton2_get_repeat_event(BeButton2* button) {
    bool result = button->sm.vars.output_repeat_event;
    return result;
}

// MUST be read after update function or the event may be lost.
// Feel free to ignore the event if you don't need it.
inline static bool BeButton2_get_release_event(BeButton2* button) {
    bool result = button->sm.vars.output_release_event;
    return result;
}

// MUST be read after update function or the event may be lost.
// You will probably also want to read the press count if this event is true.
// Feel free to ignore the event if you don't need it.
inline static bool BeButton2_get_seq_end_event(BeButton2* button) {
    bool result = button->sm.vars.output_seq_end_event;
    return result;
}

// MUST be read after update function or value may be lost.
// Feel free to ignore if you don't need it.
inline static uint8_t BeButton2_get_seq_press_count(BeButton2 * button) {
    uint8_t result = button->sm.vars.press_count;
    return result;
}

///////////////// other //////////////////////

inline static uint16_t BeButton2_get_press_timer_ms(BeButton2 * button) {
    return button->sm.vars.t1_ms;
}

// only valid if button is not pressed or if repeat is disabled. Also not valid during initialization.
inline static uint16_t BeButton2_get_release_timer_ms(BeButton2 * button) {
    return button->sm.vars.t2_ms;
}

///////////////// conditions //////////////////////

inline static bool BeButton2_is_pressed(BeButton2* button) {
    return button->sm.vars.output_press;
}

inline static bool BeButton2_is_held_at_start(BeButton2* button) {
    return button->sm.state_id == BeButton2Sm_StateId_HELD_AT_START;
}

inline static bool BeButton2_is_initializing(BeButton2* button) {
    return button->sm.state_id == BeButton2Sm_StateId_STARTUP_DELAY;
}

inline static bool BeButton2_is_released(BeButton2* button) {
    return !BeButton2_is_pressed(button);
}

#ifdef __cplusplus
}
#endif
