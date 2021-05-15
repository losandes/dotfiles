#include QMK_KEYBOARD_H

enum alt_keycodes {
    DFU_MOD, // Reboot Keyboard in DFU mode (not currently working)
};

#define CTL_CAP CTL_T(KC_CAPS)
#define ZOM_MIC LSFT(LGUI(KC_A))
#define LYR_1 TT(1)
#define LYR_2 TT(2)

/* Truefox Template
 * ┌───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┐
 * │   │   │   │   │   │   │   │   │   │   │   │   │   │   │   │   │
 * ├───┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴───┼───┤
 * │     │   │   │   │   │   │   │   │   │   │   │   │   │     │   │
 * ├─────┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴─────┼───┤
 * │      │   │   │   │   │   │   │   │   │   │   │   │        │   │
 * ├──────┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴────┬───┼───┤
 * │        │   │   │   │   │   │   │   │   │   │   │      │   │   │
 * ├────┬───┴┬──┴─┬─┴───┴───┴───┴───┴───┴──┬┴───┼───┴┬─┬───┼───┼───┤
 * │    │    │    │                        │    │    │ │   │   │   │
 * └────┴────┴────┴────────────────────────┴────┴────┘ └───┴───┴───┘
 *
 [X] = LAYOUT_truefox(
   _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
   _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
   _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______, _______, \
   _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______, _______, \
   _______, _______, _______,                            _______,                            _______, _______, _______, _______, _______  \
 ),
 */

const uint16_t keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
     /* Layer 0: Default Layer
      * ┌───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┐
      * │Esc| 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9 | 0 | - | = |   │ \ │ ` │
      * ├───┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴───┼───┤
      * │ Tab │ Q │ W │ E │ R │ T │ Y │ U │ I │ O │ P │ [ │ ] │Backs│Del│
      * ├─────┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴─────┼───┤
      * │CtlCap│ A │ S │ D │ F │ G │ H │ J │ K │ L │ ; │ ' │ Enter  │PgU│
      * ├──────┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴────┬───┼───┤
      * │ Shift  │ Z │ X │ C │ V │ B │ N │ M │ , │ . │ / │Shift │ ↑ │PgD│
      * ├────┬───┴┬──┴─┬─┴───┴───┴───┴───┴───┴──┬┴───┼───┴┬─┬───┼───┼───┤
      * │Fn1 │LAlt│LCmd│         Space          │Fn3 │Fn2 │ │ ← │ ↓ │ → │
      * └────┴────┴────┴────────────────────────┴────┴────┘ └───┴───┴───┘
      */
    [0] = LAYOUT_truefox( \
        KC_GESC, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  _______, KC_BSLS, KC_GRV,  \
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC,      KC_BSPC,     KC_DEL,  \
        CTL_CAP, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,          KC_ENT,           KC_PGUP, \
        KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,          KC_RSFT,          KC_UP,   KC_PGDN, \
        LYR_1,   KC_LALT, KC_LGUI,                            KC_SPC,                    KC_LEAD, LYR_2,                     KC_LEFT, KC_DOWN, KC_RGHT  \
    ),
    /* Layer 1: Function Keys
     * ┌───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┐
     * │DFU│F1 │F2 │F3 │F4 │F5 │F6 │F7 │F8 │F9 │F10│F11│F12│   │   │Pwr│
     * ├───┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴───┼───┤
     * │     │   │   │   │   │   │   │   │   │   │   │   │   │ Del │Mut│
     * ├─────┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴─────┼───┤
     * │      │   │   │   │   │   │ ← │ ↓ │ ↑ │ → │   │   │        │   │
     * ├──────┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴────┬───┼───┤
     * │        │   │   │   │   │   │   │   │   │   │   │      │PgU│   │
     * ├────┬───┴┬──┴─┬─┴───┴───┴───┴───┴───┴──┬┴───┼───┴┬─┬───┼───┼───┤
     * │    │    │    │                        │    │    │ │Hom│PgD│End│
     * └────┴────┴────┴────────────────────────┴────┴────┘ └───┴───┴───┘
     */
    [1] = LAYOUT_truefox( \
      DFU_MOD, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  _______, _______, KC_PWR,   \
      _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,      KC_DEL,      KC__MUTE, \
      _______, _______, _______, _______, _______, _______, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, _______, _______,          _______,          _______,  \
      _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,          KC_PGUP, _______,  \
      _______, _______, _______,                            _______,                   _______, _______,                   KC_HOME, KC_PGDN, KC_END    \
    ),
    /* LAYER 2: Media and Mouse
     * ┌───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┐
     * │   │   │   │   │   │   │   │   │   │   │   │   │   │   │   │Mic│
     * ├───┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴───┼───┤
     * │     │   │M↑ │   │   │   │   │   │   │   │>||│   │   │ Del │Mut│
     * ├─────┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴─────┼───┤
     * │RClick│M← │M↓ │M→ │   │   │   │   │   │   │   │   │        │Vo↑│
     * ├──────┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴────┬───┼───┤
     * │        │   │   │   │   │   │   │   │   │   │   │      │   │Vo↓│
     * ├────┬───┴┬──┴─┬─┴───┴───┴───┴───┴───┴──┬┴───┼───┴┬─┬───┼───┼───┤
     * │    │    │    │       Left Click       │    │    │ │Pre│   │Nxt│
     * └────┴────┴────┴────────────────────────┴────┴────┘ └───┴───┴───┘
     */
     [2] = LAYOUT_truefox( \
       _______, KC_ACL0, KC_ACL1, KC_ACL2, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, ZOM_MIC,     \
       _______, _______, KC_MS_U, _______, _______, _______, _______, _______, _______, _______, KC_MPLY, _______, _______,      KC_DEL,      KC__MUTE,    \
       KC_BTN2, KC_MS_L, KC_MS_D, KC_MS_R, _______, _______, _______, _______, _______, _______, _______, _______,          _______,          KC__VOLUP,   \
       _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,          _______, KC__VOLDOWN, \
       _______, _______, _______,                            KC_BTN1,                   _______, _______,                   KC_MRWD, _______, KC_MFFD      \
     ),
};

