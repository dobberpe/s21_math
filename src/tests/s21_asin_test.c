#include "s21_math_test.h"

START_TEST(asin_09) {
  for (double i = 0.9; i > -1; i -= 0.4) {
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

START_TEST(asin_NAN) {
  // NAN
  ld_bits check = {asin(S21_NAN)};
  ld_bits result = {s21_asin(S21_NAN)};
  for (int i = 0; i < 5; ++i) ck_assert_uint_eq(check.bits[i], result.bits[i]);
}
END_TEST

START_TEST(asin_NAN2) {
  // -NAN
  ld_bits check = {asin(S21_NAN)};
  ld_bits result = {s21_asin(S21_NAN)};
  for (int i = 0; i < 5; ++i) ck_assert_uint_eq(check.bits[i], result.bits[i]);
}
END_TEST

START_TEST(asin_S21_INF) {
  // NAN
  ld_bits check = {asin(S21_INF)};
  ld_bits result = {s21_asin(S21_INF)};
  for (int i = 0; i < 5; ++i) ck_assert_uint_eq(check.bits[i], result.bits[i]);
}
END_TEST

START_TEST(asin_S21_INFL) {
  // NAN
  ld_bits check = {asin(-S21_INF)};
  ld_bits result = {s21_asin(-S21_INF)};
  for (int i = 0; i < 5; ++i) ck_assert_uint_eq(check.bits[i], result.bits[i]);
}
END_TEST

START_TEST(s21_asin_max_double) {
  // NAN
  ld_bits check = {asin(S21_double_MAX)};
  ld_bits result = {s21_asin(S21_double_MAX)};
  for (int i = 0; i < 5; ++i) ck_assert_uint_eq(check.bits[i], result.bits[i]);
}
END_TEST

START_TEST(s21_asin_min_double) {
  // 0.0
  ck_assert_ldouble_eq_tol(s21_asin(S21_double_MIN), asin(S21_double_MIN), S21_EPS);
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
  tcase_add_test(tc, asin_S21_INF);
  tcase_add_test(tc, asin_S21_INFL);
  tcase_add_test(tc, s21_asin_max_double);
  tcase_add_test(tc, s21_asin_min_double);

  suite_add_tcase(c, tc);
  return c;
}
