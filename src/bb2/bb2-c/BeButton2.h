#pragma once
#include "BeButton2Sm.h"
#include "BeButton2Platform.h"

#ifdef __cplusplus
extern "C" {
#endif

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

/**
 * @brief Returns true if the press event occurred. Clears the event.
 */
bool BeButton2_pop_press_event(BeButton2 * button);

/**
 * @brief Returns true if the long event occurred. Clears the event.
 */
bool BeButton2_pop_long_event(BeButton2 * button);

/**
 * @brief Returns true if the repeat event occurred. Clears the event.
 */
bool BeButton2_pop_repeat_event(BeButton2 * button);

/**
 * @brief Returns true if the release event occurred. Clears the event.
 */
bool BeButton2_pop_release_event(BeButton2 * button);



////////////////////// conditions //////////////////////

/**
 * @brief Returns true if the button is released.
 */
bool BeButton2_is_released(BeButton2 * button);

/**
 * @brief Returns true if the button is pressed.
 */
bool BeButton2_is_pressed(BeButton2 * button);

/**
 * @brief Returns true if the button is long pressed.
 */
bool BeButton2_is_long_pressed(BeButton2 * button);

/**
 * @brief Returns true if the button is repeating.
 */
bool BeButton2_is_repeating(BeButton2 * button);


#ifdef __cplusplus
}
#endif
