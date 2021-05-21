#include QMK_KEYBOARD_H
#include "muse.h"

extern keymap_config_t keymap_config;

enum planck_layers {
  _QWERTY,
  _LYR_NUM,
  _LYR_PAD,
  _LYR_NAV,
  _LYR_MOS,
  _LYR_PLK
};

enum planck_keycodes {
  QWERTY = SAFE_RANGE,
  LYR_NUM,
  LYR_PAD,
  LYR_NAV,
  LYR_MOS,
  LYR_PLK,
  KCM_PRN,
  KCM_CBR,
  KCM_BRC,
  KCM_ARR
};

#define LYR_NUM TT(_LYR_NUM)

#define LYR_NAV MO(_LYR_NAV)
#define LYR_MOS LT(_LYR_MOS, KC_ESC)
#define LYR_PLK MO(_LYR_PLK)
#define SFT_CPS LSFT_T(KC_CAPS)
#define ZOM_MIC LSFT(LGUI(KC_A))
#define CTL_TAB CTL_T(KC_TAB)
#define ALFRED LALT(KC_SPACE)
#define TAB_LEFT LALT(LGUI(KC_LEFT))
#define TAB_RGHT LALT(LGUI(KC_RIGHT))

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* QWERTY (Teal)
 * ,-----------------------------------------------------------------------.
 * |MsEsc|  Q  |  W  |  E  |  R  |  T  |  Y  |  U  |  I  |  O  |  P  | Bksp|
 * |-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----|
 * |CtlTb|  A  |  S  |  D  |  F  |  G  |  H  |  J  |  K  |  L  |  ;  |  "  |
 * |-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----|
 * |SftCp|  Z  |  X  |  C  |  V  |  B  |  N  |  M  |  ,  |  .  |  /  |Enter|
 * |-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----|
 * |Plank| Alt | Gui | Gui | Nav | Num1|   Space   |  ←  |  →  |  ↓  |  ↑  |
 * `-----------------------------------------------------------------------'
 */
[_QWERTY] = LAYOUT_planck_grid(
  LYR_MOS, KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,   KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,
  CTL_TAB, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,   KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
  SFT_CPS, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,   KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_ENT,
  LYR_PLK, KC_LALT, KC_LGUI, KC_LGUI, LYR_NAV, LYR_NUM, KC_SPC, KC_SPC,  KC_LEFT, KC_RGHT, KC_DOWN, KC_UP
),

/* NUM (Goldenrod)
 * ,-----------------------------------------------------------------------.
 * |  `  |  !  |  @  |  #  |  $  |  %  |  ^  |  &  |  *  |  () |  -  |  =  |
 * |-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----|
 * |  ~  |  1  |  2  |  3  |  4  |  5  |  6  |  7  |  8  |  9  |  0  |  +  |
 * |-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----|
 * |     |     |  -  |  _  |  =  | Bksp| Del |     |  <  |  >  |  \  |  |  |
 * |-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----|
 * |     |     |     |     |     |*NUM*|   ALFRED  |     |     |     |     |
 * `-----------------------------------------------------------------------'
 */
[_LYR_NUM] = LAYOUT_planck_grid(
  KC_GRV,  KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KCM_PRN, KC_MINS, KC_EQL,
  KC_TILD, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_PLUS,
  XXXXXXX, XXXXXXX, KC_MINS, KC_UNDS, KC_EQL, KC_BSPC, KC_DEL,  XXXXXXX, KC_LT,   KC_GT,   KC_BSLS, KC_PIPE,
  _______, _______, _______, _______, KC_LCTL, _______, ALFRED,  ALFRED,  _______, _______, _______, _______
),

/* NUMPAD (Coral)
 * ,-----------------------------------------------------------------------.
 * |  F7 |  F8 |  F9 | F12 |  (  |  () |  =  |  )  |  7  |  8  |  9  |  -  |
 * |-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----|
 * |  F4 |  F5 |  F6 | F11 |  {  |  {} |     |  }  |  4  |  5  |  6  |  +  |
 * |-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----|
 * |  F1 |  F2 |  F3 | F10 |  [  |  [] |  _  |  ]  |  1  |  2  |  3  |  *  |
 * |-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----|
 * |     | Alt | Gui | Ctl |     |     |   Space   |  0  |  ,  |  .  |  /  |
 * `-----------------------------------------------------------------------'
 */
