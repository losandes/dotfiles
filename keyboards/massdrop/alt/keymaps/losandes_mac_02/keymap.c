#include QMK_KEYBOARD_H
#include "wait.h"
#include "config.h"
#include "led_matrix.h"
#include "my_led_programs.c"

enum alt_keycodes {
    L_BRI = SAFE_RANGE, //LED Brightness Increase
    L_BRD,              //LED Brightness Decrease
    L_EDG_I,            //LED Edge Brightness Increase
    L_EDG_D,            //LED Edge Brightness Decrease
    L_EDG_M,            //LED Edge lighting mode
    L_PTN,              //LED Pattern Select Next
    L_PTP,              //LED Pattern Select Previous
    L_PSI,              //LED Pattern Speed Increase
    L_PSD,              //LED Pattern Speed Decrease
    L_T_MD,             //LED Toggle Mode
    L_T_ONF,            //LED Toggle On / Off
    L_ON,               //LED On
    L_OFF,              //LED Off
    L_T_BR,             //LED Toggle Breath Effect
    L_T_PTD,            //LED Toggle Scrolling Pattern Direction and effect
    U_T_AGCR,           //USB Toggle Automatic GCR control
    DBG_TOG,            //DEBUG Toggle On / Off
    DBG_MTRX,           //DEBUG Toggle Matrix Prints
    DBG_KBD,            //DEBUG Toggle Keyboard Prints
    DBG_MOU,            //DEBUG Toggle Mouse Prints
    DBG_FAC,            //DEBUG Factory light testing (All on white)
    MD_BOOT,            //Restart into bootloader after hold timeout
};

#define TG_NKRO MAGIC_TOGGLE_NKRO //Toggle 6KRO / NKRO mode
#define CTL_CAP CTL_T(KC_CAPS)
#define ZOM_MIC LSFT(LGUI(KC_A))
#define LYR_1 TT(1)
#define LYR_2 TT(2)

keymap_config_t keymap_config;

