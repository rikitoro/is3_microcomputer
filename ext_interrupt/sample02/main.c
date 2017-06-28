#include <avr/interrupt.h>
#include "my_interrupt6.h"

#include "sw_input_interface.h"
#include "led_output_interface.h"
#include "delay.h"

int main(void)
{
  init_sw();
  init_led();

  init_int6(); // 外部割り込みINT6の初期化
  sei();  // 割り込み許可

  while (1) // カウント値を点滅させる
  {
    set_led(get_count());
    delay(600);
    set_led(0x00);
    delay(600);
  }
}
