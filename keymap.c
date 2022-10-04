#include QMK_KEYBOARD_H
#include <stdio.h>

 

enum layers {
    _QWERTY = 1,
    _SHIFT,
    _SYM,
    _MOUSE,
    _MINECFT,
    _FACTORI,
    _FACTSYM,
};
  


// Aliases for readability
#define BASE     DF(_BASE)
#define HOME     DF(_QWERTY)
#define SHF      MO(_SHIFT)
#define SYM      MO(_SYM)
#define SYT      TG(_SYM)
#define MINECFT      TG(_MINECFT)
#define FACTORI      TG(_FACTORI)
#define FACTSYM      MO(_FACTSYM)
#define MOUSE    MO(_MOUSE)

#define SAB LT(_SYM, KC_BSPC)
#define AAD MT(MOD_LALT, KC_DEL)



const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = { // this is fine

/*
 * Template Layer: 
 *
 * ,-----------------------------------------.                              ,-----------------------------------------.
 * |      |      |      |      |      |      |                              |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                              |------+------+------+------+------+------|
 * |      |      |      |      |      |      |                              |      |      |      |      |      |      |
 * |------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |  |      |      |      |      |      |      |      |      |
 * `--------------------+------+------+------+      |      |  |      |      +------+------+------+--------------------'
 *                      |      |      |      |      |      |  |      |      |      |      |      |
 *                      `----------------------------------'  `----------------------------------'
 */

/*
 * Base Layer: QWERTY
 *
 * ,-----------------------------------------.                              ,-----------------------------------------.
 * |  esc |   q  |   w  |   e  |   r  |   t  |                              |   y  |   u  |   i  |   o  |   p  | hui+ |
 * |------+------+------+------+------+------|                              |------+------+------+------+------+------|
 * |  tab |   a  |   s  |   d  |   f  |   g  |                              |   h  |   j  |   k  |   l  |   ;  |   '  |
 * |------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+------|
 * |      |   z  |   x  |   c  |   v  |   b  |      |      |  |      |      |   n  |   m  |   ,  |   .  |   /  | sat+ |
 * `--------------------+------+------+------+  spc |  alt |  |  SYM |  ent +------+------+------+--------------------'
 *                      |      | (sft | ctrl |      |  del |  | bspc |      | mous | sft) | home |
 *                      `----------------------------------'  `----------------------------------'
 */


/*
 * Base Layer: QWERTY
 *
 * ,-----------------------------------------.                              ,-----------------------------------------.
 * |      |   Q  |   W  |   E  |   R  |   T  |                              |   Y  |   U  |   I  |   O  |   P  |      |
 * |------+------+------+------+------+------|                              |------+------+------+------+------+------|
 * |      |   A  |   S  |   D  |   F  |   G  |                              |   H  |   J  |   K  |   L  | ;  : |  "  '|
 * |------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+------|
 * |      |   Z  |   X  |   C  |   V  |   B  |      |xxxxxx|  |xxxxxx|      |   N  |   M  | ,  < | . >  | /  ? |      |
 * `--------------------+------+------+------+xxxxxx+------|  |------+xxxxxx+------+------+------+--------------------'
 *                      |xxxxxx|xxxxxx|xxxxxx|      |xxxxxx|  |xxxxxx|      |xxxxxx|xxxxxx|xxxxxx|
 *                      `----------------------------------'  `----------------------------------'
 */
    [_QWERTY] = LAYOUT(
     KC_ESC, KC_Q ,  KC_W   ,  KC_E  ,   KC_R ,   KC_T ,                                          KC_Y   , KC_U   , KC_I   , KC_O   , KC_P   , RGB_HUI,
     KC_TAB,  KC_A,   KC_S  ,  KC_D  ,   KC_F ,   KC_G ,                                          KC_H   ,  KC_J  ,  KC_K  ,  KC_L  , KC_SCLN, KC_QUOTE,
    _______, KC_Z ,  KC_X   ,  KC_C  ,   KC_V ,   KC_B , XXXXXXX, XXXXXXX,      XXXXXXX, XXXXXXX, KC_N   , KC_M   , KC_COMM, KC_DOT , KC_SLSH, RGB_SAI,
                              MINECFT, KC_LSPO, KC_LCTL,  KC_SPC,     AAD,          SAB,  KC_ENT,   MOUSE, KC_RSPC, KC_HOME
    ),


 /*
 * SYM Layer: numbers, symbols, and arrows 
 *
 * ,-----------------------------------------.                              ,-----------------------------------------.
 * |      |   <  |   [  |   {  |   (  |      |                              |   `  |   7  |   8  |   9  |   0  |      |
 * |------+------+------+------+------+------|                              |------+------+------+------+------+------|
 * |      | left | down |  up  | righ |      |                              |   -  |   4  |   5  |   6  |   \  |      |
 * |------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+------|
 * |      |   >  |   ]  |   }  |   )  |      |      |      |  |      |      |   =  |   1  |   2  |   3  |      |      |
 * `--------------------+------+------+------+      |      |  |      |      +------+------+------+--------------------'
 *                      |      |      |      |      |      |  |      |      |      |      |      |
 *                      `----------------------------------'  `----------------------------------'
 */
    [_SYM] = LAYOUT(
      _______,   KC_LT, KC_LBRC, KC_LCBR, KC_LPRN, _______,                                           KC_GRV ,  KC_7  ,  KC_8  ,   KC_9  ,   KC_0 , _______,
      _______, KC_LEFT, KC_DOWN, KC_UP  , KC_RGHT, _______,                                           KC_MINS,  KC_4  ,  KC_5  ,   KC_6  , KC_BSLS, _______,
      _______,   KC_GT, KC_RBRC, KC_RCBR, KC_RPRN, _______, XXXXXXX, XXXXXXX,       XXXXXXX, XXXXXXX, KC_EQL ,  KC_1  ,  KC_2  ,   KC_3  , _______, _______,
                                 _______, _______, _______, _______, _______,       _______, _______, _______, _______, _______
    ),



/*
 * gaming template
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |   1    |   2  |   3  |   4  |   5  |   6  |                              |      |      |      |      |      |        |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |   7    |   a  |  s   |   w  |   d  |   e  |                              |      |      |      |      |      |        |
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * |   j    | /    |  f   |   q  |   8  |   9  |      |xxxxxx|  |xxxxxx|      |      |      |      |      |      |        |
 * `----------------------+------+------+------+  spc +------|  |------+xxxxxx+------+------+------+----------------------'
 *                        |xxxxxx| ctrl |      |      |  esc |  |xxxxxx|      |xxxxxx|xxxxxx|xxxxxx|
 *                        |      |      | shif |      |      |  |      |      |      |      |      |
 *                        `----------------------------------'  `----------------------------------'
 */                           
     [_MINECFT] = LAYOUT(
          KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,                                          _______, _______, _______, _______, _______, _______,
          KC_7,    KC_A,    KC_S,    KC_W,    KC_D,    KC_E,                                          _______, KC_MS_L, KC_MS_U, KC_MS_D, KC_MS_R, _______,
          KC_J, KC_SLSH,    KC_F,    KC_Q,    KC_8,    KC_9, XXXXXXX, XXXXXXX,      _______, _______, _______, _______, _______, _______, _______, _______,
                                  MINECFT, KC_LCTL, KC_LSFT,  KC_SPC,  KC_ESC,      _______, KC_BTN2, KC_BTN1, KC_LOCK, _______
    ),

/*
 * FACTORIO template
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |   esc  |   q  |   f  |   m  |   r  |   t  |                              |      |      |      |      |      |        |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |   tab  | a    |  s   |   w  |  d   |   e  |                              |      |      |      |      |      |        |
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * |   shi  | z    |  x   |  c   |   v  |   b  |      |  ent |  |xxxxxx|      |      |      |      |      |      |        |
 * `----------------------+------+------+------+  spc +------|  |------+xxxxxx+------+------+------+----------------------'
 *                        |xxxxxx| fnum |  ctl |      |  alt |  |xxxxxx|      |xxxxxx|xxxxxx|xxxxxx|
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        `----------------------------------'  `----------------------------------'
 */                           
     [_FACTORI] = LAYOUT(
        _______, _______,    KC_F,    KC_M, _______, _______,                                         _______, _______, _______, _______, _______, _______,
        _______,    KC_A,    KC_S,    KC_W,    KC_D,    KC_E,                                         _______, _______, _______, _______, _______, _______,
        KC_LSFT, _______, _______, _______, _______, _______, XXXXXXX,  KC_ENT,     _______, _______, _______, _______, _______, _______, _______, _______,
                                   FACTORI, FACTSYM, _______, _______, _______,     _______, _______, _______, _______, _______
    ),

/*
 * factorio symbols template
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |        |   6  |   7  |   8  |   9  |   0  |                              |      |      |      |      |      |        |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |        |   1  |  2   |   3  |   4  |   5  |                              |      |      |      |      |      |        |
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * |        |      |      |      |   -  |   +  |      |      |  |xxxxxx|      |      |      |      |      |      |        |
 * `----------------------+------+------+------+      +------|  |------+xxxxxx+------+------+------+----------------------'
 *                        |xxxxxx|      |      |      |      |  |xxxxxx|      |xxxxxx|xxxxxx|xxxxxx|
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        `----------------------------------'  `----------------------------------'
 */                           
     [_FACTSYM] = LAYOUT(
        _______,    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                                         _______, _______, _______, _______, _______, _______,
        _______,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,                                         _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, KC_PMNS, KC_PPLS, XXXXXXX, _______,     _______, _______, _______, _______, _______, _______, _______, _______,
                                   _______, _______, _______, _______, _______,     _______, _______, _______, _______, _______
    ),

/*
 * factorio symbols template
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |        |   6  |   7  |   8  |   9  |   0  |                              |      |      |      |      |      |        |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |        |   1  |  2   |   3  |   4  |   5  |                              |      |      |      |      |      |        |
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * |        |      |      |      |   -  |   +  |      |      |  |xxxxxx|      |      |      |      |      |      |        |
 * `----------------------+------+------+------+      +------|  |------+xxxxxx+------+------+------+----------------------'
 *                        |xxxxxx|      |      |      |      |  |xxxxxx|      |xxxxxx|xxxxxx|xxxxxx|
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        `----------------------------------'  `----------------------------------'
 */                           
     [_MOUSE] = LAYOUT(
        _______, _______, _______, _______, _______, _______,                                         KC_BTN3, KC_BTN4, KC_BTN5, KC_BTN6, KC_BTN7, KC_BTN8,
        _______, KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R, _______,                                         KC_WH_L, KC_BTN1, KC_BTN2, KC_WH_U, KC_WH_D, KC_WH_R,
        _______, _______, _______, _______, _______, _______, _______, _______,     _______, _______, _______, KC_ACL0, KC_ACL1, KC_ACL2, _______, _______,
                                   _______, _______, _______, _______, _______,     _______, _______, _______, _______, _______
    ),
};





