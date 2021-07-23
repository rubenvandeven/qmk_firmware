/*
Copyright 2019 @foostan
Copyright 2020 Drashna Jaelre <@drashna>

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


/*KC_Q,              KC_W,              KC_F,              KC_P,              KC_B,              KC_J,              KC_L,              KC_U,              KC_Y,              KC_QUOT,
    LGUI_T(KC_A),      LALT_T(KC_R),      LCTL_T(KC_S),      LSFT_T(KC_T),      KC_G,              KC_K,              LSFT_T(KC_N),      LCTL_T(KC_E),      LALT_T(KC_I),      LGUI_T(KC_O),
    KC_Z,              ALGR_T(KC_X),      KC_C,              KC_D,              KC_V,              KC_M,              KC_H,              KC_COMM,           ALGR_T(KC_DOT),    KC_SLSH,
    KC_NP,             KC_NP,             LT(MEDR, KC_ESC),  LT(NAVR, KC_SPC),  LT(MOUR, KC_TAB),  LT(NSSL, KC_ENT),  LT(NSL, KC_BSPC),  LT(FUNL, KC_DEL),  KC_NP,             KC_NP*/


// default layers
#define L_BASE 0
#define L_QWERTY 1
// over layers
#define L_LOWER 2 // nav & numbers
#define L_SYMBOLS 3 // symbols
#define L_MOUSE 4 // mouse
#define L_FUNCTION 7 // Fn & media
#define L_SWAYWM 8 // Keys for swaywm
#define L_KEYPAD 9 // Keypad


// Tap Dance declarations
enum {
    TD_PARENTHESES,
};

