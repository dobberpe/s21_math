#include "s21_math.h"

long double s21_acos(double x) {
  return (x > 1 || x < -1)  ? S21_NAN
         : s21_fabs(x) == 1 ? (x == 1.0 ? 0 : S21_PI)
         : x >= 0 && x < 1  ? s21_atan(s21_sqrt(1 - x * x) / x)
                            : S21_PI + s21_atan(s21_sqrt(1 - x * x) / x);
}