#ifdef OLED_ENABLE 
    oled_rotation_t oled_init_user(oled_rotation_t rotation) { return OLED_ROTATION_180; }

    /* advanced settings */
    #    define ANIM_FRAME_DURATION 200  // how long each frame lasts in ms
    #    define ANIM_SIZE           16   // number of bytes in array. If you change sprites, minimize for adequate firmware size. max is 1024

    /* timers */
    uint32_t anim_timer = 0;
    uint32_t anim_sleep = 0;
    uint32_t idle_time  = 0;

    /* current frame */
    uint8_t current_frame = 0;

    /* status variables */
    int   current_wpm = 0;
    led_t led_usb_state;

    /* logic */
    static void render_juno(uint8_t JUNO_X, uint8_t JUNO_Y) {


        static const char PROGMEM tail[10][ANIM_SIZE] = {
            {0,  0,  0,  0,  0,  0,  0,  2, 28, 96,128,239,250,254,239,128},
            {0,  0,  0,  0,  0,  0,  0,  0, 15,112,128,239,250,254,239,128},
            {0,  0,  0,  0,  0,  0,  0,  0,  0,127,128,239,250,254,239,128},
            {0,  0,  0,  0,  0,  0,  0,  0, 60, 66,128,239,250,254,239,128},
            {0,  0,  0,  0,  0,  0, 24, 36, 64, 64,128,239,250,254,239,128},
            {0,  0,  0,  0,  0, 16, 32, 32, 64, 64,128,239,250,254,239,128},
            {0,  0,  0,  0,  0, 32, 32, 64, 64, 64,128,239,250,254,239,128},
            {0,  0,  0,  0,  0, 64, 64,128,128,128,128,239,250,254,239,128},
            {0,  0,  0,  0,  0,  0,128, 64, 64, 64,128,239,250,254,239,128},
            {0,  0,  0,  0,  0, 32, 16, 16, 16, 96,128,239,250,254,239,128}
        };


        /* animation */
        void animate_luna(void) {

            /* switch frame */
            current_frame = (current_frame + 1) % 10;

            oled_set_cursor(JUNO_X, JUNO_Y + 1);
            oled_write_raw_P(tail[abs(current_frame)], ANIM_SIZE);  
        }

        /* animation timer */
        if (timer_elapsed32(anim_timer) > ANIM_FRAME_DURATION) {
            anim_timer = timer_read32();
            animate_luna();
        }

        /* this fixes the screen on and off bug */
        
        
        

    }

    

    void render_layer_information(void) {
        oled_write_P(PSTR("Layer: "), false);
        switch (get_highest_layer(layer_state|default_layer_state)) {
            case _QWERTY:
                oled_write_P(PSTR("QWERTY\n"), false);
                break;
            case _SYM:
                oled_write_P(PSTR("Symbol\n"), false);
                break;
            case _MINECFT:
                oled_write_P(PSTR("Minecraft\n"), false);
                break;
            case _FACTORI:
                oled_write_P(PSTR("Factorio\n"), false);
                break;
            case _FACTSYM:
                oled_write_P(PSTR("Hotbar\n"), false);
                break;
            default:
                oled_write_P(PSTR("Undefined\n"), false);
        }
        oled_write(get_u8_str(get_current_wpm(), '0'), false);
        oled_write_P(PSTR("\n"), false);
        
    }

    void render_toggle_status(void) {
        led_t led_usb_state = host_keyboard_led_state();
        oled_write_P(led_usb_state.num_lock    ? PSTR("NUMLCK ") : PSTR("       "), false);
        oled_write_P(led_usb_state.caps_lock   ? PSTR("CAPLCK ") : PSTR("       "), false);
        oled_write_P(led_usb_state.scroll_lock ? PSTR("SCRLCK ") : PSTR("       "), false);
        
    }


    bool oled_task_user(void) {
        current_wpm   = get_current_wpm();

        if (current_wpm <= 1) {
            idle_time = anim_sleep;
        }

        if (current_wpm > 0) {
            oled_on();
            rgblight_enable();
            anim_sleep = timer_read32();
        } else if (timer_elapsed32(anim_sleep) > OLED_TIMEOUT) {
            oled_off();
            rgblight_enable();
        } 
    
        

        // Render Master Animation
        if (is_keyboard_master()) {
            render_layer_information();
            render_toggle_status();
            render_juno(5, 6);
        }
        return false;
    }
