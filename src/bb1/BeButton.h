#pragma once
#include "BeButtonSm.h"
#include "BeButtonPlatform.h"

#ifdef __cplusplus
extern "C" {
#endif



typedef struct BeButton {
    BeButtonSm sm;
    BeButtonPin pin;
} BeButton;

void BeButton_setup(BeButton* button, const BeButtonPin pin);

void BeButton_update(BeButton* button, uint32_t elapsed_time_ms);

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

#ifdef __cplusplus
}
#endif
