#include QMK_KEYBOARD_H
#include "muse.h"

extern keymap_config_t keymap_config;

enum planck_layers {
  _QWERTY,
  _LYR_NUM,
  _LYR_SYM,
  _LYR_NAV,
  _LYR_MOS,
  _LYR_PLK
};

enum planck_keycodes {
  QWERTY = SAFE_RANGE,
  LYR_NUM,
  LYR_SYM,
  LYR_NAV,
  LYR_MOS,
  LYR_PLK,
  KCM_PRN,
  KCM_CBR,
  KCM_BRC
};

#define LYR_NUM TT(_LYR_NUM)
#define LYR_SYM MO(_LYR_SYM)
#define LYR_NAV LT(_LYR_NAV, KC_ENT)
#define LYR_MOS LT(_LYR_MOS, KC_ESC)
#define LYR_PLK MO(_LYR_PLK)
#define SFT_CPS LSFT_T(KC_CAPS)
#define SPC_SFT RSFT_T(KC_SPC)
#define ZOM_MIC LSFT(LGUI(KC_A))
#define CTL_TAB CTL_T(KC_TAB)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Qwerty
 * ,-----------------------------------------------------------------------.
 * |MsEsc|  Q  |  W  |  E  |  R  |  T  |  Y  |  U  |  I  |  O  |  P  | Bksp|
 * |-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----|
 * |CtlTb|  A  |  S  |  D  |  F  |  G  |  H  |  J  |  K  |  L  |  ;  |  "  |
 * |-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----|
 * |SftCp|  Z  |  X  |  C  |  V  |  B  |  N  |  M  |  ,  |  .  |  /  |Enter|
 * |-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----|
 * |Plank| Alt | Gui | Sym |NavEn| Num |Space+Shift|  ←  |  ↓  |  ↑  |  →  |
 * `-----------------------------------------------------------------------'
 */
[_QWERTY] = LAYOUT_planck_grid(
  LYR_MOS, KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,
  CTL_TAB, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
  SFT_CPS, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_ENT,
  LYR_PLK, KC_LALT, KC_LGUI, LYR_SYM, LYR_NAV, LYR_NUM, SPC_SFT, SPC_SFT, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT
),

/* NUM (Teal)
 * ,-----------------------------------------------------------------------.
 * |  F7 |  F8 |  F9 | F12 |  (  |     |     |  )  |  7  |  8  |  9  |  -  |
 * |-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----|
 * |  F4 |  F5 |  F6 | F11 |  {  |  <  |  >  |  }  |  4  |  5  |  6  |  +  |
 * |-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----|
 * |  F1 |  F2 |  F3 | F10 |  [  |Shift|  =  |  ]  |  1  |  2  |  3  |  *  |
 * |-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----|
 * | Ctl | Alt | Gui |     |     |*NUM*|Space+Shift|  0  |  ,  |  .  |  /  |
 * `-----------------------------------------------------------------------'
 */
[_LYR_NUM] = LAYOUT_planck_grid(
  KC_F7,   KC_F8,   KC_F9,   KC_F12,  KC_LPRN, XXXXXXX, XXXXXXX, KC_RPRN, KC_7,    KC_8,    KC_9,   KC_PMNS,
  KC_F4,   KC_F5,   KC_F6,   KC_F11,  KC_LCBR, KC_LT,   KC_GT,   KC_RCBR, KC_4,    KC_5,    KC_6,   KC_PPLS,
  KC_F1,   KC_F2,   KC_F3,   KC_F10,  KC_LBRC, XXXXXXX, KC_EQL,  KC_RBRC, KC_1,    KC_2,    KC_3,   KC_PAST,
  KC_LCTL, KC_LALT, KC_LGUI, XXXXXXX, XXXXXXX, _______, SPC_SFT, SPC_SFT, KC_0,    KC_COMM, KC_DOT, KC_SLSH
),

/* Sym (Yellow)
 * ,-----------------------------------------------------------------------.
 * |  `  |  !  |  @  |  #  |  $  |  %  |  ^  |  &  |  *  |  () |  -  |  =  |
 * |-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----|
 * |  ~  |  () |  -  |  =  |     |     |     |     |     |  {} |  _  |  +  |
 * |-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----|
 * |Shift|  {} |  _  |  +  |     |     |     |Shift|     |  [] |  \  |  |  |
 * |-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----|
 * |     |  [] |  |  |*SYM*|     |     |Space+Shift|  0  |     |     |  $  |
 * `-----------------------------------------------------------------------'
 */
