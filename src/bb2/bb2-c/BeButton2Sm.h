// Autogenerated with StateSmith 0.11.2-alpha+4a4e30018e9a371124530fa96cf2ba3322b80459.
// Algorithm: Balanced1. See https://github.com/StateSmith/StateSmith/wiki/Algorithms

#pragma once
#include <stdint.h>

#include <stdint.h> // for fixed width integer state machine variables below

typedef enum __attribute__((packed)) BeButton2Sm_EventId
{
    BeButton2Sm_EventId_DO = 0, // The `do` event is special. State event handlers do not consume this event (ancestors all get it too) unless a transition occurs.
} BeButton2Sm_EventId;

enum
{
    BeButton2Sm_EventIdCount = 1
};

typedef enum __attribute__((packed)) BeButton2Sm_StateId
{
    BeButton2Sm_StateId_ROOT = 0,
    BeButton2Sm_StateId_PRESSED_DEBOUNCE = 1,
    BeButton2Sm_StateId_PRESSED_STABLE = 2,
    BeButton2Sm_StateId_CONFIRM_LONG = 3,
    BeButton2Sm_StateId_PRESSED_LONG = 4,
    BeButton2Sm_StateId_PRESSED_REPEAT = 5,
    BeButton2Sm_StateId_RELEASED_DEBOUNCE = 6,
    BeButton2Sm_StateId_RELEASED_STABLE = 7,
} BeButton2Sm_StateId;

enum
{
    BeButton2Sm_StateIdCount = 8
};


// Generated state machine
// forward declaration
typedef struct BeButton2Sm BeButton2Sm;

// State machine variables. Can be used for inputs, outputs, user variables...
typedef struct BeButton2Sm_Vars
{
    // you need to add your loop time to this variable in your main loop.
    // max time is 65535 ms.
    uint16_t timer_ms;
    
    // set to 1 when button is detected as active.
    uint8_t input_active: 1;
    
    // read and clear event flags in your main loop.
    uint8_t output_release_event: 1;
    uint8_t output_press_event: 1;
    uint8_t output_long_event: 1;
    uint8_t output_repeat_event: 1;
    
    // read these flags in your main loop, but don't clear them.
    // they are cleared automatically.
    uint8_t output_press: 1;
    uint8_t output_long: 1;
    uint8_t output_repeat: 1;
} BeButton2Sm_Vars;


// event handler type
typedef void (*BeButton2Sm_Func)(BeButton2Sm* sm);

// State machine constructor. Must be called before start or dispatch event functions. Not thread safe.
void BeButton2Sm_ctor(BeButton2Sm* sm);

// Starts the state machine. Must be called before dispatching events. Not thread safe.
void BeButton2Sm_start(BeButton2Sm* sm);

// Dispatches an event to the state machine. Not thread safe.
void BeButton2Sm_dispatch_event(BeButton2Sm* sm, BeButton2Sm_EventId event_id);

// Thread safe.
char const * BeButton2Sm_state_id_to_string(BeButton2Sm_StateId id);

// Thread safe.
char const * BeButton2Sm_event_id_to_string(BeButton2Sm_EventId id);

// Generated state machine
struct BeButton2Sm
{
    // Used internally by state machine. Feel free to inspect, but don't modify.
    BeButton2Sm_StateId state_id;
    
    // Used internally by state machine. Don't modify.
    BeButton2Sm_Func ancestor_event_handler;
    
    // Used internally by state machine. Don't modify.
    BeButton2Sm_Func current_event_handlers[BeButton2Sm_EventIdCount];
    
    // Used internally by state machine. Don't modify.
    BeButton2Sm_Func current_state_exit_handler;
    
    // Variables. Can be used for inputs, outputs, user variables...
    BeButton2Sm_Vars vars;
};

