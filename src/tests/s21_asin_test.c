#include "s21_math_test.h"

START_TEST(asin_09) {
  for (double i = 0.9; i > -1; i -= 0.4) {
    ck_assert(!precision_check(s21_asin(i), asin(i), false));
    // ck_assert_double_eq_tol(asin(i), s21_asin(i), 1e-07);
  };
}
END_TEST

START_TEST(asin_1) {
  ck_assert(!precision_check(s21_asin(1), asin(1), false));
  ck_assert(!precision_check(s21_asin(-1), asin(-1), false));
  // ck_assert_double_eq_tol(asin(1), s21_asin(1), 1e-07);
  // ck_assert_double_eq_tol(asin(-1), s21_asin(-1), 1e-07);
}
END_TEST

START_TEST(asin_100) {
  for (double i = 100; i >= -100; i -= 10) {
    if (i) ck_assert(!precision_check(s21_asin(i), asin(i), false));
    // ck_assert(isnan(asin(i)) && isnan(s21_asin(i)));
  }
}
END_TEST

START_TEST(asin_NAN) {
  // NAN
  ck_assert(!precision_check(s21_asin(S21_NAN), asin(S21_NAN), false));
  // ld_bits check = {asin(S21_NAN)};
  // ld_bits result = {s21_asin(S21_NAN)};
  // for (int i = 0; i < 5; ++i) ck_assert_uint_eq(check.bits[i], result.bits[i]);
}
END_TEST

START_TEST(asin_NAN2) {
  // -NAN
  // printf("\n%.6Lf\n%.6f\n\n", s21_asin(-S21_NAN), asin(-S21_NAN));
  ck_assert(!precision_check(s21_asin(-S21_NAN), asin(-S21_NAN), false));
  // ld_bits check = {asin(S21_NAN)};
  // ld_bits result = {s21_asin(S21_NAN)};
  // for (int i = 0; i < 5; ++i) ck_assert_uint_eq(check.bits[i], result.bits[i]);
}
END_TEST

START_TEST(asin_S21_INF) {
  // NAN
  ck_assert(!precision_check(s21_asin(S21_INF), asin(S21_INF), false));
  // ld_bits check = {asin(S21_INF)};
  // ld_bits result = {s21_asin(S21_INF)};
  // for (int i = 0; i < 5; ++i) ck_assert_uint_eq(check.bits[i], result.bits[i]);
}
END_TEST

START_TEST(asin_S21_INFL) {
  // NAN
  ck_assert(!precision_check(s21_asin(-S21_INF), asin(-S21_INF), false));
  // ld_bits check = {asin(-S21_INF)};
  // ld_bits result = {s21_asin(-S21_INF)};
  // for (int i = 0; i < 5; ++i) ck_assert_uint_eq(check.bits[i], result.bits[i]);
}
END_TEST

START_TEST(s21_asin_max_double) {
  // NAN
  ck_assert(!precision_check(s21_asin(S21_double_MAX), asin(S21_double_MAX), false));
  // ld_bits check = {asin(S21_double_MAX)};
  // ld_bits result = {s21_asin(S21_double_MAX)};
  // for (int i = 0; i < 5; ++i) ck_assert_uint_eq(check.bits[i], result.bits[i]);
}
END_TEST

START_TEST(s21_asin_max_double_neg) {
  // NAN
  ck_assert(!precision_check(s21_asin(-S21_double_MAX), asin(-S21_double_MAX), false));
  // ld_bits check = {asin(S21_double_MAX)};
  // ld_bits result = {s21_asin(S21_double_MAX)};
  // for (int i = 0; i < 5; ++i) ck_assert_uint_eq(check.bits[i], result.bits[i]);
}
END_TEST

START_TEST(s21_asin_min_double) {
  // 0.0
  ck_assert(!precision_check(s21_asin(S21_double_MIN), asin(S21_double_MIN), false));
  // ck_assert_ldouble_eq_tol(s21_asin(S21_double_MIN), asin(S21_double_MIN), S21_EPS);
}
END_TEST

START_TEST(s21_asin_min_double_neg) {
  // 0.0
  ck_assert(!precision_check(s21_asin(-S21_double_MIN), asin(-S21_double_MIN), false));
  // ck_assert_ldouble_eq_tol(s21_asin(S21_double_MIN), asin(S21_double_MIN), S21_EPS);
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
  tcase_add_test(tc, s21_asin_max_double_neg);
  tcase_add_test(tc, s21_asin_min_double);
  tcase_add_test(tc, s21_asin_min_double_neg);

  suite_add_tcase(c, tc);
  return c;
}
