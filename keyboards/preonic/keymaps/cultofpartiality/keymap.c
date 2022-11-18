// Normal QMK Include
#include QMK_KEYBOARD_H

// Userspace
#include "cultofpartiality.h"

// Split sections into different files for clarity
#include "muse.h"
#include "defines.h"
//#include "combos.h"
//#include "tapdance.h"

enum preonic_layers {
  _QWERTY,
  _MODTAP,
  _LOWER,
  _RAISE,
  _ADJUST
};

enum preonic_keycodes {
  QWERTY = SAFE_RANGE,
  MODTAP,
  LOWER,
  RAISE,
  BACKLIT
};


//Defines for quick enable of tapdance in code. It seemed interesting, but the delay before an action fires it super annoying.
//Might be able to tune it out, but I find after using the planck I don't really use it.
//Comment the following out to not use the tapdance layer functions
//#define USETAPDANCELAYERS


#ifdef USETAPDANCELAYERS
  #define KC_LOWER TD(TD_LOWER)
  #define KC_RAISE TD(TD_RAISE)
#else
  #define KC_LOWER MO(_LOWER)
  #define KC_RAISE MO(_RAISE)
#endif


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Qwerty
 * ,-----------------------------------------------------------------------------------.
 * | `Esc |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | Del  |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |  "   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  |Shift |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Ctrl | GUI  | Alt  |      |Lower |Space |Enter |Raise |      |  Alt |  GUI | Ctrl |
 * `-----------------------------------------------------------------------------------'
 */
[_QWERTY] = LAYOUT_ortho_5x12(
  KC_GESC, KC_1,    KC_2,    KC_3,     KC_4,     KC_5,    KC_6,    KC_7,     KC_8,     KC_9,    KC_0,    KC_BSPC,
  KC_TAB,  KC_Q,    KC_W,    KC_E,     KC_R,     KC_T,    KC_Y,    KC_U,     KC_I,     KC_O,    KC_P,    KC_DEL,
  KC_TAB,  KC_A,    KC_S,    KC_D,     KC_F,     KC_G,    KC_H,    KC_J,     KC_K,     KC_L,    KC_SCLN, KC_QUOT,
  KC_LSFT, KC_Z,    KC_X,    KC_C,     KC_V,     KC_B,    KC_N,    KC_M,     KC_COMM,  KC_DOT,  KC_SLSH, KC_RSFT,
  KC_LCTL, KC_LGUI, KC_LALT, KC_LOWER, KC_LOWER, KC_SPC,  KC_ENT,  KC_RAISE, KC_RAISE, KC_RALT, KC_RGUI, KC_RCTL
),

/* Qwerty (with homerow mods)
 * ,-----------------------------------------------------------------------------------.
 * | `Esc |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | Del  |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |  "   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  |Shift |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Ctrl | GUI  | Alt  |      |Lower |Space |Enter |Raise |      |  Alt |  GUI | Ctrl |
 * `-----------------------------------------------------------------------------------'
 */
[_MODTAP] = LAYOUT_ortho_5x12(
  KC_GESC, KC_1,    KC_2,    KC_3,         KC_4,         KC_5,    KC_6,   KC_7,         KC_8,         KC_9,    KC_0,    KC_BSPC,
  KC_TAB,  KC_Q,    KC_W,    KC_E,         KC_R,         KC_T,    KC_Y,   KC_U,         KC_I,         KC_O,    KC_P,    KC_DEL,
  KC_TAB,  HM_A,    HM_S,    HM_D,         HM_F,         KC_G,    KC_H,   HM_J,         HM_K,         HM_L,    HM_SCLN, KC_QUOT,
  KC_LSFT, KC_Z,    KC_X,    KC_C,         KC_V,         KC_B,    KC_N,   KC_M,         KC_COMM,      KC_DOT,  KC_SLSH, KC_RSFT,
  KC_LCTL, KC_LGUI, KC_LALT, KC_LOWER, KC_LOWER, KC_SPC,  KC_ENT,  KC_RAISE, KC_RAISE, KC_RALT, KC_RGUI, KC_RCTL
),

/* Lower
 * ,-----------------------------------------+-----------------------------------------.
 * |   ~  |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |  F7  |  F8  |  F9  |  F10 | Bksp |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |   ~  |   !  |   @  |   #  |   $  |   %  |   =  |   [  |   ]  |   (  |  F11 | Del  |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Del  |      |      |      |Print |      |   -  |   (  |   )  |   {  |  F12 |  \   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |      |      |      |      |      |   =  |   {  |   }  | Home |      |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      | Next | Vol- | Vol+ | Play |
 * `-----------------------------------------+-----------------------------------------'
 */
[_LOWER] = LAYOUT_ortho_5x12(
  KC_GRV,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,       KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,
  KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,     KC_EQL,  KC_LBRC, KC_RBRC, XXXXXXX, XXXXXXX, KC_F12,
  KC_DEL,  KC_F1,   KC_F2,   KC_F3,   KC_PSCR, KC_F5,       KC_MINS, KC_LPRN, KC_RPRN, XXXXXXX, KC_PIPE, KC_BSLS,
  _______, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,      KC_EQL,  KC_LCBR, KC_RCBR, XXXXXXX, _______, _______,
  _______, _______, _______, _______, _______, _______,     _______, _______, _______, _______, _______, _______
),

