#include "s21_math_test.h"

START_TEST(acos_09) {
  for (double i = 0.9; i > -1; i -= 0.4) {
    ck_assert_double_eq_tol(acos(i), s21_acos(i), 1e-07);
  };
}
END_TEST

START_TEST(acos_1) {
  ck_assert_double_eq_tol(acos(1), s21_acos(1), 1e-07);
  ck_assert_double_eq_tol(acos(-1), s21_acos(-1), 1e-07);
}
END_TEST

START_TEST(acos_100) {
  for (double i = 100; i >= -100; i -= 10) {
    if (i == 0) continue;
    ck_assert(isnan(acos(i)) && isnan(s21_acos(i)));
  }
}
END_TEST

START_TEST(acos_NAN) { ck_assert(isnan(acos(S21_NAN)) && isnan(s21_acos(S21_NAN))); }
END_TEST

START_TEST(acos_NAN2) { ck_assert(isnan(acos(-S21_NAN)) && isnan(s21_acos(-S21_NAN))); }
END_TEST

START_TEST(acos_INFINITY) {
  ck_assert(isnan(acos(S21_INF)) && isnan(s21_acos(S21_INF)));
}
END_TEST

START_TEST(acos_INFINITYL) {
  ck_assert(isnan(acos(-S21_INF)) && isnan(s21_acos(-S21_INF)));
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

  suite_add_tcase(c, tc);
  return c;
}
