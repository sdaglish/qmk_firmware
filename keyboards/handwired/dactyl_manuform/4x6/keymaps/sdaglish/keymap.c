#include "keycode.h"
#include QMK_KEYBOARD_H


#define _BASE 0
#define _RAISE 1
#define _LOWER 2

// Fillers to make layering more clear

#define ____ KC_TRNS

#define SFT_ESC  SFT_T(KC_ESC)
#define CTL_BSPC CTL_T(KC_BSPC)
#define ALT_SPC  ALT_T(KC_SPC)
#define SFT_ENT  SFT_T(KC_ENT)

#define SFT_ESC  SFT_T(KC_ESC)
#define CTL_ESC  CTL_T(KC_ESC)
#define CTL_BSPC CTL_T(KC_BSPC)
#define RS_BSPC  LT(_RAISE, KC_BSPC)
#define LW_SPC  LT(_LOWER, KC_SPC)
#define ALT_SPC  ALT_T(KC_SPC)
#define SFT_ENT  SFT_T(KC_ENT)
#define LCTL_TAB CTL_T(KC_TAB)
#define LGUI_TAB LGUI_T(KC_TAB)
#define ALT_ENT ALT_T(KC_ENT)


#define RAISE MO(_RAISE)
#define LOWER MO(_LOWER)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Base (dvorak)
 * +-----------------------------------------+                             +-----------------------------------------+
 * | ESC  |   '  |   ,  |   .  |   p  |   y  |                             |   f  |   g  |   c  |   r  |   l  | DEL  |
 * |------+------+------+------+------+------|                             |------+------+------+------+------+------|
 * | TAB  |   a  |   o  |   e  |   u  |   i  |                             |   d  |   h  |   t  |   n  |   s  | SHFT |
 * |------+------+------+------+------+------|                             |------+------+------+------+------+------|
 * | SHFT |   ;  |   q  |   j  |   k  |   x  |                             |   d  |   m  |   w  |   v  |   z  | ENTR |
 * +------+------+------+------+-------------+                             +-------------+------+------+------+------+
 *               |  [   |   ]  |                                                         |  -   |      |
 *               +-------------+---------------------+              +--------------------+-------------+
 *                             |      |      |       |              |      |      |      |
 *                             +---------------------+              +--------------------+

 */

[_BASE] = LAYOUT( \
		 KC_LALT, KC_QUOT,  KC_COMM,   KC_DOT, KC_P,   KC_Y,                                                   KC_F,   KC_G,   KC_C,   KC_R,   KC_L,  KC_LALT, \
		 KC_LSFT, KC_A,     KC_O,      KC_E,   KC_U,   KC_I,                                                   KC_D,   KC_H,   KC_T,   KC_N,   KC_S,  KC_RSFT, \
		 KC_LCTL, KC_SCLN,  KC_Q,      KC_J,   KC_K,   KC_X,                                                   KC_B,   KC_M,   KC_W,   KC_V,   KC_Z,  KC_RCTRL , \
		 KC_LBRC, KC_RBRC,                             CTL_ESC,  RS_BSPC,  LGUI_TAB,               KC_LGUI, LW_SPC,  ALT_ENT, KC_MINS,KC_EQL \
		  ),
/* Raise
 * ,----------------------------------,                             ,----------------------------------,
 * |      |      |  mup |      |      |                             | VOL+ |      |  up  |      | PgUp |
 * |------+------+------+------+------|                             |-------------+------+------+------|
 * |      | mleft| mdown|mright|      |                             | MUTE | left | down |right | PgDn |
 * |------+------+------+------+------|                             |------|------+------+------+------|
 * |      |      |      |      |      |                             | VOL- |  /   |  \   |  ?   |  |   |
 * |------+------+------+-------------,                             ,-------------+------+------+------,
 *        |      |      |                                                         | mbtn |mbtn2 |
 *        '------+------'-------------'                             '-------------'------+------'
 *                      |      |      |                             |      |      |
 *                      |      |      |                             |      |      |
 *                      |      |      |                             |      |      |
 *                      '------+------'                             '------+------'
 *                                    '------+------' '------+------'
 *                                   |      |      | |      |      |
 *                                    '------+------' '------+------'
 *                                    |      | RESET| |      |      |
 *                                    '------+------' '------+------'
 */
[_RAISE] = LAYOUT( \
		  KC_LALT, KC_QUOT,  KC_COMM,   KC_DOT, KC_P,   KC_Y,                                                   KC__VOLDOWN,   KC__VOLUP,   KC__MUTE,   KC_R,   KC_L,  KC_LALT, \
		  KC_LSFT, KC_A,     KC_O,      KC_E,   KC_U,   KC_I,                                                   KC_D,   KC_LEFT,   KC_DOWN,   KC_UP,   KC_RIGHT,  KC_RSFT, \
		  KC_LCTL, KC_SCLN,  KC_Q,      KC_J,   KC_K,   KC_X,                                                   KC_NUHS,   KC_SLSH, KC_NUBS, KC_QUES,  S(KC_NUBS),  KC_RCTRL , \
		  KC_LBRC, KC_RBRC,                             CTL_ESC,  RS_BSPC,  KC_LGUI,              KC_LGUI, LW_SPC,  ALT_ENT, KC_MINS,KC_EQL \
		   ),

/* Lower
 * ,----------------------------------,                             ,----------------------------------,
 * |      |      |  mup |      |      |                             | VOL+ |      |  up  |      | PgUp |
 * |------+------+------+------+------|                             |-------------+------+------+------|
 * |      | mleft| mdown|mright|      |                             | MUTE | left | down |right | PgDn |
 * |------+------+------+------+------|                             |------|------+------+------+------|
 * |      |      |      |      |      |                             | VOL- |  /   |  \   |  ?   |  |   |
 * |------+------+------+-------------,                             ,-------------+------+------+------,
 *        |      |      |                                                         | mbtn |mbtn2 |
 *        '------+------'-------------'                             '-------------'------+------'
 *                      |      |      |                             |      |      |
 *                      |      |      |                             |      |      |
 *                      |      |      |                             |      |      |
 *                      '------+------'                             '------+------'
 *                                    '------+------' '------+------'
 *                                    |      |      | |      |      |
 *                                    '------+------' '------+------'
 *                                    |      | RESET| |      |      |
 *                                    '------+------' '------+------'
 */
[_LOWER] = LAYOUT( \
		  KC_TAB, KC_F1,   KC_F2,  KC_F3,   KC_F4,  KC_F5,                            KC_F6,   KC_F7,    KC_F8,   KC_F9,   KC_F10,KC_LALT, \
		  KC_LSFT, KC_1,    KC_2,   KC_3,    KC_4,   KC_5,                             KC_6,    KC_7,     KC_8,    KC_9,    KC_0,  KC_RSFT, \
		  KC_LCTL, KC_EXLM, S(KC_2),S(KC_3), KC_DLR, KC_PERC,                          KC_CIRC, KC_AMPR,  KC_ASTR, KC_LPRN, KC_RPRN,  KC_RCTRL , \
		  S(KC_LBRC), S(KC_RBRC),                             CTL_ESC,  KC_DEL,  RESET,               KC_LGUI, LW_SPC,  ALT_ENT, S(KC_MINS),KC_EQL \
		   )

};


void persistent_default_layer_set(uint16_t default_layer) {
  eeconfig_update_default_layer(default_layer);
  default_layer_set(default_layer);
}
