#include "../s21_math.h"

// #define S21_EPS 1e-200
// #define S21_PI 3.1415926535897932
// #define S21_EXP 2.7182818284590452
// #define S21_MAX 1e100
// #define S21_S21_NAN (__builtin_nanf(""))
// #define S21_INF 1.0 / 0.0L
// #define -S21_INF -1.0 / 0.0L
// #define isS21_NAN(x) (x != x)
// #define isS21_INF(x) (x == S21_INF)
// #define is-S21_INF(x) (x == -S21_INF)
// #define isNormal(x) (!isS21_NAN(x) && !is-S21_INF(x) && !isS21_INF(x))

double cases_pow_zeros[][2] = {{0, 5},        {0, -5},      {0, S21_NAN},
                               {0, -S21_NAN},     {0, 0},       {0, -S21_INF},
                               {-1, S21_INF}, {-1, -S21_INF}};

double cases_pow_exp[][2] = {{1, S21_NAN}, {1, S21_INF}, {1, 0},  {1, -5},  {1, 5},
                             {1, 1.5}, {-1, 3},      {-1, 2}, {-1, 1.5}};

double cases_pow_base[][2] = {{S21_NAN, 0}, {S21_INF, 0}, {5, 0}};

double cases_pow_base_fractional[][2] = {
    {0.1, S21_INF}, {-0.1, S21_INF}, {0.1, -S21_INF}, {-0.1, -S21_INF},
    {5, S21_INF},   {-5, S21_INF},   {5, -S21_INF},   {-5, -S21_INF}};

double cases_pow_INF_exp[][2] = {
    {S21_INF, 0}, {S21_INF, 5}, {S21_INF, S21_INF}, {S21_INF, S21_NAN},
    {-S21_INF, 0}, {-S21_INF, 5}, {-S21_INF, S21_INF}, {-S21_INF, S21_NAN},
};

double cases_pow_S21_NAN[][2] = {{S21_NAN, S21_NAN}, {S21_NAN, -S21_NAN}, {-S21_NAN, -S21_NAN}};
double cases_pow_usual[][2] = {{5, S21_NAN}, {5, -S21_NAN}, {5, S21_INF}, {5, -S21_INF}};

double cases_pow_return_nan[][2] = {
    {0.00, S21_NAN},  {S21_INF, S21_NAN}, {-S21_INF, S21_NAN}, {S21_NAN, S21_NAN},    {S21_NAN, -S21_NAN},
    {-S21_NAN, -S21_NAN}, {0.00, -S21_NAN},   {0.00, -S21_NAN},   {-1.00, 1.50}, {-S21_NAN, -S21_NAN}};

double cases_pow_return_inf[][2] = {
    {0.00, -5.00},    {0.00, -S21_INF},    {0.10, -S21_INF},
    {-0.10, -S21_INF}, {5.00, S21_INF},    {-5.00, S21_INF},
    {S21_INF, 5.00},  {S21_INF, S21_INF}, {-S21_INF, S21_INF}};

double cases_pow_return_one[][2] = {
    {-1.00, S21_INF}, {-1.00, -S21_INF}, {1.00, S21_NAN},     {1.00, S21_INF},
    {1.00, 0.00},     {1.00, -5.00},    {1.00, 5.00},    {1.00, 1.50},
    {-1.00, 2.00},    {S21_NAN, 0.00},      {S21_INF, 0.00}, {5.00, 0.00},
    {-S21_INF, 0.00}};

// pow(0.00, 5.00)->0.00
// pow(0.00, -5.00)->S21_INF //
// pow(0.00, S21_NAN)->S21_NAN  //
// pow(0.00, -S21_NAN)->-S21_NAN //
// pow(0.00, 0.00)->1.00
// pow(0.00, -S21_INF)->S21_INF //
// pow(-1.00, S21_INF)->1.00 //
// pow(-1.00, -S21_INF)->1.00 //
// END

// pow(1.00, S21_NAN)->1.00 // 55
// pow(1.00, S21_INF)->1.00 // 55
// pow(1.00, 0.00)->1.00 // 55
// pow(1.00, -5.00)->1.00 // 55
// pow(1.00, 5.00)->1.00 // 55
// pow(1.00, 1.50)->1.00 // 55
// pow(-1.00, 3.00)->-1.00
// pow(-1.00, 2.00)->1.00 //
// pow(-1.00, 1.50)->-S21_NAN //
// END

// pow(S21_NAN, 0.00)->1.00 //
// pow(S21_INF, 0.00)->1.00 // 33
// pow(5.00, 0.00)->1.00 //
// END

// pow(0.10, S21_INF)->0.00 22
// pow(-0.10, S21_INF)->0.00 11
// pow(0.10, -S21_INF)->S21_INF // 22
// pow(-0.10, -S21_INF)->S21_INF //11
// pow(5.00, S21_INF)->S21_INF //
// pow(-5.00, S21_INF)->S21_INF //
// pow(5.00, -S21_INF)->0.00
// pow(-5.00, -S21_INF)->0.00
// END

// pow(S21_INF, 5.00)->S21_INF // 33
// pow(S21_INF, S21_INF)->S21_INF // 33
// pow(S21_INF, S21_NAN)->S21_NAN 33
// pow(-S21_INF, 0.00)->1.00 // 44
// pow(-S21_INF, 5.00)->-S21_INF 44
// pow(-S21_INF, S21_INF)->S21_INF // 44
// pow(-S21_INF, S21_NAN)->S21_NAN// 44
// END

// pow(S21_NAN, S21_NAN)->S21_NAN //
// pow(S21_NAN, -S21_NAN)->S21_NAN //
// pow(-S21_NAN, -S21_NAN)->-S21_NAN //
// END