[_LYR_SYM] = LAYOUT_planck_grid(
  KC_GRV,  KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KCM_PRN, KC_MINS, KC_EQL,
  KC_TILD, KCM_PRN, KC_MINS, KC_EQL,  _______, _______, _______, _______, _______, KCM_CBR, KC_UNDS, KC_PLUS,
  KC_LSFT, KCM_CBR, KC_UNDS, KC_PLUS, _______, _______, _______, KC_LSFT, _______, KCM_BRC, KC_BSLS, KC_PIPE,
  XXXXXXX, KCM_BRC, KC_PIPE, _______, XXXXXXX, XXXXXXX, SPC_SFT, SPC_SFT, KC_0,    _______, _______, KC_DLR
),

/* Nav (Purple)
 * ,-----------------------------------------------------------------------.
 * |     |     |     |     |     |     |     |     | PgUp|Home |  ↑  | End |
 * |-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----|
 * |     |Shift| Ctrl| Alt | Gui |     |     |     | PgDn|  ←  |  ↓  |  →  |
 * |-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----|
 * |     |     |     |     |     |     |     | Mute|     | Play|     | Mic |
 * |-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----|
 * |     |     |     |     |*NAV*|     |Space+Shift| Prev| Vol↓| Vol↑| Next|
 * `-----------------------------------------------------------------------'
 */
[_LYR_NAV] = LAYOUT_planck_grid(
  _______, _______, _______, _______, _______, _______, _______, _______,  KC_PGUP,  KC_HOME,  KC_UP,   KC_END,
  _______, KC_LSFT, KC_LCTL, KC_LALT, KC_LGUI, _______, _______, _______,  KC_PGDN,  KC_LEFT,  KC_DOWN, KC_RGHT,
  _______, _______, _______, _______, _______, _______, _______, KC__MUTE, _______,  KC_MPLY,  _______, ZOM_MIC,
  XXXXXXX, _______, _______, XXXXXXX, _______, XXXXXXX, SPC_SFT, SPC_SFT,  KC_MRWD,  KC_VOLD,  KC_VOLU, KC_MFFD
),

/* Mouse (Blue)
 * ,-----------------------------------------------------------------------.
 * |*MOS*|Shift| Ctrl| Alt | Gui |     |     |     |ScrlU|LClk |  ↑  | RClk|
 * |-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----|
 * |     |     |     |     |     |     |     |     |ScrlD|  ←  |  ↓  |  →  |
 * |-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----|
 * |     |     |     |     |     |     |     |     |     |     |     |     |
 * |-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----|
 * |     |     |     |     |     |     |Space+Shift|     |     |     |     |
 * `-----------------------------------------------------------------------'
 */
[_LYR_MOS] = LAYOUT_planck_grid(
  _______, KC_LSFT, KC_LCTL, KC_LALT, KC_LGUI, _______, _______, _______, KC_WH_U, KC_BTN1, KC_MS_U, KC_BTN2,
  _______, _______, _______, _______, _______, _______, _______, _______, KC_WH_D, KC_MS_L, KC_MS_D, KC_MS_R,
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
  XXXXXXX, _______, _______, XXXXXXX, XXXXXXX, XXXXXXX, SPC_SFT, SPC_SFT, _______, _______, _______, _______
),