/* Raise
 * ,-----------------------------------------|-----------------------------------------.
 * |   `  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   _  |   0  | Bksp |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |      |      |      |      |      | Pg Up|PrvWrd|  Up  |NxtWrd|      | Del  |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |      |      |      |      |      | Pg Dw| Left | Down |Right |      |  \   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      | Undo |  Cut | Copy | Paste|      |      | Home |      | End  |      |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      | Next | Vol- | Vol+ | Play |
 * `-----------------------------------------|-----------------------------------------'
 */
[_RAISE] = LAYOUT_ortho_5x12(
  KC_GRV,  _______, _______, _______, _______, _______,      KC_6,    KC_7,    KC_8,    KC_UNDS, KC_0,    KC_BSPC,
  _______, NAV_L4T, NAV_L3T, NAV_L2T, NAV_L1T, NAV_L0T, /**/ NAV_R0T, NAV_R1T, NAV_R2T, NAV_R3T, NAV_R4T, KC_DEL,
  _______, NAV_L4M, NAV_L3M, NAV_L2M, NAV_L1M, NAV_L0M, /**/ NAV_R0M, NAV_R1M, NAV_R2M, NAV_R3M, NAV_R4M, KC_BSLS,
  _______, NAV_L4B, NAV_L3B, NAV_L2B, NAV_L1B, NAV_L0B, /**/ NAV_R0B, NAV_R1B, NAV_R2B, NAV_R3B, NAV_R4B, _______,
  _______, _______, _______, _______, _______, _______,      _______, _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
),

/* Adjust (Lower + Raise)
 * ,-----------------------------------------------------------------------------------.
 * |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      | Debug| Reset|      |      |      |      |      |      |      |  Del |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      |Aud cy|Aud on|AudOff|AGnorm|AGswap|<Desk |      | Desk>|      |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |Voice-|Voice+|Mus on|MusOff|MidiOn|MidOff|      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_ADJUST] = LAYOUT_ortho_5x12(
  RESET,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,
  MODTAP,  _______, DEBUG,   _______, _______, _______, _______, _______, _______, _______, _______, KC_DEL,
  QWERTY,  _______, _______, _______, _______, _______, _______, WD_LEFT, _______, WG_RGHT, _______, _______,
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
)


};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
        case QWERTY:
          if (record->event.pressed) {
            set_single_persistent_default_layer(_QWERTY);
          }
          return false;
          break;
        case MODTAP:
          if (record->event.pressed) {
            set_single_persistent_default_layer(_MODTAP);
          }
          return false;
          break;
       /*  case LOWER:
          if (record->event.pressed) {
            layer_on(_LOWER);
            update_tri_layer(_LOWER, _RAISE, _ADJUST);
          } else {
            layer_off(_LOWER);
            update_tri_layer(_LOWER, _RAISE, _ADJUST);
          }
          return false;
          break;
        case RAISE:
          if (record->event.pressed) {
            layer_on(_RAISE);
            update_tri_layer(_LOWER, _RAISE, _ADJUST);
          } else {
            layer_off(_RAISE);
            update_tri_layer(_LOWER, _RAISE, _ADJUST);
          }
          return false;
          break; */
        case BACKLIT:
          if (record->event.pressed) {
            register_code(KC_RSFT);
            #ifdef BACKLIGHT_ENABLE
              backlight_step();
            #endif
            #ifdef RGBLIGHT_ENABLE
              rgblight_step();
            #endif
            #ifdef __AVR__
            writePinLow(E6);
            #endif
          } else {
            unregister_code(KC_RSFT);
            #ifdef __AVR__
            writePinHigh(E6);
            #endif
          }
          return false;
          break;
      }
      update_tri_layer(_LOWER, _RAISE, _ADJUST);
      return true;
};

bool muse_mode = false;
uint8_t last_muse_note = 0;
uint16_t muse_counter = 0;
uint8_t muse_offset = 70;
uint16_t muse_tempo = 50;

bool encoder_update_user(uint8_t index, bool clockwise) {
  if (muse_mode) {
    if (IS_LAYER_ON(_RAISE)) {
      if (clockwise) {
        muse_offset++;
      } else {
        muse_offset--;
      }
    } else {
      if (clockwise) {
        muse_tempo+=1;
      } else {
        muse_tempo-=1;
      }
    }
  } else {
    if (clockwise) {
      register_code(KC_PGDN);
      unregister_code(KC_PGDN);
    } else {
      register_code(KC_PGUP);
      unregister_code(KC_PGUP);
    }
  }
    return true;
}

bool dip_switch_update_user(uint8_t index, bool active) {
    switch (index) {
        case 0:
            if (active) {
                layer_on(_ADJUST);
            } else {
                layer_off(_ADJUST);
            }
            break;
        case 1:
            if (active) {
                muse_mode = true;
            } else {
                muse_mode = false;
            }
    }
    return true;
}

void matrix_scan_user(void) {
#ifdef AUDIO_ENABLE
    if (muse_mode) {
        if (muse_counter == 0) {
            uint8_t muse_note = muse_offset + SCALE[muse_clock_pulse()];
            if (muse_note != last_muse_note) {
                stop_note(compute_freq_for_midi_note(last_muse_note));
                play_note(compute_freq_for_midi_note(muse_note), 0xF);
                last_muse_note = muse_note;
            }
        }
        muse_counter = (muse_counter + 1) % muse_tempo;
    } else {
        if (muse_counter) {
            stop_all_notes();
            muse_counter = 0;
        }
    }
#endif
}

bool music_mask_user(uint16_t keycode) {
  switch (keycode) {
    case RAISE:
    case LOWER:
      return false;
    default:
      return true;
  }
}
