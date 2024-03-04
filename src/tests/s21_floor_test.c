#include "s21_math_test.h"

START_TEST(floor_fn) {
  ck_assert(!precision_check(s21_floor(1.5), floor(1.5), false));
  ck_assert(!precision_check(s21_floor(0.45), floor(0.45), false));
  ck_assert(!precision_check(s21_floor(4), floor(4), false));
  ck_assert(!precision_check(s21_floor(0.000001), floor(0.000001), false));
  ck_assert(!precision_check(s21_floor(-3.01), floor(-3.01), false));
  ck_assert(!precision_check(s21_floor(-0.24), floor(-0.24), false));
  ck_assert(!precision_check(s21_floor(0.0), floor(0.0), false));
  ck_assert(!precision_check(s21_floor(-1.5), floor(-1.5), false));
  ck_assert(!precision_check(s21_floor(1.99), floor(1.99), false));
  ck_assert(!precision_check(s21_floor(6.75), floor(6.75), false));
  ck_assert(!precision_check(s21_floor(-1.0), floor(-1.0), false));
  ck_assert(!precision_check(s21_floor(2.0), floor(2.0), false));
  ck_assert(!precision_check(s21_floor(2), floor(2), false));
  ck_assert(!precision_check(s21_floor(5), floor(5), false));
  // ck_assert_uint_eq(s21_floor(1.5), 1);
  // ck_assert_uint_eq(s21_floor(0.45), 0);
  // ck_assert_uint_eq(s21_floor(4), 4);
  // ck_assert_uint_eq(s21_floor(0.000001), 0);
  // ck_assert_uint_eq(s21_floor(-3.01), -4);
  // ck_assert_uint_eq(s21_floor(-0.24), -1);
  // ck_assert_uint_eq(s21_floor(0.0), 0);
  // ck_assert_uint_eq(s21_floor(-1.5), -2);
  // ck_assert_uint_eq(s21_floor(1.99), 1);
  // ck_assert_uint_eq(s21_floor(1.99), 1);
  // ck_assert_uint_eq(s21_floor(6.75), 6);
  // ck_assert_uint_eq(s21_floor(-1.0), -1);
  // ck_assert_uint_eq(s21_floor(2.0), 2);
  // ck_assert_uint_eq(s21_floor(2), 2);
  // ck_assert_uint_eq(s21_floor(5), 5);
}
END_TEST

START_TEST(s21_floor_inf) {
  // INF
  ck_assert(!precision_check(s21_floor(S21_INF), floor(S21_INF), false));
  // ck_assert_ldouble_eq(floor(S21_INF), s21_floor(S21_INF));
}
END_TEST

START_TEST(s21_floor_inf_negative) {
  // -INF
  ck_assert(!precision_check(s21_floor(-S21_INF), floor(-S21_INF), false));
  // ck_assert_ldouble_eq(floor(-S21_INF), s21_floor(-S21_INF));
}
END_TEST

START_TEST(s21_floor_nan) {
  // NAN
  ck_assert(!precision_check(s21_floor(S21_NAN), floor(S21_NAN), false));
  // ld_bits check = {floor(S21_NAN)};
  // ld_bits result = {s21_floor(S21_NAN)};
  // for (int i = 0; i < 5; ++i)  ck_assert_uint_eq(check.bits[i], result.bits[i]);
}
END_TEST

START_TEST(s21_floor_nan_negative) {
  // -NAN
  ck_assert(!precision_check(s21_floor(-S21_NAN), floor(-S21_NAN), false));
  // ld_bits check = {floor(-S21_NAN)};
  // ld_bits result = {s21_floor(-S21_NAN)};
  // for (int i = 0; i < 5; ++i)  ck_assert_uint_eq(check.bits[i], result.bits[i]);
}
END_TEST

START_TEST(s21_floor_max_double) {
  // S21_double_MAX
  ck_assert(!precision_check(s21_floor(S21_double_MAX), floor(S21_double_MAX), false));
  // ck_assert_double_eq_tol(floor(S21_double_MAX), s21_floor(S21_double_MAX), S21_EPS);
}
END_TEST

START_TEST(s21_floor_max_double_neg) {
  // S21_double_MAX
  ck_assert(!precision_check(s21_floor(-S21_double_MAX), floor(-S21_double_MAX), false));
  // ck_assert_double_eq_tol(floor(S21_double_MAX), s21_floor(S21_double_MAX), S21_EPS);
}
END_TEST

START_TEST(s21_floor_max_double_neg1) {
  // S21_double_MAX
  // printf("\n%.6Lf\n%.6f\n\n", s21_floor(-S21_double_MAX / 1), floor(-S21_double_MAX / 1));
  ck_assert(!precision_check(s21_floor(-S21_double_MAX / 1), floor(-S21_double_MAX / 1), false));
  // ck_assert_double_eq_tol(floor(S21_double_MAX), s21_floor(S21_double_MAX), S21_EPS);
}
END_TEST

START_TEST(s21_floor_min_double) {
  // 0.0
  ck_assert(!precision_check(s21_floor(S21_double_MIN), floor(S21_double_MIN), false));
  // ck_assert_ldouble_eq_tol(s21_floor(S21_double_MIN), floor(S21_double_MIN), S21_EPS);
}
END_TEST

START_TEST(s21_floor_min_double_neg) {
  // 0.0
  ck_assert(!precision_check(s21_floor(-S21_double_MIN), floor(-S21_double_MIN), false));
  // ck_assert_ldouble_eq_tol(s21_floor(S21_double_MIN), floor(S21_double_MIN), S21_EPS);
}
END_TEST


Suite *s21_floor_cases(void) {
  Suite *c = suite_create("s21_floor_cases");
  TCase *tc = tcase_create("s21_floor_tc");

  tcase_add_test(tc, floor_fn);
  tcase_add_test(tc, s21_floor_inf);
  tcase_add_test(tc, s21_floor_inf_negative);
  tcase_add_test(tc, s21_floor_nan);
  tcase_add_test(tc, s21_floor_nan_negative);
  tcase_add_test(tc, s21_floor_max_double);
  tcase_add_test(tc, s21_floor_max_double_neg);
  tcase_add_test(tc, s21_floor_max_double_neg1);
  tcase_add_test(tc, s21_floor_min_double);
  tcase_add_test(tc, s21_floor_min_double_neg);

  suite_add_tcase(c, tc);

  return c;
}
