/*
 * Copyright 2021 Quentin LEBASTARD <qlebastard@gmail.com>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include QMK_KEYBOARD_H

#include <stdio.h>
#include "keymap_german.h"

// Norbert Klein - mini Skeletyl
#define _LAYER0_BONE 0
#define _LAYER1_PROG 1
#define _LAYER2_MV_NUM 2
#define _LAYER3_GAME 3
#define _LAYER4_DE 4
#define _LAYER5_F 5

#define NONONON KC_NO

#define HOME_C LGUI_T(DE_C)
#define HOME_T LALT_T(DE_T)
#define HOME_I LCTL_T(DE_I)
#define HOME_E LSFT_T(DE_E)

#define NK_O  LT(_LAYER4_DE, DE_O)
#define NK_B  LT(_LAYER4_DE, DE_B)

#define HOME_N RSFT_T(DE_N)
#define HOME_R LCTL_T(DE_R)
#define HOME_S LALT_T(DE_S)   // was RALT_T — testing if Windows intercepts RALT
#define HOME_G LGUI_T(DE_G)

#define RALT_X RALT_T(KC_X)
#define RALT_DOT RALT_T(KC_DOT)

#define THUMB_LL LCTL_T(KC_ESC)
#define THUMB_LM LT(_LAYER2_MV_NUM, KC_SPC)
#define THUMB_LR LT(_LAYER1_PROG, KC_TAB)
#define THUMB_RL LT(_LAYER5_F, KC_ENTER)
#define THUMB_RM LT(_LAYER2_MV_NUM, KC_BSPC)
#define THUMB_RR LT(_LAYER1_PROG, KC_DEL)

// enum {
//     TD_LSFT_CAPS,
// };147258369´0
// qk_tap_dance_action_t tap_dance_actions[] = {fdsagbfbffbff
//     // Tap once for shift, twice for Caps Lock
//     [TD_LSFT_CAPS] = ACTION_TAP_DANCE_DOUBLE(KC_LSFT, KC_CAPS),
// };
// neuer Versuch[]
// #define TD_LSFT_CAPS TD(TD_LSFT_CAPS)  



const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_LAYER0_BONE] = LAYOUT_split_3x5_3(
  //,--------------------------------------------.      ,--------------------------------------------.
      DE_J,    DE_D,    DE_U,    DE_A,    DE_X,            DE_P,    DE_H,    DE_L,    DE_M,   DE_W,
  //|--------+--------+--------+--------+--------|      |--------+--------+--------+--------+--------|
      HOME_C,  HOME_T,  HOME_I,  HOME_E,  NK_O,            NK_B  ,  HOME_N,  HOME_R,  HOME_S,  HOME_G,
  //|--------+--------+--------+--------+--------|      |--------+--------+--------+--------+--------|
      DE_F,    DE_V,    DE_K,    DE_Q,    KC_PSCR,         DE_Y,    DE_Z,   DE_COMM,  DE_DOT, DE_MINS,
  //|--------+--------+--------+--------+--------|      |--------+--------+--------+--------+--------|
             THUMB_LL, THUMB_LM, THUMB_LR,                         THUMB_RL,  THUMB_RM, THUMB_RR 
  //        `----------------------------'                         `----------------------------'
),


[_LAYER1_PROG] = LAYOUT_split_3x5_3(
  /* Layer 1 (neo3) Special Characters - ergonomic placement for coding
   *
   * ʘ----------------------------------ʘ                    ʘ----------------------------------ʘ
   * |   @  |   _  |   [  |   ]  |   ^  |                    |   !  |   <  |   >  |   =  |   &  |
   * |------+------+------+------+------|                    |------+------+------+------+------|
   * |   \  |   /  |   {  |   }  |   *  |                    |   ?  |   (  |   )  |   -  |   :  |
   * |------+------+------+------+------|                    |------+------+------+------+------|
   * |   #  |   ~  |   |  |   $  |   €  |                    |   +  |   %  |   "  |   '  |   ;  |
   * ʘ------+------+------+------+------ʘ                    ʘ------+------+------+------+------ʘ
   */

     DE_AT  , DE_UNDS, DE_LBRC, DE_RBRC, DE_CIRC,          DE_EXLM, DE_LABK, DE_RABK, DE_EQL,  DE_AMPR, 
     DE_BSLS, DE_SLSH, DE_LCBR, DE_RCBR, DE_ASTR,          DE_QUES, DE_LPRN, DE_RPRN, DE_MINS, DE_COLN, 
     DE_HASH, DE_TILD, DE_PIPE, DE_DLR,  DE_EURO,          DE_PLUS, DE_PERC, DE_DQUO, DE_QUOT, DE_SCLN, 
                       _______, _______, _______,                            _______, _______, _______
  ),

