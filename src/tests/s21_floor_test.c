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

Suite *s21_floor_cases(void) {
  Suite *c = suite_create("s21_floor_cases");
  TCase *tc = tcase_create("s21_floor_tc");

  tcase_add_test(tc, floor_fn);

  suite_add_tcase(c, tc);

  return c;
}
