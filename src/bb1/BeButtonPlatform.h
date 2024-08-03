#pragma once
#include <stdint.h>
#include <stdbool.h>

#ifdef __cplusplus
extern "C" {
#endif

#define ARDUINO // FIXME - remove this after initial simulation testing

///////////////////////////////// ARDUINO /////////////////////////////////
#ifdef ARDUINO
// for Arduino
typedef uint8_t BeButtonPin;
#endif




// We purposely don't do pin initialization here. let user do it. there are many ways to initialize a pin across platforms.

// returns true if pin is "active"
bool BeButtonPlatform_is_pin_active(const BeButtonPin pin);

#ifdef __cplusplus
}
#endif
