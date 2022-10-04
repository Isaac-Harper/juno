#pragma once

#ifdef RGBLIGHT_ENABLE
#    define RGBLIGHT_HUE_STEP  8
#    define RGBLIGHT_SAT_STEP  8
#    define RGBLIGHT_VAL_STEP  8
#    define RGBLIGHT_LIMIT_VAL 150
#endif

#define DEFAULT_LAYER = 1

// Configure the global tapping term (default: 200ms)
#define TAPPING_TERM 200

#define TAP_CODE_DELAY 20

// Prevent normal rollover on alphas from accidentally triggering mods.
#define IGNORE_MOD_TAP_INTERRUPT

// Enable rapid switch from tap to hold, disables double tap hold auto-repeat.
#define TAPPING_FORCE_HOLD

#define BOTH_SHIFTS_TURNS_ON_CAPS_WORD

#define OLED_BRIGHTNESS 255
#define OLED_TIMEOUT 6000

#undef LOCKING_SUPPORT_ENABLE // cherry mx lock only
#undef LOCKING_RESYNC_ENABLE  // cherry mx lock only


#define LAYER_STATE_8BIT   // using less than 8 layers

#define SPLIT_LAYER_STATE_ENABLE
#define SPLIT_LED_STATE_ENABLE
#define SPLIT_WPM_ENABLE
#define SPLIT_MODS_ENABLE
#define SPLIT_OLED_ENABLE


#define RGBLIGHT_SLEEP

#define RGBLIGHT_LAYERS


#define MOUSEKEY_DELAY          0
#define MOUSEKEY_INTERVAL       16
#define MOUSEKEY_WHEEL_DELAY    0
#define MOUSEKEY_MAX_SPEED      6
#define MOUSEKEY_TIME_TO_MAX    64

#define MK_COMBINED