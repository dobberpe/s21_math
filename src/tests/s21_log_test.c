#include "s21_math_test.h"

START_TEST(log_fn) {
  ck_assert_ldouble_eq_tol(s21_log(1.1), log(1.1), S21_EPS);
  for (double i = 1.; i < 10; i += 0.1) {
    // printf("\n%f\n\n", i);
    ck_assert_ldouble_eq_tol(s21_log(i), log(i), S21_EPS);
  }
  for (double i = 0.1; i < 2; i += 0.01) {
    ck_assert_ldouble_eq_tol(s21_log(i), log(i), S21_EPS);
  }
}
END_TEST

START_TEST(log_fn_comparison) {
  double x = 3.14;
  long double result_s21 = s21_log(x);
  long double result_standard = log(x);
  ck_assert(fabsl(result_s21 - result_standard) < S21_EPS);
}
END_TEST

START_TEST(log_fn_extra) {
  ck_assert_ldouble_eq_tol(s21_log(2.0), log(2.0), S21_EPS);
  for (double i = 1.; i < 10; i += 1.0) {
    ck_assert_ldouble_eq_tol(s21_log(i), log(i), S21_EPS);
  }
  for (double i = 10.; i < 100; i += 10.0) {
    ck_assert_ldouble_eq_tol(s21_log(i), log(i), S21_EPS);
  }
}
END_TEST

START_TEST(s21_log_negative) {
  // -NAN
  ld_bits check = {log(-2)};
  ld_bits result = {s21_log(-2)};
  // printf("\n%Lf\n%Lf\n\n", result.full, check.full);
  for (int i = 0; i < 5; ++i) ck_assert_ldouble_eq(check.bits[i], result.bits[i]);
}
END_TEST

START_TEST(s21_log_zero) {
  // -INF
  ck_assert_ldouble_eq(log(0.), s21_log(0.));
}
END_TEST

START_TEST(s21_log_inf) {
  // INF
  ck_assert_ldouble_eq(log(INFINITY), s21_log(INFINITY));
}
END_TEST

START_TEST(s21_log_inf_negative) {
  // -NAN
  ld_bits check = {log(-INFINITY)};
  ld_bits result = {s21_log(-INFINITY)};
  for (int i = 0; i < 5; ++i)  ck_assert_ldouble_eq(check.bits[i], result.bits[i]);
}
END_TEST

START_TEST(s21_log_nan) {
  // NAN
  ld_bits check = {log(NAN)};
  ld_bits result = {s21_log(NAN)};
  for (int i = 0; i < 5; ++i)  ck_assert_ldouble_eq(check.bits[i], result.bits[i]);
}
END_TEST

START_TEST(s21_log_nan_negative) {
  // -NAN
  ld_bits check = {log(-NAN)};
  ld_bits result = {s21_log(-NAN)};
  for (int i = 0; i < 5; ++i)  ck_assert_ldouble_eq(check.bits[i], result.bits[i]);
}
END_TEST

Suite *s21_log_cases(void) {
  Suite *c = suite_create("s21_log_cases");
  TCase *tc = tcase_create("s21_log_tc");

  tcase_add_test(tc, log_fn);
  tcase_add_test(tc, log_fn_comparison);
  tcase_add_test(tc, log_fn_extra);
  tcase_add_test(tc, s21_log_negative);
  tcase_add_test(tc, s21_log_zero);
  tcase_add_test(tc, s21_log_inf);
  tcase_add_test(tc, s21_log_inf_negative);
  tcase_add_test(tc, s21_log_nan);
  tcase_add_test(tc, s21_log_nan_negative);

  suite_add_tcase(c, tc);

  return c;
}
