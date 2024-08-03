// assertions about RAM usage. Feel free to remove.
#include <assert.h>
#if defined(ARDUINO_AVR_UNO)
// Very interesting. I didn't expect the alignment for AVR GCC to be 1 byte (as int is 2 bytes), 
// but it does make sense as the AVR is an 8-bit architecture.

// when not using a packed enum
// static_assert(sizeof(BeButtonSm_StateId) == 2, "state id wrong size");
// static_assert(sizeof(BeButtonSm_Vars) == 3, "vars wrong size");
// static_assert(sizeof(BeButtonSm) == 11, "wrong size");

// when using a packed enum
static_assert(sizeof(BeButtonSm_StateId) == 1, "state id wrong size");
static_assert(sizeof(BeButtonSm_Vars) == 3, "vars wrong size");
static_assert(sizeof(BeButtonSm) == 10, "wrong size");

#endif

