/*
This is the c configuration file for the keymap

Copyright 2012 Jun Wako <wakojun@gmail.com>
Copyright 2015 Jack Humbert

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

#pragma once

//#define USE_MATRIX_I2C

/* Select hand configuration */

#define MASTER_LEFT
// #define MASTER_RIGHT
// #define EE_HANDS

#define USE_SERIAL_PD2

// #define TAPPING_FORCE_HOLD
// Because we enable permissive hold we can increase the tapping term a bit
#define TAPPING_TERM 300
// shift(kc_x)+a becomes A even within tapping term, 
#define PERMISSIVE_HOLD

#define AUTO_SHIFT_TIMEOUT 200
//Do not Auto Shift alpha characters, which include A through Z.
#define NO_AUTO_SHIFT_ALPHA

#ifdef RGBLIGHT_ENABLE
    #undef RGBLED_NUM
    // #define RGBLIGHT_ANIMATIONS
    #define RGBLED_NUM 27
    #define RGBLIGHT_LIMIT_VAL 120
    #define RGBLIGHT_HUE_STEP 10
    #define RGBLIGHT_SAT_STEP 17
    #define RGBLIGHT_VAL_STEP 17
    #define RGBLIGHT_SLEEP // If defined, the RGB lighting will be switched off when the host goes to sleep
    #define RGBLIGHT_DISABLE_KEYCODES // If defined, disables the ability to control RGB Light from the keycodes. You must use code functions to control the feature
    #define RGBLIGHT_DEFAULT_HUE 145
    #define RGBLIGHT_DEFAULT_SAT 255
    #define RGBLIGHT_DEFAULT_VAL 40
    #define RGBLIGHT_LAYERS // layers
#endif

// #define OLED_FONT_H "keyboards/crkbd/lib/glcdfont.c"


/* From users/manna-harbour_miryoku */
// Prevent normal rollover on alphas from accidentally triggering mods.
#define IGNORE_MOD_TAP_INTERRUPT

// Enable rapid switch from tap to hold, disables double tap hold auto-repeat.
// #define TAPPING_FORCE_HOLD

// Mouse key speed and acceleration.
#undef MOUSEKEY_DELAY
#define MOUSEKEY_DELAY          0
#undef MOUSEKEY_INTERVAL
#define MOUSEKEY_INTERVAL       16
#undef MOUSEKEY_WHEEL_DELAY
#define MOUSEKEY_WHEEL_DELAY    0
#undef MOUSEKEY_MAX_SPEED
#define MOUSEKEY_MAX_SPEED      6
#undef MOUSEKEY_TIME_TO_MAX
#define MOUSEKEY_TIME_TO_MAX    64

/* end manna-harbour/miryoku */
