#include "s21_math_test.h"

START_TEST(fabs_fn) {
  ck_assert_uint_eq(s21_fabs(-612367.54783), fabs(-612367.54783));
  ck_assert_uint_eq(s21_fabs(-45.345), fabs(-45.345));
  ck_assert_uint_eq(s21_fabs(1.0), fabs(1.0));
}
END_TEST

Suite *s21_fabs_cases(void) {
  Suite *c = suite_create("s21_fabs_cases");
  TCase *tc = tcase_create("s21_fabs_tc");

  tcase_add_test(tc, fabs_fn);

  suite_add_tcase(c, tc);

  return c;
}
