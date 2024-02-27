#include "s21_math_test.h"

START_TEST(s21_sqrt_negative) {
  // -NAN
  ld_bits check = {sqrt(-2)};
  ld_bits result = {s21_sqrt(-2)};
  for (int i = 0; i < 5; ++i) ck_assert_uint_eq(check.bits[i], result.bits[i]);
}
END_TEST

START_TEST(s21_sqrt_inf) {
  // INF
  ck_assert_ldouble_eq(sqrt(INFINITY), s21_sqrt(INFINITY));
}
END_TEST

START_TEST(s21_sqrt_inf_negative) {
  // -NAN
  ld_bits check = {sqrt(-INFINITY)};
  ld_bits result = {s21_sqrt(-INFINITY)};
  for (int i = 0; i < 5; ++i)  ck_assert_uint_eq(check.bits[i], result.bits[i]);
}
END_TEST

START_TEST(s21_sqrt_nan) {
  // NAN
  ld_bits check = {sqrt(NAN)};
  ld_bits result = {s21_sqrt(NAN)};
  for (int i = 0; i < 5; ++i)  ck_assert_uint_eq(check.bits[i], result.bits[i]);
}
END_TEST

START_TEST(s21_sqrt_nan_negative) {
  // -NAN
  ld_bits check = {sqrt(-NAN)};
  ld_bits result = {s21_sqrt(-NAN)};
  for (int i = 0; i < 5; ++i)  ck_assert_uint_eq(check.bits[i], result.bits[i]);
}
END_TEST

START_TEST(s21_sqrt_normal_1) {
  // 2.0
  ck_assert_double_eq_tol(sqrt(4), s21_sqrt(4), S21_EPS);
}
END_TEST

START_TEST(s21_sqrt_normal_2) {
  // 22.627417
  ck_assert_ldouble_eq_tol(sqrt(512), s21_sqrt(512), S21_EPS);
}
END_TEST

Suite *s21_sqrt_cases(void) {
  Suite *c = suite_create("s21_sqrt_cases");
  TCase *tc = tcase_create("s21_sqrt_tc");
  tcase_add_test(tc, s21_sqrt_negative);
  tcase_add_test(tc, s21_sqrt_inf);
  tcase_add_test(tc, s21_sqrt_inf_negative);
  tcase_add_test(tc, s21_sqrt_nan);
  tcase_add_test(tc, s21_sqrt_nan_negative);
  tcase_add_test(tc, s21_sqrt_normal_1);
  tcase_add_test(tc, s21_sqrt_normal_2);
  suite_add_tcase(c, tc);
  return c;
}
