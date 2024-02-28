#include "s21_math_test.h"

START_TEST(cos_09) {
  for (double i = 0.9; i > -1; i -= 0.1) {
    ck_assert_double_eq_tol(cos(i), s21_cos(i), 1e-07);
  };
}
END_TEST

START_TEST(cos_1) {
  ck_assert_double_eq_tol(cos(1), s21_cos(1), 1e-07);
  ck_assert_double_eq_tol(cos(-1), s21_cos(-1), 1e-07);
}
END_TEST

START_TEST(cos_100) {
  for (double i = 99999; i >= 1; i /= 1.413) {
    ck_assert_double_eq_tol(sin(i), s21_sin(i), 1e-07);
  }
}
END_TEST

START_TEST(cos_NAN) { ck_assert(isnan(cos(S21_NAN)) && isnan(s21_cos(S21_NAN))); }
END_TEST

START_TEST(cos_NAN2) { ck_assert(isnan(cos(-S21_NAN)) && isnan(s21_cos(-S21_NAN))); }
END_TEST

START_TEST(cos_INFINITY) {
  ck_assert(isnan(cos(S21_INF)) && isnan(s21_cos(S21_INF)));
}
END_TEST

START_TEST(cos_INFINITYL) {
  ck_assert(isnan(cos(-S21_INF)) && isnan(s21_cos(-S21_INF)));
}
END_TEST

Suite *s21_cos_cases(void) {
  Suite *c = suite_create("s21_cos_cases");
  TCase *tc = tcase_create("s21_cos_tc");

  tcase_add_test(tc, cos_09);
  tcase_add_test(tc, cos_1);
  tcase_add_test(tc, cos_100);
  tcase_add_test(tc, cos_NAN);
  tcase_add_test(tc, cos_NAN2);
  tcase_add_test(tc, cos_INFINITY);
  tcase_add_test(tc, cos_INFINITYL);

  suite_add_tcase(c, tc);
  return c;
}
