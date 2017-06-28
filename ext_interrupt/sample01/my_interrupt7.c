#include "my_interrupt7.h"
#include <avr/interrupt.h> // 割り込みを使う場合にインクルードする

#include "sw_input_interface.h"
#include "led_output_interface.h"
#include "delay.h"

static unsigned char count = 0; // カウント値(SB7の立ち上がりをカウント)

// INT7 外部割り込み処理のプロトタイプ宣言
ISR(INT7_vect); // ISRマクロにINT7の割り込みベクタ INT7_vectを渡す

// INT7 外部割り込み処理の実装
ISR(INT7_vect) {
  delay(100); // チャタリングキャンセルのための遅延
  if (get_sw7() == 1) // SB7の立ち上がりを確認
  {
    count++;
    set_led(count);
  }
  EIFR |= 0x80; // INT7割り込み要求をクリア(論理1を書き込むとクリア(0)される)
}

void init_int7() {
  EICRB = 0xC0; // INT7の立ち上がりエッジで割り込み要求を生成
  EIMSK = 0x80; // INT7割り込み許可
}
