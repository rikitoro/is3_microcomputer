#ifndef MY_INTERRUPT6_H_
#define MY_INTERRUPT6_H_

// 外部割込みINT6 初期設定
void init_int6(void); 

// SW6(SB6)の立ち上がりのカウント値を返す
unsigned char get_count(void);

#endif /* MY_INTERRUPT6_H_ */
