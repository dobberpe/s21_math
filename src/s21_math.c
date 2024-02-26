#include <math.h>
#include <stdio.h>

#define S21_PI 3.1415926535897932384626433832795L

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

// int main() {
//     double x = 1.90941;
//     printf("%.20lf\n", sin(x));
//     printf("%.20Lf\n", s21_sin(x));
//     printf("%.20lf\n", cos(x));
//     printf("%.20Lf\n", s21_cos(x));
//     printf("%.20lf\n", tan(x));
//     printf("%.20Lf\n", s21_tan(x));
//     return 0;
// }