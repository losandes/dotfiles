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

#define LYR_NUM LT(_LYR_NUM, KC_ENT)
#define LYR_SYM LT(_LYR_SYM, KC_PGUP)
#define LYR_NAV MO(_LYR_NAV)
#define LYR_MOS MO(_LYR_MOS)
#define LYR_MED MO(_LYR_MED)
#define LYR_PLK MO(_LYR_PLK)
#define SPC_SFT RSFT_T(KC_SPC)
#define ZOM_MIC LSFT(LGUI(KC_A))

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Qwerty
 * ,-----------------------------------------------------------------------.
 * |  Q  |  W  |  E  |  R  |  T  | Esc | Bksp|  Y  |  U  |  I  |  O  |  P  |
 * |-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----|
 * |  A  |  S  |  D  |  F  |  G  |SymUp|  ;  |  H  |  J  |  K  |  L  |  "  |
 * |-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----|
 * |Shift|  Z  |  X  |  C  |  V  | PgDn|  B  |  N  |  M  |  ,  |  .  |  /  |
 * |-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----|
 * |Plank| Alt | Gui |Mouse| Nav |EntNm|Space+Shift|  ←  |  ↓  |  ↑  |  →  |
 * `-----------------------------------------------------------------------'
 */
[_QWERTY] = LAYOUT_planck_grid(
  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_ESC,  KC_BSPC,  KC_Y,    KC_U,    KC_I,    KC_O,   KC_P,
  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    LYR_SYM, KC_SCLN,  KC_H,    KC_J,    KC_K,    KC_L,   KC_QUOT,
  KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_PGDN, KC_B,     KC_N,    KC_M,    KC_COMM, KC_DOT, KC_SLSH,
  LYR_PLK, KC_LALT, KC_LGUI, LYR_MOS, LYR_NAV, LYR_NUM,  SPC_SFT,  SPC_SFT, KC_LEFT, KC_DOWN, KC_UP,  KC_RGHT
),

/* NUM (Teal)
 * ,-----------------------------------------------------------------------.
 * |  F7 |  F8 |  F9 | F12 |  (  | Esc | Bksp|  )  |  7  |  8  |  9  |  -  |
 * |-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----|
 * |  F4 |  F5 |  F6 | F11 |  {  |  <  |  >  |  }  |  4  |  5  |  6  |  +  |
 * |-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----|
 * |  F1 |  F2 |  F3 | F10 |  [  |Shift|  =  |  ]  |  1  |  2  |  3  |  *  |
 * |-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----|
 * |     |     |     | Alt | Gui |*NUM*|Space+Shift|  0  |  ,  |  .  |  /  |
 * `-----------------------------------------------------------------------'
 */
[_LYR_NUM] = LAYOUT_planck_grid(
  KC_F7,   KC_F8,   KC_F9,   KC_F12,  KC_LPRN, KC_ESC,  KC_BSPC, KC_RPRN, KC_7, KC_8,    KC_9,   KC_PMNS,
  KC_F4,   KC_F5,   KC_F6,   KC_F11,  KC_LCBR, KC_LT,   KC_GT,   KC_RCBR, KC_4, KC_5,    KC_6,   KC_PPLS,
  KC_F1,   KC_F2,   KC_F3,   KC_F10,  KC_LBRC, _______, KC_EQL,  KC_RBRC, KC_1, KC_2,    KC_3,   KC_PAST,
  XXXXXXX, _______, _______, KC_LALT, KC_LGUI, KC_LSFT, SPC_SFT, SPC_SFT, KC_0, KC_COMM, KC_DOT, KC_SLSH
),

/* SYM (Yellow)
 * ,-----------------------------------------------------------------------.
 * |  `  |     |  <  |  >  |  () | Esc | Bksp|  &  |  *  |  -  |  +  |  `  |
 * |-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----|
 * |     |  |  |  !  |  =  |  {} |*SYM*|  ;  |  !  |  @  |  #  |  $  |  "  |
 * |-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----|
 * |Shift|     |  _  |  -  |  [] |Shift|Shift|  |  |  %  |  ,  |  .  |  /  |
 * |-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----|
 * |     |     |     |     |     | Ent |Space+Shift|  ^  |     |     |  \  |
 * `-----------------------------------------------------------------------'
 */
[_LYR_SYM] = LAYOUT_planck_grid(
  KC_GRV,  _______, KC_LT,   KC_GT,   KCM_PRN, KC_ESC,  KC_BSPC, KC_AMPR, KC_ASTR, KC_MINS, KC_PLUS, KC_GRV,
  _______, KC_PIPE, KC_EXLM, KC_EQL,  KCM_CBR, _______, KC_SCLN, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_QUOT,
  KC_LSFT, KC_F2,   KC_UNDS, KC_MINS, KCM_BRC, KC_LSFT, KC_EQL,  KC_PIPE, KC_PERC, KC_COMM, KC_DOT,  KC_SLSH,
  _______, _______, _______, _______, _______, KC_ENT,  SPC_SFT, SPC_SFT, KC_CIRC, _______, _______, KC_BSLS
),

