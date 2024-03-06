#include "s21_math_test.h"

START_TEST(asin_09) {
  for (double i = 0.9; i > -1; i -= 0.4) {
    ck_assert(!precision_check(s21_asin(i), asin(i), false));
  };
}
END_TEST

START_TEST(asin_1) {
  ck_assert(!precision_check(s21_asin(1), asin(1), false));
  ck_assert(!precision_check(s21_asin(-1), asin(-1), false));
}
END_TEST

START_TEST(asin_100) {
  for (double i = 100; i >= -100; i -= 10) {
    if (i) ck_assert(!precision_check(s21_asin(i), asin(i), false));
  }
}
END_TEST

START_TEST(asin_NAN) {
  // NAN
  ck_assert(!precision_check(s21_asin(S21_NAN), asin(S21_NAN), false));
}
END_TEST

START_TEST(asin_NAN2) {
  // -NAN
  ck_assert(!precision_check(s21_asin(-S21_NAN), asin(-S21_NAN), false));
}
END_TEST

START_TEST(asin_S21_INF) {
  // NAN
  ck_assert(!precision_check(s21_asin(S21_INF), asin(S21_INF), false));
}
END_TEST

START_TEST(asin_S21_INFL) {
  // NAN
  ck_assert(!precision_check(s21_asin(-S21_INF), asin(-S21_INF), false));
}
END_TEST

START_TEST(s21_asin_max_double) {
  // NAN
  ck_assert(
      !precision_check(s21_asin(S21_double_MAX), asin(S21_double_MAX), false));
}
END_TEST

START_TEST(s21_asin_max_double_neg) {
  // NAN
  ck_assert(!precision_check(s21_asin(-S21_double_MAX), asin(-S21_double_MAX),
                             false));
}
END_TEST

START_TEST(s21_asin_min_double) {
  // 0.0
  ck_assert(
      !precision_check(s21_asin(S21_double_MIN), asin(S21_double_MIN), false));
}
END_TEST

START_TEST(s21_asin_min_double_neg) {
  // 0.0
  ck_assert(!precision_check(s21_asin(-S21_double_MIN), asin(-S21_double_MIN),
                             false));
}
END_TEST

Suite *s21_asin_cases(void) {
  Suite *c = suite_create("s21_asin_cases");
  TCase *tc = tcase_create("s21_asin_tc");

  tcase_add_test(tc, asin_09);
  tcase_add_test(tc, asin_1);
  tcase_add_test(tc, asin_100);
  tcase_add_test(tc, asin_NAN);
  tcase_add_test(tc, asin_NAN2);
  tcase_add_test(tc, asin_S21_INF);
  tcase_add_test(tc, asin_S21_INFL);
  tcase_add_test(tc, s21_asin_max_double);
  tcase_add_test(tc, s21_asin_max_double_neg);
  tcase_add_test(tc, s21_asin_min_double);
  tcase_add_test(tc, s21_asin_min_double_neg);

  suite_add_tcase(c, tc);
  return c;
}
