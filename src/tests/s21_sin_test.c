#include "s21_math_test.h"

START_TEST(sin_09) {
  for (double i = 0.9; i > -1; i -= 0.1) {
    ck_assert(!precision_check(s21_sin(i), sin(i), false));
  };
}
END_TEST

START_TEST(sin_1) {
  ck_assert(!precision_check(s21_sin(1), sin(1), false));
  ck_assert(!precision_check(s21_sin(-1), sin(-1), false));
}
END_TEST

START_TEST(sin_100) {
  for (double i = 99999; i >= 1; i /= 1.328) {
    ck_assert(!precision_check(s21_sin(i), sin(i), false));
  }
}
END_TEST

START_TEST(sin_NAN) {
  // NAN
  ck_assert(!precision_check(s21_sin(S21_NAN), sin(S21_NAN), false));
}
END_TEST

START_TEST(sin_NAN2) {
  // -NAN
  ck_assert(!precision_check(s21_sin(-S21_NAN), sin(-S21_NAN), false));
}
END_TEST

START_TEST(sin_INFINITY) {
  // -NAN
  ck_assert(!precision_check(s21_sin(S21_INF), sin(S21_INF), false));
}
END_TEST

START_TEST(sin_INFINITYL) {
  // -NAN
  ck_assert(!precision_check(s21_sin(-S21_INF), sin(-S21_INF), false));
}
END_TEST

START_TEST(s21_sin_min_double) {
  // 0.0
  ck_assert(
      !precision_check(s21_sin(S21_double_MIN), sin(S21_double_MIN), false));
}
END_TEST

START_TEST(s21_sin_min_double_neg) {
  // 0.0
  ck_assert(
      !precision_check(s21_sin(-S21_double_MIN), sin(-S21_double_MIN), false));
}
END_TEST

Suite *s21_sin_cases(void) {
  Suite *c = suite_create("s21_sin_cases");
  TCase *tc = tcase_create("s21_sin_tc");

  tcase_add_test(tc, sin_09);
  tcase_add_test(tc, sin_1);
  tcase_add_test(tc, sin_100);
  tcase_add_test(tc, sin_NAN);
  tcase_add_test(tc, sin_NAN2);
  tcase_add_test(tc, sin_INFINITY);
  tcase_add_test(tc, sin_INFINITYL);
  tcase_add_test(tc, s21_sin_min_double);
  tcase_add_test(tc, s21_sin_min_double_neg);

  suite_add_tcase(c, tc);
  return c;
}
