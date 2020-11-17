#include QMK_KEYBOARD_H

#define _DEFAULT 0
#define _QWERTY 1
#define _FN1 2
#define _FN2 3
#define _FN3 4

enum custom_keycodes {
  EL_TMWN = SAFE_RANGE,
  EL_TMWP,
  EL_VMBN,
  EL_VMBP,
  EL_VMBW,
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (record->event.pressed) {
    switch(keycode) {
      case EL_TMWN:
        SEND_STRING(SS_LCTRL("b") "n");
        return false;
      case EL_TMWP:
        SEND_STRING(SS_LCTRL("b") "p");
        return false;
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
   * |  `|  1|  2|  3|  4|  5|  6|  7|  8|  9|  0|  [|  ]|  \|QWE|Prt|
   * |Tb/Cm|  '|  ,|  .|  P|  Y|  F|  G|  C|  R|  L|  /|  =|Backs|Del|
   * |Es/Ctl|  A|  O|  E|  U|  I|  D|  H|  T|  N|  S|  -|Enter   |VoU|
   * |Shift   |  ;|  Q|  J|  K|  X|  B|  M|  W|  V|  Z|Fn2   |Up |VoD|
   * |Fn1 |Alt |Gui |         Space         |Gui |Fn3 |  |Lef|Dow|Rig|
   * `---------------------------------------------------------------'
   */
  [_DEFAULT] = LAYOUT_truefox( \
      KC_GRV         , KC_1    , KC_2    , KC_3   , KC_4    , KC_5    , KC_6    , KC_7    , KC_8    , KC_9    , KC_0    , KC_LBRC , KC_RBRC , KC_BSLS , DF(_QWERTY) , KC_PSCR , \
      LGUI_T(KC_TAB) , KC_QUOT , KC_COMM , KC_DOT , KC_P    , KC_Y    , KC_F    , KC_G    , KC_C    , KC_R    , KC_L    , KC_SLSH , KC_EQL  , KC_BSPC               , KC_DEL  , \
      CTL_T(KC_ESC)  , KC_A    , KC_O    , KC_E   , KC_U    , KC_I    , KC_D    , KC_H    , KC_T    , KC_N    , KC_S    , KC_MINS , KC_ENT                          , KC_VOLU , \
      KC_LSFT                  , KC_SCLN , KC_Q   , KC_J    , KC_K    , KC_X    , KC_B    , KC_M    , KC_W    , KC_V    , KC_Z    , MO(_FN2)          , KC_UP       , KC_VOLD , \
      MO(_FN1)       , KC_LALT , KC_LGUI , KC_SPC                                                             , KC_RGUI , MO(_FN3)          , KC_LEFT , KC_DOWN     , KC_RGHT \
  ),

  /* QWERTY Layer
   * ,---------------------------------------------------------------.
   * |   |   |   |   |   |   |   |   |   |   |   |  -|  =|   |DVR|   |
   * |     |  Q|  W|  E|  R|  T|  Y|  U|  I|  O|  P|  [|  ]|     |   |
   * |      |  A|  S|  D|  F|  G|  H|  J|  K|  L|  ;|  '|        |   |
   * |        |  Z|  X|  C|  V|  B|  N|  M|  ,|  .|  /|      |   |   |
   * |    |    |    |                       |    |    |  |   |   |   |
   * `---------------------------------------------------------------'
   */
  [_QWERTY] = LAYOUT_truefox( \
      _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , KC_MINS , KC_EQL  , _______ , DF(_DEFAULT) , _______ , \
      _______ , KC_Q    , KC_W    , KC_E    , KC_R    , KC_T    , KC_Y    , KC_U    , KC_I    , KC_O    , KC_P    , KC_LBRC , KC_RBRC , _______                , _______ , \
      _______ , KC_A    , KC_S    , KC_D    , KC_F    , KC_G    , KC_H    , KC_J    , KC_K    , KC_L    , KC_SCLN , KC_QUOT , _______                          , _______ , \
      _______           , KC_Z    , KC_X    , KC_C    , KC_V    , KC_B    , KC_N    , KC_M    , KC_COMM , KC_DOT  , KC_SLSH , _______           , _______      , _______ , \
      _______           , _______ , _______ , _______                                                   , _______ , _______           , _______ , _______      , _______ \
  ),

  /* Function layer 1. The main function layer, with mousekeys, function keys, etc.
   * ,---------------------------------------------------------------.
   * |   | F1| F2| F3| F4| F5| F6| F7| F8| F9|F10|F11|F12|   |   |   |
   * |     |   |MS2|MS3|   |   |   |MA0|Up |MA1|   |   |   |     |   |
   * |      |MSL|MSD|MSU|MSR|   |   |Lef|Dow|Rig|MA2|   |        |Ply|
   * |        |MWL|MWD|MWU|MWR|   |MS2|MS3|   |MS4|MS5|      |PgU|Mut|
   * |    |    |    |           MS1         |    |    |  |Hom|PgD|End|
   * `---------------------------------------------------------------'
   */
  [_FN1] = LAYOUT_truefox( \
      _______ , KC_F1   , KC_F2   , KC_F3   , KC_F4   , KC_F5   , KC_F6   , KC_F7   , KC_F8   , KC_F9   , KC_F10  , KC_F11  , KC_F12  , _______ , _______ , _______ , \
      _______ , _______ , KC_BTN2 , KC_BTN3 , _______ , _______ , _______ , KC_ACL0 , KC_UP   , KC_ACL1 , _______ , _______ , _______ , _______           , _______ , \
      _______ , KC_MS_L , KC_MS_D , KC_MS_U , KC_MS_R , _______ , _______ , KC_LEFT , KC_DOWN , KC_RGHT , KC_ACL2 , _______ , _______                     , KC_MPLY , \
      _______           , KC_WH_L , KC_WH_D , KC_WH_U , KC_WH_R , _______ , KC_BTN2 , KC_BTN3 , _______ , KC_BTN4 , KC_BTN5 , _______           , KC_PGUP , KC_MUTE , \
      _______           , _______ , _______ , KC_BTN1                                                   , _______ , _______           , KC_HOME , KC_PGDN , KC_END  \
  ),

  /* Function layer 2. Fn1 modifications.
   * ,---------------------------------------------------------------.
   * |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
   * |     |   |   |   |   |   |   |   |PgU|   |   |   |   |     |   |
   * |      |   |   |   |   |   |   |Hom|PgD|End|   |   |        |   |
   * |        |   |   |   |   |   |   |   |   |   |   |      |PgU|   |
   * |    |    |    |                       |    |    |  |Hom|PgD|End|
   * `---------------------------------------------------------------'
   */
  [_FN2] = LAYOUT_truefox( \
      _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , \
      _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , KC_PGUP , _______ , _______ , _______ , _______ , _______           , _______ , \
      _______ , _______ , _______ , _______ , _______ , _______ , _______ , KC_HOME , KC_PGDN , KC_END  , _______ , _______ , _______                     , KC_MPLY , \
      _______           , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______           , KC_PGUP , KC_MUTE , \
      _______           , _______ , _______ , _______                                                   , _______ , _______           , KC_HOME , KC_PGDN , KC_END  \
  ),

  /* Function layer 3. Macros, numbers.
   * ,---------------------------------------------------------------.
   * |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
   * |---------------------------------------------------------------|
   * |     |  `|   |   |   |   |Del|Bsp|Ent|  [|  ]|  \|   |     |   |
   * |---------------------------------------------------------------|
   * |      |  1|  2|  3|  4|  5|  6|  7|  8|  9|  0|   |        |Prv|
   * |---------------------------------------------------------------|
   * |        |MTP|MTN|MVP|MVN|   |MVW|   |   |   |   |      |   |Nxt|
   * |---------------------------------------------------------------|
   * |    |    |    |                       |    |    |  |   |   |   |
   * `---------------------------------------------------------------'
   */
  [_FN3] = LAYOUT_truefox( \
      _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , \
      _______ , KC_GRV  , _______ , _______ , _______ , _______ , KC_DEL  , KC_BSPC , KC_ENT  , KC_LBRC , KC_RBRC , KC_BSLS , _______ , _______           , _______ , \
      _______ , KC_1    , KC_2    , KC_3    , KC_4    , KC_5    , KC_6    , KC_7    , KC_8    , KC_9    , KC_0    , _______ , _______                     , KC_MPRV , \
      _______           , EL_TMWP , EL_TMWN , EL_VMBP , EL_VMBN , _______ , EL_VMBW , _______ , _______ , _______ , _______ , _______           , _______ , KC_MNXT , \
      _______           , _______ , _______ , _______                                                   , _______ , _______           , _______ , _______ , _______  \
  ),
};
