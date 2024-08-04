#pragma once
#include <stdint.h>
#include <stdbool.h>

#ifdef __cplusplus
extern "C" {
#endif

#ifndef ARDUINO
#define ARDUINO // FIXME - remove this after initial simulation testing
#endif

///////////////////////////////// ARDUINO /////////////////////////////////
#ifdef ARDUINO
// for Arduino
typedef uint8_t BeButton2Pin;
#endif


// We purposely don't do pin initialization here. let user do it. there are many ways to initialize a pin across platforms.

// returns true if pin is "active"
bool BeButton2Platform_is_pin_active(const BeButton2Pin pin);

#ifdef __cplusplus
}
#endif
