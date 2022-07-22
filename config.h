#pragma once

#ifdef RGBLIGHT_ENABLE
#    define RGBLIGHT_ANIMATIONS
#    define RGBLIGHT_HUE_STEP  8
#    define RGBLIGHT_SAT_STEP  8
#    define RGBLIGHT_VAL_STEP  8
#    define RGBLIGHT_LIMIT_VAL 150
#endif

#define DEFAULT_LAYER = 1



#define TAPPING_TERM 175
#define TAPPING_TOGGLE 3

#define OLED_BRIGHTNESS 255
#define OLED_TIMEOUT 30000

#undef LOCKING_SUPPORT_ENABLE // cherry mx lock only
#undef LOCKING_RESYNC_ENABLE  // cherry mx lock only


#define LAYER_STATE_8BIT   // using less than 8 layers

#define SPLIT_LAYER_STATE_ENABLE
#define SPLIT_LED_STATE_ENABLE
#define SPLIT_WPM_ENABLE
#define SPLIT_MODS_ENABLE
#define SPLIT_OLED_ENABLE


#define RGBLIGHT_SLEEP