#include "sw_intput_interface.h"
#include "led_output_interface.h"

unsigned char get_sw7(); //sw7の値を返す

int main(void)
{
  unsigned char count = 0x00; //カウント値
  unsigned char sw_now;   // 現時点でのsw7の値を保持
  unsigned char sw_prev;  // 一つ前に取得したsw7の値を保持
  
  init_sw();
  init_led();


  sw_prev = get_sw7();

  while(1) {
    sw_now = get_sw7();
    if (sw_prev == 0 && sw_now == 1) // sw7が0から1に切り替わった条件
    {
      count++;
    }
    sw_prev = sw_now;

    set_led(count); 
  }
}

unsigned char get_sw7() {
  return (get_sw() >> 7) & 0x01;
}