[_LAYER2_MV_NUM] = LAYOUT_split_3x5_3(
  /* Layer 2 (neo4) Navigation & Number Blocks
   *
   * ʘ----------------------------------ʘ                      ʘ----------------------------------ʘ
   * | PgUp | Bksp |  Up  |  DEL | PgDn |                      |      |   7  |   8  |   9  |   ´  |
   * |------+------+------+------+------|                      |------+------+------+------+------|
   * | Home |  Lft | Down | Right| End  |                      |      |   4  |   5  |   6  |   .  |
   * |------+------+------+------+------|                      |------+------+------+------+------|
   * |      |      |      |      |      |                      |      |   1  |   2  |   3  |   ,  |
   * ʘ------+------+------+------+------ʘ                      ʘ------+------+------+------+------ʘ
   *               ʘ--------------------ʘ                      ʘ--------------------ʘ
   *               |      |      |      |                      |      |  0   |      |
   *               ʘ------+------+------ʘ                      ʘ------+------+------ʘ
   */

     KC_PGUP, KC_BSPC, KC_UP,   KC_DEL,  KC_PGDN,            _______,  DE_7  ,  DE_8  ,  DE_9  , DE_GRV,
     KC_HOME, KC_LEFT, KC_DOWN, KC_RGHT, KC_END ,            _______,  DE_4  ,  DE_5  ,  DE_6  , DE_DOT ,
     _______, _______, _______, _______ , KC_PSCR ,            _______,  DE_1  ,  DE_2  ,  DE_3  , DE_COMM,
                       _______, _______, _______,                                _______, DE_0, _______
    ),

  [_LAYER4_DE] = LAYOUT_split_3x5_3(
  //,--------------------------------------------.        ,--------------------------------------------.
      NONONON, NONONON, DE_UDIA, DE_ADIA, NONONON,          NONONON, NONONON, NONONON, NONONON, NONONON,
  //|--------+--------+--------+--------+--------|        |--------+--------+--------+--------+--------|
      NONONON, NONONON, NONONON, NONONON, DE_ODIA,          NONONON, NONONON, NONONON,  DE_SS , NONONON,
  //|--------+--------+--------+--------+--------|        |--------+--------+--------+--------+--------|
      NONONON, NONONON, NONONON, NONONON, NONONON,          NONONON, NONONON, NONONON, NONONON, NONONON,
  //|--------+--------+--------+--------+--------|        |--------+--------+--------+--------+--------|
                          _______, _______, _______,     _______, _______, _______
                       //`--------------------------'  `--------------------------'
),

    [_LAYER5_F] = LAYOUT_split_3x5_3(
    //,--------------------------------------------.        ,--------------------------------------------.
        NONONON, NONONON, NONONON, NONONON, NONONON,           KC_F12, KC_F7,   KC_F8,   KC_F9,  _______,
    //|--------+--------+--------+--------+--------|        |--------+--------+--------+--------+--------|
        KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, NONONON,           KC_F11, KC_F4,   KC_F5,   KC_F6,  NONONON,
    //|--------+--------+--------+--------+--------|        |--------+--------+--------+--------+--------|
        NONONON, KC_RALT, NONONON, NONONON, NONONON,           KC_F10, KC_F1,   KC_F2,   KC_F3,  _______,
    //|--------+--------+--------+--------+--------|        |--------+--------+--------+--------+--------|
                              _______, _______, _______,    _______, _______, _______
                          //`--------------------------'  `--------------------------'
    )
};

