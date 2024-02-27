#include "s21_math_test.h"

START_TEST(atan_09) {
  for (double i = 0.9; i > -1; i -= 0.1) {
    ck_assert_double_eq_tol(atan(i), s21_atan(i), 1e-06);
  };
}
END_TEST

START_TEST(atan_2) {
  ck_assert_double_eq_tol(atan(0.999999), s21_atan(0.999999), 1e-06);
  ck_assert_double_eq_tol(atan(-0.999999), s21_atan(-0.999999), 1e-06);
  ck_assert_double_eq_tol(atan(0.99999999), s21_atan(0.99999999), 1e-06);
  ck_assert_double_eq_tol(atan(-0.99999999), s21_atan(-0.99999999), 1e-06);
  ck_assert_double_eq_tol(atan(0.9999999999), s21_atan(0.9999999999), 1e-06);
  ck_assert_double_eq_tol(atan(-0.9999999999), s21_atan(-0.9999999999), 1e-06);
}

START_TEST(atan_1) {
  ck_assert_double_eq_tol(atan(1), s21_atan(1), 1e-06);
  ck_assert_double_eq_tol(atan(-1), s21_atan(-1), 1e-06);
}
END_TEST

START_TEST(atan_100) {
  for (double i = 100; i >= -100; i -= 10) {
    ck_assert_double_eq_tol(atan(i), s21_atan(i), 1e-06);
  }
}
END_TEST

START_TEST(atan_100000) {
  for (double i = 100000; i >= -100000; i -= 1000) {
    ck_assert_double_eq_tol(atan(i), s21_atan(i), 1e-06);
  }
}
END_TEST

START_TEST(atan_NAN) { ck_assert(isnan(atan(NAN)) && isnan(s21_atan(NAN))); }
END_TEST

START_TEST(atan_NAN2) { ck_assert(isnan(atan(-NAN)) && isnan(s21_atan(-NAN))); }
END_TEST

START_TEST(atan_INFINITY) {
  ck_assert_double_eq_tol(atan(INFINITY), s21_atan(INFINITY), 1e-06);
}
END_TEST

START_TEST(atan_INFINITY2) {
  ck_assert_double_eq_tol(atan(-INFINITY), s21_atan(-INFINITY), 1e-06);
}
END_TEST

Suite *s21_atan_cases(void) {
  Suite *c = suite_create("s21_atan_cases");
  TCase *tc = tcase_create("s21_atan_tc");

  tcase_add_test(tc, atan_09);
  tcase_add_test(tc, atan_1);
  tcase_add_test(tc, atan_100);
  tcase_add_test(tc, atan_100000);
  tcase_add_test(tc, atan_NAN);
  tcase_add_test(tc, atan_NAN2);
  tcase_add_test(tc, atan_INFINITY);
  tcase_add_test(tc, atan_INFINITY2);
  tcase_add_test(tc, atan_2);

  suite_add_tcase(c, tc);
  return c;
}
