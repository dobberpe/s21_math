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
}
END_TEST

START_TEST(s21_floor_inf) {
  // INF
  ck_assert(!precision_check(s21_floor(S21_INF), floor(S21_INF), false));
}
END_TEST

START_TEST(s21_floor_inf_negative) {
  // -INF
  ck_assert_ldouble_eq(s21_floor(-S21_INF), floor(-S21_INF));
}
END_TEST

START_TEST(s21_floor_nan) {
  // NAN
  ck_assert(!precision_check(s21_floor(S21_NAN), floor(S21_NAN), false));
}
END_TEST

START_TEST(s21_floor_nan_negative) {
  // -NAN
  ck_assert(!precision_check(s21_floor(-S21_NAN), floor(-S21_NAN), false));
}
END_TEST

START_TEST(s21_floor_max_double) {
  // S21_double_MAX
  ck_assert(!precision_check(s21_floor(S21_double_MAX), floor(S21_double_MAX),
                             false));
}
END_TEST

START_TEST(s21_floor_max_double_neg) {
  // S21_double_MAX
  ck_assert(!precision_check(s21_floor(-S21_double_MAX), floor(-S21_double_MAX),
                             false));
}
END_TEST

START_TEST(s21_floor_max_double_neg1) {
  // S21_double_MAX
  ck_assert(!precision_check(s21_floor(-S21_double_MAX / 1),
                             floor(-S21_double_MAX / 1), false));
}
END_TEST

START_TEST(s21_floor_min_double) {
  // 0.0
  ck_assert(!precision_check(s21_floor(S21_double_MIN), floor(S21_double_MIN),
                             false));
}
END_TEST

START_TEST(s21_floor_min_double_neg) {
  // 0.0
  ck_assert(!precision_check(s21_floor(-S21_double_MIN), floor(-S21_double_MIN),
                             false));
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
