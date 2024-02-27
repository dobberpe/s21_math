#include "s21_math_test.h"

START_TEST(exp_fn) {
  ck_assert_uint_eq(s21_exp(5), exp(5));
  ck_assert_uint_eq(s21_exp(-2), exp(-2));
  ck_assert_uint_eq(s21_exp(1234567), exp(1234567));
  ck_assert_uint_eq(s21_exp(-1234567), exp(-1234567));
  for (double i = -10; i < 10; i++) {
    ck_assert_uint_eq(s21_exp(i), exp(i));
  }
  ck_assert(fabs((double)s21_exp(0.0) - exp(0.0)) < 0.00001);
  ck_assert(fabs((double)s21_exp(1.0) - exp(1.0)) < 0.00001);
  ck_assert(fabs((double)s21_exp(-1.0) - exp(-1.0)) < 0.00001);
  ck_assert(fabs((double)s21_exp(10.0) - exp(10.0)) < 0.00001);
  ck_assert(fabs((double)s21_exp(-10.0) - exp(-10.0)) < 0.00001);
  ck_assert(fabs((double)s21_exp(-100.0) - exp(-100.0)) < 0.00001);
  ck_assert(fabs((double)s21_exp(-1000.0) - exp(-1000.0)) < 0.00001);
  ck_assert(fabs((double)s21_exp(0.1) - exp(0.1)) < 0.00001);
  ck_assert(fabs((double)s21_exp(-0.1) - exp(-0.1)) < 0.00001);

  for (double i = -10000; i <= 10000; i += 1000) {
    ck_assert_double_eq(s21_exp(i), exp(i));
  }
}
END_TEST

Suite *s21_exp_cases(void) {
  Suite *c = suite_create("s21_exp_cases");
  TCase *tc = tcase_create("s21_exp_tc");

  tcase_add_test(tc, exp_fn);

  suite_add_tcase(c, tc);

  return c;
}
