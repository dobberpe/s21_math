#include "s21_math_test.h"

START_TEST(acos_09) {
  for (double i = 0.9; i > -1; i -= 0.4) {
    ck_assert(!precision_check(s21_acos(i), acos(i), false));
  };
}
END_TEST

START_TEST(acos_1) {
  ck_assert(!precision_check(s21_acos(1), acos(1), false));
  ck_assert(!precision_check(s21_acos(-1), acos(-1), false));
}
END_TEST

START_TEST(acos_100) {
  for (double i = 100; i >= -100; i -= 10) {
    if (i) ck_assert(!precision_check(s21_acos(i), acos(i), false));
  }
}
END_TEST

START_TEST(acos_NAN) {
  // NAN
  ck_assert(!precision_check(s21_acos(S21_NAN), acos(S21_NAN), false));
}
END_TEST

START_TEST(acos_NAN2) {
  // -NAN
  ck_assert(!precision_check(s21_acos(-S21_NAN), acos(-S21_NAN), false));
}
END_TEST

START_TEST(acos_INFINITY) {
  // NAN
  ck_assert(!precision_check(s21_acos(S21_INF), acos(S21_INF), false));
}
END_TEST

START_TEST(acos_INFINITYL) {
  // NAN
  ck_assert(!precision_check(s21_acos(-S21_INF), acos(-S21_INF), false));
}
END_TEST

START_TEST(s21_acos_max_double) {
  // NAN
  ck_assert(
      !precision_check(s21_acos(S21_double_MAX), acos(S21_double_MAX), false));
}
END_TEST

START_TEST(s21_acos_max_double_neg) {
  // NAN
  ck_assert(!precision_check(s21_acos(-S21_double_MAX), acos(-S21_double_MAX),
                             false));
}
END_TEST

START_TEST(s21_acos_min_double) {
  // 1.570796
  ck_assert(
      !precision_check(s21_acos(S21_double_MIN), acos(S21_double_MIN), false));
}
END_TEST

START_TEST(s21_acos_min_double_neg) {
  // 1.570796
  ck_assert(!precision_check(s21_acos(-S21_double_MIN), acos(-S21_double_MIN),
                             false));
}
END_TEST

Suite *s21_acos_cases(void) {
  Suite *c = suite_create("s21_acos_cases");
  TCase *tc = tcase_create("s21_acos_tc");

  tcase_add_test(tc, acos_09);
  tcase_add_test(tc, acos_1);
  tcase_add_test(tc, acos_100);
  tcase_add_test(tc, acos_NAN);
  tcase_add_test(tc, acos_NAN2);
  tcase_add_test(tc, acos_INFINITY);
  tcase_add_test(tc, acos_INFINITYL);
  tcase_add_test(tc, s21_acos_max_double);
  tcase_add_test(tc, s21_acos_max_double_neg);
  tcase_add_test(tc, s21_acos_min_double);
  tcase_add_test(tc, s21_acos_min_double_neg);

  suite_add_tcase(c, tc);
  return c;
}
