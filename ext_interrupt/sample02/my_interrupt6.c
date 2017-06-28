#include "my_interrupt6.h"
#include <avr/interrupt.h> // 割り込みを使う場合にインクルードする

#include "sw_input_interface.h"
#include "led_output_interface.h"
#include "delay.h"

static unsigned char count = 0; // カウント値(SB6の立ち上がりをカウント)

// INT6 外部割り込み処理のプロトタイプ宣言
ISR(INT6_vect);

// INT7 外部割り込み処理の実装
ISR(INT6_vect) {
  delay(100);
  if (get_sw6() == 1)
  {
    count++;
  }
  EIFR |= 0x40; // INT6割り込み要求をクリア
}

void init_int6() {
  EICRB = 0x30; // INT6の立ち上がりエッジで割り込み要求を生成
  EIMSK = 0x40; // INT6割り込み許可
}

unsigned char get_count() {
  return count;
}
