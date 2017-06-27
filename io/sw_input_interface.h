#ifndef SW_INTPUT_INTERFACE_H_
#define SW_INTPUT_INTERFACE_H_

// SW の初期化
void init_sw();

// SW(SB7-SB0)の値を返す
unsigned char get_sw();

// SW7(SB7)の値を返す
unsigned char get_sw7();

#endif /* SW_INTPUT_INTERFACE_H_ */