/* PLANCK
 *                      v------------------------RGB CONTROL--------------------v
 * ,-----------------------------------------------------------------------------------.
 * | Reset| Debug|      | RGB  |RGBMOD| HUE+ | HUE- | SAT+ | SAT- |BRGTH+|BRGTH-| Del  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |MUSmod|Aud on|Audoff|AGnorm|AGswap|      |      |      |      | Power|
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |Qwerty|Voice-|Voice+|Mus on|Musoff|MIDIon|MIDIof|TermOn|TermOf|      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |  RGB |      |      |      |             |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_LYR_PLK] = LAYOUT_planck_grid(
    RESET,   DEBUG,   _______, RGB_TOG, RGB_MOD, RGB_HUI, RGB_HUD, RGB_SAI, RGB_SAD,  RGB_VAI, RGB_VAD, KC_DEL ,
    _______, _______, MU_MOD,  AU_ON,   AU_OFF,  AG_NORM, AG_SWAP, _______,  _______,  _______, _______, KC_PWR,
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
      }
      return false;
      break;
    case KCM_PRN:
      if (record->event.pressed) {
        SEND_STRING("()" SS_TAP(X_LEFT));
      }
      return false;
      break;
    case KCM_CBR:
      if (record->event.pressed) {
        SEND_STRING("{}" SS_TAP(X_LEFT) SS_TAP(X_ENTER) SS_TAP(X_ENTER) SS_TAP(X_UP));
      }
      return false;
      break;
    case KCM_BRC:
      if (record->event.pressed) {
        SEND_STRING("[]" SS_TAP(X_LEFT));
      }
      return false;
      break;
  }
  return true;
}

enum combo_events {
  XC_COPY,
  CV_PASTE,
  ZX_ALFRED,
  QW_SCREEN_LEFT,
  WE_SCREEN_RIGHT,
  AS_TAB_LEFT,
  SD_TAB_RIGHT,
  QS_WORD_LEFT,
  WD_WORD_RIGHT
};

const uint16_t PROGMEM copy_combo[] = {KC_X, KC_C, COMBO_END};
const uint16_t PROGMEM paste_combo[] = {KC_C, KC_V, COMBO_END};
const uint16_t PROGMEM alfred_combo[] = {KC_Z, KC_X, COMBO_END};
const uint16_t PROGMEM screen_left_combo[] = {KC_Q, KC_W, COMBO_END};
const uint16_t PROGMEM screen_right_combo[] = {KC_W, KC_E, COMBO_END};
const uint16_t PROGMEM tab_left_combo[] = {KC_A, KC_S, COMBO_END};
const uint16_t PROGMEM tab_right_combo[] = {KC_S, KC_D, COMBO_END};
const uint16_t PROGMEM word_left_combo[] = {KC_Q, KC_S, COMBO_END};
const uint16_t PROGMEM word_right_combo[] = {KC_W, KC_D, COMBO_END};

combo_t key_combos[COMBO_COUNT] = {
  [XC_COPY] = COMBO_ACTION(copy_combo),
  [CV_PASTE] = COMBO_ACTION(paste_combo),
  [ZX_ALFRED] = COMBO_ACTION(alfred_combo),
  [QW_SCREEN_LEFT] = COMBO_ACTION(screen_left_combo),
  [WE_SCREEN_RIGHT] = COMBO_ACTION(screen_right_combo),
  [AS_TAB_LEFT] = COMBO_ACTION(tab_left_combo),
  [SD_TAB_RIGHT] = COMBO_ACTION(tab_right_combo),
  [QS_WORD_LEFT] = COMBO_ACTION(word_left_combo),
  [WD_WORD_RIGHT] = COMBO_ACTION(word_right_combo)
};

void process_combo_event(uint16_t combo_index, bool pressed) {
  switch(combo_index) {
    case XC_COPY:
      if (pressed) {
        tap_code16(LGUI(KC_C));
      }
      break;
    case CV_PASTE:
      if (pressed) {
        tap_code16(LGUI(KC_V));
      }
      break;
    case ZX_ALFRED:
      if (pressed) {
        tap_code16(LALT(KC_SPACE));
      }
      break;
    case QW_SCREEN_LEFT:
      if (pressed) {
        tap_code16(LCTL(KC_LEFT));
      }
      break;
    case WE_SCREEN_RIGHT:
      if (pressed) {
        tap_code16(LCTL(KC_RIGHT));
      }
      break;
    case AS_TAB_LEFT:
      if (pressed) {
        tap_code16(LALT(LGUI(KC_LEFT)));
      }
      break;
    case SD_TAB_RIGHT:
      if (pressed) {
        tap_code16(LALT(LGUI(KC_RIGHT)));
      }
      break;
    case QS_WORD_LEFT:
      if (pressed) {
        tap_code16(LALT(KC_LEFT));
      }
      break;
    case WD_WORD_RIGHT:
      if (pressed) {
        tap_code16(LALT(KC_RIGHT));
      }
      break;
  }
}
