#include "s21_math.h"

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
           (s21_isinf(exp) && base && s21_fabs(base) > 1) ||
           (s21_isinf(-exp) && base && s21_fabs(base) < 1))
    result = S21_INFL;
  else if (s21_isinf(-base) && exp < 0 && !s21_fmod(exp, 1) && s21_fmod(exp, 2))
    result = -0.0;
  else if ((s21_isinf(s21_fabs(base)) && exp < 0) ||
           (s21_isinf(-exp) && base && s21_fabs(base) > 1) ||
           (s21_isinf(exp) && base && s21_fabs(base) < 1))
    result = 0;
  else {
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