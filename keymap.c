#include QMK_KEYBOARD_H
#include <stdio.h>
 

enum layers {
    _BASE,
    _QWERTY = 1,
    _SYM,
    _GAM,
    _FACTORI,
    _FACTSYM,
};


// Aliases for readability
#define BASE     DF(_BASE)
#define HOME     MO(_QWERTY)
#define SYM      MO(_SYM)
#define GAM      TG(_GAM)
#define FACTORI      TG(_FACTORI)
#define FACTSYM      MO(_FACTSYM)


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = { // this is fine


/*
 * Base Layer: Base
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |   esc  |      |      |      |      |      |                              |      |      |      |      |      | bksp   |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |   tab  |      |      |      |      |      |                              |      |      |      |      |      |        |
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * | shift  |      |      |      |      |      |      |      |  |      |      |      |      |      |      |      | shift  |
 * `----------------------+------+------+------+space +------|  |------| enter|------+------+------+----------------------'
 *                        |  enc | gui  | ctrl |      | alt  |  | sym  |      | bksp |  del |  enc |
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        `----------------------------------'  `----------------------------------'
 */
    [_BASE] = LAYOUT(
     KC_ESC, _______, _______, _______, _______, _______,                                     _______, _______, _______, _______, _______, KC_BSPC,
     KC_TAB, _______, _______, _______, _______, _______,                                     _______, _______, _______, _______, _______, _______,
    KC_LSFT, _______, _______, _______, _______, _______, XXXXXXX, FACTORI, _______, XXXXXXX, _______, _______, _______, _______, _______, KC_RSFT,
                               _______, KC_LGUI, KC_LCTL, KC_SPC , KC_LALT ,   SYM , KC_ENT , KC_BSPC, KC_DEL , _______
    ),


/*
 * Base Layer: QWERTY
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |        |   Q  |   W  |   E  |   R  |   T  |                              |   Y  |   U  |   I  |   O  |   P  |        |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |        |   A  |   S  |   D  |   F  |   G  |                              |   H  |   J  |   K  |   L  | ;  : |  "  '  |
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * |        |   Z  |   X  |   C  |   V  |   B  |      |xxxxxx|  |xxxxxx|      |   N  |   M  | ,  < | . >  | /  ? |        |
 * `----------------------+------+------+------+xxxxxx+------|  |------+xxxxxx+------+------+------+----------------------'
 *                        |xxxxxx|xxxxxx|xxxxxx|      |xxxxxx|  |xxxxxx|      |xxxxxx|xxxxxx|xxxxxx|
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        `----------------------------------'  `----------------------------------'
 */
    [_QWERTY] = LAYOUT(
    _______, KC_Q ,  KC_W   ,  KC_E  ,   KC_R ,   KC_T ,                                     KC_Y   , KC_U   , KC_I   , KC_O   , KC_P   , _______,
    _______, KC_A,   KC_S   ,  KC_D  ,   KC_F ,   KC_G ,                                     KC_H   ,  KC_J  ,  KC_K  ,  KC_L  , KC_SCLN, KC_QUOTE,
    _______, KC_Z ,  KC_X   ,  KC_C  ,   KC_V ,   KC_B , XXXXXXX, _______, _______, XXXXXXX, KC_N   , KC_M   , KC_COMM, KC_DOT , KC_SLSH, _______,
                              _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
    ),

/*
  * Sym Layer: Numbers and symbols
  *
  * ,-------------------------------------------.                              ,-------------------------------------------.
  * |        |  {   |   [  |  (   |   <  |      |                              |  `/~ |   1  |   2  |   3  |  0   |        |
  * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
  * |        | GUI  | ALT  | SHFT | CTRL |      |                              |  -/_ |   4  |   5  |   6  |  \/| |        |
  * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
  * |        |  }   |   ]  |  )   |   >  |      |      |xxxxxx|  |xxxxxx|      |  =/+ |   7  |   8  |   9  |      |        |
  * `----------------------+------+------+------+xxxxxx+------|  |------+xxxxxx+------+------+------+----------------------'
  *                        |xxxxxx|xxxxxx|xxxxxx|      |xxxxxx|  |xxxxxx|      |xxxxxx|xxxxxx|xxxxxx|
  *                        |      |      |      |      |      |  |      |      |      |      |      |
  *                        `----------------------------------'  `----------------------------------'
  */
    [_SYM] = LAYOUT(
      _______,   KC_LT, KC_LBRC, KC_LCBR, KC_LPRN, _______,                                     KC_GRV ,  KC_7  ,  KC_8  ,   KC_9  ,   KC_0 , _______,
      _______, KC_LEFT, KC_DOWN, KC_UP  , KC_RGHT, _______,                                     KC_MINS,  KC_4  ,  KC_5  ,   KC_6  , KC_BSLS, _______,
      _______,   KC_GT, KC_RBRC, KC_RCBR, KC_RPRN, _______, XXXXXXX, _______, _______, XXXXXXX, KC_EQL ,  KC_1  ,  KC_2  ,   KC_3  , _______, _______,
                                 _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
    ),



/*
 * gaming template
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |   5    |   1  |   2  |   W  |   3  |   4  |                              |      |      |      |      |      |        |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |   6    | lshf |  A   |   S  |   D  |   e  |                              |      |      |      |      |      |        |
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * |   7    | lctl |  /   |  j   |   f  |   q  |      |xxxxxx|  |xxxxxx|      |      |      |      |      |      |        |
 * `----------------------+------+------+------+  spc +------|  |------+xxxxxx+------+------+------+----------------------'
 *                        |xxxxxx|   8  |  9   |      |  esc |  |xxxxxx|      |xxxxxx|xxxxxx|xxxxxx|
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        `----------------------------------'  `----------------------------------'
 */                           
     [_GAM] = LAYOUT(
          KC_5,    KC_1,    KC_2,    KC_W,    KC_3,    KC_4,                                     _______, _______, _______, _______, _______, _______,
          KC_6, KC_LSFT,    KC_A,    KC_S,    KC_D,    KC_E,                                     _______, _______, _______, _______, _______, _______,
          KC_7, KC_LCTL, KC_SLSH,    KC_J,    KC_F,    KC_Q, XXXXXXX, _______, _______, _______, _______, _______, _______, _______, _______, _______,
                                  _______,    KC_8,    KC_9,  KC_SPC,  KC_ESC, _______, _______, _______, _______, _______
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
        _______, _______,    KC_F,    KC_M, _______, _______,                                     _______, _______, _______, _______, _______, _______,
        _______,    KC_A,    KC_S,    KC_W,    KC_D,    KC_E,                                     _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, XXXXXXX,  KC_ENT, _______, _______, _______, _______, _______, _______, _______, _______,
                                   _______, FACTSYM, _______, _______, _______, _______, _______, _______, _______, _______
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
        _______,    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                                     _______, _______, _______, _______, _______, _______,
        _______,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,                                     _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, KC_PMNS, KC_PPLS, XXXXXXX, FACTORI, _______, _______, _______, _______, _______, _______, _______, _______,
                                   _______, _______, _______,  _______,  _______, _______, _______, _______, _______, _______
    ),
};





