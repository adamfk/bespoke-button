#pragma once
#include "BeButtonSm.h"
#include "BeButtonPlatform.h"

#ifdef __cplusplus
extern "C" {
#endif

///////////////// structures //////////////////////

typedef struct BeButton {
    BeButtonSm sm;
    BeButtonPin pin;
} BeButton;


///////////////// basic functions //////////////////////

/**
 * @brief Setup the button state machine.
 * @note NOTE! You must initialize the pin before calling this function.
 */
void BeButton_setup(BeButton * button, const BeButtonPin pin);

/**
 * @brief Reads button pin, updates button state machine and timer.
 */
void BeButton_update(BeButton * button, uint32_t elapsed_time_ms);


///////////////// events //////////////////////

/**
 * @brief Returns true if the press event occurred. Clears the event.
 */
bool BeButton_pop_press_event(BeButton * button);

/**
 * @brief Returns true if the long event occurred. Clears the event.
 */
bool BeButton_pop_long_event(BeButton * button);

/**
 * @brief Returns true if the repeat event occurred. Clears the event.
 */
bool BeButton_pop_repeat_event(BeButton * button);

/**
 * @brief Returns true if the release event occurred. Clears the event.
 */
bool BeButton_pop_release_event(BeButton * button);



////////////////////// conditions //////////////////////

/**
 * @brief Returns true if the button is released.
 */
bool BeButton_is_released(BeButton * button);

/**
 * @brief Returns true if the button is pressed.
 */
bool BeButton_is_pressed(BeButton * button);

/**
 * @brief Returns true if the button is long pressed.
 */
bool BeButton_is_long_pressed(BeButton * button);

/**
 * @brief Returns true if the button is repeating.
 */
bool BeButton_is_repeating(BeButton * button);


#ifdef __cplusplus
}
#endif
