#include "s21_math.h"

long double s21_fabs(double x) {
  long double result;
  if (s21_isnan(x) || s21_isnan(-x) || x == S21_INF || x == -S21_INF) {
    result = x == S21_INF || x == -S21_INF ? S21_INFL : S21_NANL;
  } else {
    result = !x ? 0 : (x < 0) ? -x : x;
  }
  return result;
}