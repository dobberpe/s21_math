#ifndef S21_MATH_H
#define S21_MATH_H

#include <stdbool.h>
#include <stdio.h>
#include <string.h>

#define S21_PI 3.1415926535897932384626433832795L
#define S21_EXP 2.718281828459045235360287471352662
#define S21_double_MAX 1.7976931348623158e308
#define S21_double_MIN 2.22507385850720138309023271733240406e-308
#define S21_EPS 1E-7
#define NAN_BITS 9221120237041090560
#define INF_BITS 9218868437227405312
#define S21_NANL __builtin_nanl("")
#define S21_INFL __builtin_infl()
#define S21_NAN __builtin_nan("")
#define S21_INF __builtin_inf()

typedef union {
  double full;
  unsigned long long bits;
} d_bits;

bool precision_check(long double value, long double check, bool extended_prec);
bool s21_isnan(double n);
bool s21_isinf(double n);

int s21_abs(int x);
long double s21_ceil(double x);
long double s21_floor(double x);
long double s21_fabs(double x);
long double s21_sqrt(double x);
long double s21_pow(double base, double exp);
long double s21_exp(double x);
long double s21_log(double x);
long double s21_fmod(double x, double y);
long double s21_sin(double x);
long double s21_cos(double x);
long double s21_tan(double x);
long double s21_asin(double x);
long double s21_acos(double x);
long double s21_atan(double x);

#endif