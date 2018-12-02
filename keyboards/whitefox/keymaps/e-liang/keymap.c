/*
Copyright 2015 Jun Wako <wakojun@gmail.com>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/
#include QMK_KEYBOARD_H

#define _DEFAULT 0
#define _FN 1
#define _FN2 2

enum custom_keycodes {
  EL_VMBN = SAFE_RANGE,
  EL_VMBP,
  EL_VMBW,
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (record->event.pressed) {
    switch(keycode) {
      case EL_VMBN:
        SEND_STRING(":bn\n");
        return false;
      case EL_VMBP:
        SEND_STRING(":bp\n");
        return false;
      case EL_VMBW:
        SEND_STRING(":w\n");
        return false;
    }
  }
  return true;
};

const uint16_t keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  /* Main layer
   * ,---------------------------------------------------------------.
   * |  `|  1|  2|  3|  4|  5|  6|  7|  8|  9|  0|  [|  ]|  \|   |   |
   * |---------------------------------------------------------------|
   * |Tab  |  '|  ,|  .|  P|  Y|  F|  G|  C|  R|  L|  /|  =|Backs|Del|
   * |---------------------------------------------------------------|
   * |Es/Ctl|  A|  O|  E|  U|  I|  D|  H|  T|  N|  S|  -|Enter   |VoU|
   * |---------------------------------------------------------------|
   * |Shift   |  ;|  Q|  J|  K|  X|  B|  M|  W|  V|  Z|Fn2   |Up |VoD|
   * |---------------------------------------------------------------|
   * |Fn1 |Alt |Gui |         Space         |Gui |Alt |  |Lef|Dow|Rig|
   * `---------------------------------------------------------------'
   */
  [_DEFAULT] = LAYOUT_truefox( \
      KC_GRV         , KC_1    , KC_2    , KC_3   , KC_4  , KC_5  , KC_6  , KC_7  , KC_8  , KC_9 , KC_0 , KC_LBRC , KC_RBRC , KC_BSLS , XXXXXXX , XXXXXXX , \
      KC_TAB         , KC_QUOT , KC_COMM , KC_DOT , KC_P  , KC_Y  , KC_F  , KC_G  , KC_C  , KC_R , KC_L , KC_SLSH , KC_EQL  , KC_BSPC           , KC_DEL  , \
      LCTL_T(KC_ESC) , KC_A    , KC_O    , KC_E   , KC_U  , KC_I  , KC_D  , KC_H  , KC_T  , KC_N , KC_S , KC_MINS , KC_ENT                      , KC_VOLU , \
      KC_LSFT                  , KC_SCLN , KC_Q   , KC_J  , KC_K  , KC_X  , KC_B  , KC_M  , KC_W , KC_V , KC_Z    , MO(_FN2)          , KC_UP   , KC_VOLD , \
      MO(_FN)        , KC_LALT , KC_LGUI , KC_SPC                                                       , KC_RGUI , KC_RALT , KC_LEFT , KC_DOWN , KC_RGHT \
      ),

  /* Function layer 1. The main function layer, with mousekeys, function keys, etc.
   * ,---------------------------------------------------------------.
   * |   | F1| F2| F3| F4| F5| F6| F7| F8| F9|F10|F11|F12|   |   |   |
   * |---------------------------------------------------------------|
   * |     |   |MS1|MS2|MS3|   |   |   |Up |MA0|   |   |   |     |   |
   * |---------------------------------------------------------------|
   * |Caps  |MSL|MSD|MSU|MSR|   |   |Lef|Dow|Rig|MA1|   |        |Ply|
   * |---------------------------------------------------------------|
   * |        |MWL|MWD|MWU|MWR|   |MS1|MS2|MS3|   |   |      |PgU|Mut|
   * |---------------------------------------------------------------|
   * |    |    |    |                       |    |    |  |Hom|PgD|End|
   * `---------------------------------------------------------------'
   */
  [_FN] = LAYOUT_truefox( \
      _______ , KC_F1   , KC_F2   , KC_F3   , KC_F4   , KC_F5   , KC_F6   , KC_F7   , KC_F8   , KC_F9   , KC_F10  , KC_F11  , KC_F12  , _______ , _______ , _______ , \
      _______ , _______ , KC_BTN1 , KC_BTN2 , KC_BTN3 , _______ , _______ , _______ , KC_UP   , KC_ACL0 , _______ , _______ , _______ , _______           , _______ , \
      KC_CAPS , KC_MS_L , KC_MS_D , KC_MS_U , KC_MS_R , _______ , _______ , KC_LEFT , KC_DOWN , KC_RGHT , KC_ACL1 , _______ , _______                     , KC_MPLY , \
      _______           , KC_WH_L , KC_WH_D , KC_WH_U , KC_WH_R , _______ , KC_BTN1 , KC_BTN2 , KC_BTN3 , _______ , _______ , _______           , KC_PGUP , KC_MUTE , \
      _______           , _______ , _______ , _______                                                             , _______ , _______ , KC_HOME , KC_PGDN , KC_END  \
      ),

  /* Function layer 2. Macros.
   * ,---------------------------------------------------------------.
   * |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
   * |---------------------------------------------------------------|
   * |     |   |   |   |   |   |   |   |   |   |   |   |   |     |   |
   * |---------------------------------------------------------------|
   * |      |   |   |MVP|MVN|   |   |   |   |   |MVW|   |        |   |
   * |---------------------------------------------------------------|
   * |        |   |   |   |   |   |   |   |   |   |   |      |   |   |
   * |---------------------------------------------------------------|
   * |    |    |    |                       |    |    |  |   |   |   |
   * `---------------------------------------------------------------'
   */
  [_FN2] = LAYOUT_truefox( \
      _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , \
      _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______           , _______ , \
      _______ , _______ , _______ , EL_VMBP , EL_VMBN , _______ , _______ , _______ , _______ , _______ , EL_VMBW , _______ , _______                     , _______ , \
      _______           , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______           , _______ , _______ , \
      _______           , _______ , _______ , _______                                                             , _______ , _______ , _______ , _______ , _______  \
      ),
};
