#include "s21_math.h"

// pair s21_factorial(int n) {
//   pair result;
//   if (n == 0) {
//     result.first = 1;
//     result.second = 1;
//   } else {
//     pair tmp = s21_factorial(n - 1);
//     result.first = tmp.second;
//     result.second = tmp.first + tmp.second;
//   }

//   return result;
// }

bool precision_check(long double value, long double check, bool extended_prec) {
  char buf1[512] = {0};
  char buf2[512] = {0};
  if (value >= 10000000000) {
    sprintf(buf1, "%.*Le", extended_prec ? 18 : 16, value);
    sprintf(buf2, "%.*Le", extended_prec ? 18 : 16, check);
  } else {
    sprintf(buf1, "%.*Lf", extended_prec ? 9 : 7, value);
    sprintf(buf2, "%.*Lf", extended_prec ? 9 : 7, check);
  }
  // printf("\n%s\n%s\n", buf1, buf2);
  return strcmp(buf1, buf2);
}

// #include <math.h>

long double s21_pow(double base, double exp) {
  long double result = 1;

  if (!exp)
    result = 1;
  else if (s21_isnan(base) || s21_isnan(-base))
    result = !s21_fmod(exp, 2) ? s21_fabs(base) : base;
  else if (base == 1 || (base == -1 && !s21_fmod(exp, 2)) ||
           (base == -1 && s21_isinf(s21_fabs(exp))))
    result = 1;
  else if ((s21_isinf(s21_fabs(base)) && exp > 0 && exp != 1) ||
           (s21_isinf(exp) && base && s21_fabs(base) > 1) || (s21_isinf(-exp) && base && s21_fabs(base) < 1))
    result = S21_INFL;
  else if (s21_isinf(-base) && exp < 0 && !s21_fmod(exp, 1) && s21_fmod(exp, 2))
    result = -0.0;
  else if ((s21_isinf(s21_fabs(base)) && exp < 0) ||
           (s21_isinf(-exp) && base && s21_fabs(base) > 1) || (s21_isinf(exp) && base && s21_fabs(base) < 1))
    result = 0;
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
    } else
      result = s21_exp(exp * s21_log(base));
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
    } while (precision_check(n, ni, true));
  }

  return n;
}

// long double s21_sqrt(double x) {
//     return s21_pow(x, 0.5);
// }

long double s21_fmod(double x, double y) {
  long double result =
      s21_isnan(x) || s21_isnan(-x)                              ? x
      : s21_isnan(y)                                             ? S21_NANL
      : s21_isnan(-y) || x == S21_INF || -x == S21_INF || y == 0 ? -S21_NANL
      : s21_isinf(y) || s21_isinf(-y) || s21_fabs(x) < s21_fabs(y)
          ? x
          : (x) - s21_floor(s21_fabs(x / y)) * (x / y < 0 ? -1 : 1) * y;
  // printf("%f - s21_floor(%f / %f) * %f\n", x, x, y, y);
  // printf("%f - s21_floor(%f) * %f\n", x, x / y, y);
  // printf("%f - %Lf * %f\n", x, s21_floor(x / y), y);
  // printf("%f - %Lf\n", x, s21_floor(x / y) * y);
  result = !result && x < 0 ? -0.0 : result;
  return result;
}

bool s21_isnan(double n) {
  d_bits d = {n};
  return d.bits == NAN_BITS;
}

bool s21_isinf(double n) {
  d_bits d = {n};
  return d.bits == INF_BITS;
}

// bool s21_isnan(double n) {
//   return n != n;
// }

// bool s21_isinf(double n) {
//   return !s21_isnan(n) && s21_isnan(n - n);
// }

bool s21_isnormal(double n) {
  return n != S21_INF && !s21_isnan(n) && !s21_isnan(-n);
}

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

