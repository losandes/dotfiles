#include QMK_KEYBOARD_H
#include "muse.h"

extern keymap_config_t keymap_config;

enum planck_layers {
  _QWERTY,
  _LYR_NUM,
  _LYR_FNC,
  _LYR_NAV,
  _LYR_WSD,
  _LYR_MOS,
  _LYR_PLK
};

enum planck_keycodes {
  QWERTY = SAFE_RANGE,
  LYR_NUM,
  LYR_FNC,
  LYR_NAV,
  LYR_WSD,
  LYR_MOS,
  LYR_PLK,
  KCM_PRN,
  KCM_CBR,
  KCM_BRC,
  KCM_ARR,
  KCM_ALR
};

void open_alfred(void);

#define LYR_NUM TT(_LYR_NUM)
#define LYR_NAV TT(_LYR_NAV)
#define LYR_FNC MO(_LYR_FNC)
#define LYR_WSD LT(_LYR_WSD, KC_ENT)
#define LYR_MOS LT(_LYR_MOS, KC_ESC)

#define SFT_CPS LSFT_T(KC_CAPS)
#define CTL_TAB CTL_T(KC_TAB)
#define ALFRED  LALT(KC_SPACE)
#define ZOM_MIC LSFT(LGUI(KC_A))
#define CMD_ENT LGUI(KC_ENT)
#define TAB_LFT LALT(LGUI(KC_LEFT))
#define TAB_RGT LALT(LGUI(KC_RIGHT))
#define CAP_ARA LSFT(LGUI(KC_4))

/* LYR_NAME
 * ,-----------------------------------------------------------------------.
 * |     |     |     |     |     |     |     |     |     |     |     |     |
 * |-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----|
 * |     |     |     |     |     |     |     |     |     |     |     |     |
 * |-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----|
 * |     |     |     |     |     |     |     |     |     |     |     |     |
 * |-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----|
 * |     |     |     |     |     |     |     |     |     |     |     |     |
 * `-----------------------------------------------------------------------'

 [_LYR_NAME] = LAYOUT_planck_grid(
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
 ),

 */

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* QWERTY (Teal)
 * ,-----------------------------------------------------------------------.
 * |MsEsc|  Q  |  W  |  E  |  R  |  T  |  Y  |  U  |  I  |  O  |  P  | Bksp|
 * |-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----|
 * |CtlTb|  A  |  S  |  D  |  F  |  G  |  H  |  J  |  K  |  L  |  ;  |  "  |
 * |-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----|
 * |SftCp|  Z  |  X  |  C  |  V  |  B  |  N  |  M  |  ,  |  .  |  /  |     |
 * |-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----|
 * | FUNC| Alt | Gui | Gui | NAV | NUM |Space| WSD |  ←  |  →  |  ↓  |  ↑  |
 * `-----------------------------------------------------------------------'
 */
[_QWERTY] = LAYOUT_planck_grid(
  LYR_MOS, KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,   KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,
  CTL_TAB, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,   KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
  SFT_CPS, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,   KC_M,    KC_COMM, KC_DOT,  KC_SLSH, XXXXXXX,
  LYR_FNC, KC_LALT, KC_LGUI, KC_LGUI, LYR_NAV, LYR_NUM, KC_SPC, LYR_WSD, KC_LEFT, KC_RGHT, KC_DOWN, KC_UP
),

/* NUM (Goldenrod)
 * ,-----------------------------------------------------------------------.
 * |  `  |  !  |  @  |  #  |  $  |  %  |  (  |  )  |  7  |  8  |  9  |  -  |
 * |-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----|
 * |  ~  |  1  |  2  |  ^  |  &  |  *  |  {  |  }  |  4  |  5  |  6  |  +  |
 * |-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----|
 * |  \  |  |  |  -  |  _  |  =  |  >  |  [  |  ]  |  1  |  2  |  3  |  *  |
 * |-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----|
 * |     |     |     |     | CTRL|*NUM*|Space| WSD |  0  |  ,  |  .  |  /  |
 * `-----------------------------------------------------------------------'
 */
[_LYR_NUM] = LAYOUT_planck_grid(
  KC_GRV,  KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_LPRN, KC_RPRN, KC_7, KC_8,    KC_9,   KC_MINS,
  KC_TILD, KC_1,    KC_2,    KC_CIRC, KC_AMPR, KC_PAST, KC_LCBR, KC_RCBR, KC_4, KC_5,    KC_6,   KC_PLUS,
  KC_BSLS, KC_PIPE, KC_MINS, KC_UNDS, KC_EQL,  KC_GT,   KC_LBRC, KC_RBRC, KC_1, KC_2,    KC_3,   KC_PAST,
  _______, _______, _______, _______, KC_LCTL, _______, KC_SPC,  LYR_WSD, KC_0, KC_COMM, KC_DOT, KC_SLSH
),

/* Fn (Coral)
 * ,-----------------------------------------------------------------------.
 * |Reset|     |     |     |     |     |     |  F12|  F7 |  F8 |  F9 | Del |
 * |-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----|
 * |PLNCK| ALR |     |     |     |     |     |  F11|  F4 |  F5 |  F6 | Pwr |
 * |-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----|
 * |QWRTY| Bksp| Del |     |     |     |     |  F10|  F1 |  F2 |  F3 |     |
 * |-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----|
 * |*FNC*| rgb |     |     |     |     |     |     |     |     |     |     |
 * `-----------------------------------------------------------------------'
 */
