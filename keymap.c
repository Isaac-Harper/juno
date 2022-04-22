#include QMK_KEYBOARD_H
#include <stdio.h>


char wpm_str[10];

enum layers {
    _BASE,
    _QWERTY = 1,
    _NAV,
    _SYM,
};


// Aliases for readability
#define BASE   DF(_BASE)

#define HOME     MO(_QWERTY)
#define SYM      MO(_SYM)
#define NAV      MO(_NAV)


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {


/*
 * Base Layer: Base
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |        |      |      |      |      |      |                              |      |      |      |      |      |  Bksp  |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |                              |      |      |      |      |      |  tab   |
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |      |  |      |      |      |      |      |      |      | del    |
 * `----------------------+------+------+------+Space +------|  |------+enter +------+------+------+----------------------'
 *                        |      |Lshif | ctrl |      |Esc   |  | Sym  |      |  alt |  nav |      |
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        `----------------------------------'  `----------------------------------'
 */
    [_BASE] = LAYOUT(
    _______, _______, _______, _______, _______, _______,                                     _______, _______, _______, _______, _______, KC_BSPC,
    _______, _______, _______, _______, _______, _______,                                     _______, _______, _______, _______, _______, KC_TAB ,
    _______, _______, _______, _______, _______, _______, XXXXXXX, _______, _______, XXXXXXX, _______, _______, _______, _______, _______, KC_DEL ,
                               _______, KC_LSFT, KC_LCTL, KC_SPC , KC_ESC , SYM    , KC_ENT , KC_LALT, NAV    , _______
    ),


/*
 * Base Layer: QWERTY
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |        |   Q  |   W  |   E  |   R  |   T  |                              |   Y  |   U  |   I  |   O  |   P  |  Bksp  |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |  "  '  |   A  |   S  |   D  |   F  |   G  |                              |   H  |   J  |   K  |   L  | ;  : |  tab   |
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * |        |   Z  |   X  |   C  |   V  |   B  |      |      |  |      |      |   N  |   M  | ,  < | . >  | /  ? | del    |
 * `----------------------+------+------+------+Space +------|  |------+enter +------+------+------+----------------------'
 *                        |      |Lshif | ctrl |      |Esc   |  | Sym  |      |  alt |  nav |      |
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        `----------------------------------'  `----------------------------------'
 */
    [_QWERTY] = LAYOUT(
    _______, KC_Q ,  KC_W   ,  KC_E  ,   KC_R ,   KC_T ,                                     KC_Y   , KC_U   , KC_I   , KC_O   , KC_P   , _______,
   KC_QUOTE, KC_A ,  KC_S   ,  KC_D  ,   KC_F ,   KC_G ,                                     KC_H   , KC_J   , KC_K   , KC_L   , KC_SCLN, _______,
    _______, KC_Z ,  KC_X   ,  KC_C  ,   KC_V ,   KC_B , XXXXXXX, _______, _______, XXXXXXX, KC_N   , KC_M   , KC_COMM, KC_DOT , KC_SLSH, _______,
                              _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
    ),


/*
 * Nav Layer: Media, navigation
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |        |      |      |      |      |      |                              |      |      |      |      |      |  bksp  |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |        | Left | Down |  Up  |Right |      |                              |      | Left | Down |  Up  |Right |  tab   |
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |      |  |      |      |      |      |      |      |      |  del   |
 * `----------------------+------+------+------+ space+------|  |------+ enter+------+------+------+----------------------'
 *                        |      |Lshif | ctrl |      |Esc   |  | Sym  |      |  alt |  nav |      |
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        `----------------------------------'  `----------------------------------'
 */
    [_NAV] = LAYOUT(
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                                     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,
      XXXXXXX, KC_LEFT, KC_DOWN, KC_UP  , KC_RGHT, XXXXXXX,                                     XXXXXXX, KC_LEFT, KC_DOWN, KC_UP  , KC_RGHT, _______,
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______, _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,
                                 _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
    ),



/*
  * Sym Layer: Numbers and symbols
  *
  * ,-------------------------------------------.                              ,-------------------------------------------.
  * |    F9  | F10  | F11  | F12  |   (  |   )  |                              |   `  |   1  |   2  |   3  |  0   |  Bksp  |
  * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
  * |    F5  |  F6  |  F7  |  F8  |   [  |   ]  |                              |   -  |   4  |   5  |   6  |  \   |  tab   |
  * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
  * |    F1  |  F2  |  F3  |  F4  |   <  |   >  |      |numloc|  |caploc|      |   =  |   7  |   8  |   9  |      |   Del  |
  * `----------------------+------+------+------+ space+------|  |------+ enter+------+------+------+----------------------'
  *                        |      |Lshif | ctrl |      |Esc   |  | Sym  |      |  alt |  nav |      |
  *                        |      |      |      |      |      |  |      |      |      |      |      |
  *                        `----------------------------------'  `----------------------------------'
  */
    [_SYM] = LAYOUT(
       KC_F9 ,  KC_F10,  KC_F11,  KC_F12, KC_LPRN, KC_RPRN,                                     KC_GRV ,  KC_7  ,  KC_8  ,   KC_9  ,   KC_0 , _______,
       KC_F5 ,  KC_F6 ,  KC_F7 ,  KC_F8 , KC_LBRC, KC_RBRC,                                     KC_MINS,  KC_4  ,  KC_5  ,   KC_6  , KC_BSLS, _______,
       KC_F1 ,  KC_F2 ,  KC_F3 ,  KC_F4 , KC_LT  , KC_GT  , XXXXXXX, KC_NLCK, KC_CAPS, XXXXXXX, KC_EQL ,  KC_1  ,  KC_2  ,   KC_3  , XXXXXXX, _______,
                                 _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
    ),

/*
 * Layer template
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |        |      |      |      |      |      |                              |      |      |      |      |      |        |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |                              |      |      |      |      |      |        |
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |      |  |      |      |      |      |      |      |      |        |
 * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        `----------------------------------'  `----------------------------------'
 */
//     [_LAYERINDEX] = LAYOUT(
//       _______, _______, _______, _______, _______, _______,                                     _______, _______, _______, _______, _______, _______,
//       _______, _______, _______, _______, _______, _______,                                     _______, _______, _______, _______, _______, _______,
//       _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
//                                  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
//     ),
};



