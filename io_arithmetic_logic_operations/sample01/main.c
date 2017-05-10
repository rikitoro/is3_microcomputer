#include <avr/io.h> // I/Oポート関連のレジスタが定義されている

int main()
{
  // トグルスイッチに接続するI/Oポートの初期設定
  DDRG  = 0x00; // PORTGを入力に設定
  PORTG = 0x1F; // PORTGのbit4,3,2,1,0をプルアップ
  DDRE  = 0x00; // PORTEを入力に設定
  PORTE = 0xC4; // PORTEのbit7,6,2をプルアップ

  // LEDに接続するI/Oポートの初期設定
  DDRC  = 0xFF;  // PORTCを出力に設定

  unsigned char data = 0x00;

  while (1) {
    // PORTG, PORTEからスイッチの情報を取得
    data  = (PING & 0x1F)|(PINE & 0xC0)|((PINE & 0x04) << 3);

    // LEDに出力
    // LEDは出力ポートが0のときに点灯するのでビット反転した
    PORTC = ~data;
  }

}