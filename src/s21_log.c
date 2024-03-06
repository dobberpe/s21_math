#include "s21_math.h"

long double s21_log(double x) {
  int power = 0;
  long double result = 0.;
  long double term = 0.;
  if (s21_isnan(x) || s21_isnan(-x)) {
    result = x;
  } else if (x == S21_INF) {
    result = S21_INF;
  } else if (x == -S21_INF) {
    result = -S21_NANL;
  } else if (x == 0.) {
    result = -S21_INFL;
  } else if (x < 0.) {
    result = -S21_NANL;
  } else {
    do {
      term = result;
      result = term + 2 * ((x - s21_exp(term)) / (x + s21_exp(term)));
    } while (precision_check(result, term, true));
  }
  return (result + power);
}