/* Nav (Purple)
 * ,-----------------------------------------------------------------------.
 * |     |     |     |     |     |     | Del |     |Home |  ↑  | End | PgUp|
 * |-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----|
 * |     |Shift| Alt | Gui | Ctrl|     |     | Tab |  ←  |  ↓  |  →  | PgDn|
 * |-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----|
 * |     |     |     |     |     |     |     | BkSp| Del | Mute|     | Mic |
 * |-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----|
 * |     |     |     |     |*NAV*|EntNm|Space+Shift| Next| Vol↓| Vol↑| Play|
 * `-----------------------------------------------------------------------'
 */
[_LYR_NAV] = LAYOUT_planck_grid(
  _______, _______, _______, _______, _______, _______, KC_DEL,  _______, KC_HOME, KC_UP,    KC_END,  KC_PGUP,
  _______, KC_LSFT, KC_LALT, KC_LGUI, KC_LCTL, _______, _______, KC_TAB,  KC_LEFT, KC_DOWN,  KC_RGHT, KC_PGDN,
  _______, _______, _______, _______, _______, _______, _______, KC_BSPC, KC_DEL,  KC__MUTE, _______, ZOM_MIC,
  _______, _______, _______, _______, LYR_NAV, KC_ENT,  SPC_SFT, SPC_SFT, KC_MFFD, KC_VOLD,  KC_VOLU, KC_MPLY
),

/* Mouse (Blue)
 * ,-----------------------------------------------------------------------.
 * |     |     |     |     |     |     |     |     |LClk |  ↑  | RClk|ScrlU|
 * |-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----|
 * |     |Shift| Alt | Gui | Ctrl|     |     |     |  ←  |  ↓  |  →  |ScrlD|
 * |-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----|
 * |     |     |     |     |     |     |     |     |     |     |     |     |
 * |-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----|
 * |     |     |     |     |*NAV*|EntNm|Space+Shift|     |     |     |     |
 * `-----------------------------------------------------------------------'
 */
[_LYR_MOS] = LAYOUT_planck_grid(
  _______, _______, _______, _______, _______, _______, _______, _______, KC_BTN1, KC_MS_U, KC_BTN2, KC_WH_U,
  _______, KC_LSFT, KC_LALT, KC_LGUI, KC_LCTL, KC_PGUP, _______, _______, KC_MS_L, KC_MS_D, KC_MS_R, KC_WH_D,
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
  _______, _______, _______, LYR_MOS, _______, KC_ENT,  SPC_SFT, SPC_SFT, _______, _______, _______, _______
),


/* PLANCK
 *               v-------------------------------RGB CONTROL--------------------v
 * ,-----------------------------------------------------------------------------------.
 * | Reset| Debug|      | RGB  |RGBMOD| HUE+ | HUE- | SAT+ | SAT- |BRGTH+|BRGTH-|Power |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |MUSmod|Aud on|Audoff|AGnorm|AGswap|Qwerty| Num  | Nav  |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |Voice-|Voice+|Mus on|Musoff|MIDIon|MIDIof|TermOn|TermOf|      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_LYR_PLK] = LAYOUT_planck_grid(
    RESET,   DEBUG,   _______, RGB_TOG, RGB_MOD, RGB_HUI, RGB_HUD, RGB_SAI, RGB_SAD,  RGB_VAI, RGB_VAD, KC_PWR ,
    _______, _______, MU_MOD,  AU_ON,   AU_OFF,  AG_NORM, AG_SWAP, QWERTY,  _______,  _______, _______, _______,
    _______, MUV_DE,  MUV_IN,  MU_ON,   MU_OFF,  MI_ON,   MI_OFF,  TERM_ON, TERM_OFF, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______,  _______, _______, _______
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
  QW_SCREEN_LEFT,
  WE_SCREEN_RIGHT,
  AS_TAB_LEFT,
  SD_TAB_RIGHT,
  QS_WORD_LEFT,
  WD_WORD_RIGHT
};

const uint16_t PROGMEM copy_combo[] = {KC_X, KC_C, COMBO_END};
const uint16_t PROGMEM paste_combo[] = {KC_C, KC_V, COMBO_END};
const uint16_t PROGMEM screen_left_combo[] = {KC_Q, KC_W, COMBO_END};
const uint16_t PROGMEM screen_right_combo[] = {KC_W, KC_E, COMBO_END};
const uint16_t PROGMEM tab_left_combo[] = {KC_A, KC_S, COMBO_END};
const uint16_t PROGMEM tab_right_combo[] = {KC_S, KC_D, COMBO_END};
const uint16_t PROGMEM word_left_combo[] = {KC_Q, KC_S, COMBO_END};
const uint16_t PROGMEM word_right_combo[] = {KC_W, KC_D, COMBO_END};

combo_t key_combos[COMBO_COUNT] = {
  [XC_COPY] = COMBO_ACTION(copy_combo),
  [CV_PASTE] = COMBO_ACTION(paste_combo),
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
