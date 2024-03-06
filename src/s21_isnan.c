#include "s21_math.h"

bool s21_isnan(double n) {
  d_bits d = {n};
  return d.bits == NAN_BITS;
}