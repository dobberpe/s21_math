#include "s21_math.h"

long double s21_asin(double x) {
  return (x > 1 || x < -1)  ? S21_NAN
         : s21_fabs(x) == 1 ? (x == 1.0 ? S21_PI / 2.0 : S21_PI / 2.0 * (-1))
                            : s21_atan(x / s21_sqrt(1 - x * x));
}