#include "s21_math.h"

long double s21_cos(double x) {
  x = s21_fmod(x, S21_PI * 2);
  int n = 0;
  long double sum = 0, sign = 1.0, pow = 1.0, fact = 1.0;
  while (n < 150) {
    sum += sign * pow / fact;
    sign = -sign;
    pow *= x * x;
    n++;
    fact *= (n * 2) * (n * 2 - 1);
  }
  return sum;
}