/* Aria Template
 * ┌───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───────┬───┐
 * │   │   │   │   │   │   │   │   │   │   │   │   │   │       │   │
 * ├───┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─────┼───┤
 * │     │   │   │   │   │   │   │   │   │   │   │   │   │     │   │
 * ├─────┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴─────┼───┤
 * │      │   │   │   │   │   │   │   │   │   │   │   │        │   │
 * ├──────┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴────┬───┼───┤
 * │        │   │   │   │   │   │   │   │   │   │   │      │   │   │
 * ├────┬───┴┬──┴─┬─┴───┴───┴───┴───┴───┴──┬┴───┼───┴┬─┬───┼───┼───┤
 * │    │    │    │                        │    │    │ │   │   │   │
 * └────┴────┴────┴────────────────────────┴────┴────┘ └───┴───┴───┘
 *
 [X] = LAYOUT(
   _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
   _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
   _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______, _______, \
   _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______, _______, \
   _______, _______, _______,                            _______,                            _______, _______, _______, _______, _______  \
 ),
 */

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
   /* Layer 0: Default Layer
    * ┌───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───────┬───┐
    * │Esc| 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9 | 0 | - | = |  Del  │ ` │
    * ├───┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─────┼───┤
    * │ Tab │ Q │ W │ E │ R │ T │ Y │ U │ I │ O │ P │ [ │ ] │BkSpc│ | │
    * ├─────┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴─────┼───┤
    * │CtlCap│ A │ S │ D │ F │ G │ H │ J │ K │ L │ ; │ ' │ Enter  │PgU│
    * ├──────┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴────┬───┼───┤
    * │ Shift  │ Z │ X │ C │ V │ B │ N │ M │ , │ . │ / │Shift │ ↑ │PgD│
    * ├────┬───┴┬──┴─┬─┴───┴───┴───┴───┴───┴──┬┴───┼───┴┬─┬───┼───┼───┤
    * │Lyr1│LAlt│LCmd│         Space          │Lyr3│Lyr2│ │ ← │ ↓ │ → │
    * └────┴────┴────┴────────────────────────┴────┴────┘ └───┴───┴───┘
    */
    [0] = LAYOUT(
        KC_GESC, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_DEL,  KC_GRV,  \
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSPC, KC_BSLS, \
        CTL_CAP, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,          KC_ENT,  KC_PGUP, \
        KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,          KC_UP,   KC_PGDN, \
        LYR_1,   KC_LALT, KC_LGUI,                            KC_SPC,                             KC_LEAD, LYR_2,   KC_LEFT, KC_DOWN, KC_RGHT  \
    ),
    /* Layer 1: Function Keys
     * ┌───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───────┬───┐
     * │DFU│F1 │F2 │F3 │F4 │F5 │F6 │F7 │F8 │F9 │F10│F11│F12│  Del  │Pwr│
     * ├───┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─────┼───┤
     * │Breth│Sp↓│Br↑│Sp↑│Ed↑│   │   │   │GCR│   │>||│   │   │ Del │Mut│
     * ├─────┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴─────┼───┤
     * │ LDir │L← │Br↓│L→ │Ed↓│   │ ← │ ↓ │ ↑ │ → │   │   │        │   │
     * ├──────┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴────┬───┼───┤
     * │        │LMo│LOf│   │EdM│DFU│NKR│   │   │   │   │      │Br↑│LOf│
     * ├────┬───┴┬──┴─┬─┴───┴───┴───┴───┴───┴──┬┴───┼───┴┬─┬───┼───┼───┤
     * │    │    │    │         Debug          │    │    │ │Hom│Br↓│End│
     * └────┴────┴────┴────────────────────────┴────┴────┘ └───┴───┴───┘
     */
    [1] = LAYOUT(
        MD_BOOT, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  XXXXXXX, KC_PWR,   \
        L_T_BR,  L_PSD,   L_BRI,   L_PSI,   L_EDG_I, _______, _______, _______, U_T_AGCR,_______, _______, _______, _______, KC_DEL,  KC__MUTE, \
        L_T_PTD, L_PTP,   L_BRD,   L_PTN,   L_EDG_D, _______, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, _______, _______,          _______, _______,  \
        _______, L_T_MD,  L_T_ONF, _______, L_EDG_M, MD_BOOT, TG_NKRO, _______, _______, _______, _______, _______,          L_BRI,   L_T_ONF,  \
        _______, _______, _______,                            DBG_FAC,                            _______, _______, KC_HOME, L_BRD,   KC_END    \
    ),
    /* LAYER 2: Media and Mouse
     * ┌───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───────┬───┐
     * │   │   │   │   │   │   │   │   │   │   │   │   │   │  Del  │Mic│
     * ├───┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─────┼───┤
     * │     │   │M↑ │   │   │   │   │   │   │   │>||│   │   │ Del │Mut│
     * ├─────┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴─────┼───┤
     * │RClck │M← │M↓ │M→ │   │   │   │   │   │   │   │   │        │Vo↑│
     * ├──────┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴────┬───┼───┤
     * │        │   │   │   │   │   │   │   │   │   │   │      │   │Vo↓│
     * ├────┬───┴┬──┴─┬─┴───┴───┴───┴───┴───┴──┬┴───┼───┴┬─┬───┼───┼───┤
     * │    │    │    │       Left Click       │    │    │ │Pre│   │Nxt│
     * └────┴────┴────┴────────────────────────┴────┴────┘ └───┴───┴───┘
     */
    [2] = LAYOUT(
        _______, KC_ACL0, KC_ACL1, KC_ACL2, _______, _______, _______, _______, _______, _______, _______, _______, _______, XXXXXXX, ZOM_MIC,  \
        _______, _______, KC_MS_U, _______, _______, _______, _______, _______, _______, _______, KC_MPLY, _______, _______, KC_DEL , KC__MUTE, \
        KC_BTN2, KC_MS_L, KC_MS_D, KC_MS_R, _______, _______, _______, _______, _______, _______, _______, _______,          _______, KC_VOLU,  \
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______, KC_VOLD,  \
        _______, _______, _______,                            KC_BTN1,                            _______, _______, KC_MRWD, _______, KC_MFFD   \
    ),
};

// This assumes there are 11 values in the `led_setups` array
// in 'qmk_firmware/tmk_core/protocol/arm_atsam/led_matrix_programs.c'
uint8_t my_led_setups_count = 11;

