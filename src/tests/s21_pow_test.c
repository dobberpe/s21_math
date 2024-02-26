#include "s21_math_test.h"

START_TEST(s21_pow_inf_inf) {
  // -NAN
  double base = INFINITY, exp = INFINITY;
  long double check = pow(base, exp);
  long double result = s21_pow(base, exp);
  ck_assert_ldouble_lt(fabsl(check - result), S21_EPS);
}
END_TEST

START_TEST(s21_pow_inf_inf_neg) {
  // -NAN
  double base = INFINITY, exp = -INFINITY;
  long double check = pow(base, exp);
  long double result = s21_pow(base, exp);
  ck_assert_ldouble_lt(fabsl(check - result), S21_EPS);
}
END_TEST

START_TEST(s21_pow_inf_nan) {
  // -NAN
  double base = INFINITY, exp = NAN;
  long double check = pow(base, exp);
  long double result = s21_pow(base, exp);
  ck_assert_ldouble_lt(fabsl(check - result), S21_EPS);
}
END_TEST

START_TEST(s21_pow_inf_nan_neg) {
  // -NAN
  double base = INFINITY, exp = -NAN;
  long double check = pow(base, exp);
  long double result = s21_pow(base, exp);
  ck_assert_ldouble_lt(fabsl(check - result), S21_EPS);
}
END_TEST

START_TEST(s21_pow_inf_neg_inf) {
  // -NAN
  double base = -INFINITY, exp = INFINITY;
  long double check = pow(base, exp);
  long double result = s21_pow(base, exp);
  ck_assert_ldouble_lt(fabsl(check - result), S21_EPS);
}
END_TEST

START_TEST(s21_pow_inf_neg_inf_neg) {
  // -NAN
  double base = -INFINITY, exp = -INFINITY;
  long double check = pow(base, exp);
  long double result = s21_pow(base, exp);
  ck_assert_ldouble_lt(fabsl(check - result), S21_EPS);
}
END_TEST

START_TEST(s21_pow_inf_neg_nan) {
  // -NAN
  double base = -INFINITY, exp = NAN;
  long double check = pow(base, exp);
  long double result = s21_pow(base, exp);
  ck_assert_ldouble_lt(fabsl(check - result), S21_EPS);
}
END_TEST

START_TEST(s21_pow_inf_neg_nan_neg) {
  // -NAN
  double base = -INFINITY, exp = -NAN;
  long double check = pow(base, exp);
  long double result = s21_pow(base, exp);
  ck_assert_ldouble_lt(fabsl(check - result), S21_EPS);
}
END_TEST

START_TEST(s21_pow_nan_inf) {
  // -NAN
  double base = NAN, exp = INFINITY;
  long double check = pow(base, exp);
  long double result = s21_pow(base, exp);
  ck_assert_ldouble_lt(fabsl(check - result), S21_EPS);
}
END_TEST

START_TEST(s21_pow_nan_inf_neg) {
  // -NAN
  double base = NAN, exp = -INFINITY;
  long double check = pow(base, exp);
  long double result = s21_pow(base, exp);
  ck_assert_ldouble_lt(fabsl(check - result), S21_EPS);
}
END_TEST

START_TEST(s21_pow_nan_nan) {
  // -NAN
  double base = NAN, exp = NAN;
  long double check = pow(base, exp);
  long double result = s21_pow(base, exp);
  ck_assert_ldouble_lt(fabsl(check - result), S21_EPS);
}
END_TEST

START_TEST(s21_pow_nan_nan_neg) {
  // -NAN
  double base = NAN, exp = -NAN;
  long double check = pow(base, exp);
  long double result = s21_pow(base, exp);
  ck_assert_ldouble_lt(fabsl(check - result), S21_EPS);
}
END_TEST

START_TEST(s21_pow_nan_neg_inf) {
  // -NAN
  double base = -NAN, exp = INFINITY;
  long double check = pow(base, exp);
  long double result = s21_pow(base, exp);
  ck_assert_ldouble_lt(fabsl(check - result), S21_EPS);
}
END_TEST

START_TEST(s21_pow_nan_neg_inf_neg) {
  // -NAN
  double base = -NAN, exp = -INFINITY;
  long double check = pow(base, exp);
  long double result = s21_pow(base, exp);
  ck_assert_ldouble_lt(fabsl(check - result), S21_EPS);
}
END_TEST

START_TEST(s21_pow_nan_neg_nan) {
  // -NAN
  double base = -NAN, exp = NAN;
  long double check = pow(base, exp);
  long double result = s21_pow(base, exp);
  ck_assert_ldouble_lt(fabsl(check - result), S21_EPS);
}
END_TEST

START_TEST(s21_pow_nan_neg_nan_neg) {
  // -NAN
  double base = -NAN, exp = -NAN;
  long double check = pow(base, exp);
  long double result = s21_pow(base, exp);
  ck_assert_ldouble_lt(fabsl(check - result), S21_EPS);
}
END_TEST

Suite *s21_pow_cases(void) {
  Suite *c = suite_create("s21_pow_cases");
  TCase *tc = tcase_create("s21_pow_tc");
  tcase_add_test(tc, s21_pow_inf_inf);
  tcase_add_test(tc, s21_pow_inf_inf_neg);
  tcase_add_test(tc, s21_pow_inf_nan);
  tcase_add_test(tc, s21_pow_inf_nan_neg);
  tcase_add_test(tc, s21_pow_inf_neg_inf);
  tcase_add_test(tc, s21_pow_inf_neg_inf_neg);
  tcase_add_test(tc, s21_pow_inf_neg_nan);
  tcase_add_test(tc, s21_pow_inf_neg_nan_neg);
  tcase_add_test(tc, s21_pow_nan_inf);
  tcase_add_test(tc, s21_pow_nan_inf_neg);
  tcase_add_test(tc, s21_pow_nan_nan);
  tcase_add_test(tc, s21_pow_nan_nan_neg);
  tcase_add_test(tc, s21_pow_nan_neg_inf);
  tcase_add_test(tc, s21_pow_nan_neg_inf_neg);
  tcase_add_test(tc, s21_pow_nan_neg_nan);
  tcase_add_test(tc, s21_pow_nan_neg_nan_neg);
  suite_add_tcase(c, tc);
  return c;
}
