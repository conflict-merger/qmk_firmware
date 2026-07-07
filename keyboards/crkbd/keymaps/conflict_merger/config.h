#pragma once

/* The way how "handedness" is decided (which half is which),
see https://docs.qmk.fm/#/feature_split_keyboard?id=setting-handedness
for more options.
*/

#define MASTER_LEFT
// #define MASTER_RIGHT

//#define TAPPING_TERM 170
#define TAPPING_TERM 300
#define TAPPING_TERM_PER_KEY

// #define COMBO_MUST_HOLD_MODS
// #define COMBO_HOLD_TERM 150

// Achordion feature
#define CHORDAL_HOLD

#define PERMISSIVE_HOLD

#define DOUBLE_TAP_SHIFT_TURNS_ON_CAPS_WORD

#define DYNAMIC_MACRO_DELAY 20 
#define DYNAMIC_MACRO_NO_NESTING

#define LEADER_TIMEOUT 800
#define LEADER_PER_KEY_TIMING
#define LEADER_KEY_STRICT_KEY_PROCESSING

// Flow Tap
// #define FLOW_TAP_TERM 150

// Enable rapid switch from tap to hold, disables double tap hold auto-repeat.
// #define TAPPING_FORCE_HOLD
#define QUICK_TAP_TERM 0

// One shot keys
//#define ONESHOT_TAP_TOGGLE 4  /* Tapping this number of times holds the key until tapped once again. */
// #define oneshot_tap_toggle 3  /* tapping this number of times holds the key until tapped once again. */
#define oneshot_timeout 2000  /* time (in ms) before the one shot key is released */