[_LYR_PAD] = LAYOUT_planck_grid(
  KC_F7,   KC_F8,   KC_F9,   KC_F12,  KC_LPRN, KCM_PRN, KC_EQL,  KC_RPRN, KC_7,    KC_8,    KC_9,   KC_MINS,
  KC_F4,   KC_F5,   KC_F6,   KC_F11,  KC_LCBR, KCM_CBR, XXXXXXX, KC_RCBR, KC_4,    KC_5,    KC_6,   KC_PLUS,
  KC_F1,   KC_F2,   KC_F3,   KC_F10,  KC_LBRC, KCM_BRC, KC_UNDS, KC_RBRC, KC_1,    KC_2,    KC_3,   KC_PAST,
  _______, _______, _______, KC_LCTL, XXXXXXX, XXXXXXX, KC_SPC,  KC_SPC,  KC_0,    KC_COMM, KC_DOT, KC_SLSH
),

/* NAV (Magenta)
 * ,-----------------------------------------------------------------------.
 * |     |     |  => |  !  |  =  |  (  |  )  |     |Home |  ↑  | End | PgUp|
 * |-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----|
 * |     |Shift| Ctrl| Alt | Gui |  {  |  }  |     |  ←  |  ↓  |  →  | PgDn|
 * |-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----|
 * |     |     |  [] |  {} |  () |  [  |  ]  | Mute|     | Play|     | Mic |
 * |-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----|
 * |     |     |     |     |*NAV*|     |   Space   | Prev| Next| Vol↓| Vol↑|
 * `-----------------------------------------------------------------------'
 */
[_LYR_NAV] = LAYOUT_planck_grid(
  _______, _______, KCM_ARR, KC_EXLM, KC_EQL,  KC_LPRN, KC_RPRN, _______,  KC_HOME,  KC_UP,   KC_END,   KC_PGUP,
  _______, KC_LSFT, KC_LCTL, KC_LALT, KC_LGUI, KC_LCBR, KC_RCBR, _______,  KC_LEFT,  KC_DOWN, KC_RGHT,  KC_PGDN,
  _______, _______, KCM_BRC, KCM_CBR, KCM_PRN, KC_LBRC, KC_RBRC, KC__MUTE, _______,  KC_MPLY, _______,  ZOM_MIC,
  _______, _______, _______, XXXXXXX, _______, XXXXXXX, KC_SPC,  KC_SPC,   KC_MRWD,  KC_MFFD, KC_VOLD,  KC_VOLU
),

/* MOUSE (Blue)
 * ,-----------------------------------------------------------------------.
 * |*MOS*|Shift| Ctrl| Alt | Gui |     |     |     |LClk |  ↑  | RClk|ScrlU|
 * |-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----|
 * |     |     |     |     |     |     |     |     |  ←  |  ↓  |  →  |ScrlD|
 * |-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----|
 * |     |     |     |     |     |     |     |     |     |     |     |     |
 * |-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----|
 * |     |     |     |     |     |     |   LClick  | TabL| TabR|     |     |
 * `-----------------------------------------------------------------------'
 */
[_LYR_MOS] = LAYOUT_planck_grid(
  _______, KC_LSFT, KC_LCTL,  KC_LALT,  KC_LGUI, _______, _______, _______, KC_BTN1,  KC_MS_U,  KC_BTN2, KC_WH_D,
  _______, _______, _______,  _______,  _______, _______, _______, _______, KC_MS_L,  KC_MS_D,  KC_MS_R, KC_WH_U,
  _______, _______, _______,  _______,  _______, _______, _______, _______, _______,  _______,  _______, _______,
  _______, _______, _______,  XXXXXXX,  XXXXXXX, XXXXXXX, KC_BTN1, KC_BTN1, TAB_LEFT, TAB_RGHT, _______, _______
),


