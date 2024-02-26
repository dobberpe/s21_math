#include "s21_math_test.h"

START_TEST(s21_fmod_inf_inf) {
  // -NAN
  double x = INFINITY, y = INFINITY;
  long double check = fmod(x, y);
  long double result = s21_fmod(x, y);
  ck_assert_ldouble_lt(fabsl(check - result), S21_EPS);
}
END_TEST

START_TEST(s21_fmod_inf_inf_neg) {
  // -NAN
  double x = INFINITY, y = -INFINITY;
  long double check = fmod(x, y);
  long double result = s21_fmod(x, y);
  ck_assert_ldouble_lt(fabsl(check - result), S21_EPS);
}
END_TEST

START_TEST(s21_fmod_inf_nan) {
  // -NAN
  double x = INFINITY, y = NAN;
  long double check = fmod(x, y);
  long double result = s21_fmod(x, y);
  ck_assert_ldouble_lt(fabsl(check - result), S21_EPS);
}
END_TEST

START_TEST(s21_fmod_inf_nan_neg) {
  // -NAN
  double x = INFINITY, y = -NAN;
  long double check = fmod(x, y);
  long double result = s21_fmod(x, y);
  ck_assert_ldouble_lt(fabsl(check - result), S21_EPS);
}
END_TEST

START_TEST(s21_fmod_inf_neg_inf) {
  // -NAN
  double x = -INFINITY, y = INFINITY;
  long double check = fmod(x, y);
  long double result = s21_fmod(x, y);
  ck_assert_ldouble_lt(fabsl(check - result), S21_EPS);
}
END_TEST

START_TEST(s21_fmod_inf_neg_inf_neg) {
  // -NAN
  double x = -INFINITY, y = -INFINITY;
  long double check = fmod(x, y);
  long double result = s21_fmod(x, y);
  ck_assert_ldouble_lt(fabsl(check - result), S21_EPS);
}
END_TEST

START_TEST(s21_fmod_inf_neg_nan) {
  // -NAN
  double x = -INFINITY, y = NAN;
  long double check = fmod(x, y);
  long double result = s21_fmod(x, y);
  ck_assert_ldouble_lt(fabsl(check - result), S21_EPS);
}
END_TEST

START_TEST(s21_fmod_inf_neg_nan_neg) {
  // -NAN
  double x = -INFINITY, y = -NAN;
  long double check = fmod(x, y);
  long double result = s21_fmod(x, y);
  ck_assert_ldouble_lt(fabsl(check - result), S21_EPS);
}
END_TEST

START_TEST(s21_fmod_nan_inf) {
  // -NAN
  double x = NAN, y = INFINITY;
  long double check = fmod(x, y);
  long double result = s21_fmod(x, y);
  ck_assert_ldouble_lt(fabsl(check - result), S21_EPS);
}
END_TEST

START_TEST(s21_fmod_nan_inf_neg) {
  // -NAN
  double x = NAN, y = -INFINITY;
  long double check = fmod(x, y);
  long double result = s21_fmod(x, y);
  ck_assert_ldouble_lt(fabsl(check - result), S21_EPS);
}
END_TEST

START_TEST(s21_fmod_nan_nan) {
  // -NAN
  double x = NAN, y = NAN;
  long double check = fmod(x, y);
  long double result = s21_fmod(x, y);
  ck_assert_ldouble_lt(fabsl(check - result), S21_EPS);
}
END_TEST

START_TEST(s21_fmod_nan_nan_neg) {
  // -NAN
  double x = NAN, y = -NAN;
  long double check = fmod(x, y);
  long double result = s21_fmod(x, y);
  ck_assert_ldouble_lt(fabsl(check - result), S21_EPS);
}
END_TEST

START_TEST(s21_fmod_nan_neg_inf) {
  // -NAN
  double x = -NAN, y = INFINITY;
  long double check = fmod(x, y);
  long double result = s21_fmod(x, y);
  ck_assert_ldouble_lt(fabsl(check - result), S21_EPS);
}
END_TEST

START_TEST(s21_fmod_nan_neg_inf_neg) {
  // -NAN
  double x = -NAN, y = -INFINITY;
  long double check = fmod(x, y);
  long double result = s21_fmod(x, y);
  ck_assert_ldouble_lt(fabsl(check - result), S21_EPS);
}
END_TEST

START_TEST(s21_fmod_nan_neg_nan) {
  // -NAN
  double x = -NAN, y = NAN;
  long double check = fmod(x, y);
  long double result = s21_fmod(x, y);
  ck_assert_ldouble_lt(fabsl(check - result), S21_EPS);
}
END_TEST

START_TEST(s21_fmod_nan_neg_nan_neg) {
  // -NAN
  double x = -NAN, y = -NAN;
  long double check = fmod(x, y);
  long double result = s21_fmod(x, y);
  ck_assert_ldouble_lt(fabsl(check - result), S21_EPS);
}
END_TEST

Suite *s21_fmod_cases(void) {
  Suite *c = suite_create("s21_fmod_cases");
  TCase *tc = tcase_create("s21_fmod_tc");
  tcase_add_test(tc, s21_fmod_inf_inf);
  tcase_add_test(tc, s21_fmod_inf_inf_neg);
  tcase_add_test(tc, s21_fmod_inf_nan);
  tcase_add_test(tc, s21_fmod_inf_nan_neg);
  tcase_add_test(tc, s21_fmod_inf_neg_inf);
  tcase_add_test(tc, s21_fmod_inf_neg_inf_neg);
  tcase_add_test(tc, s21_fmod_inf_neg_nan);
  tcase_add_test(tc, s21_fmod_inf_neg_nan_neg);
  tcase_add_test(tc, s21_fmod_nan_inf);
  tcase_add_test(tc, s21_fmod_nan_inf_neg);
  tcase_add_test(tc, s21_fmod_nan_nan);
  tcase_add_test(tc, s21_fmod_nan_nan_neg);
  tcase_add_test(tc, s21_fmod_nan_neg_inf);
  tcase_add_test(tc, s21_fmod_nan_neg_inf_neg);
  tcase_add_test(tc, s21_fmod_nan_neg_nan);
  tcase_add_test(tc, s21_fmod_nan_neg_nan_neg);
  suite_add_tcase(c, tc);
  return c;
}
