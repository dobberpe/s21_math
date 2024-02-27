#include "s21_math.h"

// #define S21_double_MAX 1.7976931348623158e308

long double s21_exp(double x) {
  long double result = 1;
  long double term = 1;
  int sign = 1;
  int i = 1;
  long double prev_result = 0;
  if (x < 0) {
    x = -x;
    sign = -1;
  }
  while (s21_fabs(result - prev_result) > S21_EPS) {
    prev_result = result;
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

long double s21_fabs(double x) {
  long double result;
  if (x != x || x == S21_INFL || x == -S21_INFL) {
    result = (x != x) ? S21_NANL : S21_INFL;
  } else {
    result = (x < 0) ? -x : x;
  }
  return result;
}

long double s21_floor(double x) {
  long double result = x;
  long long int int_part = (long long int)x;
  if (x < 0.0 && result != int_part) {
    result = int_part - 1.0;
  } else {
    result = int_part;
  }

  return result;
}

long double s21_log(double x) {
  long double result;

  if (x <= 0.0) {
    result = -S21_INFL;
  } else if (x == 1.0) {
    result = 0.0;
  } else if (x < 1.0) {
    x = 1 / x;
    result = -s21_log(x);
  } else {
    result = 0.0;
    long double term = (x - 1.0) / (x + 1.0);
    long double term_squared = term * term;
    long double current_term = term;
    long double power = 1.0;

    for (int i = 0; i < 100; i++) {
      result += current_term / power;
      current_term *= term_squared;
      power += 2.0;
    }

    result = 2 * result;
  }

  return result;
}