void open_alfred() {
  register_code(KC_LALT);
  register_code(KC_SPC);
  unregister_code(KC_SPC);
  unregister_code(KC_LALT);
  wait_ms(30);
}

void open_spotlight() {
  register_code(KC_LGUI);
  register_code(KC_SPC);
  unregister_code(KC_SPC);
  unregister_code(KC_LGUI);
  wait_ms(30);
}

LEADER_EXTERNS();

// Runs constantly in the background, in a loop.
void matrix_scan_user(void) {
   /* Leader Keys: App Hotkeys
    * ┌───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┐
    * │Slp│Ds1│Ds2│   │   │   │   │   │   │   │   │   │   │   │   │   │
    * ├───┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴───┼───┤
    * │     │   │   │   │   │Trm│   │   │   │   │   │Trm│IDE│Brows│   │
    * ├─────┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴─────┼───┤
    * │      │Atm│Slk│   │Fnd│   │   │   │   │Lck│   │   │        │   │
    * ├──────┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴────┬───┼───┤
    * │        │Zöm│   │Cal│VsC│Brs│   │Nōt│Māl│   │   │Slack │   │   │
    * ├────┬───┴┬──┴─┬─┴───┴───┴───┴───┴───┴──┬┴───┼───┴┬─┬───┼───┼───┤
    * │    │    │    │        Spotlite        │Lēdr│Alfr│ │   │   │   │
    * └────┴────┴────┴────────────────────────┴────┴────┘ └───┴───┴───┘
    */
  LEADER_DICTIONARY() {
      leading = false;
      leader_end();

      SEQ_ONE_KEY(KC_ESC) {
        open_alfred();
        SEND_STRING("Sleep" SS_TAP(X_ENTER));
      }

      SEQ_ONE_KEY(KC_1) {
        register_code(KC_LCTL);
        register_code(KC_1);
        unregister_code(KC_1);
        unregister_code(KC_LCTL);
      }

      SEQ_ONE_KEY(KC_2) {
        register_code(KC_LCTL);
        register_code(KC_2);
        unregister_code(KC_2);
        unregister_code(KC_LCTL);
      }

      SEQ_ONE_KEY(KC_A) {
        open_spotlight();
        SEND_STRING("Atom.app" SS_TAP(X_ENTER));
      }

      SEQ_ONE_KEY(KC_RBRC) {
        open_spotlight();
        SEND_STRING("Atom.app" SS_TAP(X_ENTER));
      }

      SEQ_ONE_KEY(KC_B) {
        open_spotlight();
        SEND_STRING("Firefox.app" SS_TAP(X_ENTER));
      }

      SEQ_TWO_KEYS(KC_B, KC_B) {
        open_spotlight();
        SEND_STRING("Safari.app" SS_TAP(X_ENTER));
      }

      SEQ_ONE_KEY(KC_C) {
        open_spotlight();
        SEND_STRING("Calendar.app" SS_TAP(X_ENTER));
      }

      SEQ_TWO_KEYS(KC_C, KC_C) {
        open_spotlight();
        SEND_STRING("Numi.app" SS_TAP(X_ENTER));
      }

      SEQ_ONE_KEY(KC_F) {
        open_spotlight();
        SEND_STRING("Finder.app" SS_TAP(X_ENTER));
      }

      SEQ_TWO_KEYS(KC_F, KC_F) {
        open_spotlight();
        SEND_STRING("Firefox.app" SS_TAP(X_ENTER));
      }

      SEQ_ONE_KEY(KC_BSPC) {
        open_spotlight();
        SEND_STRING("Firefox.app" SS_TAP(X_ENTER));
      }

      SEQ_ONE_KEY(KC_L) {
        open_alfred();
        SEND_STRING("Lock" SS_TAP(X_ENTER));
      }

      SEQ_ONE_KEY(KC_M) {
        open_spotlight();
        SEND_STRING("Mail.app" SS_TAP(X_ENTER));
      }

      SEQ_TWO_KEYS(KC_M, KC_M) {
        open_spotlight();
        SEND_STRING("Messages.app" SS_TAP(X_ENTER));
      }

      SEQ_ONE_KEY(KC_N) {
        open_spotlight();
        SEND_STRING("Notes.app" SS_TAP(X_ENTER));
      }

      SEQ_ONE_KEY(KC_S) {
        open_spotlight();
        SEND_STRING("Slack.app" SS_TAP(X_ENTER));
      }

      SEQ_ONE_KEY(KC_RSFT) {
        open_spotlight();
        SEND_STRING("Slack.app" SS_TAP(X_ENTER));
      }

      SEQ_TWO_KEYS(KC_S, KC_S) {
        open_spotlight();
        SEND_STRING("Safari.app" SS_TAP(X_ENTER));
      }

      SEQ_TWO_KEYS(KC_BSPC, KC_BSPC) {
        open_spotlight();
        SEND_STRING("Safari.app" SS_TAP(X_ENTER));
      }

      SEQ_ONE_KEY(KC_SPC) {
        open_spotlight();
      }

      SEQ_ONE_KEY(LYR_2) {
        open_alfred();
      }

      SEQ_ONE_KEY(KC_T) {
        open_spotlight();
        SEND_STRING("Terminal.app" SS_TAP(X_ENTER));
      }

      SEQ_ONE_KEY(KC_LBRC) {
        open_spotlight();
        SEND_STRING("Terminal.app" SS_TAP(X_ENTER));
      }

      SEQ_ONE_KEY(KC_V) {
        open_spotlight();
        SEND_STRING("Visual Studio Code.app" SS_TAP(X_ENTER));
      }

      SEQ_TWO_KEYS(KC_RBRC, KC_RBRC) {
        open_spotlight();
        SEND_STRING("Visual Studio Code.app" SS_TAP(X_ENTER));
      }

      SEQ_ONE_KEY(KC_Z) {
        open_spotlight();
        SEND_STRING("zoom.us.app" SS_TAP(X_ENTER));
      }
    }
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    static uint32_t key_timer;

    switch (keycode) {
        case DFU_MOD:
            if (record->event.pressed) {
                key_timer = timer_read32();
            } else {
                if (timer_elapsed32(key_timer) >= BOOTKEY_HOLD_MS) {
                    reset_keyboard();
                }
            }
            return false; // Cancel further processing
        default:
            return true;  // Process all other keycodes normally
    }
}
