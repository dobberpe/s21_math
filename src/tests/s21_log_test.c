#include "s21_math_test.h"

START_TEST(log_fn) {
  ck_assert_uint_eq(s21_log(1.1), log(1.1));
  for (double i = -1.; i < 10; i += 0.1) {
    ck_assert_uint_eq(s21_log(i), log(i));
  }
  for (double i = 0.; i < 2; i += 0.01) {
    ck_assert_uint_eq(s21_log(i), log(i));
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
  ck_assert_uint_eq(s21_log(2.0), log(2.0));
  for (double i = -10.; i < 10; i += 1.0) {
    ck_assert_uint_eq(s21_log(i), log(i));
  }
  for (double i = -100.; i < 100; i += 10.0) {
    ck_assert_uint_eq(s21_log(i), log(i));
  }
}
END_TEST

Suite *s21_log_cases(void) {
  Suite *c = suite_create("s21_log_cases");
  TCase *tc = tcase_create("s21_log_tc");

  tcase_add_test(tc, log_fn);
  tcase_add_test(tc, log_fn_comparison);
  tcase_add_test(tc, log_fn_extra);

  suite_add_tcase(c, tc);

  return c;
}
