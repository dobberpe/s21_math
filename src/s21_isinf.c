#include "s21_math.h"

bool s21_isinf(double n) {
  d_bits d = {n};
  return d.bits == INF_BITS;
}