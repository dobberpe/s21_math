#include "s21_math.h"

long double s21_sqrt(double x) {
  long double n, ni = 1;

  if (x < 0 || s21_isnan(-x))
    n = -S21_NANL;
  else if (s21_isinf(x))
    n = S21_INFL;
  else if (s21_isnan(x))
    n = S21_NANL;
  else {
    do {
      n = ni;
      ni = (n + (x / n)) / 2;
    } while (precision_check(n, ni, true));
  }

  return n;
}