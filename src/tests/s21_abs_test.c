#include "s21_math_test.h"

START_TEST(s21_abs_fn) {
  ck_assert_int_eq(s21_abs(-45785), abs(-45785));
  ck_assert_int_eq(s21_abs(478912), abs(478912));
  ck_assert_int_eq(s21_abs(-2147483648), abs(-2147483648));
  ck_assert_int_eq(s21_abs(2147483648), abs(2147483648));
  ck_assert_int_eq(s21_abs(0), abs(0));
  ck_assert_int_eq(s21_abs(NAN), abs(NAN));
  ck_assert_int_eq(s21_abs(-NAN), abs(-NAN));
  ck_assert_int_eq(s21_abs(INFINITY), abs(INFINITY));
  ck_assert_int_eq(s21_abs(-INFINITY), abs(-INFINITY));
}
END_TEST

Suite *s21_abs_cases(void) {
  Suite *c = suite_create("s21_abs_cases");
  TCase *tc = tcase_create("s21_abs_tc");

  tcase_add_test(tc, s21_abs_fn);

  suite_add_tcase(c, tc);

  return c;
}