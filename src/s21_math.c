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
