#include "delay.h"

// ビルド時はコンパイルの最適化オプションをNone(-O0)とすること
void delay(int n) {
  int i, j;
  for (i = 0; i < n; ++i)
  {
    for (j = 0; j < n; ++j) {
      // Do nothing
    }
  }
}
