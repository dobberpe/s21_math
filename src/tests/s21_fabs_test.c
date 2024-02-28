#include "s21_math_test.h"

START_TEST(fabs_fn) {
  ck_assert_ldouble_eq(s21_fabs(-612367.54783), fabs(-612367.54783));
  ck_assert_ldouble_eq(s21_fabs(-45.345), fabs(-45.345));
  ck_assert_ldouble_eq(s21_fabs(1.0), fabs(1.0));
  ck_assert_ldouble_eq(s21_fabs(S21_INF), fabs(S21_INF));
  ck_assert_ldouble_eq(s21_fabs(-S21_INF), fabs(-S21_INF));
  ld_bits check = {fabs(S21_NAN)};
  ld_bits result = {s21_fabs(S21_NAN)};
  for (int i = 0; i < 5; ++i) ck_assert_uint_eq(check.bits[i], result.bits[i]);
  check.full = fabs(-S21_NAN);
  result.full = s21_fabs(-S21_NAN);
  for (int i = 0; i < 5; ++i) ck_assert_uint_eq(check.bits[i], result.bits[i]);
}
END_TEST

START_TEST(s21_fabs_inf) {
  // INF
  ck_assert_ldouble_eq(fabs(S21_INF), s21_fabs(S21_INF));
}
END_TEST

START_TEST(s21_fabs_inf_negative) {
  // INF
  ck_assert_ldouble_eq(fabs(-S21_INF), s21_fabs(-S21_INF));
}
END_TEST

START_TEST(s21_fabs_nan) {
  // NAN
  ld_bits check = {fabs(S21_NAN)};
  ld_bits result = {s21_fabs(S21_NAN)};
  for (int i = 0; i < 5; ++i)  ck_assert_uint_eq(check.bits[i], result.bits[i]);
}
END_TEST

START_TEST(s21_fabs_nan_negative) {
  // NAN
  ld_bits check = {fabs(-S21_NAN)};
  ld_bits result = {s21_fabs(-S21_NAN)};
  for (int i = 0; i < 5; ++i)  ck_assert_uint_eq(check.bits[i], result.bits[i]);
}
END_TEST

Suite *s21_fabs_cases(void) {
  Suite *c = suite_create("s21_fabs_cases");
  TCase *tc = tcase_create("s21_fabs_tc");

  tcase_add_test(tc, fabs_fn);
  tcase_add_test(tc, s21_fabs_inf);
  tcase_add_test(tc, s21_fabs_inf_negative);
  tcase_add_test(tc, s21_fabs_nan);
  tcase_add_test(tc, s21_fabs_nan_negative);

  suite_add_tcase(c, tc);

  return c;
}
