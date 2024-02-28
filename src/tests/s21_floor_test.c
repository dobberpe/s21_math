#include "s21_math_test.h"

START_TEST(floor_fn) {
  ck_assert_uint_eq(s21_floor(1.5), 1);
  ck_assert_uint_eq(s21_floor(0.45), 0);
  ck_assert_uint_eq(s21_floor(4), 4);
  ck_assert_uint_eq(s21_floor(0.000001), 0);
  ck_assert_uint_eq(s21_floor(-3.01), -4);
  ck_assert_uint_eq(s21_floor(-0.24), -1);
  ck_assert_uint_eq(s21_floor(0.0), 0);
  ck_assert_uint_eq(s21_floor(-1.5), -2);
  ck_assert_uint_eq(s21_floor(1.99), 1);
  ck_assert_uint_eq(s21_floor(1.99), 1);
  ck_assert_uint_eq(s21_floor(6.75), 6);
  ck_assert_uint_eq(s21_floor(-1.0), -1);
  ck_assert_uint_eq(s21_floor(2.0), 2);
  ck_assert_uint_eq(s21_floor(2), 2);
  ck_assert_uint_eq(s21_floor(5), 5);
}
END_TEST

START_TEST(s21_floor_inf) {
  // INF
  ck_assert_ldouble_eq(floor(S21_INF), s21_floor(S21_INF));
}
END_TEST

START_TEST(s21_floor_inf_negative) {
  // INF
  ck_assert_ldouble_eq(floor(-S21_INF), s21_floor(-S21_INF));
}
END_TEST

START_TEST(s21_floor_nan) {
  // NAN
  ld_bits check = {floor(S21_NAN)};
  ld_bits result = {s21_floor(S21_NAN)};
  for (int i = 0; i < 5; ++i)  ck_assert_uint_eq(check.bits[i], result.bits[i]);
}
END_TEST

START_TEST(s21_floor_nan_negative) {
  // NAN
  ld_bits check = {floor(-S21_NAN)};
  ld_bits result = {s21_floor(-S21_NAN)};
  for (int i = 0; i < 5; ++i)  ck_assert_uint_eq(check.bits[i], result.bits[i]);
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

  suite_add_tcase(c, tc);

  return c;
}
