#include "s21_math.h"

long double s21_exp(double x) {
  long double result = 1;
  long double term = 1;
  int sign = 1;
  int i = 1;
  if (x < 0) {
    x = -x;
    sign = -1;
  }
  while (s21_fabs(term) > 1e-200 && !s21_isinf(result)) {
    term *= x / i;
    i++;
    result += term;
  }
  if (sign == -1) {
    result = 1 / result;
  }
  if (result > S21_double_MAX) {
    result = S21_INFL;
  }
  return result;
}