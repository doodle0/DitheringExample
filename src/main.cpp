#include "bitmap.h"
#include "dither.h"
#include <algorithm>
#include <cmath>

int main() {
  Bitmap img(256, 256);
  for (int i = 0; i < 256; i++) {
    for (int j = 0; j < 256; j++) {
      float dist = (pow((i - 127.5) / 127.5, 2) + pow((j - 127.5) / 127.5, 2));
      img.Set(i, j, std::max(0, int((1 - pow(dist, 0.5)) * 255)));
    }
  }

  BasicDitherer ditherer(255, 255);

  ditherer.Dither(img).ExportPNG("circle.png");
}