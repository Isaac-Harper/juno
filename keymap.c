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

#define SHFTSPC SFT_T(KC_SPC)
#define TABCTRL CTL_T(KC_TAB)
#define ENTALT  ALT_T(KC_ENT)



const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = { // this is fine


/*
 * Base Layer: Base
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |        |      |      |      |      |      |                              |      |      |      |      |      |        |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |                              |      |      |      |      |      |        |
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |      |  |      |      |      |      |      |      |      |        |
 * `----------------------+------+------+------+space +------|  |------| enter|------+------+------+----------------------'
 *                        |  enc | Sym  | tab  |shift | bksp |  | del  |  alt |      |      |  enc |
 *                        |      |      | ctrl |      |      |  |      |      |      |      |      |
 *                        `----------------------------------'  `----------------------------------'
 */
    [_BASE] = LAYOUT(
    _______, _______, _______, _______, _______, _______,                                     _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______,                                     _______, _______, _______, _______, _______, _______ ,
    _______, _______, _______, _______, _______, _______, XXXXXXX, _______, _______, XXXXXXX, _______, _______, _______, _______, _______, _______,
                               _______, SYM    , TABCTRL, SHFTSPC , KC_BSPC, KC_DEL,  ENTALT, _______, _______, _______
    ),


/*
 * Base Layer: czz  DAFADFAASDFASF
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |  esc   |   Q  |   W  |   E  |   R  |   T  |                              |   Y  |   U  |   I  |   O  |   P  |  \ |   |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |  TAB   |   A  |   S  |   D  |   F  |   G  |                              |   H  |   J  |   K  |   L  | ;  : |  "  '  |
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * |        |   Z  |   X  |   C  |   V  |   B  |      |xxxxxx|  |xxxxxx|      |   N  |   M  | ,  < | . >  | /  ? |        |
 * `----------------------+------+------+------+xxxxxx+------|  |------+xxxxxx+------+------+------+----------------------'
 *                        |xxxxxx|xxxxxx|xxxxxx|      |xxxxxx|  |xxxxxx|      |xxxxxx|xxxxxx|xxxxxx|
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        `----------------------------------'  `----------------------------------'
 */
    [_QWERTY] = LAYOUT(
     KC_ESC, KC_Q ,  KC_W   ,  KC_E  ,   KC_R ,   KC_T ,                                     KC_Y   , KC_U   , KC_I   , KC_O   , KC_P   , KC_BSLS,
    _______, KC_A ,  KC_S   ,  KC_D  ,   KC_F ,   KC_G ,                                     KC_H   , KC_J   , KC_K   , KC_L   , KC_SCLN, KC_QUOTE,
    _______, KC_Z ,  KC_X   ,  KC_C  ,   KC_V ,   KC_B , XXXXXXX, _______, _______, XXXXXXX, KC_N   , KC_M   , KC_COMM, KC_DOT , KC_SLSH, _______,
                              _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
    ),


/*
 * Nav Layer: Media, navigation
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |   F1   |   F2 |   F3 |   F4 |   F5 |   F6 |                              |   F7 |   F8 |   F9 |  F10 |  F11 |  F12   |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |        | Left | Down |  Up  |Right |      |                              |      | Left | Down |  Up  |Right |        |
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |xxxxxx|  |xxxxxx|      |      |      |      |      |      |        |
 * `----------------------+------+------+------+xxxxxx+------|  |------+xxxxxx+------+------+------+----------------------'
 *                        |xxxxxx|xxxxxx|xxxxxx|      |xxxxxx|  |xxxxxx|      |xxxxxx|xxxxxx|xxxxxx|
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
  * |        |  {   |   [  |  (   |   <  |      |                              |  `/~ |   1  |   2  |   3  |  0   |        |
  * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
  * |        | Left | Down |  Up  |Right |      |                              |  -/_ |   4  |   5  |   6  |  \/| |        |
  * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
  * |        |  }   |   ]  |  )   |   >  |      |      |xxxxxx|  |xxxxxx|      |  =/+ |   7  |   8  |   9  |      |        |
  * `----------------------+------+------+------+xxxxxx+------|  |------+xxxxxx+------+------+------+----------------------'
  *                        |xxxxxx|xxxxxx|xxxxxx|      |xxxxxx|  |xxxxxx|      |xxxxxx|xxxxxx|xxxxxx|
  *                        |      |      |      |      |      |  |      |      |      |      |      |
  *                        `----------------------------------'  `----------------------------------'
  */
    [_SYM] = LAYOUT(
      _______, KC_LCBR, KC_LBRC, KC_LPRN,   KC_LT, _______,                                     KC_GRV ,  KC_7  ,  KC_8  ,   KC_9  ,   KC_0 , _______,
      _______, KC_LEFT, KC_DOWN, KC_UP  , KC_RGHT, _______,                                     KC_MINS,  KC_4  ,  KC_5  ,   KC_6  , KC_BSLS, _______,
      _______, KC_RCBR, KC_RBRC, KC_RPRN, KC_GT  , _______, XXXXXXX, KC_NLCK, KC_CAPS, XXXXXXX, KC_EQL ,  KC_1  ,  KC_2  ,   KC_3  , _______, _______,
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
 * |        |      |      |      |      |      |      |xxxxxx|  |xxxxxx|      |      |      |      |      |      |        |
 * `----------------------+------+------+------+xxxxxx+------|  |------+xxxxxx+------+------+------+----------------------'
 *                        |xxxxxx|xxxxxx|xxxxxx|      |xxxxxx|  |xxxxxx|      |xxxxxx|xxxxxx|xxxxxx|
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



#ifdef OLED_ENABLE // it is
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

        static const char PROGMEM juno_head_anim[JUNO_TAIL_FRAMES][JUNO_TAIL_ANIM_SIZE] = {
            {
                0,  0,  0,192,248,240,224,224,224,224,240,248,192,  0,  0,  0,      
            },
            {
                0,  0,  0,192,248,240,224,224,224, 96,240,248,192,  0,  0,  0,
            }
        };
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
                    oled_write_raw_P(juno_tail1[0], JUNO_TAIL_ANIM_SIZE);
                    oled_set_cursor(0, 3);
                    oled_write_raw_P(juno_tail2[0], JUNO_TAIL_ANIM_SIZE);
                }
                if(get_current_wpm() >IDLE_SPEED && get_current_wpm() <TAP_SPEED){
                    oled_write_P(PSTR("Function\n"), false);
                    oled_set_cursor(0, 0);
                    render_juno_head();
                    oled_set_cursor(0, 1);
                    render_juno_body();
                    oled_set_cursor(0, 2);
                    oled_write_raw_P(juno_tail1[abs((JUNO_TAIL_FRAMES-1)-current_juno_tail_frame)], JUNO_TAIL_ANIM_SIZE);
                    oled_set_cursor(0, 3);
                    oled_write_raw_P(juno_tail2[abs((JUNO_TAIL_FRAMES-1)-current_juno_tail_frame)], JUNO_TAIL_ANIM_SIZE);
                }
                if(get_current_wpm() >=TAP_SPEED){
                    oled_set_cursor(0, 0);
                    oled_write_raw_P(juno_head_anim[abs((JUNO_TAIL_FRAMES-1)-current_juno_tail_frame)], JUNO_TAIL_ANIM_SIZE);
                    oled_set_cursor(0, 1);
                    render_juno_body();
                    oled_set_cursor(0, 2);
                    oled_write_raw_P(juno_tail1[abs((JUNO_TAIL_FRAMES-1)-current_juno_tail_frame)], JUNO_TAIL_ANIM_SIZE);
                    oled_set_cursor(0, 3);
                    oled_write_raw_P(juno_tail2[abs((JUNO_TAIL_FRAMES-1)-current_juno_tail_frame)], JUNO_TAIL_ANIM_SIZE);
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