// Tap Dance definitions
qk_tap_dance_action_t tap_dance_actions[] = {
    // Tap once for Escape, twice for Caps Lock
    [TD_PARENTHESES] = ACTION_TAP_DANCE_DOUBLE(KC_LPRN, KC_RPRN),
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [L_BASE] = LAYOUT_split_3x6_3(
  //,--------------------------------------------------------------------------.                    ,-----------------------------------------------------.
       KC_DEL,        KC_Q,         KC_W,         KC_F,         KC_P,  KC_B,                         KC_J,    KC_L,    KC_U,    KC_Y,   KC_SCLN,  KC_BSLASH,
  //|--------+--------------+-------------+-------------+-------------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_ESC, LCTL_T(KC_A), LSFT_T(KC_R), LALT_T(KC_S), LGUI_T(KC_T), KC_G,                         KC_M, RGUI_T(KC_N), RALT_T(KC_E), RSFT_T(KC_I), RCTL_T(KC_O),KC_QUOT,
  //|--------+--------------+-------------+-------------+-------------+--------|                    |--------+--------+--------+--------+--------+--------|
      TD(TD_PARENTHESES),        KC_Z , ALGR_T(KC_X),        KC_C,         KC_D,  KC_V,                         KC_K, KC_H, KC_COMM, ALGR_T(KC_DOT), KC_SLSH, KC_MINUS,
  //|--------+--------------+-------------+-------------+-------------+--------+-----|  |--------+--------+--------+--------+--------+--------+--------|
                                        LT(L_MOUSE, KC_HOME),     LT(L_LOWER, KC_SPC),  LT(L_SWAYWM, KC_TAB),          LT(L_SYMBOLS, KC_BSPC),   LT(L_LOWER, KC_ENT), LT(L_FUNCTION, KC_DEL)
                                      //`--------------------------------------------'  `--------------------------------------------'

  ),
 [L_QWERTY] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                                        ,-----------------------------------------------------.
       KC_DEL,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                                             KC_Y,    KC_U,    KC_I,    KC_O,   KC_P,  KC_BSLASH,
  //|--------+--------+--------+--------+--------+--------|                                        |--------+--------+--------+--------+--------+--------|
      KC_ESC, LCTL_T(KC_A), LSFT_T(KC_S), LALT_T(KC_D), LGUI_T(KC_F), KC_G,                         KC_H, RGUI_T(KC_J), RALT_T(KC_K), RSFT_T(KC_L), RCTL_T(KC_SCLN), KC_QUOT,
  //|--------+--------+--------+--------+--------+--------|                                        |--------+--------+--------+--------+--------+--------|
      DF(L_BASE),    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                                       KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH,  KC_ESC,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          LT(L_MOUSE, KC_HOME),     LT(L_LOWER, KC_SPC),  LT(L_SWAYWM, KC_TAB),          LT(L_SYMBOLS, KC_BSPC),   LT(L_LOWER, KC_ENT), LT(L_FUNCTION, KC_DEL)
                                      //`--------------------------'  `--------------------------'

  ),

    // numbers and navigation
  [L_LOWER] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.             ,-----------------------------------------------------.                    
     KC_EQUAL, KC_1, KC_2, KC_3, KC_4, KC_5,                                KC_6, KC_7,    KC_8,    KC_9,  KC_0,  KC_MINUS,                
  //|--------+--------+--------+--------+--------+--------|             |--------+--------+--------+--------+--------+--------|                    
    KC_GRAVE,  KC_LCTL, KC_LSFT, KC_LALT, KC_LGUI, _______,                 KC_WWW_BACK, KC_LEFT,   KC_UP,KC_DOWN,KC_RIGHT, KC_WWW_FORWARD,                    
  //|--------+--------+--------+--------+--------+--------|             |--------+--------+--------+--------+--------+--------|  
  //                        long press for {}                  
      DF(L_QWERTY), KC_LPRN, KC_LBRC, KC_RBRC, KC_RPRN, _______,                KC_UNDO, KC_HOME, KC_PGUP, KC_PGDN,KC_END, KC_AGAIN,            
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          MO(L_KEYPAD), _______,  _______,     _______,   _______,_______
                                      //`--------------------------'  `--------------------------'
  ),

  [L_KEYPAD] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       _______, _______, _______, _______, _______, _______,                     _______,  KC_KP_7, KC_KP_8, KC_KP_9, KC_KP_MINUS, _______,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______,  KC_LCTL, KC_LSFT, KC_LALT, KC_LGUI, _______,                     KC_KP_SLASH, KC_KP_4, KC_KP_5, KC_KP_6, KC_KP_PLUS,  _______, 
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______, _______, _______, _______, _______, _______,                      KC_KP_0,  KC_KP_1, KC_KP_2, KC_KP_3, KC_KP_ASTERISK, _______,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                                 _______,   _______, _______, KC_BSPC,KC_KP_EQUAL, KC_KP_DOT
                                      //`--------------------------'  `--------------------------'
  ),

  [L_SWAYWM] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
  //    close window,   swhitch workspaces 1-10 (TODO: long press for move??)
       SGUI(KC_Q), LGUI(KC_1), LGUI(KC_2), LGUI(KC_3), LGUI(KC_4), LGUI(KC_5),         LGUI(KC_6), LGUI(KC_7), LGUI(KC_8), LGUI(KC_9), LGUI(KC_0), _______,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
  //                                        full screen , key store                              input to left display                           move focus                 input to right display
      _______, KC_LCTL, KC_LSFT, KC_LALT, LGUI(KC_F), MEH(KC_K),                      LCAG(KC_LEFT), LGUI(KC_LEFT), LGUI(KC_UP),   LGUI(KC_DOWN),LGUI(KC_RIGHT), LCAG(KC_LEFT), 
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
  //                    resize       launcher    split h     split v                            nautilus/explorer,  move windows
      _______, _______, LGUI(KC_R), LGUI(KC_D), LGUI(KC_B), LGUI(KC_V),                      LGUI(KC_N),SGUI(KC_LEFT), SGUI(KC_UP),   SGUI(KC_DOWN),SGUI(KC_RIGHT), _______,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
  //                                                float toggle
                                          _______, SGUI(KC_SPC),  _______,     _______, LGUI(KC_ENT), _______
                                      //`--------------------------'  `--------------------------'
  ),

  [L_SYMBOLS] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                 ,-----------------------------------------------------.                    
      _______, _______, KC_LPRN, KC_RPRN, _______, _______,                  _______, _______,   _______, _______,  _______, _______,                    
  // |--------+--------+--------+--------+--------+--------|                |--------+--------+--------+--------+--------+--------|                   
      _______,  _______, KC_LBRC, KC_RBRC, _______,  KC_GRV,                   _______, _______, _______, _______, _______, _______,                    
  //|--------+--------+--------+--------+--------+--------|                 |--------+--------+--------+--------+--------+--------|                    
      _______, _______, KC_LCBR, KC_RCBR, _______, _______,                  _______, _______, KC_LEFT_ANGLE_BRACKET, KC_RIGHT_ANGLE_BRACKET, _______, _______,                    
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          _______,   _______,  _______, _______, _______, _______
                                      //`--------------------------'  `--------------------------'
  ),

  [L_MOUSE] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
        RESET, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      RGB_TOG, RGB_HUI, RGB_SAI, RGB_VAI, XXXXXXX, XXXXXXX,                      XXXXXXX, KC_MS_L, KC_MS_U, KC_MS_D, KC_MS_R, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      RGB_MOD, RGB_HUD, RGB_SAD, RGB_VAD, XXXXXXX, XXXXXXX,                      XXXXXXX, KC_WH_L, KC_WH_U, KC_WH_D, KC_WH_R, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          _______, MO(L_KEYPAD),  _______,     KC_BTN3, KC_BTN1, KC_BTN2
                                      //`--------------------------'  `--------------------------'
  ),

  [L_FUNCTION] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
        RESET, XXXXXXX, KC_F7,    KC_F8,    KC_F9, KC_F10,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______, KC_EXECUTE, KC_F4,   KC_F5,   KC_F6, KC_F11,                      KC_MEDIA_PREV_TRACK, KC_MPLY, KC__VOLUP, KC__VOLDOWN, KC__MUTE, KC_MEDIA_NEXT_TRACK,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      LSFT(KC_PSCR), KC_PSCR, KC_F1, KC_F2,   KC_F3, KC_F12,                      XXXXXXX, _______, _______, _______, _______, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_LGUI, _______,  _______,     _______, MO(L_KEYPAD), _______
                                      //`--------------------------'  `--------------------------'
  )
};

