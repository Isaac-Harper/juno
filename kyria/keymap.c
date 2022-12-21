
#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include "config.h"

#include QMK_KEYBOARD_H

typedef struct {
    bool is_press_action;
    int state;
} tap;

enum {
    SINGLE_TAP = 1,
    SINGLE_HOLD = 2,
    DOUBLE_TAP = 3,
    DOUBLE_HOLD = 4,
    DOUBLE_SINGLE_TAP = 5, //send two single taps
    TRIPLE_TAP = 6,
    TRIPLE_HOLD = 7
};

//Tap dance enums
enum {
    X_CTL = 0,
    PAR,
    CUR,
    BRA,
    ALI,
    SOME_OTHER_DANCE
};

int cur_dance (qk_tap_dance_state_t *state);

//for the x tap dance. Put it here so it can be used in any keymap
void x_finished (qk_tap_dance_state_t *state, void *user_data);
void x_reset (qk_tap_dance_state_t *state, void *user_data);

void par_finished (qk_tap_dance_state_t *state, void *user_data);
void par_reset (qk_tap_dance_state_t *state, void *user_data);

void cur_finished (qk_tap_dance_state_t *state, void *user_data);
void cur_reset (qk_tap_dance_state_t *state, void *user_data);

void bra_finished (qk_tap_dance_state_t *state, void *user_data);
void bra_reset (qk_tap_dance_state_t *state, void *user_data);

void ali_finished (qk_tap_dance_state_t *state, void *user_data);
void ali_reset (qk_tap_dance_state_t *state, void *user_data);





enum layers {
    _QWERTY = 1,
    _SYM,
    _MOUSE,
    _MINECFT,
    _FACTORI,
    _FACTSYM,
};
  


// Aliases for readability
#define HOME            DF(_QWERTY)
#define SYM             MO(_SYM)
#define SYT             TG(_SYM)
#define MINECFT         TG(_MINECFT)
#define FACTORI         TG(_FACTORI)
#define FACTSYM         MO(_FACTSYM)
#define MOUSE           MO(_MOUSE)

#define SAB             LT(_SYM, KC_BSPC)         // click for backspace, hold for sym
#define AAD MT(MOD_LGUI, KC_DEL)      // click for delete, hold for alt



