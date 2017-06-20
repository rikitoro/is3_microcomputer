#include "led_output_interface.h"
#include <avr/io.h>

void init_led() {
  DDRC  = 0xFF;  // PORTCを出力に設定
}

void set_led(const unsigned char data) {
  PORTC = ~data; // LEDは出力が0のときに点灯するのでbit反転
}
