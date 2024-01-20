#include QMK_KEYBOARD_H

#ifdef CONSOLE_ENABLE
  #include <print.h>
#endif

#include "version.h"

static unsigned int type_count = 0;
void count_type(void) {
    type_count++;
}

// キーを押す・離すタイミングで呼ばれる関数
// 関数自体なければ関数ごと追加、あれば`#ifdef OLED_ENABLE`内だけ追加する
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (record->event.pressed) {
        count_type();
    }
    return true;
}


void oled_write_type_count(void) {
    static char type_count_str[7];
    oled_write_P(PSTR("Count:"), false);
    itoa(type_count, type_count_str, 10);
    oled_write_ln(type_count_str, false);
}



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

// カスタム内容表示
void keyball_oled_render_mysub(void) {
    //oled_set_cursor(0, 0);
    oled_write_P(PSTR("Keymap:"), false);
    oled_write_ln_P(PSTR(QMK_KEYMAP), false);
    oled_write_uptime();
    //oled_write_type_count();
    //oled_write_P(PSTR("Ref:"), false);
    oled_write_P(PSTR(QMK_BUILDDATE), false);
}