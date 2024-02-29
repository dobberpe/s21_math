#include "s21_math_test.h"

START_TEST(tan_09) {
  for (double i = 0.9; i > -1; i -= 0.1) {
    ck_assert_double_eq_tol(tan(i), s21_tan(i), 1e-07);
  };
}
END_TEST

START_TEST(tan_1) {
  ck_assert_double_eq_tol(tan(1), s21_tan(1), 1e-07);
  ck_assert_double_eq_tol(tan(-1), s21_tan(-1), 1e-07);
}
END_TEST

START_TEST(tan_100) {
  for (double i = 99999; i >= 1; i /= 1.217) {
    ck_assert_double_eq_tol(tan(i), s21_tan(i), 1e-07);
  }
}
END_TEST

START_TEST(tan_NAN) { ck_assert(isnan(tan(S21_NAN)) && isnan(s21_tan(S21_NAN))); }
END_TEST

START_TEST(tan_NAN2) { ck_assert(isnan(tan(-S21_NAN)) && isnan(s21_tan(-S21_NAN))); }
END_TEST

START_TEST(tan_INFINITY) {
  ck_assert(isnan(tan(S21_INF)) && isnan(s21_tan(S21_INF)));
}
END_TEST

START_TEST(tan_INFINITYL) {
  ck_assert(isnan(tan(-S21_INF)) && isnan(s21_tan(-S21_INF)));
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

  suite_add_tcase(c, tc);
  return c;
}
