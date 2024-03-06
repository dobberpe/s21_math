#include "s21_math.h"

long double s21_floor(double x) {
  long double result;
  d_bits d = {x};
  if (s21_isnan(x) || s21_isnan(-x)) {
    result = x;
  } else if (x == S21_INF) {
    result = S21_INFL;
  } else if (x == -S21_INF) {
    result = -S21_INFL;
  } else if ((int)((d.bits << 1) >> 53) - 1023 > 51) {
    result = (long double)x;
  } else {
    long long int int_part = (long long int)x;
    result = (x - int_part != 0 && x < 0) ? int_part - 1 : int_part;
  }
  return result;
}