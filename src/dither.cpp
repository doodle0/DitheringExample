#include "dither.h"
#include "bitmap.h"
#include <cstdint>
#include <vector>

BasicDitherer::BasicDitherer(int r, int c) : r(r), c(c) {
  pattern = std::vector<std::vector<float>>(r, std::vector<float>(c));
  for (int i = 0; i < r; i++) {
    for (int j = 0; j < c; j++) {
      int idx = (j >> 1 & 1) | ((i ^ j) >> 1 & 1) << 1 | //
                (j & 1) << 2 | ((i ^ j) & 1) << 3;
      pattern[i][j] = (idx + .5f) / 16.f;
    }
  }
}

Bitmap BasicDitherer::Dither(const Bitmap &inp) {
  Bitmap outp(r, c);
  for (int i = 0; i < r; i++) {
    for (int j = 0; j < c; j++) {
      if (inp.GetMap()[i][j].r > pattern[i][j] * 255)
        outp[i][j] = {255, 255, 255};
      else
        outp[i][j] = {0, 0, 0};
    }
  }
  return outp;
}
