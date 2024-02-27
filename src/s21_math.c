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
    
    if (x < 0 || s21_isnan(-x)) n = S21_NANL_NEG;
    else if (s21_isinf(x)) n = S21_INFL;
    else if (s21_isnan(x)) n = -S21_NANL_NEG;
    else {
        do {
            n = ni;
            ni = (n + (x / n)) / 2;
        } while (s21_abs(n - ni) >= S21_EPS);
    }

    return n;
}

long double s21_fmod(double x, double y) {
    return (y == 0 || s21_isnan(y) || s21_isnan(x)) ? -S21_NANL_NEG : s21_isinf(y) ? x : x - (long double)s21_floor(x / y) * y;
}

bool s21_isnan(double n) {
    d_bits d = {n};
    return d.bits == NAN_BITS;
}

bool s21_isinf(double n) {
    return n == S21_INF;
}

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

long double s21_tan(double x) {
    return s21_sin(x) / s21_cos(x);
}

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
  if (x != x || x == S21_INF || x == -S21_INF) {
    result = (x != x) ? -S21_NANL_NEG : S21_INFL;
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
  if (x <= 0.0) {
    return -S21_INFL;
  }
  if (x == 1.0) {
    return 0.0;
  }
  if (x < 1.0) {
    x = 1 / x;
    return -s21_log(x);
  }
  long double result = 0.0;
  long double term = (x - 1.0) / (x + 1.0);
  long double term_squared = term * term;
  long double current_term = term;
  long double power = 1.0;
  for (int i = 0; i < 100; i++) {
    result += current_term / power;
    current_term *= term_squared;
    power += 2.0;
  }
  return 2 * result;
}
