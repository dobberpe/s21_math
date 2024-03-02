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

START_TEST(tan_NAN) {
  // NAN
  ld_bits check = {tan(S21_NAN)};
  ld_bits result = {s21_tan(S21_NAN)};
  for (int i = 0; i < 5; ++i) ck_assert_uint_eq(check.bits[i], result.bits[i]);
}
END_TEST

START_TEST(tan_NAN2) {
  // -NAN
  ld_bits check = {tan(S21_NAN)};
  ld_bits result = {s21_tan(S21_NAN)};
  for (int i = 0; i < 5; ++i) ck_assert_uint_eq(check.bits[i], result.bits[i]);
}
END_TEST

START_TEST(tan_INFINITY) {
  // -NAN
  ld_bits check = {tan(S21_INF)};
  ld_bits result = {s21_tan(S21_INF)};
  for (int i = 0; i < 5; ++i) ck_assert_uint_eq(check.bits[i], result.bits[i]);
}
END_TEST

START_TEST(tan_INFINITYL) {
  // -NAN
  ld_bits check = {tan(-S21_INF)};
  ld_bits result = {s21_tan(-S21_INF)};
  for (int i = 0; i < 5; ++i) ck_assert_uint_eq(check.bits[i], result.bits[i]);
}
END_TEST

START_TEST(s21_tan_max_double) {
  // -0.004962
  ck_assert_double_eq_tol(tan(S21_double_MAX), s21_tan(S21_double_MAX), S21_EPS);
}
END_TEST

START_TEST(s21_tan_min_double) {
  // 0.0
  ck_assert_ldouble_eq_tol(s21_tan(S21_double_MIN), tan(S21_double_MIN), S21_EPS);
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
  tcase_add_test(tc, s21_tan_min_double);

  suite_add_tcase(c, tc);
  return c;
}