#ifdef OLED_ENABLE
    oled_rotation_t oled_init_user(oled_rotation_t rotation) { return OLED_ROTATION_180; }




    #define TAP_FRAMES 2
    #define TAP_SPEED 50
    #define IDLE_SPEED 10 // below this wpm value your animation will idle

    #define JUNO_TAIL_FRAMES 2
    #define JUNO_TAIL_SPEED 50
    #define JUNO_TAIL_ANIM_SIZE 16

    #define IDLE_SPEED 10 // below this wpm value your animation will idle

    #define ANIM_FRAME_DURATION 500 // how long each frame lasts in ms
    #define ANIM_SIZE 600 // number of bytes in array, minimize for adequate firmware size, max is 1024

    uint32_t anim_timer = 0;
    uint32_t anim_sleep = 0;
    uint8_t current_idle_frame = 0;
    uint8_t current_prep_frame = 0;
    uint8_t current_tap_frame = 0;
    uint8_t current_juno_tail_frame = 0;

    int current_wpm = 0;

    void render_logo(void) {
        static const char PROGMEM raw_logo[ANIM_SIZE] = {
            0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,192,248,240,224,224,224,240,248,192,  0,  0,  0,
            0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,192,240,253,255,255,255,255,255,253,240,192,  0,  0,
            0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  1,  3,135,231,255, 63,  7,  3,  1,  0,  0,  0,
            0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  1,  3,  6,  4,  0,  0,  0,  0,  0,  0,

            };
        oled_write_raw_P(raw_logo, sizeof(raw_logo));
    }

    void render_juno_head(void) {
        static const char PROGMEM raw_logo[ANIM_SIZE] = {
            0,  0,  0,192,248,240,224,224,224,224,240,248,192,  0,  0,  0,
        };
        oled_write_raw_P(raw_logo, sizeof(raw_logo));
    }

    void render_juno_body(void) {
        static const char PROGMEM raw_logo[ANIM_SIZE] = {
            0,  0,192,240,253,255,255,255,255,255,255,253,240,192,  0,  0,
        };
        oled_write_raw_P(raw_logo, sizeof(raw_logo));
    }
    void render_juno_tail1(void) {
        static const char PROGMEM raw_logo[ANIM_SIZE] = {
            0,  0,  0,  1,  3,  7,135,231,255, 63,  7,  3,  1,  0,  0,  0,
        };
        oled_write_raw_P(raw_logo, sizeof(raw_logo));
    }
    void render_juno_tail2(void) {
        static const char PROGMEM raw_logo[ANIM_SIZE] = {
                0,  0,  0,  0,  0,  0,  1,  3,  6,  4,  0,  0,  0,  0,  0,  0,
        };
        oled_write_raw_P(raw_logo, sizeof(raw_logo));
    }

    static void render_anim(void) {
        /*
        static const char PROGMEM tap[TAP_FRAMES][ANIM_SIZE] = {
            {
            0,0,3,231,255,123,63,63,123,255,231,3,0,0               
            },
            {
            0,  0,192,248,240,224,224,224,240,248,192,  0,  0,  0,  0,  0,  
            0,192,240,253,255,255,255,255,255,253,240,192,  0,  0,  0,  0,  
            0,  0,  1,  3,135,231,255, 63,  7,  3,  1,  0,  0,  0,  0,  0,  
            0,  0,  0,  0,  1,  3,  6,  4,  0,  0,  0,  0,  0,  0,  0,  0,
            }
        };
*/
        static const char PROGMEM juno_tail1[JUNO_TAIL_FRAMES][JUNO_TAIL_ANIM_SIZE] = {
            {
                0,  0,  0,  1,  3,  7,135,231,255, 63,  7,  3,  1,  0,  0,  0,      
            },
            {
                0,  0,  0,  1,  3,  7, 63,255,231,135,  7,  3,  1,  0,  0,  0,
            }
        };
        static const char PROGMEM juno_tail2[JUNO_TAIL_FRAMES][JUNO_TAIL_ANIM_SIZE] = {
            {
                0,  0,  0,  0,  0,  0,  1,  3,  6,  4,  0,  0,  0,  0,  0,  0,    
            },
            {
                0,  0,  0,  0,  0,  0,  4,  6,  3,  1,  0,  0,  0,  0,  0,  0,
            }
        };
    

        

        void animation_phase(void) {
                current_tap_frame = (current_tap_frame + 1) % TAP_FRAMES;

                current_juno_tail_frame = (current_juno_tail_frame + 1) % JUNO_TAIL_FRAMES;
                

                if (get_current_wpm() <=IDLE_SPEED) {
                    //oled_write_raw_P(tap[abs((TAP_FRAMES-1)-current_tap_frame)], ANIM_SIZE);
                    oled_set_cursor(0, 0);
                    render_juno_head();
                    oled_set_cursor(0, 1);
                    render_juno_body();
                    oled_set_cursor(0, 2);
                    oled_write_raw_P(juno_tail1[abs((JUNO_TAIL_FRAMES-1)-current_juno_tail_frame)], JUNO_TAIL_ANIM_SIZE);
                    oled_set_cursor(0, 3);
                    oled_write_raw_P(juno_tail2[abs((JUNO_TAIL_FRAMES-1)-current_juno_tail_frame)], JUNO_TAIL_ANIM_SIZE);
                }
                if(get_current_wpm() >IDLE_SPEED && get_current_wpm() <TAP_SPEED){
                    oled_write_P(PSTR("Function\n"), false);
                }
                if(get_current_wpm() >=TAP_SPEED){
                    oled_write_P(PSTR("Undefined\n"), false);
                }
                
        }
        
        


        if(get_current_wpm() != 000) {
            oled_on(); // not essential but turns on animation OLED with any alpha keypress
            if(timer_elapsed32(anim_timer) > ANIM_FRAME_DURATION) {
                anim_timer = timer_read32();
                oled_clear();
                animation_phase();
            }
            anim_sleep = timer_read32();
        } else {
            if(timer_elapsed32(anim_sleep) > OLED_TIMEOUT) {
                oled_off();
            } else {
                if(timer_elapsed32(anim_timer) > ANIM_FRAME_DURATION) {
                    anim_timer = timer_read32();
                    oled_clear();
                    animation_phase();
                }
            }
        }
        
    }

    void render_layer(void) {
        oled_write_P(PSTR("Layer: "), false);
        switch (get_highest_layer(layer_state|default_layer_state)) {
            case _QWERTY:
                oled_write_P(PSTR("QWERTY\n"), false);
                break;
            case _NAV:
                oled_write_P(PSTR("Nav\n"), false);
                break;
            case _SYM:
                oled_write_P(PSTR("Sym\n"), false);
                break;
            default:
                oled_write_P(PSTR("Undefined\n"), false);
        }
        oled_write(get_u8_str(get_current_wpm(), '0'), false);
    }

    void render_status(void) {
        led_t led_usb_state = host_keyboard_led_state();
        oled_write_P(led_usb_state.num_lock    ? PSTR("NUMLCK ") : PSTR("       "), false);
        oled_write_P(led_usb_state.caps_lock   ? PSTR("CAPLCK ") : PSTR("       "), false);
        oled_write_P(led_usb_state.scroll_lock ? PSTR("SCRLCK ") : PSTR("       "), false);
    }


    bool oled_task_user(void) {

        if (is_keyboard_master()) {
            render_anim();
        }
        if (!is_keyboard_master()) {
            render_layer();
            render_status();
             
        }

        return false;
    }
#endif

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

void suspend_power_down_user(void) {
    oled_off();
}

void suspend_wakeup_init_user(void) {
    set_single_persistent_default_layer(_QWERTY);
}