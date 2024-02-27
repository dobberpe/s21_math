#include "s21_math.h"

pair s21_factorial(int n) {
  pair result;
  if (n == 0) {
    result.first = 1;
    result.second = 1;
  } else {
    pair tmp = s21_factorial(n - 1);
    result.first = tmp.second;
    result.second = tmp.first + tmp.second;
  }

  return result;
}

long double s21_pow(double base, double exp) {
  long double result = 1;

  if (exp) {
    if (!s21_fmod(exp, 1)) {
      while (exp) {
        if (s21_fmod(exp, 2)) {
          result = exp < 0 ? result / base : result * base;
          exp += exp < 0 ? 1 : -1;
        } else {
          base *= base;
          exp /= 2;
        }
      }
    } else {
      result = s21_exp(exp * s21_log(base));
    }
  }

  return result;
}

long double s21_sqrt(double x) {
  long double n, ni = 1;

  if (x < 0 || s21_isnan(-x))
    n = -S21_NANL;
  else if (s21_isinf(x))
    n = S21_INFL;
  else if (s21_isnan(x))
    n = S21_NANL;
  else {
    do {
      n = ni;
      ni = (n + (x / n)) / 2;
    } while (s21_abs(n - ni) >= S21_EPS);
  }

  return n;
}

long double s21_fmod(double x, double y) {
  return (y == 0 || s21_isnan(y) || s21_isnan(x)) ? S21_NANL
         : s21_isinf(y)                           ? x
                        : x - (long double)s21_floor(x / y) * y;
}

bool s21_isnan(double n) {
  d_bits d = {n};
  return d.bits == NAN_BITS;
}

bool s21_isinf(double n) { return n == S21_INF; }

long double s21_sin(double x) {
  x += -(int)(x / (2 * S21_PI)) * (2 * S21_PI);
  int n = 0;
  long double sum = 0, sign = 1.0, pow = x, fact = 1.0;
  while (n < 50) {
    sum += sign * pow / fact;
    sign = -sign;
    pow *= x * x;
    n++;
    fact *= (n * 2) * (n * 2 + 1);
  }
  return sum;
}

long double s21_cos(double x) {
  x += -(int)(x / (2 * S21_PI)) * (2 * S21_PI);
  int n = 0;
  long double sum = 0, sign = 1.0, pow = 1.0, fact = 1.0;
  while (n < 50) {
    sum += sign * pow / fact;
    sign = -sign;
    pow *= x * x;
    n++;
    fact *= (n * 2) * (n * 2 - 1);
  }
  return sum;
}

long double s21_tan(double x) { return s21_sin(x) / s21_cos(x); }

long double s21_atan(double x) {
  double sign = -1;
  long double arctn = 0;

  if (x == S21_INF) {
    arctn = S21_PI / 2;

  } else if (x == S21_INFL) {
    arctn = -S21_PI / 2;

  } else if (s21_fabs(x) >= 1) {
    for (int i = 0; i < 1000; i++) {
      arctn += (s21_pow(sign, i) * s21_pow(x, (-1 - 2 * i))) / (1 + 2 * i);
    }
    arctn = S21_PI * s21_fabs(x) / (2 * x) - arctn;

  } else if (s21_fabs(x) == 1) {
    // arctn = (x == 1.0) ? S21_PI / 4.0 : S21_PI / 4.0 * (-1);
    arctn = 0.78539816339744795 * (x < 0 ? -1.0 : 1.0);

  } else {
    for (int i = 1; i < 10000; i++) {
      arctn += s21_pow(sign, i - 1) * s21_pow(x, 2 * i - 1) / (2 * i - 1);
    }
  }

  return arctn;
}

long double s21_asin(double x) {
  long double arcsin = S21_NAN;

  if (s21_fabs(x) == 1) {
    arcsin = (x == 1.0 ? S21_PI / 2.0 : S21_PI / 2.0 * (-1));

  } else if (s21_fabs(x) < 1) {
    arcsin = s21_atan(x / sqrt(1 - x * x));
  }

  return arcsin;
}

long double s21_acos(double x) {
  long double arccos = S21_NAN;

  if (x == 1) {
    arccos = 0;

  } else if (x == -1) {
    arccos = S21_PI;

  } else if (x < 1 && x >= 0) {
    arccos = s21_atan(s21_sqrt(1 - x * x) / x);

  } else if (x < 0 && x >= -1) {
    arccos = S21_PI + s21_atan(s21_sqrt(1 - x * x) / x);
  }

  return arccos;
}
