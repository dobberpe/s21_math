#include "s21_math_test.h"

START_TEST(acos_09) {
  for (double i = 0.9; i > -1; i -= 0.4) {
    ck_assert_double_eq_tol(acos(i), s21_acos(i), S21_EPS);
  };
}
END_TEST

START_TEST(acos_1) {
  ck_assert_double_eq_tol(acos(1), s21_acos(1), S21_EPS);
  ck_assert_double_eq_tol(acos(-1), s21_acos(-1), S21_EPS);
}
END_TEST

START_TEST(acos_100) {
  for (double i = 100; i >= -100; i -= 10) {
    if (i == 0) continue;
    ck_assert(isnan(acos(i)) && isnan(s21_acos(i)));
  }
}
END_TEST

START_TEST(acos_NAN) {
  // NAN
  ld_bits check = {acos(S21_NAN)};
  ld_bits result = {s21_acos(S21_NAN)};
  for (int i = 0; i < 5; ++i) ck_assert_uint_eq(check.bits[i], result.bits[i]);
}
END_TEST

START_TEST(acos_NAN2) {
  // -NAN
  ld_bits check = {acos(S21_NAN)};
  ld_bits result = {s21_acos(S21_NAN)};
  for (int i = 0; i < 5; ++i) ck_assert_uint_eq(check.bits[i], result.bits[i]);
}
END_TEST

START_TEST(acos_INFINITY) {
  // NAN
  ld_bits check = {acos(S21_INF)};
  ld_bits result = {s21_acos(S21_INF)};
  for (int i = 0; i < 5; ++i) ck_assert_uint_eq(check.bits[i], result.bits[i]);
}
END_TEST

START_TEST(acos_INFINITYL) {
  // NAN
  ld_bits check = {acos(-S21_INF)};
  ld_bits result = {s21_acos(-S21_INF)};
  for (int i = 0; i < 5; ++i) ck_assert_uint_eq(check.bits[i], result.bits[i]);
}
END_TEST

START_TEST(s21_acos_max_double) {
  // NAN
  ld_bits check = {acos(S21_double_MAX)};
  ld_bits result = {s21_acos(S21_double_MAX)};
  for (int i = 0; i < 5; ++i) ck_assert_uint_eq(check.bits[i], result.bits[i]);
}
END_TEST

START_TEST(s21_acos_min_double) {
  // 1.570796
  ck_assert_ldouble_eq_tol(s21_acos(S21_double_MIN), acos(S21_double_MIN), S21_EPS);
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
  tcase_add_test(tc, s21_acos_max_double);
  tcase_add_test(tc, s21_acos_min_double);

  suite_add_tcase(c, tc);
  return c;
}