long double s21_cos(double x) {
  x += -(int)(x / (2 * S21_PI)) * (2 * S21_PI);
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

long double s21_tan(double x) { return s21_sin(x) / s21_cos(x); }

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

// long double s21_atan(double x) {
//   double sign = 1;
//   long double arctn = 0;

//   if (x == S21_INF) {
//     arctn = S21_PI / 2;

//   } else if (x == -S21_INF) {
//     arctn = -S21_PI / 2;

//   } else if (s21_fabs(x) > 1) {
//     long double iks = x;
//     arctn = 1 / iks;

//     for (int i = 1; i < 1000000; i++) {
//       sign *= -1;
//       iks *= x * x;
//       arctn += sign / (iks * (1 + 2 * i));
//     }

//     arctn = S21_PI * s21_fabs(x) / (2 * x) - arctn;

//   } else if (s21_fabs(x) == 1) {
//     arctn = (x == 1.0) ? S21_PI / 4.0 : S21_PI / 4.0 * (-1);

//   } else {
//     sign = 1;
//     long double iks = x;
//     arctn = x;

//     for (int i = 2; i < 1000000; i++) {
//       sign *= -1;
//       iks *= x * x;
//       arctn += sign * (iks / (2 * i - 1));
//     }
//   }

//   return arctn;
// }


// long double s21_atan(double x) {
//   double sign = 1;
//   double iks = x;
//   long double arctn = 0;

//   if (x <= 0) {
//     iks *= -1;
//     sign *= -1;
//   }

//   if (s21_fabs(x) == 1) {
//     arctn = (x == 1.0) ? S21_PI / 4.0 : S21_PI / 4.0 * (-1);

//   } else {
//     if (s21_fabs(x) > 1) iks = 1 / s21_fabs(x);

//     for (int i = 2; i < 1000; i++) {
//       arctn += s21_pow(-1, i - 1) * (s21_pow(iks, 2 * i - 1) / (2 * i - 1));
//     }

//     if (s21_fabs(x) > 1) arctn = sign *(S21_PI / 2 - arctn);
//   }

//   // if (s21_fabs(x) != 1) {
//   //   arctn *= sign;
//   // }

//   return arctn;
// }

long double s21_asin(double x) {
  return (x > 1 || x < -1)  ? S21_NAN
         : s21_fabs(x) == 1 ? (x == 1.0 ? S21_PI / 2.0 : S21_PI / 2.0 * (-1))
                            : s21_atan(x / s21_sqrt(1 - x * x));
}

long double s21_acos(double x) {
  return (x > 1 || x < -1)  ? S21_NAN
         : s21_fabs(x) == 1 ? (x == 1.0 ? 0 : S21_PI)
         : x >= 0 && x < 1  ? s21_atan(s21_sqrt(1 - x * x) / x)
                            : S21_PI + s21_atan(s21_sqrt(1 - x * x) / x);
}

long double s21_exp(double x) {
  long double result = 1;
  long double term = 1;
  int sign = 1;
  int i = 1;
  // long double prev_result = 0;
  if (x < 0) {
    x = -x;
    sign = -1;
  }
  // while (s21_fabs(result - prev_result) > S21_EPS) {
  while (s21_fabs(term) > 1e-200 && !s21_isinf(result)) {
  // while (precision_check(result, prev_result, true)) {
    // prev_result = result;
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
  if (s21_isnan(x) || s21_isnan(-x) || x == S21_INF || x == -S21_INF) {
    result = x == S21_INF || x == -S21_INF ? S21_INFL : S21_NANL;
  } else {
    result = !x ? 0 : (x < 0) ? -x : x;
  }
  return result;
}

long double s21_floor(double x) {
  long double result;
  d_bits d = {x};
  if (s21_isnan(x) || s21_isnan(-x)) {
    result = x;
  } else if (x == S21_INF) {
    result = S21_INFL;
  } else if (x == -S21_INF) {
    result = -S21_INFL;
  } else if ((int)((d.bits << 1) >> 53) - 1023 > 51) {
    result = (long double)x;
  } else {
    long long int int_part = (long long int)x;
    result = (x - int_part != 0 && x < 0) ? int_part - 1 : int_part;
  }
  return result;
}

long double s21_log(double x) {
  int power = 0;
  long double result = 0.;
  long double term = 0.;
  if (s21_isnan(x) || s21_isnan(-x)) {
    result = x;
  } else if (x == S21_INF) {
    result = S21_INF;
  } else if (x == -S21_INF) {
    result = -S21_NANL;
  } else if (x == 0.) {
    result = -S21_INFL;
  } else if (x < 0.) {
    result = -S21_NANL;
  } else {
    // do {
    //   term = result;
    //   result = term + 2 * ((x - s21_exp(term)) / (x + s21_exp(term)));
    // } while (precision_check(result, term, true));
    // for (; x >= S21_EXP; x /= S21_EXP, power++) continue;
    for (int i = 0; i < 500; ++i) {
      term = result;
      result = term + 2 * (x - s21_exp(term)) / (x + s21_exp(term));
    }
  }
  return (result + power);
}

int s21_abs(int x) { return (x < 0) ? -x : x; }

long double s21_ceil(double x) {  // if exp > 52 ? result = x
  long double result = 0.0;
  // printf("", );
  // d_bits d = {x};
  // ((d.bits << 1) >> 53) - 1023 > 51
  if (x == S21_INF || x == -S21_INF || s21_isnan(x) || s21_isnan(-x) ||
      !s21_fmod(x, 1))
    result = x;
  else {
    result = s21_floor(x) + 1;
    result *= result == 0 && x < 0 ? -1 : 1;
    // long long int integer_part = (long long int)x;
    // result = (long double)integer_part;
    // if (x > 0.0 && x != integer_part) result += 1.0;
    // if (x < 0.0 && result == 0) result *= -1.0;
  }
  return result;
}