[_LYR_FNC] = LAYOUT_planck_grid(
  RESET,   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_F12,  KC_F7,   KC_F8,   KC_F9,   KC_DEL,
  LYR_PLK, KCM_ALR, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_F11,  KC_F4,   KC_F5,   KC_F6,   KC_PWR,
  QWERTY,  KC_BSPC, KC_DEL,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_F10,  KC_F1,   KC_F2,   KC_F3,   XXXXXXX,
  _______, RGB_TOG, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
),

/* NAV (Magenta)
 * ,-----------------------------------------------------------------------.
 * |     |     |  => |  !  |  =  |  (  |  )  |     | Home|  ↑  | End | PgUp|
 * |-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----|
 * |     |Shift| Ctrl| Alt | Gui |  {  |  }  |     |  ←  |  ↓  |  →  | PgDn|
 * |-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----|
 * |     |     |  [] |  {} |  () |  [  |  ]  | Mute| Mic | Play| Next|     |
 * |-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----|
 * |     |     |     |     |*NAV*|     |ALFRD|     | Vol↓| Vol↑|     |     |
 * `-----------------------------------------------------------------------'
 */
[_LYR_NAV] = LAYOUT_planck_grid(
  _______, XXXXXXX, KCM_ARR, KC_EXLM, KC_EQL,  KC_LPRN, KC_RPRN, XXXXXXX,  KC_HOME,  KC_UP,   KC_END,   KC_PGUP,
  _______, KC_LSFT, KC_LCTL, KC_LALT, KC_LGUI, KC_LCBR, KC_RCBR, XXXXXXX,  KC_LEFT,  KC_DOWN, KC_RGHT,  KC_PGDN,
  _______, XXXXXXX, KCM_BRC, KCM_CBR, KCM_PRN, KC_LBRC, KC_RBRC, KC__MUTE, ZOM_MIC,  KC_MPLY, KC_MFFD,  XXXXXXX,
  _______, _______, _______, _______, _______, XXXXXXX, ALFRED,  XXXXXXX,  KC_VOLD,  KC_VOLU, XXXXXXX,  XXXXXXX
),

/* LYR_WSD
 * ,-----------------------------------------------------------------------.
 * |     | Home|  ↑  | End | PgUp|     |     |     |  (  |  )  |     |     |
 * |-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----|
 * |     |  ←  |  ↓  |  →  | PgDn|Shift| Alt | Cmd |  {  |  }  |     |     |
 * |-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----|
 * |     |     |     |CapAr|BkSpc| Del |     |     |  [  |  ]  |     |     |
 * |-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----|
 * |     |     |     |     |     |     |     |*WSD*|     |     |     |     |
 * `-----------------------------------------------------------------------'
 */
 [_LYR_WSD] = LAYOUT_planck_grid(
  _______, KC_HOME, KC_UP,   KC_END,  KC_PGUP, _______, _______, _______, KC_LPRN, KC_RPRN, _______, _______,
  _______, KC_LEFT, KC_DOWN, KC_RGHT, KC_PGDN, KC_LSFT, KC_LALT, KC_LGUI, KC_LCBR, KC_RCBR, _______, _______,
  _______, _______, _______, CAP_ARA, KC_BSPC, KC_DEL,  _______, _______, KC_LBRC, KC_RBRC, _______, _______,
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
 ),

