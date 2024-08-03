#include "BeButtonPlatform.h"

///////////////////////////////// ARDUINO /////////////////////////////////
#ifdef ARDUINO
#include "arduino.h"

bool BeButtonPlatform_is_pin_active(const BeButtonPin pin)
{
    return (digitalRead(pin) == LOW);
}
#endif

///////////////////////////////// STM32 /////////////////////////////////
// TODO

// ...
