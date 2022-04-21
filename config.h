#pragma once

#ifdef RGBLIGHT_ENABLE
#    define RGBLIGHT_ANIMATIONS
#    define RGBLIGHT_HUE_STEP  8
#    define RGBLIGHT_SAT_STEP  8
#    define RGBLIGHT_VAL_STEP  8
#    define RGBLIGHT_LIMIT_VAL 150
#endif

// If you are using an Elite C rev3 on the slave side, uncomment the lines below:
//#define SPLIT_USB_DETECT
//#define NO_USB_STARTUP_CHECK

#define OLED_BRIGHTNESS 255
#define OLED_TIMEOUT 20000

#undef LOCKING_SUPPORT_ENABLE // cherry mx lock only
#undef LOCKING_RESYNC_ENABLE  // cherry mx lock only


#define LAYER_STATE_8BIT   // using less than 8 layers

#define SPLIT_LAYER_STATE_ENABLE
#define SPLIT_LED_STATE_ENABLE
#define SPLIT_WPM_ENABLE
#define SPLIT_MODS_ENABLE
#define SPLIT_OLED_ENABLE


#define RGBLIGHT_SLEEP