#include "s21_math_test.h"

START_TEST(atan_09) {
  for (double i = 0.999; i > -1; i -= 0.001) {
    ck_assert_double_eq_tol(atan(i), s21_atan(i), 1e-07);
  };
}
END_TEST

START_TEST(atan_1) {
  ck_assert_double_eq_tol(atan(1), s21_atan(1), 1e-07);
  ck_assert_double_eq_tol(atan(-1), s21_atan(-1), 1e-07);
}
END_TEST

START_TEST(atan_100) {
  for (double i = 100; i >= -100; i -= 1) {
    ck_assert_double_eq_tol(atan(i), s21_atan(i), 1e-07);
  }
}
END_TEST

START_TEST(atan_100000) {
  for (double i = 100000; i >= -100000; i -= 100) {
    ck_assert_double_eq_tol(atan(i), s21_atan(i), 1e-07);
  }
}
END_TEST

START_TEST(atan_S21_NAN) {
  ck_assert_double_eq_tol(atan(S21_NAN), s21_atan(S21_NAN), 1e-07);
}
END_TEST

START_TEST(atan_S21_NANL) {
  ck_assert_double_eq_tol(atan(S21_NANL), s21_atan(S21_NANL), 1e-07);
}
END_TEST

START_TEST(atan_S21_INF) {
  ck_assert_double_eq_tol(atan(S21_INF), s21_atan(S21_INF), 1e-07);
}
END_TEST

START_TEST(atan_S21_INFL) {
  ck_assert_double_eq_tol(atan(S21_INFL), s21_atan(S21_INFL), 1e-07);
}
END_TEST

Suite *s21_atan_cases(void) {
  Suite *c = suite_create("s21_atan_cases");
  TCase *tc = tcase_create("s21_atan_tc");

  tcase_add_test(tc, atan_09);
  tcase_add_test(tc, atan_1);
  tcase_add_test(tc, atan_100);
  tcase_add_test(tc, atan_100000);
  tcase_add_test(tc, atan_S21_NAN);
  tcase_add_test(tc, atan_S21_NANL);
  tcase_add_test(tc, atan_S21_INF);
  tcase_add_test(tc, atan_S21_INFL);

  suite_add_tcase(c, tc);
  return c;
}