/* PLANCK (Pink)
 *                      v------------------------RGB CONTROL--------------------v
 * ,-----------------------------------------------------------------------------------.
 * | Reset| Debug|      | RGB  |RGBMOD| HUE+ | HUE- | SAT+ | SAT- |BRGTH+|BRGTH-| Del  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |NUMPAD|      |MUSmod|Aud on|Audoff|AGnorm|AGswap|      |      |      |      | Power|
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |QWERTY|Voice-|Voice+|Mus on|Musoff|MIDIon|MIDIof|TermOn|TermOf|      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |*PLNK*|  RGB |      |      |      |             |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_LYR_PLK] = LAYOUT_planck_grid(
    RESET,   DEBUG,   _______, RGB_TOG, RGB_MOD, RGB_HUI, RGB_HUD, RGB_SAI, RGB_SAD,  RGB_VAI, RGB_VAD, KC_DEL ,
    LYR_PAD, _______, MU_MOD,  AU_ON,   AU_OFF,  AG_NORM, AG_SWAP, _______,  _______, _______, _______, KC_PWR,
    QWERTY,  MUV_DE,  MUV_IN,  MU_ON,   MU_OFF,  MI_ON,   MI_OFF,  TERM_ON, TERM_OFF, _______, _______, _______,
    _______, RGB_TOG, _______, _______, _______, _______, _______, _______, _______,  _______, _______, _______
)

};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case QWERTY:
      if (record->event.pressed) {
        print("mode just switched to qwerty\n");
        set_single_persistent_default_layer(_QWERTY);
        rgblight_sethsv(HSV_TEAL);
      }
      return false;
      break;
    case LYR_PAD:
      if (record->event.pressed) {
        print("mode just switched to NUMPAD\n");
        set_single_persistent_default_layer(_LYR_PAD);
        rgblight_sethsv(HSV_CORAL);
      }
      return false;
      break;
    case LYR_NUM:
      if (record->event.pressed) {
        rgblight_sethsv(HSV_GOLDENROD);
      } else {
        rgblight_sethsv(HSV_TEAL);
      }
      return true;
      break;
    case LYR_NAV:
      if (record->event.pressed) {
        rgblight_sethsv(HSV_MAGENTA);
      } else {
        rgblight_sethsv(HSV_TEAL);
      }
      return true;
      break;
    case LYR_MOS:
      if (record->event.pressed) {
        rgblight_sethsv(HSV_BLUE);
      } else {
        rgblight_sethsv(HSV_TEAL);
      }
      return true;
      break;
    case LYR_PLK:
      if (record->event.pressed) {
        rgblight_sethsv(HSV_PINK);
      } else {
        rgblight_sethsv(HSV_TEAL);
      }
      return true;
      break;
    case KCM_PRN:
      if (record->event.pressed) {
        SEND_STRING("()" SS_TAP(X_LEFT));
      }
      return false;
      break;
    case KCM_CBR:
      if (record->event.pressed) {
        SEND_STRING("{}" SS_TAP(X_LEFT));
      }
      return false;
      break;
    case KCM_BRC:
      if (record->event.pressed) {
        SEND_STRING("[]" SS_TAP(X_LEFT));
      }
      return false;
      break;
    case KCM_ARR:
      if (record->event.pressed) {
        SEND_STRING("=>" SS_TAP(X_LEFT));
      }
      return false;
      break;
  }
  return true;
}

enum combo_events {
  CMB_NUMPAD,
  CMB_PIPE
};

const uint16_t PROGMEM s_f_combo[] = {KC_S, KC_F, COMBO_END};
const uint16_t PROGMEM dot_slsh_combo[] = {KC_DOT, KC_SLSH, COMBO_END};

combo_t key_combos[COMBO_COUNT] = {
  [CMB_NUMPAD] = COMBO_ACTION(s_f_combo),
  [CMB_PIPE] = COMBO_ACTION(dot_slsh_combo)
};

void process_combo_event(uint16_t combo_index, bool pressed) {
  switch(combo_index) {
    case CMB_NUMPAD:
      if (pressed) {
        layer_on(_LYR_PAD);
      } else {
        layer_off(_LYR_PAD);
      }
      break;
    case CMB_PIPE:
      if (pressed) {
        tap_code16(KC_PIPE);
      }
      break;
  }
}
