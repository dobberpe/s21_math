#include "s21_math.h"

long double s21_floor(double x) {
  long double result;
  d_bits d = {x};
  if (s21_isnan(x) || s21_isnan(-x) || x == S21_INF || x == -S21_INF ||
      (int)((d.bits << 1) >> 53) - 1023 > 51) {
    result = x;
  } else {
    long long int int_part = (long long int)x;
    result = (x - int_part != 0 && x < 0) ? int_part - 1 : int_part;
  }
  return result;
}