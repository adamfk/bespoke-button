#pragma once
#include "BeButtonSm.hpp"
#include "BeButtonPlatform.hpp"

///////////////// structures //////////////////////

class BeButton {
    BeButtonSm sm;
    BeButtonPin pin;

    // returns true if pin is "active"
    static bool is_pin_active(const BeButtonPin pin);

public:

    ///////////////// basic functions //////////////////////

    /**
     * @brief Setup the button state machine.
     * @note NOTE! You must initialize the pin before calling this function.
     */
    void setup(const BeButtonPin pin);

    /**
     * @brief Reads button pin, updates button state machine and timer.
     */
    void update(uint32_t elapsed_time_ms);

    ///////////////// events //////////////////////

    /**
     * @brief Returns true if the press event occurred. Clears the event.
     */
    bool pop_press_event();

    /**
     * @brief Returns true if the long event occurred. Clears the event.
     */
    bool pop_long_event();

    /**
     * @brief Returns true if the repeat event occurred. Clears the event.
     */
    bool pop_repeat_event();

    /**
     * @brief Returns true if the release event occurred. Clears the event.
     */
    bool pop_release_event();



    ////////////////////// conditions //////////////////////

    /**
     * @brief Returns true if the button is released.
     */
    bool is_released();

    /**
     * @brief Returns true if the button is pressed.
     */
    bool is_pressed();

    /**
     * @brief Returns true if the button is long pressed.
     */
    bool is_long_pressed();

    /**
     * @brief Returns true if the button is repeating.
     */
    bool is_repeating();
};
