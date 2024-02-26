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
                    --exp;
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
    
    do {
        n = ni;
        ni = (n + (x / n)) / 2;
    } while (s21_abs(n - ni) >= S21_EPS);

    return n;
}

long double s21_fmod(double x, double y) {
    return (y == 0 || s21_isnan(y) || s21_isnan(x)) ? S21_NANL : s21_isinf(y) ? x : x - (long double)s21_floor(x / y) * y;
}

bool s21_isnan(double n) {
    d_bits d = {n};
    return d.bits == 18444492273895866368;
}

bool s21_isinf(double n) {
    return n == S21_INF;
}