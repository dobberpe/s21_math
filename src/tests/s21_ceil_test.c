#include "s21_math_test.h"

START_TEST(s21_ceil_fn) {
  ck_assert(!precision_check(s21_ceil(-0.1), ceil(-0.1), false));
  ck_assert(!precision_check(s21_ceil(-2.8), ceil(-2.8), false));
  ck_assert(!precision_check(s21_ceil(5.3), ceil(5.3), false));
  ck_assert(!precision_check(s21_ceil(50726), ceil(50726), false));
  ck_assert(!precision_check(s21_ceil(-0.0), ceil(-0.0), false));
  ck_assert(!precision_check(s21_ceil(0.0), ceil(0.0), false));
  ck_assert(!precision_check(s21_ceil(1.7e-308), ceil(1.7e-308), false));
}
END_TEST

START_TEST(s21_ceil_inf) {
  // INF
  ck_assert(!precision_check(s21_ceil(S21_INF), ceil(S21_INF), false));
}
END_TEST

START_TEST(s21_ceil_inf_negative) {
  // -INF
  ck_assert(!precision_check(s21_ceil(-S21_INF), ceil(-S21_INF), false));
  ck_assert_ldouble_eq(s21_ceil(-S21_INF), ceil(-S21_INF));
}
END_TEST

START_TEST(s21_ceil_nan) {
  // NAN
  ck_assert(!precision_check(s21_ceil(S21_NAN), ceil(S21_NAN), false));
}
END_TEST

START_TEST(s21_ceil_nan_negative) {
  // -NAN
  ck_assert(!precision_check(s21_ceil(-S21_NAN), ceil(-S21_NAN), false));
}
END_TEST

START_TEST(s21_ceil_max_double) {
  // S21_double_MAX
  ck_assert(
      !precision_check(s21_ceil(S21_double_MAX), ceil(S21_double_MAX), false));
}
END_TEST

START_TEST(s21_ceil_max_double_neg) {
  // S21_double_MAX
  ck_assert(!precision_check(s21_ceil(-S21_double_MAX), ceil(-S21_double_MAX),
                             false));
}
END_TEST

START_TEST(s21_ceil_min_double) {
  // 1.0
  ck_assert(
      !precision_check(s21_ceil(S21_double_MIN), ceil(S21_double_MIN), false));
}
END_TEST

START_TEST(s21_ceil_min_double_neg) {
  // 1.0
  ck_assert(!precision_check(s21_ceil(-S21_double_MIN), ceil(-S21_double_MIN),
                             false));
}
END_TEST

Suite *s21_ceil_cases(void) {
  Suite *c = suite_create("s21_ceil_cases");
  TCase *tc = tcase_create("s21_ceil_tc");

  tcase_add_test(tc, s21_ceil_fn);
  tcase_add_test(tc, s21_ceil_inf);
  tcase_add_test(tc, s21_ceil_inf_negative);
  tcase_add_test(tc, s21_ceil_nan);
  tcase_add_test(tc, s21_ceil_nan_negative);
  tcase_add_test(tc, s21_ceil_max_double);
  tcase_add_test(tc, s21_ceil_max_double_neg);
  tcase_add_test(tc, s21_ceil_min_double);
  tcase_add_test(tc, s21_ceil_min_double_neg);

  suite_add_tcase(c, tc);

  return c;
}