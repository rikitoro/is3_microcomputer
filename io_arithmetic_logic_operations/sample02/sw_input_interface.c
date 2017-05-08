#include <avr/io.h>

void init_sw() {
  DDRG  &= 0xE0; // PORTGのbit4,3,2,1,0を入力に設定
  PORTG |= 0x1F; // PORTGのbit4,3,2,1,0をプルアップ
  DDRE  &= 0x00; // PORTEのbit7,6,2を入力に設定
  PORTE |= 0xC4; // PORTEのbit7,6,2をプルアップ

}

unsigned char get_sw(){
  // PORTG, PORTEからスイッチの情報を取得
  return (PING & 0x1F)|(PINE & 0xC0)|((PINE & 0x04) << 3);
}
