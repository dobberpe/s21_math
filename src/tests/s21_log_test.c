#include "s21_math_test.h"

START_TEST(log_fn) {
  ck_assert(!precision_check(s21_log(1.1), log(1.1), false));
  for (double i = 1.; i < 10; i += 0.1) {
    ck_assert(!precision_check(s21_log(i), log(i), false));
  }
  for (double i = 0.1; i < 2; i += 0.01) {
    ck_assert(!precision_check(s21_log(i), log(i), false));
  }
}
END_TEST

START_TEST(log_fn_comparison) {
  ck_assert(!precision_check(s21_log(3.14), log(3.14), false));
}
END_TEST

START_TEST(log_fn_extra) {
  ck_assert(!precision_check(s21_log(2.0), log(2.0), false));
  for (double i = 1.; i < 10; i += 1.0) {
    ck_assert(!precision_check(s21_log(i), log(i), false));
  }
  for (double i = 10.; i < 100; i += 10.0) {
    ck_assert(!precision_check(s21_log(i), log(i), false));
  }
}
END_TEST

START_TEST(s21_log_negative) {
  // -NAN
  ck_assert(!precision_check(s21_log(-2), log(-2), false));
}
END_TEST

START_TEST(s21_log_zero) {
  // -INF
  ck_assert(!precision_check(s21_log(0.), log(0.), false));
}
END_TEST

START_TEST(s21_log_inf) {
  // INF
  ck_assert(!precision_check(s21_log(S21_INF), log(S21_INF), false));
}
END_TEST

START_TEST(s21_log_inf_negative) {
  // -NAN
  ck_assert(!precision_check(s21_log(-S21_INF), log(-S21_INF), false));
}
END_TEST

START_TEST(s21_log_nan) {
  // NAN
  ck_assert(!precision_check(s21_log(S21_NAN), log(S21_NAN), false));
}
END_TEST

START_TEST(s21_log_nan_negative) {
  // -NAN
  ck_assert(!precision_check(s21_log(-S21_NAN), log(-S21_NAN), false));
}
END_TEST

START_TEST(s21_log_max_double) {
  // 709.782713
  ck_assert(
      !precision_check(s21_log(S21_double_MAX), log(S21_double_MAX), false));
}
END_TEST

START_TEST(s21_log_max_double_neg) {
  // 709.782713
  ck_assert(
      !precision_check(s21_log(-S21_double_MAX), log(-S21_double_MAX), false));
}
END_TEST

START_TEST(s21_log_min_double) {
  // -709.782713
  ck_assert(
      !precision_check(s21_log(S21_double_MIN), log(S21_double_MIN), false));
}
END_TEST

START_TEST(s21_log_min_double_neg) {
  // -709.782713
  ck_assert(
      !precision_check(s21_log(-S21_double_MIN), log(-S21_double_MIN), false));
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
  tcase_add_test(tc, s21_log_max_double);
  tcase_add_test(tc, s21_log_max_double_neg);
  tcase_add_test(tc, s21_log_min_double);
  tcase_add_test(tc, s21_log_min_double_neg);

  suite_add_tcase(c, tc);

  return c;
}
