#include "s21_math_test.h"

START_TEST(cos_09) {
  for (double i = 0.9; i > -1; i -= 0.1) {
    ck_assert(!precision_check(s21_cos(i), cos(i), false));
    // ck_assert_double_eq_tol(cos(i), s21_cos(i), S21_EPS);
  };
}
END_TEST

START_TEST(cos_1) {
  ck_assert(!precision_check(s21_cos(1), cos(1), false));
  ck_assert(!precision_check(s21_cos(-1), cos(-1), false));
  // ck_assert_double_eq_tol(cos(1), s21_cos(1), S21_EPS);
  // ck_assert_double_eq_tol(cos(-1), s21_cos(-1), S21_EPS);
}
END_TEST

START_TEST(cos_100) {
  for (double i = 99999; i >= 1; i /= 1.413) {
  ck_assert(!precision_check(s21_cos(i), cos(i), false));
    // ck_assert_double_eq_tol(sin(i), s21_sin(i), S21_EPS);
  }
}
END_TEST

START_TEST(cos_NAN) {
  // NAN
  ck_assert(!precision_check(s21_cos(S21_NAN), cos(S21_NAN), false));
  // ld_bits check = {cos(S21_NAN)};
  // ld_bits result = {s21_cos(S21_NAN)};
  // for (int i = 0; i < 5; ++i) ck_assert_uint_eq(check.bits[i], result.bits[i]);
}
END_TEST

START_TEST(cos_NAN2) {
  // -NAN
  ck_assert(!precision_check(s21_cos(-S21_NAN), cos(-S21_NAN), false));
  // ld_bits check = {cos(S21_NAN)};
  // ld_bits result = {s21_cos(S21_NAN)};
  // for (int i = 0; i < 5; ++i) ck_assert_uint_eq(check.bits[i], result.bits[i]);
}
END_TEST

START_TEST(cos_INFINITY) {
  // -NAN
  ck_assert(!precision_check(s21_cos(S21_INF), cos(S21_INF), false));
  // ld_bits check = {cos(S21_INF)};
  // ld_bits result = {s21_cos(S21_INF)};
  // for (int i = 0; i < 5; ++i) ck_assert_uint_eq(check.bits[i], result.bits[i]);
}
END_TEST

START_TEST(cos_INFINITYL) {
  // -NAN
  ck_assert(!precision_check(s21_cos(-S21_INF), cos(-S21_INF), false));
  // ld_bits check = {cos(-S21_INF)};
  // ld_bits result = {s21_cos(-S21_INF)};
  // for (int i = 0; i < 5; ++i) ck_assert_uint_eq(check.bits[i], result.bits[i]);
}
END_TEST

START_TEST(s21_cos_max_double) {
  // -0.999988
  ck_assert(!precision_check(s21_cos(S21_double_MAX), cos(S21_double_MAX), false));
  // ck_assert_double_eq_tol(cos(S21_double_MAX), s21_cos(S21_double_MAX), S21_EPS);
}
END_TEST

START_TEST(s21_cos_max_double_neg) {
  // -0.999988
  ck_assert(!precision_check(s21_cos(-S21_double_MAX), cos(-S21_double_MAX), false));
  // ck_assert_double_eq_tol(cos(S21_double_MAX), s21_cos(S21_double_MAX), S21_EPS);
}
END_TEST

START_TEST(s21_cos_min_double) {
  // 1.0
  ck_assert(!precision_check(s21_cos(S21_double_MIN), cos(S21_double_MIN), false));
  // ck_assert_ldouble_eq_tol(s21_cos(S21_double_MIN), cos(S21_double_MIN), S21_EPS);
}
END_TEST

START_TEST(s21_cos_min_double_neg) {
  // 1.0
  ck_assert(!precision_check(s21_cos(-S21_double_MIN), cos(-S21_double_MIN), false));
  // ck_assert_ldouble_eq_tol(s21_cos(S21_double_MIN), cos(S21_double_MIN), S21_EPS);
}
END_TEST

Suite *s21_cos_cases(void) {
  Suite *c = suite_create("s21_cos_cases");
  TCase *tc = tcase_create("s21_cos_tc");

  tcase_add_test(tc, cos_09);
  tcase_add_test(tc, cos_1);
  tcase_add_test(tc, cos_100);
  tcase_add_test(tc, cos_NAN);
  tcase_add_test(tc, cos_NAN2);
  tcase_add_test(tc, cos_INFINITY);
  tcase_add_test(tc, cos_INFINITYL);
  tcase_add_test(tc, s21_cos_max_double);
  tcase_add_test(tc, s21_cos_max_double_neg);
  tcase_add_test(tc, s21_cos_min_double);
  tcase_add_test(tc, s21_cos_min_double_neg);

  suite_add_tcase(c, tc);
  return c;
}
