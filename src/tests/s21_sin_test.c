#include "s21_math_test.h"

START_TEST(sin_09) {
  for (double i = 0.9; i > -1; i -= 0.1) {
    ck_assert_double_eq_tol(sin(i), s21_sin(i), 1e-07);
  };
}
END_TEST

START_TEST(sin_1) {
  ck_assert_double_eq_tol(sin(1), s21_sin(1), 1e-07);
  ck_assert_double_eq_tol(sin(-1), s21_sin(-1), 1e-07);
}
END_TEST

START_TEST(sin_100) {
  for (double i = 99999; i >= 1; i /= 1.328) {
    ck_assert_double_eq_tol(sin(i), s21_sin(i), 1e-07);
  }
}
END_TEST

START_TEST(sin_NAN) { ck_assert(isnan(sin(S21_NAN)) && isnan(s21_sin(S21_NAN))); }
END_TEST

START_TEST(sin_NAN2) { ck_assert(isnan(sin(-S21_NAN)) && isnan(s21_sin(-S21_NAN))); }
END_TEST

START_TEST(sin_INFINITY) {
  ck_assert(isnan(sin(S21_INF)) && isnan(s21_sin(S21_INF)));
}
END_TEST

START_TEST(sin_INFINITYL) {
  ck_assert(isnan(sin(-S21_INF)) && isnan(s21_sin(-S21_INF)));
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

  suite_add_tcase(c, tc);
  return c;
}