#ifdef OLED_ENABLE 
    oled_rotation_t oled_init_user(oled_rotation_t rotation) { return OLED_ROTATION_180; }

    /* KEYBOARD PET START */

/* settings */
#    define MIN_WALK_SPEED      10
#    define MIN_RUN_SPEED       40

/* advanced settings */
#    define ANIM_FRAME_DURATION 200  // how long each frame lasts in ms
#    define ANIM_SIZE           16   // number of bytes in array. If you change sprites, minimize for adequate firmware size. max is 1024

/* timers */
uint32_t anim_timer = 0;
uint32_t anim_sleep = 0;

/* current frame */
uint8_t current_frame = 0;

/* status variables */
int   current_wpm = 0;
led_t led_usb_state;

bool isSneaking = false;

/* logic */
static void render_luna(uint8_t LUNA_X, uint8_t LUNA_Y) {

    /* Bark */
    static const char PROGMEM bark[2][ANIM_SIZE] = {/* 'sneak1', 32x22px */
        {0, 12,  8, 16, 16, 24, 12,124,254, 30, 30, 14, 62, 12,254,  0},

        /* 'sneak2', 32x22px */
        {0,  8, 48, 48, 24, 28, 12,254,126, 62, 30, 30,254, 12, 62,  0}
    };

    /* Sneak */
    static const char PROGMEM sneak[2][ANIM_SIZE] = {/* 'sneak1', 32x22px */
        {0, 12,  8, 16, 16, 24, 12,124,254, 30, 30, 14, 62, 12,254,  0},

        /* 'sneak2', 32x22px */
        {0,  8, 48, 48, 24, 28, 12,254,126, 62, 30, 30,254, 12, 62,  0}
    };

    /* Run */
    static const char PROGMEM walk[2][ANIM_SIZE] = {
        {0, 12,  8, 16, 16, 24, 12,124,254, 30, 30, 14, 62, 12,254,  0},
        {0,  8, 48, 48, 24, 28, 12,254,126, 62, 30, 30,254, 12, 62,  0}
    };

    /* Run */
    static const char PROGMEM sit[2][ANIM_SIZE] = {
        {0,  0, 24,124,196,130,226,248,252,252,190, 30,254, 12,254,  0},
        {0,  0,  7,126,192,128,224,248,252,252,190, 62,254, 12,254,  0}
    };

    /* Run */
    static const char PROGMEM run[2][ANIM_SIZE] = {
        {6, 35, 19, 25, 77, 63, 15, 14, 14, 14, 14, 14,126,142, 62,192},
        {7, 12, 16, 24,124,220, 62,126,206, 14, 14, 14, 62, 78, 14, 48}
    };

    static const char PROGMEM head[ANIM_SIZE] = {
        0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,248,144,240,248,
    };

    /* animation */
    void animate_luna(void) {

        /* switch frame */
        current_frame = (current_frame + 1) % 2;
        oled_set_cursor(LUNA_X, LUNA_Y);
        oled_write_raw_P(head, ANIM_SIZE);

        oled_set_cursor(LUNA_X, LUNA_Y + 1);
        /* current status */
        if (led_usb_state.caps_lock) {
            oled_write_raw_P(bark[abs(1 - current_frame)], ANIM_SIZE);

        } else if (isSneaking) {
            oled_write_raw_P(sneak[abs(1 - current_frame)], ANIM_SIZE);

        } else if (current_wpm <= MIN_WALK_SPEED) {
            oled_write_raw_P(sit[abs(1 - current_frame)], ANIM_SIZE);

        } else if (current_wpm <= MIN_RUN_SPEED) {
            oled_write_raw_P(walk[abs(1 - current_frame)], ANIM_SIZE);

        } else {
            oled_write_raw_P(run[abs(1 - current_frame)], ANIM_SIZE);
        }
    }

    /* animation timer */
    if (timer_elapsed32(anim_timer) > ANIM_FRAME_DURATION) {
        anim_timer = timer_read32();
        animate_luna();
    }

    /* this fixes the screen on and off bug */
    if (current_wpm > 0) {
        oled_on();
        anim_sleep = timer_read32();
    } else if (timer_elapsed32(anim_sleep) > OLED_TIMEOUT) {
        oled_off();
    }
}

