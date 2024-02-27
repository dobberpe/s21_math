#include "s21_math_test.h"

START_TEST(s21_pow_inf_inf) {
  // -NAN
  ck_assert_ldouble_eq(pow(INFINITY, INFINITY), s21_pow(INFINITY, INFINITY));
}
END_TEST

START_TEST(s21_pow_inf_inf_neg) {
  // -NAN
  ck_assert_ldouble_eq(pow(INFINITY, -INFINITY), s21_pow(INFINITY, -INFINITY));
}
END_TEST

START_TEST(s21_pow_inf_nan) {
  // -NAN
  ck_assert_ldouble_eq(pow(INFINITY, NAN), s21_pow(INFINITY, NAN));
}
END_TEST

START_TEST(s21_pow_inf_nan_neg) {
  // -NAN
  ck_assert_ldouble_eq(pow(INFINITY, -NAN), s21_pow(INFINITY, -NAN));
}
END_TEST

START_TEST(s21_pow_inf_neg_inf) {
  // -NAN
  ck_assert_ldouble_eq(pow(-INFINITY, INFINITY), s21_pow(-INFINITY, INFINITY));
}
END_TEST

START_TEST(s21_pow_inf_neg_inf_neg) {
  // -NAN
  ck_assert_ldouble_eq(pow(-INFINITY, -INFINITY), s21_pow(-INFINITY, -INFINITY));
}
END_TEST

START_TEST(s21_pow_inf_neg_nan) {
  // -NAN
  ck_assert_ldouble_eq(pow(-INFINITY, NAN), s21_pow(-INFINITY, NAN));
}
END_TEST

START_TEST(s21_pow_inf_neg_nan_neg) {
  // -NAN
  ck_assert_ldouble_eq(pow(-INFINITY, -NAN), s21_pow(-INFINITY, -NAN));
}
END_TEST

START_TEST(s21_pow_nan_inf) {
  // -NAN
  ck_assert_ldouble_eq(pow(NAN, INFINITY), s21_pow(NAN, INFINITY));
}
END_TEST

START_TEST(s21_pow_nan_inf_neg) {
  // -NAN
  ck_assert_ldouble_eq(pow(NAN, -INFINITY), s21_pow(NAN, -INFINITY));
}
END_TEST

START_TEST(s21_pow_nan_nan) {
  // -NAN
  ck_assert_ldouble_eq(pow(NAN, NAN), s21_pow(NAN, NAN));
}
END_TEST

START_TEST(s21_pow_nan_nan_neg) {
  // -NAN
  ck_assert_ldouble_eq(pow(NAN, -NAN), s21_pow(NAN, -NAN));
}
END_TEST

START_TEST(s21_pow_nan_neg_inf) {
  // -NAN
  ck_assert_ldouble_eq(pow(-NAN, INFINITY), s21_pow(-NAN, INFINITY));
}
END_TEST

START_TEST(s21_pow_nan_neg_inf_neg) {
  // -NAN
  ck_assert_ldouble_eq(pow(-NAN, -INFINITY), s21_pow(-NAN, -INFINITY));
}
END_TEST

START_TEST(s21_pow_nan_neg_nan) {
  // -NAN
  ck_assert_ldouble_eq(pow(-NAN, NAN), s21_pow(-NAN, NAN));
}
END_TEST

START_TEST(s21_pow_nan_neg_nan_neg) {
  // -NAN
  ck_assert_ldouble_eq(pow(-NAN, -NAN), s21_pow(-NAN, -NAN));
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
