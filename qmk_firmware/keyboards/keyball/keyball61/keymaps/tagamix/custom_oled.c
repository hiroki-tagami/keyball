#include QMK_KEYBOARD_H

#include "version.h"

void oled_write_2digit(unsigned int digit) {
    static char buf[6];
    itoa(digit, buf, 10);
    if (digit < 10) {
        oled_write_char('0', false);
    }
    oled_write(buf, false);
}

void oled_write_uptime(void) {
    static uint32_t uptime_s;
    uptime_s = timer_read32() / 1000;
    oled_write_P(PSTR("Uptime "), false);
    // hour
    oled_write_2digit((uptime_s / 3600) % 60);
    oled_write_char(':', false);
    // minutes
    oled_write_2digit((uptime_s / 60) % 60);
    oled_write_char(':', false);
    // seconds
    oled_write_2digit(uptime_s % 60);
    oled_write_char('\n', false);
}


static void render_version(void) {
    oled_set_cursor(0, 0);
    oled_write_P(PSTR("keymap:"), false);
    oled_write_ln_P(PSTR(QMK_KEYMAP), false);
}

// カスタム内容表示
void keyball_oled_render_mysub(void) {
    render_version();
    oled_write_uptime();
    oled_write_P(PSTR("Build:"), false);
    oled_write_ln_P(PSTR(QMK_BUILDDATE), false);
}