const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = { // this is fine

/*
 * Template Layer: 
 *
 * ┌─────┬─────┬─────┬─────┬─────┬─────┐
 * │ XXX │ XXX │ XXX │ XXX │ XXX │ XXX │
 * ├─────┼─────┼─────┼─────┼─────┼─────┤   LEFT
 * │ XXX │ XXX │ XXX │ XXX │ XXX │ XXX │
 * ├─────┼─────┼─────┼─────┼─────┼─────┼─────┬─────┐
 * │ XXX │ XXX │ XXX │ XXX │ XXX │ XXX │     │     │
 * └─────┴─────┴─────┼─────┼─────┼─────┤ XXX │ XXX │
 *                   │ XXX │ XXX │ XXX │     │     │
 *                   └─────┴─────┴─────┴─────┴─────┘
 * 
 *  
 *             ┌─────┬─────┬─────┬─────┬─────┬─────┐
 *             │ XXX │ XXX │ XXX │ XXX │ XXX │ XXX │
 *     RIGHT   ├─────┼─────┼─────┼─────┼─────┼─────┤
 *             │ XXX │ XXX │ XXX │ XXX │ XXX │ XXX │
 * ┌─────┬─────┼─────┼─────┼─────┼─────┼─────┼─────┤
 * │     │     │ XXX │ XXX │ XXX │ XXX │ XXX │ XXX │
 * │ XXX │ XXX ├─────┼─────┼─────┼─────┴─────┴─────┘
 * │     │     │ XXX │ XXX │ XXX │
 * └─────┴─────┴─────┴─────┴─────┘
 *
 *
 */

/*
 * Base Layer: QWERTY
 *
 * ┌─────┬─────┬─────┬─────┬─────┬─────┐
 * │ esc │  q  │  w  │  e  │  r  │  t  │
 * ├─────┼─────┼─────┼─────┼─────┼─────┤   LEFT
 * │ tab │  a  │  s  │  d  │  f  │  g  │
 * ├─────┼─────┼─────┼─────┼─────┼─────┼─────┬─────┐
 * │ alt │  z  │  x  │  c  │  v  │  b  │     │     │
 * └─────┴─────┴─────┼─────┼─────┼─────┤ spc │ gui │
 *                   │ XXX │ sft │ ctr │     │ del │
 *                   └─────┴─────┴─────┴─────┴─────┘
 * 
 *  
 *             ┌─────┬─────┬─────┬─────┬─────┬─────┐
 *             │  y  │  u  │  i  │  o  │  p  │ XXX │
 *     RIGHT   ├─────┼─────┼─────┼─────┼─────┼─────┤
 *             │  h  │  j  │  k  │  l  │  ;  │  '  │
 * ┌─────┬─────┼─────┼─────┼─────┼─────┼─────┼─────┤
 * │     │     │  n  │  m  │  ,  │  .  │  /  │ XXX │
 * │ sym │ ent ├─────┼─────┼─────┼─────┴─────┴─────┘
 * │ bsp │     │ mos │ sft │ XXX │
 * └─────┴─────┴─────┴─────┴─────┘
*/

    [_QWERTY] = LAYOUT(
      KC_ESC,   KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,                                             KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,     RGB_TOG,
      KC_TAB,   KC_A,     KC_S,     KC_D,     KC_F,     KC_G,                                             KC_H,     KC_J,     KC_K,     KC_L,     KC_SCLN,  KC_QUOTE,
      KC_LALT,  KC_Z,     KC_X,     KC_C,     KC_V,     KC_B,     XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,  RGB_SAI,
                                    FACTORI,  KC_LSPO,  KC_LCTL,  KC_SPC,   AAD,      SAB,      KC_ENT,   MOUSE,    KC_RSPC,  KC_HOME
    ),


 /*
 * SYM Layer: numbers, symbols, and arrows 
 *
 * ┌─────┬─────┬─────┬─────┬─────┬─────┐
 * │ XXX │ < > │ [ ] │ { } │ ( ) │ XXX │
 * ├─────┼─────┼─────┼─────┼─────┼─────┤   LEFT
 * │ XXX │  ←  │  ↓  │  ↑  │  →  │ XXX │
 * ├─────┼─────┼─────┼─────┼─────┼─────┼─────┬─────┐
 * │ XXX │ XXX │ XXX │ XXX │ XXX │ XXX │     │     │
 * └─────┴─────┴─────┼─────┼─────┼─────┤ XXX │ XXX │
 *                   │ XXX │ XXX │ XXX │     │     │
 *                   └─────┴─────┴─────┴─────┴─────┘
 * 
 *  
 *             ┌─────┬─────┬─────┬─────┬─────┬─────┐
 *             │  `  │  7  │  8  │  9  │  0  │ F2  │
 *     RIGHT   ├─────┼─────┼─────┼─────┼─────┼─────┤
 *             │  ~  │  4  │  5  │  6  │  \  │ F5  │
 * ┌─────┬─────┼─────┼─────┼─────┼─────┼─────┼─────┤
 * │     │     │  =  │  1  │  2  │  3  │ XXX │ XXX │
 * │ XXX │ XXX ├─────┼─────┼─────┼─────┴─────┴─────┘
 * │     │     │ XXX │ XXX │ XXX │
 * └─────┴─────┴─────┴─────┴─────┘
 *
 */
    [_SYM] = LAYOUT(
      _______,  TD(ALI),  TD(BRA),  TD(CUR),  TD(PAR),  KC_F2,                                            KC_GRV,   KC_7,     KC_8,     KC_9,     KC_0,     _______,
      _______,  KC_LEFT,  KC_DOWN,  KC_UP,    KC_RGHT,  KC_F5,                                            KC_MINS,  KC_4,     KC_5,     KC_6,     KC_BSLS,  _______,
      _______,  _______,  _______,  _______,  _______,  _______,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  KC_EQL,   KC_1,     KC_2,     KC_3,     _______,  _______,
                                    _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______
    ),



/*
 * minecraft template
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |   1    |   2  |   3  |   4  |   5  |   6  |                              |      |      |      |      |      |        |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |   7    |   a  |  s   |   w  |   d  |   e  |                              |      |      |      |      |      |        |
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * |   j    | /    |  f   |   q  |   8  |   9  |      |xxxxxx|  |xxxxxx|      |      |      |      |      |      |        |
 * `----------------------+------+------+------+  spc +------|  |------+xxxxxx+------+------+------+----------------------'
 *                        |xxxxxx| ctrl |      |      |  esc |  |xxxxxx|      | Rclk | Lclk | Klck |
 *                        |      |      | shif |      |      |  |      |      |      |      |      |
 *                        `----------------------------------'  `----------------------------------'
 *
 * ┌─────┬─────┬─────┬─────┬─────┬─────┐
 * │ XXX │ XXX │ XXX │ XXX │ XXX │ XXX │
 * ├─────┼─────┼─────┼─────┼─────┼─────┤   LEFT
 * │ XXX │ XXX │ XXX │ XXX │ XXX │ XXX │
 * ├─────┼─────┼─────┼─────┼─────┼─────┼─────┬─────┐
 * │ XXX │ XXX │ XXX │ XXX │ XXX │ XXX │     │     │
 * └─────┴─────┴─────┼─────┼─────┼─────┤ XXX │ XXX │
 *                   │ XXX │ XXX │ XXX │     │     │
 *                   └─────┴─────┴─────┴─────┴─────┘
 * 
 *  
 *             ┌─────┬─────┬─────┬─────┬─────┬─────┐
 *             │ XXX │ XXX │ XXX │ XXX │ XXX │ XXX │
 *     RIGHT   ├─────┼─────┼─────┼─────┼─────┼─────┤
 *             │ XXX │ XXX │ XXX │ XXX │ XXX │ XXX │
 * ┌─────┬─────┼─────┼─────┼─────┼─────┼─────┼─────┤
 * │     │     │ XXX │ XXX │ XXX │ XXX │ XXX │ XXX │
 * │ XXX │ XXX ├─────┼─────┼─────┼─────┴─────┴─────┘
 * │     │     │ XXX │ XXX │ XXX │
 * └─────┴─────┴─────┴─────┴─────┘
 *
 */                           
     [_MINECFT] = LAYOUT(
          KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,                                          _______, _______, _______, _______, _______, _______,
          KC_7,    KC_A,    KC_S,    KC_W,    KC_D,    KC_E,                                          _______, KC_MS_L, KC_MS_U, KC_MS_D, KC_MS_R, _______,
          KC_J, KC_SLSH,    KC_F,    KC_Q,    KC_8,    KC_9, XXXXXXX, XXXXXXX,      _______, _______, _______, _______, _______, _______, _______, _______,
                                  MINECFT, KC_LCTL, KC_LSFT,  KC_SPC,  KC_ESC,      _______, KC_BTN2, KC_BTN1, _______, _______
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
 *
 * ┌─────┬─────┬─────┬─────┬─────┬─────┐
 * │ XXX │ XXX │ XXX │ XXX │ XXX │ XXX │
 * ├─────┼─────┼─────┼─────┼─────┼─────┤   LEFT
 * │ XXX │ XXX │ XXX │ XXX │ XXX │ XXX │
 * ├─────┼─────┼─────┼─────┼─────┼─────┼─────┬─────┐
 * │ XXX │ XXX │ XXX │ XXX │ XXX │ XXX │     │     │
 * └─────┴─────┴─────┼─────┼─────┼─────┤ XXX │ XXX │
 *                   │ XXX │ XXX │ XXX │     │     │
 *                   └─────┴─────┴─────┴─────┴─────┘
 * 
 *  
 *             ┌─────┬─────┬─────┬─────┬─────┬─────┐
 *             │ XXX │ XXX │ XXX │ XXX │ XXX │ XXX │
 *     RIGHT   ├─────┼─────┼─────┼─────┼─────┼─────┤
 *             │ XXX │ XXX │ XXX │ XXX │ XXX │ XXX │
 * ┌─────┬─────┼─────┼─────┼─────┼─────┼─────┼─────┤
 * │     │     │ XXX │ XXX │ XXX │ XXX │ XXX │ XXX │
 * │ XXX │ XXX ├─────┼─────┼─────┼─────┴─────┴─────┘
 * │     │     │ XXX │ XXX │ XXX │
 * └─────┴─────┴─────┴─────┴─────┘
 *
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
 *
 * ┌─────┬─────┬─────┬─────┬─────┬─────┐
 * │ XXX │ XXX │ XXX │ XXX │ XXX │ XXX │
 * ├─────┼─────┼─────┼─────┼─────┼─────┤   LEFT
 * │ XXX │ XXX │ XXX │ XXX │ XXX │ XXX │
 * ├─────┼─────┼─────┼─────┼─────┼─────┼─────┬─────┐
 * │ XXX │ XXX │ XXX │ XXX │ XXX │ XXX │     │     │
 * └─────┴─────┴─────┼─────┼─────┼─────┤ XXX │ XXX │
 *                   │ XXX │ XXX │ XXX │     │     │
 *                   └─────┴─────┴─────┴─────┴─────┘
 * 
 *  
 *             ┌─────┬─────┬─────┬─────┬─────┬─────┐
 *             │ XXX │ XXX │ XXX │ XXX │ XXX │ XXX │
 *     RIGHT   ├─────┼─────┼─────┼─────┼─────┼─────┤
 *             │ XXX │ XXX │ XXX │ XXX │ XXX │ XXX │
 * ┌─────┬─────┼─────┼─────┼─────┼─────┼─────┼─────┤
 * │     │     │ XXX │ XXX │ XXX │ XXX │ XXX │ XXX │
 * │ XXX │ XXX ├─────┼─────┼─────┼─────┴─────┴─────┘
 * │     │     │ XXX │ XXX │ XXX │
 * └─────┴─────┴─────┴─────┴─────┘
 *
 */                           
     [_FACTSYM] = LAYOUT(
        _______,    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                                         _______, _______, _______, _______, _______, _______,
        _______,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,                                         _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, KC_PMNS, KC_PPLS, XXXXXXX, _______,     _______, _______, _______, _______, _______, _______, _______, _______,
                                   _______, _______, _______, _______, _______,     _______, _______, _______, _______, _______
    ),

/*
 * mouse template
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |        |      |      |      |      |      |                              |      |      |      |      |      |        |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |        | left | down |  up  | rigt |      |                              | scrL | Lclk | Rclk | scrU | scrD |  scrR  |
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |      |  |xxxxxx|      |      |      |      |      |      |        |
 * `----------------------+------+------+------+      |      |  |------+xxxxxx+------+------+------+----------------------'
 *                        |xxxxxx|      |      |      |      |  |xxxxxx|      |xxxxxx|xxxxxx|xxxxxx|
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        `----------------------------------'  `----------------------------------'
 *
 * ┌─────┬─────┬─────┬─────┬─────┬─────┐
 * │ XXX │ XXX │ XXX │ XXX │ XXX │ XXX │
 * ├─────┼─────┼─────┼─────┼─────┼─────┤   LEFT
 * │ XXX │ XXX │ XXX │ XXX │ XXX │ XXX │
 * ├─────┼─────┼─────┼─────┼─────┼─────┼─────┬─────┐
 * │ XXX │ XXX │ XXX │ XXX │ XXX │ XXX │     │     │
 * └─────┴─────┴─────┼─────┼─────┼─────┤ XXX │ XXX │
 *                   │ XXX │ XXX │ XXX │     │     │
 *                   └─────┴─────┴─────┴─────┴─────┘
 * 
 *  
 *             ┌─────┬─────┬─────┬─────┬─────┬─────┐
 *             │ XXX │ XXX │ XXX │ XXX │ XXX │ XXX │
 *     RIGHT   ├─────┼─────┼─────┼─────┼─────┼─────┤
 *             │ XXX │ XXX │ XXX │ XXX │ XXX │ XXX │
 * ┌─────┬─────┼─────┼─────┼─────┼─────┼─────┼─────┤
 * │     │     │ XXX │ XXX │ XXX │ XXX │ XXX │ XXX │
 * │ XXX │ XXX ├─────┼─────┼─────┼─────┴─────┴─────┘
 * │     │     │ XXX │ XXX │ XXX │
 * └─────┴─────┴─────┴─────┴─────┘
 *
 */                           
     [_MOUSE] = LAYOUT(
        _______, _______, _______, _______, _______, _______,                                         KC_BTN3, KC_BTN4, KC_BTN5, KC_BTN6, KC_BTN7, KC_BTN8,
        _______, KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R, _______,                                         KC_WH_L, KC_BTN1, KC_BTN2, KC_WH_U, KC_WH_D, KC_WH_R,
        _______, _______, _______, _______, _______, _______, _______, _______,     _______, _______, _______, KC_ACL0, KC_ACL1, KC_ACL2, _______, _______,
                                   _______, _______, _______, _______, _______,     _______, _______, _______, _______, _______
    )
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
            rgblight_disable();
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






/* Return an integer that corresponds to what kind of tap dance should be executed.
 *
 * How to figure out tap dance state: interrupted and pressed.
 *
 * Interrupted: If the state of a dance dance is "interrupted", that means that another key has been hit
 *  under the tapping term. This is typically indicitive that you are trying to "tap" the key.
 *
 * Pressed: Whether or not the key is still being pressed. If this value is true, that means the tapping term
 *  has ended, but the key is still being pressed down. This generally means the key is being "held".
 *
 * One thing that is currenlty not possible with qmk software in regards to tap dance is to mimic the "permissive hold"
 *  feature. In general, advanced tap dances do not work well if they are used with commonly typed letters.
 *  For example "A". Tap dances are best used on non-letter keys that are not hit while typing letters.
 *
 * Good places to put an advanced tap dance:
 *  z,q,x,j,k,v,b, any function key, home/end, comma, semi-colon
 *
 * Criteria for "good placement" of a tap dance key:
 *  Not a key that is hit frequently in a sentence
 *  Not a key that is used frequently to double tap, for example 'tab' is often double tapped in a terminal, or
 *    in a web form. So 'tab' would be a poor choice for a tap dance.
 *  Letters used in common words as a double. For example 'p' in 'pepper'. If a tap dance function existed on the
 *    letter 'p', the word 'pepper' would be quite frustating to type.
 *
 * For the third point, there does exist the 'DOUBLE_SINGLE_TAP', however this is not fully tested
 *
 */
int cur_dance (qk_tap_dance_state_t *state) {
  if (state->count == 1) {
    if (state->interrupted || !state->pressed)  return SINGLE_TAP;
    //key has not been interrupted, but they key is still held. Means you want to send a 'HOLD'.
    else return SINGLE_HOLD;
  }
  else if (state->count == 2) {
    /*
     * DOUBLE_SINGLE_TAP is to distinguish between typing "pepper", and actually wanting a double tap
     * action when hitting 'pp'. Suggested use case for this return value is when you want to send two
     * keystrokes of the key, and not the 'double tap' action/macro.
    */
    if (state->interrupted) return DOUBLE_SINGLE_TAP;
    else if (state->pressed) return DOUBLE_HOLD;
    else return DOUBLE_TAP;
  }
  //Assumes no one is trying to type the same letter three times (at least not quickly).
  //If your tap dance key is 'KC_W', and you want to type "www." quickly - then you will need to add
  //an exception here to return a 'TRIPLE_SINGLE_TAP', and define that enum just like 'DOUBLE_SINGLE_TAP'
  if (state->count == 3) {
    if (state->interrupted || !state->pressed)  return TRIPLE_TAP;
    else return TRIPLE_HOLD;
  }
  else return 8; //magic number. At some point this method will expand to work for more presses
}

//instanalize an instance of 'tap' for the 'x' tap dance.
static tap xtap_state = {
  .is_press_action = true,
  .state = 0
};

static tap par_tap_state = {
  .is_press_action = true,
  .state = 0
};

static tap cur_tap_state = {
  .is_press_action = true,
  .state = 0
};

static tap bra_tap_state = {
  .is_press_action = true,
  .state = 0
};

static tap ali_tap_state = {
  .is_press_action = true,
  .state = 0
};

void x_finished (qk_tap_dance_state_t *state, void *user_data) {
  xtap_state.state = cur_dance(state);
  switch (xtap_state.state) {
    case SINGLE_TAP: register_code(KC_X); break;
    case SINGLE_HOLD: register_code(KC_Z); break;
    case DOUBLE_TAP: register_code(KC_C); break;
    case DOUBLE_HOLD: register_code(KC_E); break;
    case DOUBLE_SINGLE_TAP: register_code(KC_X); unregister_code(KC_X); register_code(KC_X); break;
    //Last case is for fast typing. Assuming your key is `f`:
    //For example, when typing the word `buffer`, and you want to make sure that you send `ff` and not `Esc`.
    //In order to type `ff` when typing fast, the next character will have to be hit within the `TAPPING_TERM`, which by default is 200ms.
  }
}

void x_reset (qk_tap_dance_state_t *state, void *user_data) {
  switch (xtap_state.state) {
    case SINGLE_TAP: unregister_code(KC_X); break;
    case SINGLE_HOLD: unregister_code(KC_Z); break;
    case DOUBLE_TAP: unregister_code(KC_C); break;
    case DOUBLE_HOLD: unregister_code(KC_E); break;
    case DOUBLE_SINGLE_TAP: unregister_code(KC_X); break;
  }
  xtap_state.state = 0;
}

void par_finished (qk_tap_dance_state_t *state, void *user_data) {
  par_tap_state.state = cur_dance(state);
  switch (par_tap_state.state) {
    case SINGLE_TAP:        register_code16(KC_LPRN); unregister_code16(KC_LPRN); break;
    case SINGLE_HOLD:       register_code16(KC_LPRN); unregister_code16(KC_LPRN); 
							register_code16(KC_RPRN); unregister_code16(KC_RPRN); 
							register_code(KC_LEFT); unregister_code(KC_LEFT); break;
    case DOUBLE_TAP:        register_code16(KC_RPRN); unregister_code16(KC_RPRN); break;
    case DOUBLE_HOLD:       register_code16(KC_LPRN); unregister_code16(KC_LPRN); 
							register_code16(KC_RPRN); unregister_code16(KC_RPRN); break;
    case DOUBLE_SINGLE_TAP: register_code16(KC_LPRN); unregister_code16(KC_LPRN); register_code16(KC_LPRN); break;
    //Last case is for fast typing. Assuming your key is `f`:
    //For example, when typing the word `buffer`, and you want to make sure that you send `ff` and not `Esc`.
    //In order to type `ff` when typing fast, the next character will have to be hit within the `TAPPING_TERM`, which by default is 200ms.
  }
}

void par_reset (qk_tap_dance_state_t *state, void *user_data) {
  switch (par_tap_state.state) {
    case SINGLE_TAP:        break;
    case SINGLE_HOLD:       break;
    case DOUBLE_TAP:        break;
    case DOUBLE_HOLD:       break;
    case DOUBLE_SINGLE_TAP: unregister_code16(KC_LPRN); break;
  }
  par_tap_state.state = 0;
}



void cur_finished (qk_tap_dance_state_t *state, void *user_data) {
  cur_tap_state.state = cur_dance(state);
  switch (cur_tap_state.state) {
    case SINGLE_TAP:        register_code16(KC_LCBR); unregister_code16(KC_LCBR); break;
    case SINGLE_HOLD:       register_code16(KC_LCBR); unregister_code16(KC_LCBR); 
							register_code16(KC_RCBR); unregister_code16(KC_RCBR); 
							register_code(KC_LEFT); unregister_code(KC_LEFT); break;
    case DOUBLE_TAP:        register_code16(KC_RCBR); unregister_code16(KC_RCBR); break;
    case DOUBLE_HOLD:       register_code16(KC_LCBR); unregister_code16(KC_LCBR); 
							register_code16(KC_RCBR); unregister_code16(KC_RCBR); break;
    case DOUBLE_SINGLE_TAP: register_code16(KC_LCBR); unregister_code16(KC_LCBR); register_code16(KC_LCBR); break;
    //Last case is for fast typing. Assuming your key is `f`:
    //For example, when typing the word `buffer`, and you want to make sure that you send `ff` and not `Esc`.
    //In order to type `ff` when typing fast, the next character will have to be hit within the `TAPPING_TERM`, which by default is 200ms.
  }
}

void cur_reset (qk_tap_dance_state_t *state, void *user_data) {
  switch (cur_tap_state.state) {
    case SINGLE_TAP:        break;
    case SINGLE_HOLD:       break;
    case DOUBLE_TAP:        break;
    case DOUBLE_HOLD:       break;
    case DOUBLE_SINGLE_TAP: unregister_code16(KC_LCBR); break;
  }
  cur_tap_state.state = 0;
}




void bra_finished (qk_tap_dance_state_t *state, void *user_data) {
  bra_tap_state.state = cur_dance(state);
  switch (bra_tap_state.state) {
    case SINGLE_TAP:        register_code16(KC_LBRC); unregister_code16(KC_LBRC); break;
    case SINGLE_HOLD:       register_code16(KC_LBRC); unregister_code16(KC_LBRC); 
							register_code16(KC_RBRC); unregister_code16(KC_RBRC); 
							register_code(KC_LEFT); unregister_code(KC_LEFT); break;
    case DOUBLE_TAP:        register_code16(KC_RBRC); unregister_code16(KC_RBRC); break;
    case DOUBLE_HOLD:       register_code16(KC_LBRC); unregister_code16(KC_LBRC); 
							register_code16(KC_RBRC); unregister_code16(KC_RBRC); break;
    case DOUBLE_SINGLE_TAP: register_code16(KC_LBRC); unregister_code16(KC_LBRC); register_code16(KC_LBRC); break;
    //Last case is for fast typing. Assuming your key is `f`:
    //For example, when typing the word `buffer`, and you want to make sure that you send `ff` and not `Esc`.
    //In order to type `ff` when typing fast, the next character will have to be hit within the `TAPPING_TERM`, which by default is 200ms.
  }
}

void bra_reset (qk_tap_dance_state_t *state, void *user_data) {
  switch (bra_tap_state.state) {
    case SINGLE_TAP:        break;
    case SINGLE_HOLD:       break;
    case DOUBLE_TAP:        break;
    case DOUBLE_HOLD:       break;
    case DOUBLE_SINGLE_TAP: unregister_code16(KC_LBRC); break;
  }
  bra_tap_state.state = 0;
}




void ali_finished (qk_tap_dance_state_t *state, void *user_data) {
  ali_tap_state.state = cur_dance(state);
  switch (ali_tap_state.state) {
    case SINGLE_TAP:        register_code16(KC_LABK); unregister_code16(KC_LABK); break;
    case SINGLE_HOLD:       register_code16(KC_LABK); unregister_code16(KC_LABK); 
							register_code16(KC_RABK); unregister_code16(KC_RABK); 
							register_code(KC_LEFT); unregister_code(KC_LEFT); break;
    case DOUBLE_TAP:        register_code16(KC_RABK); unregister_code16(KC_RABK); break;
    case DOUBLE_HOLD:       register_code16(KC_LABK); unregister_code16(KC_LABK); 
							register_code16(KC_RABK); unregister_code16(KC_RABK); break;
    case DOUBLE_SINGLE_TAP: register_code16(KC_LABK); unregister_code16(KC_LABK); register_code16(KC_LABK); break;
    //Last case is for fast typing. Assuming your key is `f`:
    //For example, when typing the word `buffer`, and you want to make sure that you send `ff` and not `Esc`.
    //In order to type `ff` when typing fast, the next character will have to be hit within the `TAPPING_TERM`, which by default is 200ms.
  }
}

void ali_reset (qk_tap_dance_state_t *state, void *user_data) {
  switch (ali_tap_state.state) {
    case SINGLE_TAP:        break;
    case SINGLE_HOLD:       break;
    case DOUBLE_TAP:        break;
    case DOUBLE_HOLD:       break;
    case DOUBLE_SINGLE_TAP: unregister_code16(KC_LABK); break;
  }
  ali_tap_state.state = 0;
}

qk_tap_dance_action_t tap_dance_actions[] = {
  [X_CTL]     = ACTION_TAP_DANCE_FN_ADVANCED(NULL,x_finished, x_reset),
  [PAR]     = ACTION_TAP_DANCE_FN_ADVANCED(NULL,par_finished, par_reset),
  [CUR]     = ACTION_TAP_DANCE_FN_ADVANCED(NULL,cur_finished, cur_reset),
  [BRA]     = ACTION_TAP_DANCE_FN_ADVANCED(NULL,bra_finished, bra_reset),
  [ALI]     = ACTION_TAP_DANCE_FN_ADVANCED(NULL,ali_finished, ali_reset)
};