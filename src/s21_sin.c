#include "s21_math.h"

long double s21_sin(double x) {
  x += -(int)(x / (2 * S21_PI)) * (2 * S21_PI);
  int n = 0;
  long double sum = 0, sign = 1.0, pow = x, fact = 1.0;
  while (n < 150) {
    sum += sign * pow / fact;
    sign = -sign;
    pow *= x * x;
    n++;
    fact *= (n * 2) * (n * 2 + 1);
  }
  return sum;
}