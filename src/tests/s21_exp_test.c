#include "s21_math_test.h"

START_TEST(exp_fn) {
  ck_assert_ldouble_eq_tol(s21_exp(5), exp(5), S21_EPS);
  ck_assert_ldouble_eq_tol(s21_exp(-2), exp(-2), S21_EPS);
  ck_assert_ldouble_eq(s21_exp(1234567), exp(1234567)); // INF
  ck_assert_ldouble_eq_tol(s21_exp(-1234567), exp(-1234567), S21_EPS);
  for (double i = -10; i <= 10; i++) {
    ck_assert_ldouble_eq_tol(s21_exp(i), exp(i), S21_EPS);
  }
  ck_assert_ldouble_eq_tol(s21_exp(0.0), exp(0.0), S21_EPS);
  ck_assert_ldouble_eq_tol(s21_exp(1.0), exp(1.0), S21_EPS);
  ck_assert_ldouble_eq_tol(s21_exp(-1.0), exp(-1.0), S21_EPS);
  ck_assert_ldouble_eq_tol(s21_exp(10.0), exp(10.0), S21_EPS);
  ck_assert_ldouble_eq_tol(s21_exp(-10.0), exp(-10.0), S21_EPS);
  ck_assert_ldouble_eq_tol(s21_exp(-100.0), exp(-100.0), S21_EPS);
  ck_assert_ldouble_eq_tol(s21_exp(-1000.0), exp(-1000.0), S21_EPS);
  ck_assert_ldouble_eq_tol(s21_exp(0.1), exp(0.1), S21_EPS);
  ck_assert_ldouble_eq_tol(s21_exp(-0.1), exp(-0.1), S21_EPS);

  for (double i = -10000; i <= 10000; i += 1000) {
    ck_assert_double_eq(s21_exp(i), exp(i));
  }
}
END_TEST

START_TEST(s21_exp_inf) {
  // INF
  ck_assert_ldouble_eq(exp(S21_INF), s21_exp(S21_INF));
}
END_TEST

START_TEST(s21_exp_inf_negative) {
  // 0.0
  ck_assert_ldouble_eq(exp(-S21_INF), s21_exp(-S21_INF));
}
END_TEST

START_TEST(s21_exp_nan) {
  // NAN
  ld_bits check = {exp(S21_NAN)};
  ld_bits result = {s21_exp(S21_NAN)};
  for (int i = 0; i < 5; ++i)  ck_assert_uint_eq(check.bits[i], result.bits[i]);
}
END_TEST

START_TEST(s21_exp_nan_negative) {
  // -NAN
  ld_bits check = {exp(-S21_NAN)};
  ld_bits result = {s21_exp(-S21_NAN)};
  for (int i = 0; i < 5; ++i)  ck_assert_uint_eq(check.bits[i], result.bits[i]);
}
END_TEST

START_TEST(s21_exp_max_double) {
  // INF
  ck_assert_double_eq(exp(S21_double_MAX), s21_exp(S21_double_MAX));
}
END_TEST

START_TEST(s21_exp_min_double) {
  // 1.0
  ck_assert_ldouble_eq_tol(s21_exp(S21_double_MIN), exp(S21_double_MIN), S21_EPS);
}
END_TEST

Suite *s21_exp_cases(void) {
  Suite *c = suite_create("s21_exp_cases");
  TCase *tc = tcase_create("s21_exp_tc");

  tcase_add_test(tc, exp_fn);
  tcase_add_test(tc, s21_exp_inf);
  tcase_add_test(tc, s21_exp_inf_negative);
  tcase_add_test(tc, s21_exp_nan);
  tcase_add_test(tc, s21_exp_nan_negative);
  tcase_add_test(tc, s21_exp_max_double);
  tcase_add_test(tc, s21_exp_min_double);

  suite_add_tcase(c, tc);

  return c;
}
