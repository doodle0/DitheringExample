#ifndef __DITHER_H__
#define __DITHER_H__

#include "bitmap.h"
#include <cstdint>
#include <vector>

class Ditherer {
public:
  virtual Bitmap Dither(const Bitmap &inp) = 0;
};

class BasicDitherer : public Ditherer {
public:
  BasicDitherer(int r, int c);
  virtual Bitmap Dither(const Bitmap &inp);

private:
  const int r, c;
  std::vector<std::vector<float>> pattern;
};

#endif // __DITHER_H__