// Runs just one time when the keyboard initializes.
void matrix_init_user(void) {
  led_animation_id = 0;      // initial background color
  gcr_desired = 20;          // set the default brightness (GCR increment/decrement value is 10 per step, 0 is off)
  led_edge_brightness = 0.1; // set the default edge brightness to be less bright than default
  // set the default color pattern (L_T_PTD)
  led_animation_direction = 0;
  led_animation_orientation = 0;
  led_animation_circular = 1;

  // There are a max of 10 led_setups that can be overridden
  // led_setups is defined in 'qmk_firmware/tmk_core/protocol/arm_atsam/led_matrix_programs.c'
  // and consumed by 'qmk_firmware/tmk_core/protocol/arm_atsam/led_matrix.c'
  led_setups[0]  = leds_off_override;
  led_setups[1]  = leds_teal_override;
  led_setups[2]  = leds_yellow_override;
  led_setups[3]  = leds_purple;
  led_setups[4]  = leds_teal_salmon_override;
  led_setups[5]  = leds_green_override;
  led_setups[6]  = leds_irish_s;
  led_setups[7]  = led_purple_rainbow_s;
  led_setups[8]  = leds_bwo_s;
  led_setups[9]  = leds_rainbow_burst_s;
  led_setups[10] = leds_trolls_dance_party_s;
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
  /* Leader Keys: App Hotkeys (Fn3/Lēdr)
   * ┌───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───────┬───┐
   * │Slp│Ds1│Ds2│   │   │   │   │   │   │   │   │   │   │       │Mut│
   * ├───┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─────┼───┤
   * │     │   │   │   │   │Trm│   │   │tun│   │   │Trm│IDE│Brows│   │
   * ├─────┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴─────┼───┤
   * │      │Abl│Slk│   │Fnd│   │   │   │   │Lck│   │   │        │   │
   * ├──────┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴────┬───┼───┤
   * │        │Zöm│   │Cal│VsC│Brs│   │Ber│Māl│cls│snz│ join │   │   │
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

      SEQ_ONE_KEY(KC_GRV) {
        open_alfred();
        SEND_STRING("mic-toggle" SS_TAP(X_ENTER));
      }

      SEQ_ONE_KEY(KC_A) {
        open_alfred();
        SEND_STRING("Ableton Live 11 Suite.app" SS_TAP(X_ENTER));
      }

      SEQ_ONE_KEY(KC_RBRC) {
        open_alfred();
        SEND_STRING("Visual Studio Code.app" SS_TAP(X_ENTER));
      }

      SEQ_ONE_KEY(KC_B) {
        open_alfred();
        SEND_STRING("Firefox.app" SS_TAP(X_ENTER));
      }

      SEQ_TWO_KEYS(KC_B, KC_B) {
        open_alfred();
        SEND_STRING("Safari.app" SS_TAP(X_ENTER));
      }

      SEQ_ONE_KEY(KC_C) {
        open_alfred();
        SEND_STRING("Calendar.app" SS_TAP(X_ENTER));
      }

      SEQ_TWO_KEYS(KC_C, KC_C) {
        open_alfred();
        SEND_STRING("Numi.app" SS_TAP(X_ENTER));
      }

      SEQ_ONE_KEY(KC_F) {
        open_alfred();
        SEND_STRING("Finder.app" SS_TAP(X_ENTER));
      }

      SEQ_TWO_KEYS(KC_F, KC_F) {
        open_alfred();
        SEND_STRING("Firefox.app" SS_TAP(X_ENTER));
      }

      SEQ_ONE_KEY(KC_BSPC) {
        open_alfred();
        SEND_STRING("Firefox.app" SS_TAP(X_ENTER));
      }

      SEQ_ONE_KEY(KC_L) {
        open_alfred();
        SEND_STRING("Lock" SS_TAP(X_ENTER));
      }

      SEQ_ONE_KEY(KC_M) {
        open_alfred();
        SEND_STRING("Mail.app" SS_TAP(X_ENTER));
      }

      SEQ_TWO_KEYS(KC_M, KC_M) {
        open_alfred();
        SEND_STRING("Messages.app" SS_TAP(X_ENTER));
      }

      SEQ_ONE_KEY(KC_I) {
        open_alfred();
        SEND_STRING("Music.app" SS_TAP(X_ENTER));
      }

      SEQ_ONE_KEY(KC_N) {
        open_alfred();
        SEND_STRING("Bear.app" SS_TAP(X_ENTER));
      }

      SEQ_ONE_KEY(KC_S) {
        open_alfred();
        SEND_STRING("Slack.app" SS_TAP(X_ENTER));
      }

      SEQ_ONE_KEY(KC_RSFT) {
        open_alfred();
        SEND_STRING("Slack.app" SS_TAP(X_ENTER));
      }

      SEQ_TWO_KEYS(KC_S, KC_S) {
        open_alfred();
        SEND_STRING("Safari.app" SS_TAP(X_ENTER));
      }

      SEQ_TWO_KEYS(KC_BSPC, KC_BSPC) {
        open_alfred();
        SEND_STRING("Safari.app" SS_TAP(X_ENTER));
      }

      SEQ_ONE_KEY(KC_SPC) {
        open_spotlight();
      }

      SEQ_ONE_KEY(LYR_2) {
        open_alfred();
      }

      SEQ_ONE_KEY(KC_T) {
        open_alfred();
        SEND_STRING("Terminal.app" SS_TAP(X_ENTER));
      }

      SEQ_ONE_KEY(KC_LBRC) {
        open_alfred();
        SEND_STRING("Terminal.app" SS_TAP(X_ENTER));
      }

      SEQ_ONE_KEY(KC_V) {
        open_alfred();
        SEND_STRING("Visual Studio Code.app" SS_TAP(X_ENTER));
      }

      SEQ_TWO_KEYS(KC_RBRC, KC_RBRC) {
        open_alfred();
        SEND_STRING("Visual Studio Code.app" SS_TAP(X_ENTER));
      }

      SEQ_ONE_KEY(KC_Z) {
        open_alfred();
        SEND_STRING("zoom.us.app" SS_TAP(X_ENTER));
      }

      SEQ_ONE_KEY(KC_COMM) {
        open_alfred();
        SEND_STRING("close-notifications" SS_TAP(X_ENTER));
      }

      SEQ_ONE_KEY(KC_DOT) {
        open_alfred();
        SEND_STRING("snooze-notifications" SS_TAP(X_ENTER));
      }
      
      SEQ_ONE_KEY(KC_SLSH) {
        open_alfred();
        SEND_STRING("join-meeting-notification" SS_TAP(X_ENTER));
      }
    }
};

#define MODS_SHIFT (get_mods() & MOD_BIT(KC_LSHIFT) || get_mods() & MOD_BIT(KC_RSHIFT))
#define MODS_CTRL (get_mods() & MOD_BIT(KC_LCTL) || get_mods() & MOD_BIT(KC_RCTRL))

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    static uint32_t key_timer;
    static uint8_t scroll_effect = 0;

    switch (keycode) {
        case L_BRI:
            if (record->event.pressed) {
                if (LED_GCR_STEP > LED_GCR_MAX - gcr_desired) gcr_desired = LED_GCR_MAX;
                else gcr_desired += LED_GCR_STEP;
                if (led_animation_breathing) gcr_breathe = gcr_desired;
            }
            return false;
        case L_BRD:
            if (record->event.pressed) {
                if (LED_GCR_STEP > gcr_desired) gcr_desired = 0;
                else gcr_desired -= LED_GCR_STEP;
                if (led_animation_breathing) gcr_breathe = gcr_desired;
            }
            return false;
        case L_EDG_M:
            if (record->event.pressed) {
                led_edge_mode++;
                if (led_edge_mode > LED_EDGE_MODE_MAX) {
                    led_edge_mode = LED_EDGE_MODE_ALL;
                }
            }
            return false;
        case L_EDG_I:
            if (record->event.pressed) {
                led_edge_brightness += 0.1;
                if (led_edge_brightness > 1) { led_edge_brightness = 1; }
            }
            return false;
        case L_EDG_D:
            if (record->event.pressed) {
                led_edge_brightness -= 0.1;
                if (led_edge_brightness < 0) { led_edge_brightness = 0; }
            }
            return false;
        case L_PTP:
            if (record->event.pressed) {
                if (led_animation_id == 0) led_animation_id = my_led_setups_count - 1;
                else led_animation_id--;
            }
            return false;
        case L_PTN:
            if (record->event.pressed) {
                if (led_animation_id == my_led_setups_count - 1) led_animation_id = 0;
                else led_animation_id++;
            }
            return false;
        case L_PSI:
            if (record->event.pressed) {
                led_animation_speed += ANIMATION_SPEED_STEP;
            }
            return false;
        case L_PSD:
            if (record->event.pressed) {
                led_animation_speed -= ANIMATION_SPEED_STEP;
                if (led_animation_speed < 0) led_animation_speed = 0;
            }
            return false;
        case L_T_MD:
            if (record->event.pressed) {
                led_lighting_mode++;
                if (led_lighting_mode > LED_MODE_MAX_INDEX) led_lighting_mode = LED_MODE_NORMAL;
            }
            return false;
        case L_T_ONF:
            if (record->event.pressed) {
                I2C3733_Control_Set(!I2C3733_Control_Get());
            }
            return false;
        case L_ON:
            if (record->event.pressed) {
                I2C3733_Control_Set(1);
            }
            return false;
        case L_OFF:
            if (record->event.pressed) {
                I2C3733_Control_Set(0);
            }
            return false;
        case L_T_BR:
            if (record->event.pressed) {
                led_animation_breathing = !led_animation_breathing;
                if (led_animation_breathing) {
                    gcr_breathe = gcr_desired;
                    led_animation_breathe_cur = BREATHE_MIN_STEP;
                    breathe_dir = 1;
                }
            }
            return false;
        case L_T_PTD:
            if (record->event.pressed) {
                scroll_effect++;
                if (scroll_effect == 1) {               //Patterns with scroll move horizontal (Right to left)
                    led_animation_direction = 1;
                    led_animation_orientation = 0;
                    led_animation_circular = 0;
                } else if (scroll_effect == 2) {        //Patterns with scroll move vertical (Top to bottom)
                    led_animation_direction = 1;
                    led_animation_orientation = 1;
                    led_animation_circular = 0;
                } else if (scroll_effect == 3) {        //Patterns with scroll move vertical (Bottom to top)
                    led_animation_direction = 0;
                    led_animation_orientation = 1;
                    led_animation_circular = 0;
                } else if (scroll_effect == 4) {        //Patterns with scroll explode from center
                    led_animation_direction = 0;
                    led_animation_orientation = 0;
                    led_animation_circular = 1;
                } else if (scroll_effect == 5) {        //Patterns with scroll implode on center
                    led_animation_direction = 1;
                    led_animation_orientation = 0;
                    led_animation_circular = 1;
                } else {                                //Patterns with scroll move horizontal (Left to right)
                    scroll_effect = 0;
                    led_animation_direction = 0;
                    led_animation_orientation = 0;
                    led_animation_circular = 0;
                }
            }
            return false;
        case U_T_AGCR:
            if (record->event.pressed && MODS_SHIFT && MODS_CTRL) {
                TOGGLE_FLAG_AND_PRINT(usb_gcr_auto, "USB GCR auto mode");
            }
            return false;
        case DBG_FAC:
            if (record->event.pressed && MODS_SHIFT && MODS_CTRL) {
                led_lighting_mode = LED_MODE_NORMAL;
                led_edge_brightness = 1;
                led_edge_mode = LED_EDGE_MODE_ALL;
                led_animation_breathing = 0;
                led_animation_id = 7; //led_programs.c led_setups leds_white index
                gcr_desired = LED_GCR_MAX;
                I2C3733_Control_Set(1);
            }
            return false;
        case DBG_TOG:
            if (record->event.pressed) {
                TOGGLE_FLAG_AND_PRINT(debug_enable, "Debug mode");
            }
            return false;
        case DBG_MTRX:
            if (record->event.pressed) {
                TOGGLE_FLAG_AND_PRINT(debug_matrix, "Debug matrix");
            }
            return false;
        case DBG_KBD:
            if (record->event.pressed) {
                TOGGLE_FLAG_AND_PRINT(debug_keyboard, "Debug keyboard");
            }
            return false;
        case DBG_MOU:
            if (record->event.pressed) {
                TOGGLE_FLAG_AND_PRINT(debug_mouse, "Debug mouse");
            }
            return false;
        case MD_BOOT:
            if (record->event.pressed) {
                key_timer = timer_read32();
            } else {
                if (timer_elapsed32(key_timer) >= BOOTKEY_HOLD_MS) {
                    reset_keyboard();
                }
            }
            return false;
        default:
            return true; //Process all other keycodes normally
    }
}

led_instruction_t led_instructions[] = {
  //All LEDs use the user's selected pattern (this is the factory default)
  { .flags = LED_FLAG_USE_ROTATE_PATTERN },

  { .flags = LED_FLAG_MATCH_LAYER | LED_FLAG_MATCH_ID | LED_FLAG_USE_RGB, .layer = 0, .id1 = 240, .r = 47, .g = 167, .b = 190 },
  { .flags = LED_FLAG_MATCH_LAYER | LED_FLAG_USE_ROTATE_PATTERN, .layer = 1, .id2 = 4294967288, .id3 = 511 },
  { .flags = LED_FLAG_MATCH_LAYER | LED_FLAG_MATCH_ID | LED_FLAG_USE_PATTERN, .layer = 1, .id0 = 2147483648, .id1 = 50348034, .id2 = 2, .pattern_id = 1 },
  { .flags = LED_FLAG_MATCH_LAYER | LED_FLAG_MATCH_ID | LED_FLAG_USE_RGB, .layer = 1, .id0 = 16385, .r = 0, .g = 0, .b = 255 },
  { .flags = LED_FLAG_MATCH_LAYER | LED_FLAG_MATCH_ID | LED_FLAG_USE_RGB, .layer = 1, .id0 = 8190, .r = 254, .g = 119, .b = 0 },
  { .flags = LED_FLAG_MATCH_LAYER | LED_FLAG_MATCH_ID | LED_FLAG_USE_RGB, .layer = 1, .id0 = 8192, .r = 255, .g = 0, .b = 0 },
  { .flags = LED_FLAG_MATCH_LAYER | LED_FLAG_MATCH_ID | LED_FLAG_USE_RGB, .layer = 1, .id1 = 67108864, .r = 127, .g = 0, .b = 255 },
  { .flags = LED_FLAG_MATCH_LAYER | LED_FLAG_MATCH_ID | LED_FLAG_USE_RGB, .layer = 1, .id0 = 2147450880, .id1 = 4177510397, .id2 = 5, .r = 0, .g = 0, .b = 0 },
  { .flags = LED_FLAG_MATCH_LAYER | LED_FLAG_MATCH_ID | LED_FLAG_USE_RGB, .layer = 2, .id0 = 3791798272, .id1 = 570427395, .id2 = 4294967293, .id3 = 511, .r = 47, .g = 167, .b = 190 },
  { .flags = LED_FLAG_MATCH_LAYER | LED_FLAG_MATCH_ID | LED_FLAG_USE_RGB, .layer = 2, .id0 = 8192, .r = 255, .g = 0, .b = 0 },
  { .flags = LED_FLAG_MATCH_LAYER | LED_FLAG_MATCH_ID | LED_FLAG_USE_RGB, .layer = 2, .id1 = 2147483648, .r = 127, .g = 0, .b = 255 },
  { .flags = LED_FLAG_MATCH_LAYER | LED_FLAG_MATCH_ID | LED_FLAG_USE_RGB, .layer = 2, .id0 = 503160831, .id1 = 1577056252, .id2 = 2, .r = 0, .g = 0, .b = 0 },
  { .flags = LED_FLAG_MATCH_LAYER | LED_FLAG_MATCH_ID | LED_FLAG_USE_RGB, .layer = 3, .id0 = 2148532230, .id1 = 14327813, .id2 = 4294967288, .id3 = 511, .r = 254, .g = 119, .b = 0 },
  { .flags = LED_FLAG_MATCH_LAYER | LED_FLAG_MATCH_ID | LED_FLAG_USE_RGB, .layer = 3, .id1 = 1073741824, .r = 127, .g = 0, .b = 255 },
  { .flags = LED_FLAG_MATCH_LAYER | LED_FLAG_MATCH_ID | LED_FLAG_USE_RGB, .layer = 3, .id0 = 2146435065, .id1 = 3206897658, .id2 = 7, .r = 0, .g = 0, .b = 0 },

  //end must be set to 1 to indicate end of instruction set
  { .end = 1 }
};

