#pragma once
#include "BeButton1Sm.h"
#include "BeButton1Platform.h"

#ifdef __cplusplus
extern "C" {
#endif

///////////////// structures //////////////////////

typedef struct BeButton1 {
    BeButton1Sm sm;
    BeButton1Pin pin;
} BeButton1;


///////////////// basic functions //////////////////////

/**
 * @brief Setup the button state machine.
 * @note NOTE! You must initialize the pin before calling this function.
 */
void BeButton1_setup(BeButton1 * button, const BeButton1Pin pin);

/**
 * @brief Reads button pin, updates button state machine and timer.
 */
void BeButton1_update(BeButton1 * button, uint32_t elapsed_time_ms);


///////////////// events //////////////////////

/**
 * @brief Returns true if the press event occurred. Clears the event.
 */
bool BeButton1_pop_press_event(BeButton1 * button);

/**
 * @brief Returns true if the long event occurred. Clears the event.
 */
bool BeButton1_pop_long_event(BeButton1 * button);

/**
 * @brief Returns true if the repeat event occurred. Clears the event.
 */
bool BeButton1_pop_repeat_event(BeButton1 * button);

/**
 * @brief Returns true if the release event occurred. Clears the event.
 */
bool BeButton1_pop_release_event(BeButton1 * button);



////////////////////// conditions //////////////////////

/**
 * @brief Returns true if the button is released.
 */
bool BeButton1_is_released(BeButton1 * button);

/**
 * @brief Returns true if the button is pressed.
 */
bool BeButton1_is_pressed(BeButton1 * button);

/**
 * @brief Returns true if the button is long pressed.
 */
bool BeButton1_is_long_pressed(BeButton1 * button);

/**
 * @brief Returns true if the button is repeating.
 */
bool BeButton1_is_repeating(BeButton1 * button);


#ifdef __cplusplus
}
#endif
