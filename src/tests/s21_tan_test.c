#include "s21_math_test.h"

START_TEST(tan_09) {
  for (double i = 0.9; i > -1; i -= 0.1) {
    ck_assert(!precision_check(s21_tan(i), tan(i), false));
  };
}
END_TEST

START_TEST(tan_1) {
  ck_assert(!precision_check(s21_tan(1), tan(1), false));
  ck_assert(!precision_check(s21_tan(-1), tan(-1), false));
}
END_TEST

START_TEST(tan_100) {
  for (double i = 99999; i >= 1; i /= 1.217) {
    ck_assert(!precision_check(s21_tan(i), tan(i), false));
  }
}
END_TEST

START_TEST(tan_NAN) {
  // NAN
  ck_assert(!precision_check(s21_tan(S21_NAN), tan(S21_NAN), false));
}
END_TEST

START_TEST(tan_NAN2) {
  // -NAN
  ck_assert(!precision_check(s21_tan(-S21_NAN), tan(-S21_NAN), false));
}
END_TEST

START_TEST(tan_INFINITY) {
  // -NAN
  ck_assert(!precision_check(s21_tan(S21_INF), tan(S21_INF), false));
}
END_TEST

START_TEST(tan_INFINITYL) {
  // -NAN
  ck_assert(!precision_check(s21_tan(-S21_INF), tan(-S21_INF), false));
}
END_TEST

START_TEST(s21_tan_max_double) {
  // -0.004962
  ck_assert(
      !precision_check(s21_tan(S21_double_MAX), tan(S21_double_MAX), false));
}
END_TEST

START_TEST(s21_tan_max_double_neg) {
  // -0.004962
  ck_assert(
      !precision_check(s21_tan(-S21_double_MAX), tan(-S21_double_MAX), false));
}
END_TEST

START_TEST(s21_tan_min_double) {
  // 0.0
  ck_assert(
      !precision_check(s21_tan(S21_double_MIN), tan(S21_double_MIN), false));
}
END_TEST

START_TEST(s21_tan_min_double_neg) {
  // 0.0
  ck_assert(
      !precision_check(s21_tan(-S21_double_MIN), tan(-S21_double_MIN), false));
}
END_TEST

Suite *s21_tan_cases(void) {
  Suite *c = suite_create("s21_tan_cases");
  TCase *tc = tcase_create("s21_tan_tc");

  tcase_add_test(tc, tan_09);
  tcase_add_test(tc, tan_1);
  tcase_add_test(tc, tan_100);
  tcase_add_test(tc, tan_NAN);
  tcase_add_test(tc, tan_NAN2);
  tcase_add_test(tc, tan_INFINITY);
  tcase_add_test(tc, tan_INFINITYL);
  tcase_add_test(tc, s21_tan_max_double);
  tcase_add_test(tc, s21_tan_max_double_neg);
  tcase_add_test(tc, s21_tan_min_double);
  tcase_add_test(tc, s21_tan_min_double_neg);

  suite_add_tcase(c, tc);
  return c;
}