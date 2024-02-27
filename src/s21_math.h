#ifndef S21_MATH_H
#define S21_MATH_H

#include <stdbool.h>

#include <math.h>   // УДАЛИТЬ ПЕРЕД СДАЧЕЙ
#include <stdio.h>

#define S21_PI 3.1415926535897932384626433832795L
#define S21_double_MAX 1.7976931348623158e308
#define S21_EPS 1E-7
// #define NAN_BITS_NEG 18444492273895866368
// #define S21_NANL -(0.0l/0.0l)
// #define S21_INFL 1.0l/0.0l
// #define S21_NAN -(0.0/0.0)
// #define S21_INF 1.0/0.0
#define NAN_BITS 9221120237041090560
#define INF_BITS 9218868437227405312
#define S21_NANL __builtin_nanl ("")
#define S21_INFL __builtin_infl ()
#define S21_NAN __builtin_nan ("")
#define S21_INF __builtin_inf ()

typedef struct {
    double first;
    double second;
} pair;

typedef union {
    long double full;
    unsigned short bits[5];
} ld_bits;

typedef union {
    double full;
    unsigned long long bits;
} d_bits;

int s21_abs(int x);
long double s21_ceil(double x);
long double s21_floor(double x);
long double s21_fabs(double x);
long double s21_sqrt(double x);
long double s21_pow(double base, double exp);
long double s21_exp(double x);
long double s21_log(double x);
long double s21_fmod(double x, double y);

bool s21_isnan(double n);
bool s21_isinf(double n);
bool s21_isnormal(double n);

long double s21_sin(double x);
long double s21_cos(double x);
long double s21_tan(double x);
long double s21_asin(double x);
long double s21_acos(double x);
long double s21_atan(double x);

#endif