#ifdef OLED_DRIVER_ENABLE
oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    if(is_master) {
        // On corne we want to actually be able to read what we write
        return OLED_ROTATION_270;
    }

    if(is_keyboard_left()){
        return rotation;
    }
    return OLED_ROTATION_180;
}


void oled_render_layer_state(void) {
    // Base layers:
    if(layer_state_cmp(default_layer_state, L_BASE)){
        oled_write_ln_P(PSTR("-----"), false);
    }
    if(layer_state_cmp(default_layer_state, L_QWERTY)){
        oled_write_ln_P(PSTR("QWERT"), false);
    }

    if(layer_state_cmp(layer_state, L_LOWER)){
        oled_write_P(PSTR("#/nav"), false);
    }
    if(layer_state_cmp(layer_state, L_SYMBOLS)){
        oled_write_P(PSTR("Sym."), false);
    }
    if(layer_state_cmp(layer_state, L_MOUSE)){
        oled_write_P(PSTR("Mouse"), false);
    }
    if(layer_state_cmp(layer_state, L_SWAYWM)){
        oled_write_P(PSTR("Sway"), false);
    }
    if(layer_state_cmp(layer_state, L_KEYPAD)){
        oled_write_P(PSTR("Nrpad"), false);
        oled_write_P(PSTR(" 789-"), false);
        oled_write_P(PSTR("/456+"), false);
        oled_write_P(PSTR("0123*"), false);
        oled_write_P(PSTR("<=."), false);
    }
    if(layer_state_cmp(layer_state, L_FUNCTION)){
        static const char PROGMEM fn_and_media[] = {
        70, 110, 0, 38, 0, 0x0E
        };
        oled_write_P(fn_and_media, false);
    }
    // oled_write_ln_P();
    oled_write_P(PSTR("\n"), false);
}


char keylog_str[24] = {};

const char code_to_name[60] = {
    ' ', ' ', ' ', ' ', 'a', 'b', 'c', 'd', 'e', 'f',
    'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p',
    'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z',
    '1', '2', '3', '4', '5', '6', '7', '8', '9', '0',
    'R', 'E', 'B', 'T', '_', '-', '=', '[', ']', '\\',
    '#', ';', '\'', '`', ',', '.', '/', ' ', ' ', ' '};

void set_keylog(uint16_t keycode, keyrecord_t *record) {
  char name = ' ';
    if ((keycode >= QK_MOD_TAP && keycode <= QK_MOD_TAP_MAX) ||
        (keycode >= QK_LAYER_TAP && keycode <= QK_LAYER_TAP_MAX)) { keycode = keycode & 0xFF; }
  if (keycode < 60) {
    name = code_to_name[keycode];
  }

  // update keylog
  snprintf(keylog_str, sizeof(keylog_str), "%dx%d, k%2d : %c",
           record->event.key.row, record->event.key.col,
           keycode, name);
}

void oled_render_keylog(void) {
    oled_write(keylog_str, false);
}