/* KEYBOARD PET END */
 

void render_layer_information(void) {
    oled_write_P(PSTR("Layer: "), false);
    switch (get_highest_layer(layer_state|default_layer_state)) {
        case _QWERTY:
            oled_write_P(PSTR("QWERTY\n"), false);
            break;
        case _SYM:
            oled_write_P(PSTR("Sym\n"), false);
            break;
        case _GAM:
            oled_write_P(PSTR("Gam\n"), false);
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
}

void render_toggle_status(void) {
    led_t led_usb_state = host_keyboard_led_state();
    oled_write_P(led_usb_state.num_lock    ? PSTR("NUMLCK ") : PSTR("       "), false);
    oled_write_P(led_usb_state.caps_lock   ? PSTR("CAPLCK ") : PSTR("       "), false);
    oled_write_P(led_usb_state.scroll_lock ? PSTR("SCRLCK ") : PSTR("       "), false);
}


bool oled_task_user(void) {
    current_wpm   = get_current_wpm();

    // Render Master Animation
    if (is_keyboard_master()) {
        render_layer_information();
        render_toggle_status();
        render_luna(5, 6);
    }
    return false;
}
#endif

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case KC_LCTL:
            if (record->event.pressed) {
                isSneaking = true;
            } else {
                isSneaking = false;
            }
            break;
    }
    return true;
}

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
