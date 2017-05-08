#include "sw_input_interface.h"
#include "led_output_interface.h"

int main()
{
  init_sw();
  init_led();

  while (1) {
    set_led(get_sw());
  }
}