void render_bootmagic_status(bool status) {
    /* Show Ctrl-Gui Swap options */
    static const char PROGMEM logo[][2][3] = {
        {{0x97, 0x98, 0}, {0xb7, 0xb8, 0}},
        {{0x95, 0x96, 0}, {0xb5, 0xb6, 0}},
    };
    if (status) {
        oled_write_ln_P(logo[0][0], false);
        oled_write_ln_P(logo[0][1], false);
    } else {
        oled_write_ln_P(logo[1][0], false);
        oled_write_ln_P(logo[1][1], false);
    }
}

void oled_render_logo(void) {
    static const char PROGMEM crkbd_logo[] = {
        0x80, 0x81, 0x82, 0x83, 0x84, 0x85, 0x86, 0x87, 0x88, 0x89, 0x8a, 0x8b, 0x8c, 0x8d, 0x8e, 0x8f, 0x90, 0x91, 0x92, 0x93, 0x94,
        0xa0, 0xa1, 0xa2, 0xa3, 0xa4, 0xa5, 0xa6, 0xa7, 0xa8, 0xa9, 0xaa, 0xab, 0xac, 0xad, 0xae, 0xaf, 0xb0, 0xb1, 0xb2, 0xb3, 0xb4,
        0xc0, 0xc1, 0xc2, 0xc3, 0xc4, 0xc5, 0xc6, 0xc7, 0xc8, 0xc9, 0xca, 0xcb, 0xcc, 0xcd, 0xce, 0xcf, 0xd0, 0xd1, 0xd2, 0xd3, 0xd4,
        0};
    oled_write_P(crkbd_logo, false);
}

void oled_task_user(void) {
    if (is_master) {
        oled_render_layer_state();
        oled_render_keylog();
    } else {
        if(layer_state_cmp(layer_state, L_KEYPAD)){
            oled_write_P(PSTR(" 789-"), false);
            oled_write_P(PSTR("/456+"), false);
            oled_write_P(PSTR("0123*"), false);
            oled_write_P(PSTR("<=."), false);
        } else {
            oled_render_logo();
        }
    }
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (record->event.pressed) {
    set_keylog(keycode, record);
  }
  return true;
}
#endif // OLED_DRIVER_ENABLE



#ifdef RGBLIGHT_ENABLE
// Light LEDs 6 to 9 and 12 to 15 red when caps lock is active. Hard to ignore!
const rgblight_segment_t PROGMEM led_base[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 6, HSV_CYAN}//, 
    // {12, 4, HSV_RED}       // Light 4 LEDs, starting with LED 12
);
// Light LEDs 9 & 10 in cyan when keyboard layer 1 is active
const rgblight_segment_t PROGMEM led_qwerty[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 6, HSV_PURPLE}
);
// Light LEDs 11 & 12 in purple when keyboard layer 2 is active
const rgblight_segment_t PROGMEM led_lower[] = RGBLIGHT_LAYER_SEGMENTS(
    {11, 2, HSV_PURPLE}
);
// Light LEDs 13 & 14 in green when keyboard layer 3 is active
const rgblight_segment_t PROGMEM led_raise[] = RGBLIGHT_LAYER_SEGMENTS(
    {13, 2, HSV_GREEN}
);

// Light LEDs 13 & 14 in green when keyboard layer 3 is active
const rgblight_segment_t PROGMEM led_media[] = RGBLIGHT_LAYER_SEGMENTS(
    {13, 2, HSV_GREEN}
);

// Now define the array of layers. Later layers take precedence
const rgblight_segment_t* const PROGMEM my_rgb_layers[] = RGBLIGHT_LAYERS_LIST(
    led_base,
    led_qwerty,    // Overrides caps lock layer
    led_lower,    // Overrides other layers
    led_raise,     // Overrides other layers
    led_media     // Overrides other layers
);

void keyboard_post_init_user(void) {
    // Enable the LED layers
    rgblight_layers = my_rgb_layers;
}


// bool led_update_user(led_t led_state) {
//     rgblight_set_layer_state(0, led_state.caps_lock);
//     return true;
// }

layer_state_t default_layer_state_set_user(layer_state_t state) {
    rgblight_set_layer_state(0, layer_state_cmp(state, L_BASE));
    rgblight_set_layer_state(1, layer_state_cmp(state, L_QWERTY));
    return state;
}

layer_state_t layer_state_set_user(layer_state_t state) {
    rgblight_set_layer_state(2, layer_state_cmp(state, L_SYMBOLS));
    rgblight_set_layer_state(3, layer_state_cmp(state, L_SYMBOLS));
    rgblight_set_layer_state(4, layer_state_cmp(state, L_MOUSE));
    return state;
}
#endif // RGBLIGHT_ENABLE

