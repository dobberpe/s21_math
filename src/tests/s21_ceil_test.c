#include "s21_math_test.h"

START_TEST(s21_ceil_fn) {
    ck_assert_ldouble_eq_tol(s21_ceil(-0.1), ceil(-0.1), 1e-07);
    ck_assert_ldouble_eq_tol(s21_ceil(-2.8), ceil(-2.8), 1e-07);
    ck_assert_ldouble_eq_tol(s21_ceil(5.3), ceil(5.3), 1e-07);
    ck_assert_ldouble_eq_tol(s21_ceil(50726), ceil(50726), 1e-07);
    ck_assert_ldouble_eq_tol(s21_ceil(-0.0), ceil(-0.0), 1e-07);
    ck_assert_ldouble_eq_tol(s21_ceil(0.0), ceil(0.0), 1e-07);
    ck_assert_ldouble_eq_tol(s21_ceil(1.7e+308), ceil(1.7e+308), 1e-07);
    ck_assert_ldouble_eq_tol(s21_ceil(1.7e-308), ceil(1.7e-308), 1e-07);
    ck_assert_ldouble_eq(s21_ceil(INFINITY), ceil(INFINITY));
    ck_assert_ldouble_eq(s21_ceil(-INFINITY), ceil(-INFINITY));
    ck_assert_ldouble_eq(s21_ceil(NAN), ceil(NAN));
    ck_assert_ldouble_eq(s21_ceil(-NAN), ceil(-NAN));
}
END_TEST