// This file is only intended to be included by the state machine .c file.
// It is not intended to be included elsewhere as the defines are not prefixed.
#pragma once

// you can put timings here instead of hardcoding them in the state machine.

// milliseconds
#define LONG_PRESS 250

// milliseconds
#define REPEAT_DELAY 350

// milliseconds
#define REPEAT_INTERVAL 250

// milliseconds
// Max time for a button press hold before it ends a click/press sequence
#define SEQ_PRESS_MAX 500


// milliseconds
// Max time for a button release before it ends a click/press sequence
#define SEQ_RELEASE_MAX 500