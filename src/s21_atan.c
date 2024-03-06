#include "s21_math.h"

long double s21_atan(double x) {
  double sign = 1;
  long double arctn = 0, iks = x;

  if (x == S21_INF) {
    arctn = S21_PI / 2;

  } else if (x == -S21_INF) {
    arctn = -S21_PI / 2;

  } else if (s21_fabs(x) >= 1.7976931348623158e307) {
    arctn = (S21_PI / 2 - arctn) * (x < 0 ? -1 : 1);

  } else if (s21_fabs(x) > 1) {
    arctn = 1 / iks;
    for (int i = 1; i < 1000000; i++) {
      sign *= -1;
      iks *= x * x;
      arctn += sign / (iks * (1 + 2 * i));
    }

    arctn = S21_PI * s21_fabs(x) / (2 * x) - arctn;

  } else if (s21_fabs(x) == 1) {
    arctn = (x == 1.0) ? S21_PI / 4.0 : S21_PI / 4.0 * (-1);

  } else {
    sign = 1;
    iks = x;
    arctn = x;

    for (int i = 2; i < 1000000; i++) {
      sign *= -1;
      iks *= x * x;
      arctn += sign * (iks / (2 * i - 1));
    }
  }

  return arctn;
}