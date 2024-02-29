#include "s21_math.h"

bool s21_isnan(double n) {
  d_bits d = {n};
  return d.bits == NAN_BITS;
}

bool s21_isinf(double n) {
  d_bits d = {n};
  return d.bits == INF_BITS;
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
    result = (x != x) ? S21_NANL : S21_INFL;
  } else {
    result = (x < 0) ? -x : x;
  }
  return result;
}
long double s21_pow(double base, double exp) {
  long double result = 1;

  if (!exp) result = 1;
  else if (s21_isnan(base) || s21_isnan(-base)) result = !s21_fmod(exp, 2) ? s21_fabs(base) : base;
  else if (base == 1 || (base == -1 && !s21_fmod(exp, 2)) || (base == -1 && s21_isinf(s21_fabs(exp)))) result = 1;
  else if ((s21_isinf(s21_fabs(base)) && exp > 1) || (s21_isinf(exp) && base && s21_fabs(base) != 1)) result = S21_INFL;
  else if ((s21_isinf(s21_fabs(base)) && exp < 0) || (s21_isinf(-exp) && base && s21_fabs(base) != 1)) result = 0;
  else if (exp) {
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

long double s21_fmod(double x, double y) {
  return s21_isnan(x) || s21_isnan(-x) ? x : s21_isnan(y) ? S21_NANL : s21_isnan(-y) || x == S21_INF || -x == S21_INF || y == 0 ? -S21_NANL : s21_isinf(y) || s21_isinf(-y) ? x : x - (long double)s21_floor(x / y) * y;
}

// long double s21_floor(double x) {
//   long double result = x;
//
//   if (s21_isnan(x) || s21_isinf(x)) {
//     return x;
//   }
//   long long int int_part = (long long int)x;
//   if (result < 0 && 1.0/result == 0.0) {
//     return -S21_INF;
//   }
//   if (x < 0.0 && result != int_part) {
//     result = int_part - 1.0;
//   } else {
//     result = int_part;
//   }
//
//   return result;
// }

long double s21_floor(double x) {
  long double result;
  if (x != x) {
    result =  x;
  } else if (x == S21_INF) {
    result = S21_INF;
  } else if (x == -S21_INF) {
    result = -S21_INF;
  } else {
    long long int int_part = (long long int)x;
    result = (x - int_part != 0 && x < 0) ? int_part - 1 : int_part;
  }
  return result;
}

// #define S21_EXP 2.718281828459045235360287471352662

long double s21_log(double x) {
    int power = 0;
    long double result = 0.;
    long double term = 0;

    if (x != x) {
        result = x;
    } else if (x == S21_INF) {
        result = S21_INF;
    } else if (x == -S21_INF) {
        result = -S21_INF;
    } else if (x <= 0.) {
        result = -S21_INF;
    } else if (x != 0) {
for (; x >= S21_EXP; x /= S21_EXP, power++) continue;
        for (int i = 0; i < 100; i++) {
            term = result;
            result = term + 2 * (x - s21_exp(term)) / (x + s21_exp(term));
        }
    } else {
        result = -S21_INF;
    }
    return (result + power);
}


