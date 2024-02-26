#include "s21_math_test.h"

START_TEST(s21_negative) {
  // -NAN
  double value = -2;
  long double check = sqrt(value);
  long double result = s21_sqrt(value);
  ck_assert_ldouble_lt(fabsl(check - result), S21_EPS);
}
END_TEST

START_TEST(s21_inf) {
  // INF
  double value = INFINITY;
  long double check = sqrt(value);
  long double result = s21_sqrt(value);
  ck_assert_ldouble_lt(fabsl(check - result), S21_EPS);
}
END_TEST

START_TEST(s21_inf_negative) {
  // -NAN
  double value = -INFINITY;
  long double check = sqrt(value);
  long double result = s21_sqrt(value);
  ck_assert_ldouble_lt(fabsl(check - result), S21_EPS);
}
END_TEST

START_TEST(s21_nan) {
  // NAN
  double value = NAN;
  long double check = sqrt(value);
  long double result = s21_sqrt(value);
  ck_assert_ldouble_lt(fabsl(check - result), S21_EPS);
}
END_TEST

START_TEST(s21_nan_negative) {
  // -NAN
  double value = -NAN;
  long double check = sqrt(value);
  long double result = s21_sqrt(value);
  ck_assert_ldouble_lt(fabsl(check - result), S21_EPS);
}
END_TEST

START_TEST(s21_normal_1) {
  // 2.0
  double value = 4;
  long double check = sqrt(value);
  long double result = s21_sqrt(value);
  ck_assert_ldouble_lt(fabsl(check - result), S21_EPS);
}
END_TEST

START_TEST(s21_normal_2) {
  // 22.627417
  double value = 512;
  long double check = sqrt(value);
  long double result = s21_sqrt(value);
  ck_assert_ldouble_lt(fabsl(check - result), S21_EPS);
}
END_TEST

Suite *s21_converter_cases(void) {
  Suite *c = suite_create("s21_sqrt_cases");
  TCase *tc = tcase_create("s21_sqrt_tc");
  tcase_add_test(tc, s21_negative);
  tcase_add_test(tc, s21_inf);
  tcase_add_test(tc, s21_inf_negative);
  tcase_add_test(tc, s21_nan);
  tcase_add_test(tc, s21_nan_negative);
  tcase_add_test(tc, s21_normal_1);
  tcase_add_test(tc, s21_normal_2);
  suite_add_tcase(c, tc);
  return c;
}
