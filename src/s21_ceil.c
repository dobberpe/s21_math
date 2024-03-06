#include "s21_math.h"

long double s21_ceil(double x) {
  long double result = 0.0;
  if (x == S21_INF || x == -S21_INF || s21_isnan(x) || s21_isnan(-x) ||
      !s21_fmod(x, 1))
    result = x;
  else {
    result = s21_floor(x) + 1;
    result *= result == 0 && x < 0 ? -1 : 1;
  }
  return result;
}