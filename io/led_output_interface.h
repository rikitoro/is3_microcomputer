#ifndef LED_OUTPUT_INTERFACE_H_
#define LED_OUTPUT_INTERFACE_H_

// LEDの初期化
void init_led();

// dataのビット列でLED(DB7-DB0)を点灯
void set_led(unsigned char data);

#endif /* LED_OUTPUT_INTERFACE_H_ */