/* MOUSE (Blue)
 * ,-----------------------------------------------------------------------.
 * |*MOS*|Shift| Ctrl| Alt | Gui |     |     |     |LClk |  ↑  | RClk|ScrlU|
 * |-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----|
 * |     |     |     |     |     |     |     |     |  ←  |  ↓  |  →  |ScrlD|
 * |-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----|
 * |     |     |     |     |     |     |     |     |     |     |     |     |
 * |-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----|
 * |     |     |     |     |     |     |LClk |     | TabL| TabR|     |     |
 * `-----------------------------------------------------------------------'
 */
[_LYR_MOS] = LAYOUT_planck_grid(
  _______, KC_LSFT, KC_LCTL,  KC_LALT,  KC_LGUI, XXXXXXX, XXXXXXX, XXXXXXX, KC_BTN1,  KC_MS_U,  KC_BTN2, KC_WH_D,
  _______, XXXXXXX, XXXXXXX,  XXXXXXX,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_MS_L,  KC_MS_D,  KC_MS_R, KC_WH_U,
  _______, XXXXXXX, XXXXXXX,  XXXXXXX,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  XXXXXXX,  XXXXXXX, XXXXXXX,
  _______, _______, _______,  _______,  XXXXXXX, XXXXXXX, KC_BTN1, XXXXXXX, TAB_LFT, TAB_RGT, XXXXXXX, XXXXXXX
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
 * |      |  RGB |      |      |      |      |      |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_LYR_PLK] = LAYOUT_planck_grid(
    RESET,   DEBUG,   XXXXXXX, RGB_TOG, RGB_MOD, RGB_HUI, RGB_HUD, RGB_SAI, RGB_SAD,  RGB_VAI, RGB_VAD, XXXXXXX,
    XXXXXXX, XXXXXXX, MU_MOD,  AU_ON,   AU_OFF,  AG_NORM, AG_SWAP, XXXXXXX,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    QWERTY,  MUV_DE,  MUV_IN,  MU_ON,   MU_OFF,  MI_ON,   MI_OFF,  TERM_ON, TERM_OFF, XXXXXXX, XXXXXXX, XXXXXXX,
    _______, RGB_TOG, _______, _______, XXXXXXX, XXXXXXX, _______, XXXXXXX, _______,  _______, _______, _______
)

};

void open_alfred() {
  register_code(KC_LALT);
  register_code(KC_SPC);
  unregister_code(KC_SPC);
  unregister_code(KC_LALT);
  wait_ms(30);
}

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
    case LYR_WSD:
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
        SEND_STRING("()");
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
        SEND_STRING("=>");
      }
      return false;
      break;
    case KCM_ALR:
      if (record->event.pressed) {
        // for turning off Google Calendar alerts
        SEND_STRING("function alert () {}" SS_TAP(X_ENT));
      }
      return false;
      break;
  }
  return true;
}

enum combo_events {
  ZX_CUT,
  XC_COPY,
  CV_PASTE,
  QW_SCREEN_LEFT,
  WE_SCREEN_RIGHT,
  AS_TAB_LEFT,
  SD_TAB_RIGHT,
  QS_WORD_LEFT,
  WD_WORD_RIGHT
};

const uint16_t PROGMEM cut_combo[] = {KC_Z, KC_X, COMBO_END};
const uint16_t PROGMEM copy_combo[] = {KC_X, KC_C, COMBO_END};
const uint16_t PROGMEM paste_combo[] = {KC_C, KC_V, COMBO_END};
const uint16_t PROGMEM screen_left_combo[] = {KC_Q, KC_W, COMBO_END};
const uint16_t PROGMEM screen_right_combo[] = {KC_W, KC_E, COMBO_END};
const uint16_t PROGMEM tab_left_combo[] = {KC_A, KC_S, COMBO_END};
const uint16_t PROGMEM tab_right_combo[] = {KC_S, KC_D, COMBO_END};
const uint16_t PROGMEM word_left_combo[] = {KC_Q, KC_S, COMBO_END};
const uint16_t PROGMEM word_right_combo[] = {KC_W, KC_D, COMBO_END};

combo_t key_combos[COMBO_COUNT] = {
  [ZX_CUT] = COMBO_ACTION(cut_combo),
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
    case ZX_CUT:
      if (pressed) {
        tap_code16(LGUI(KC_X));
      }
      break;
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