#endif


// Define encoder action
#ifdef ENCODER_ENABLE
    bool encoder_update_user(uint8_t index, bool clockwise) {

        if (index == 0) {
            // Volume control
            if (clockwise) {
                tap_code(KC_VOLU);
            } else {
                tap_code(KC_VOLD);
            }
        } else if (index == 1) {
            // Page up/Page down
            if (clockwise) {
                tap_code(KC_PGDN);
            } else {
                tap_code(KC_PGUP);
            }
        }
        return false;
    }
#endif




// Light LEDs 6 to 9 and 12 to 15 red when caps lock is active. Hard to ignore!
const rgblight_segment_t PROGMEM my_capslock_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {1, 4, HSV_RED},       // Light 4 LEDs, starting with LED 6
    {6, 4, HSV_RED}       // Light 4 LEDs, starting with LED 12
);
// Light LEDs 9 & 10 in cyan when keyboard layer 1 is active
const rgblight_segment_t PROGMEM my_layer1_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {5, 2, HSV_CYAN}
);
// Light LEDs 9 & 10 in cyan when keyboard layer 1 is active
const rgblight_segment_t PROGMEM my_layer2_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {7, 3, HSV_PURPLE}
);



const rgblight_segment_t* const PROGMEM my_rgb_layers[] = RGBLIGHT_LAYERS_LIST(
    my_capslock_layer,
    my_layer1_layer,    // Overrides caps lock layer
    my_layer2_layer

);

void keyboard_post_init_user(void) {
    // Enable the LED layers
    rgblight_layers = my_rgb_layers;
}



bool led_update_user(led_t led_state) {
    rgblight_set_layer_state(0, led_state.caps_lock);
    return true;
}

layer_state_t default_layer_state_set_user(layer_state_t state) {
    rgblight_set_layer_state(1, layer_state_cmp(state, _QWERTY));
    return state;
}

layer_state_t layer_state_set_user(layer_state_t state) {
    rgblight_set_layer_state(2, layer_state_cmp(state, _SYM));
    return state;
}