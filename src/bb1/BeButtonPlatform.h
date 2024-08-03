#pragma once
#include <stdint.h>

typedef struct BeButtonPin {
    // uint8_t port;
    uint8_t pin;
} BeButtonPin;

extern void BeButton_init_pin(BeButtonPin const * pin);

