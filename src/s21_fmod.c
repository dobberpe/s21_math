#include "s21_math.h"

long double s21_fmod(double x, double y) {
  long double result =
      s21_isnan(x) || s21_isnan(-x)                              ? x
      : s21_isnan(y)                                             ? S21_NANL
      : s21_isnan(-y) || x == S21_INF || -x == S21_INF || y == 0 ? -S21_NANL
      : s21_isinf(y) || s21_isinf(-y) || s21_fabs(x) < s21_fabs(y)
          ? x
          : (x)-s21_floor(s21_fabs(x / y)) * (x / y < 0 ? -1 : 1) * y;
  result = !result && x < 0 ? -0.0 : result;
  return result;
}