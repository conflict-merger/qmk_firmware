#pragma once

/* The way how "handedness" is decided (which half is which),
see https://docs.qmk.fm/#/feature_split_keyboard?id=setting-handedness
for more options.
 */

#define TAPPING_TERM 250
#define TAPPING_TERM_PER_KEY

// #define COMBO_MUST_HOLD_MODS
// #define COMBO_HOLD_TERM 150

// Achordion-like feature
#define CHORDAL_HOLD
// #define HOLD_ON_OTHER_KEY_PRESS
#define PERMISSIVE_HOLD

// Flow Tap
#define FLOW_TAP_TERM 150

// Enable rapid switch from tap to hold, disables double tap hold auto-repeat.
// #define TAPPING_FORCE_HOLD
#define QUICK_TAP_TERM 0

// One shot keys
//#define ONESHOT_TAP_TOGGLE 4  /* Tapping this number of times holds the key until tapped once again. */
#define ONESHOT_TIMEOUT 2000  /* Time (in ms) before the one shot key is released */

// Auto Shift
/*#define NO_AUTO_SHIFT_ALPHA*/
/*#define AUTO_SHIFT_TIMEOUT TAPPING_TERM*/
/*#define AUTO_SHIFT_NO_SETUP*/

//#define COMBO_COUNT 8
#define DYNAMIC_KEYMAP_LAYER_COUNT 8
#define RP2040_BOOTLOADER_DOUBLE_TAP_RESET // Activates the double-tap behavior
#define RP2040_BOOTLOADER_DOUBLE_TAP_RESET_TIMEOUT 200U // Timeout window in ms in which the double tap can occur.
