#include "s21_math_test.h"

START_TEST(exp_fn) {
  ck_assert(!precision_check(s21_exp(5), exp(5), false));
  ck_assert(!precision_check(s21_exp(-2), exp(-2), false));
  ck_assert(!precision_check(s21_exp(1234567), exp(1234567), false));  // INF
  ck_assert(!precision_check(s21_exp(-1234567), exp(-1234567), false));
  for (double i = -10; i <= 10; i++) {
    ck_assert(!precision_check(s21_exp(i), exp(i), false));
  }
  ck_assert(!precision_check(s21_exp(0.0), exp(0.0), false));
  ck_assert(!precision_check(s21_exp(1.0), exp(1.0), false));
  ck_assert(!precision_check(s21_exp(-1.0), exp(-1.0), false));
  ck_assert(!precision_check(s21_exp(10.0), exp(10.0), false));
  ck_assert(!precision_check(s21_exp(-10.0), exp(-10.0), false));
  ck_assert(!precision_check(s21_exp(-100.0), exp(-100.0), false));
  ck_assert(!precision_check(s21_exp(-1000.0), exp(-1000.0), false));
  ck_assert(!precision_check(s21_exp(0.1), exp(0.1), false));
  ck_assert(!precision_check(s21_exp(-0.1), exp(-0.1), false));

  for (double i = -10000; i <= 10000; i += 1000) {
    ck_assert(!precision_check(s21_exp(i), exp(i), false));
  }
}
END_TEST

START_TEST(s21_exp_inf) {
  // INF
  ck_assert(!precision_check(s21_exp(S21_INF), exp(S21_INF), false));
}
END_TEST

START_TEST(s21_exp_inf_negative) {
  // 0.0
  ck_assert(!precision_check(s21_exp(-S21_INF), exp(-S21_INF), false));
}
END_TEST

START_TEST(s21_exp_nan) {
  // NAN
  ck_assert(!precision_check(s21_exp(S21_NAN), exp(S21_NAN), false));
}
END_TEST

START_TEST(s21_exp_nan_negative) {
  // -NAN
  ck_assert(!precision_check(s21_exp(-S21_NAN), exp(-S21_NAN), false));
}
END_TEST

START_TEST(s21_exp_max_double) {
  // INF
  ck_assert(
      !precision_check(s21_exp(S21_double_MAX), exp(S21_double_MAX), false));
}
END_TEST

START_TEST(s21_exp_max_double_neg) {
  // INF
  ck_assert(
      !precision_check(s21_exp(-S21_double_MAX), exp(-S21_double_MAX), false));
}
END_TEST

START_TEST(s21_exp_min_double) {
  // 1.0
  ck_assert(
      !precision_check(s21_exp(S21_double_MIN), exp(S21_double_MIN), false));
}
END_TEST

START_TEST(s21_exp_min_double_neg) {
  // 1.0
  ck_assert(
      !precision_check(s21_exp(-S21_double_MIN), exp(-S21_double_MIN), false));
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
  tcase_add_test(tc, s21_exp_max_double_neg);
  tcase_add_test(tc, s21_exp_min_double);
  tcase_add_test(tc, s21_exp_min_double_neg);

  suite_add_tcase(c, tc);

  return c;
}
