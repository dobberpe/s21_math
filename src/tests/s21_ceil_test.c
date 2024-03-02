#include "s21_math_test.h"

START_TEST(s21_ceil_fn) {
    ck_assert_ldouble_eq_tol(s21_ceil(-0.1), ceil(-0.1), 1e-07);
    ck_assert_ldouble_eq_tol(s21_ceil(-2.8), ceil(-2.8), 1e-07);
    ck_assert_ldouble_eq_tol(s21_ceil(5.3), ceil(5.3), 1e-07);
    ck_assert_ldouble_eq_tol(s21_ceil(50726), ceil(50726), 1e-07);
    ck_assert_ldouble_eq_tol(s21_ceil(-0.0), ceil(-0.0), 1e-07);
    ck_assert_ldouble_eq_tol(s21_ceil(0.0), ceil(0.0), 1e-07);
    ck_assert_ldouble_eq_tol(s21_ceil(S21_double_MAX), ceil(S21_double_MAX), 1e-07);
    ck_assert_ldouble_eq_tol(s21_ceil(S21_double_MIN), ceil(S21_double_MIN), 1e-07);
    ck_assert_ldouble_eq_tol(s21_ceil(1.7e-308), ceil(1.7e-308), 1e-07);
}
END_TEST

START_TEST(s21_ceil_inf) {
  ck_assert_ldouble_eq(s21_ceil(S21_INF), ceil(S21_INF));
}
END_TEST

START_TEST(s21_ceil_inf_negative) {
  ck_assert_ldouble_eq(s21_ceil(-S21_INF), ceil(-S21_INF));
}
END_TEST

START_TEST(s21_ceil_nan) {
  ld_bits check = {ceil(S21_NAN)};
  ld_bits result = {s21_ceil(S21_NAN)};
  for (int i = 0; i < 5; ++i)  ck_assert_uint_eq(check.bits[i], result.bits[i]);
}
END_TEST

START_TEST(s21_ceil_nan_negative) {
  ld_bits check = {ceil(-S21_NAN)};
  ld_bits result = {s21_ceil(-S21_NAN)};
  for (int i = 0; i < 5; ++i)  ck_assert_uint_eq(check.bits[i], result.bits[i]);
}
END_TEST

Suite *s21_ceil_cases(void) {
  Suite *c = suite_create("s21_ceil_cases");
  TCase *tc = tcase_create("s21_ceil_tc");

  tcase_add_test(tc, s21_ceil_fn);
  tcase_add_test(tc, s21_ceil_inf);
  tcase_add_test(tc, s21_ceil_nan);
  tcase_add_test(tc, s21_ceil_nan_negative);

  suite_add_tcase(c, tc);

  return c;
}