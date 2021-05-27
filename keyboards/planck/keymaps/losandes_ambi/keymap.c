#include QMK_KEYBOARD_H
#include "muse.h"

extern keymap_config_t keymap_config;

enum planck_layers {
  _QWERTY,
  _LYR_NUM,
  _LYR_FNC,
  _LYR_NAV,
  _LYR_MOS,
  _LYR_PLK
};

enum planck_keycodes {
  QWERTY = SAFE_RANGE,
  LYR_NUM,
  LYR_FNC,
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
#define LYR_FNC MO(_LYR_FNC)
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
 * | FUNC| Alt | Gui | Gui | NAV | NUM |   Space   |  ←  |  →  |  ↓  |  ↑  |
 * `-----------------------------------------------------------------------'
 */
[_QWERTY] = LAYOUT_planck_grid(
  LYR_MOS, KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,   KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,
  CTL_TAB, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,   KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
  SFT_CPS, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,   KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_ENT,
  LYR_FNC, KC_LALT, KC_LGUI, KC_LGUI, LYR_NAV, LYR_NUM, KC_SPC, KC_SPC,  KC_LEFT, KC_RGHT, KC_DOWN, KC_UP
),

/* NUM (Goldenrod)
 * ,-----------------------------------------------------------------------.
 * |  `  |  !  |  @  |  #  |  $  |  %  |  +  |  7  |  8  |  9  |  (  |  )  |
 * |-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----|
 * |  ~  |  1  |  2  |  3  |  ^  |  &  |  *  |  4  |  5  |  6  |  {  |  }  |
 * |-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----|
 * |  \  |  |  |  -  |  _  |  =  | Bksp|  /  |  1  |  2  |  3  |  [  |  ]  |
 * |-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----|
 * |     |     |     |     | CTRL|*NUM*|     0     |  ,  |  .  |  <  |  >  |
 * `-----------------------------------------------------------------------'
 */
[_LYR_NUM] = LAYOUT_planck_grid(
  KC_GRV,  KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_PLUS, KC_7, KC_8,    KC_9,   KC_LPRN, KC_RPRN,
  KC_TILD, KC_1,    KC_2,    KC_3,    KC_CIRC, KC_AMPR, KC_PAST, KC_4, KC_5,    KC_6,   KC_LCBR, KC_RCBR,
  KC_BSLS, KC_PIPE, KC_MINS, KC_UNDS, KC_EQL,  KC_BSPC, KC_SLSH, KC_1, KC_2,    KC_3,   KC_LBRC, KC_RBRC,
  _______, _______, _______, _______, KC_LCTL, _______, KC_0,    KC_0, KC_COMM, KC_DOT, KC_LT,   KC_GT
),

/* Fn (Coral)
 * ,-----------------------------------------------------------------------.
 * |Reset|     |     |     |     |     |     |  F12|  F7 |  F8 |  F9 | Del |
 * |-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----|
 * |PLNCK|     |     |     |     |     |     |  F11|  F4 |  F5 |  F6 | Pwr |
 * |-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----|
 * |QWRTY| Bksp| Del |     |     |     |     |  F10|  F1 |  F2 |  F3 |     |
 * |-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----|
 * |*FNC*| rgb |     |     |     |     |   Enter   |  0  |     |     |     |
 * `-----------------------------------------------------------------------'
 */
[_LYR_FNC] = LAYOUT_planck_grid(
  RESET,   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_F12, KC_F7, KC_F8,   KC_F9,   KC_DEL,
  LYR_PLK, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_F11, KC_F4, KC_F5,   KC_F6,   KC_PWR,
  QWERTY,  KC_BSPC, KC_DEL,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_F10, KC_F1, KC_F2,   KC_F3,   KC_PAST,
  _______, RGB_TOG, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_ENT,  KC_ENT, KC_0,  XXXXXXX, XXXXXXX, XXXXXXX
),

/* NAV (Magenta)
 * ,-----------------------------------------------------------------------.
 * |     |     |  => |  !  |  =  |     |     |     |Home |  ↑  | End | PgUp|
 * |-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----|
 * |     |Shift| Ctrl| Alt | Gui |     |     |     |  ←  |  ↓  |  →  | PgDn|
 * |-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----|
 * |     |     |  [] |  {} |  () |     |     | Mute|     | Play|     | Mic |
 * |-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----|
 * |     |     |     |     |*NAV*|     |   ALFRED  | Prev| Next| Vol↓| Vol↑|
 * `-----------------------------------------------------------------------'
 */
[_LYR_NAV] = LAYOUT_planck_grid(
  _______, XXXXXXX, KCM_ARR, KC_EXLM, KC_EQL,  XXXXXXX, XXXXXXX, XXXXXXX,  KC_HOME,  KC_UP,   KC_END,   KC_PGUP,
  _______, KC_LSFT, KC_LCTL, KC_LALT, KC_LGUI, XXXXXXX, XXXXXXX, XXXXXXX,  KC_LEFT,  KC_DOWN, KC_RGHT,  KC_PGDN,
  _______, XXXXXXX, KCM_BRC, KCM_CBR, KCM_PRN, XXXXXXX, XXXXXXX, KC__MUTE, XXXXXXX,  KC_MPLY, XXXXXXX,  ZOM_MIC,
  _______, _______, _______, _______, _______, XXXXXXX, ALFRED,  ALFRED,   KC_MRWD,  KC_MFFD, KC_VOLD,  KC_VOLU
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
  _______, KC_LSFT, KC_LCTL,  KC_LALT,  KC_LGUI, XXXXXXX, XXXXXXX, XXXXXXX, KC_BTN1,  KC_MS_U,  KC_BTN2, KC_WH_D,
  _______, XXXXXXX, XXXXXXX,  XXXXXXX,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_MS_L,  KC_MS_D,  KC_MS_R, KC_WH_U,
  _______, XXXXXXX, XXXXXXX,  XXXXXXX,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  XXXXXXX,  XXXXXXX, XXXXXXX,
  _______, _______, _______,  _______,  XXXXXXX, XXXXXXX, KC_BTN1, KC_BTN1, TAB_LEFT, TAB_RGHT, XXXXXXX, XXXXXXX
),


/* PLANCK (Pink)
 *                      v------------------------RGB CONTROL--------------------v
 * ,-----------------------------------------------------------------------------------.
 * | Reset| Debug|      | RGB  |RGBMOD| HUE+ | HUE- | SAT+ | SAT- |BRGTH+|BRGTH-|      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |MUSmod|Aud on|Audoff|AGnorm|AGswap|      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |QWERTY|Voice-|Voice+|Mus on|Musoff|MIDIon|MIDIof|TermOn|TermOf|      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |  RGB |      |      |      |             |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_LYR_PLK] = LAYOUT_planck_grid(
    RESET,   DEBUG,   XXXXXXX, RGB_TOG, RGB_MOD, RGB_HUI, RGB_HUD, RGB_SAI, RGB_SAD,  RGB_VAI, RGB_VAD, XXXXXXX,
    XXXXXXX, XXXXXXX, MU_MOD,  AU_ON,   AU_OFF,  AG_NORM, AG_SWAP, XXXXXXX,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    QWERTY,  MUV_DE,  MUV_IN,  MU_ON,   MU_OFF,  MI_ON,   MI_OFF,  TERM_ON, TERM_OFF, XXXXXXX, XXXXXXX, XXXXXXX,
    _______, RGB_TOG, _______, _______, XXXXXXX, XXXXXXX, _______, _______, _______,  _______, _______, _______
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
    case LYR_PLK:
      if (record->event.pressed) {
        print("mode just switched to planck features\n");
        set_single_persistent_default_layer(_LYR_PLK);
        rgblight_sethsv(HSV_PINK);
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
    case LYR_FNC:
      if (record->event.pressed) {
        rgblight_sethsv(HSV_CORAL);
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
