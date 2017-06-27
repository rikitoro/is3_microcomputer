#include <avr/interrupt.h>
#include "my_interrupt7.h"

#include "sw_intput_interface.h"
#include "led_output_interface.h"

int main(void)
{
  init_sw();
  init_led();

  init_int7(); // 外部割り込みINT7 初期設定
  sei(); // 割り込み許可

  set_led(0x00);
  while(1) {
    // Do nothing
  }
}
