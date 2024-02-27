#include "s21_math_test.h"

START_TEST(asin_09) {
  for (double i = 0.9; i > -1; i -= 0.1) {
    ck_assert_double_eq_tol(asin(i), s21_asin(i), 1e-07);
  };
}
END_TEST

START_TEST(asin_1) {
  ck_assert_double_eq_tol(asin(1), s21_asin(1), 1e-07);
  ck_assert_double_eq_tol(asin(-1), s21_asin(-1), 1e-07);
}
END_TEST

START_TEST(asin_100) {
  for (double i = 100; i >= -100; i -= 10) {
    if (i == 0) continue;
    ck_assert(isnan(asin(i)) && isnan(s21_asin(i)));
  }
}
END_TEST

START_TEST(asin_NAN) { ck_assert(isnan(asin(NAN)) && isnan(s21_asin(NAN))); }
END_TEST

START_TEST(asin_NAN2) { ck_assert(isnan(asin(-NAN)) && isnan(s21_asin(-NAN))); }
END_TEST

START_TEST(asin_INFINITY) {
  ck_assert(isnan(asin(INFINITY)) && isnan(s21_asin(INFINITY)));
}
END_TEST

START_TEST(asin_INFINITYL) {
  ck_assert(isnan(asin(-INFINITY)) && isnan(s21_asin(-INFINITY)));
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
  tcase_add_test(tc, asin_INFINITY);
  tcase_add_test(tc, asin_INFINITYL);

  suite_add_tcase(c, tc);
  return c;
}
