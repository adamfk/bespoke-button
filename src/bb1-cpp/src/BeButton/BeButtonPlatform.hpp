#pragma once
#include <stdint.h>
#include <stdbool.h>

#ifndef ARDUINO
#define ARDUINO // FIXME - remove this after initial simulation testing
#endif

///////////////////////////////// ARDUINO /////////////////////////////////
#ifdef ARDUINO
// for Arduino
typedef uint8_t BeButtonPin;
#endif


// We purposely don't do pin initialization here. let user do it. there are many ways to initialize a pin across platforms.



