#include "s21_math_test.h"

START_TEST(s21_sqrt_negative) {
  // -NAN
  ld_bits check = {sqrt(-2)};
  ld_bits result = {s21_sqrt(-2)};
  for (int i = 0; i < 5; ++i) ck_assert_uint_eq(check.bits[i], result.bits[i]);
}
END_TEST

START_TEST(s21_sqrt_inf) {
  // INF
  ck_assert_ldouble_eq(sqrt(S21_INF), s21_sqrt(S21_INF));
}
END_TEST

START_TEST(s21_sqrt_inf_negative) {
  // -NAN
  ld_bits check = {sqrt(-S21_INF)};
  ld_bits result = {s21_sqrt(-S21_INF)};
  for (int i = 0; i < 5; ++i)  ck_assert_uint_eq(check.bits[i], result.bits[i]);
}
END_TEST

START_TEST(s21_sqrt_nan) {
  // NAN
  ld_bits check = {sqrt(S21_NAN)};
  ld_bits result = {s21_sqrt(S21_NAN)};
  for (int i = 0; i < 5; ++i)  ck_assert_uint_eq(check.bits[i], result.bits[i]);
}
END_TEST

START_TEST(s21_sqrt_nan_negative) {
  // -NAN
  ld_bits check = {sqrt(-S21_NAN)};
  ld_bits result = {s21_sqrt(-S21_NAN)};
  for (int i = 0; i < 5; ++i)  ck_assert_uint_eq(check.bits[i], result.bits[i]);
}
END_TEST

START_TEST(s21_sqrt_normal_1) {
  // 2.0
  ck_assert_double_eq_tol(sqrt(4), s21_sqrt(4), S21_EPS);
}
END_TEST

START_TEST(s21_sqrt_normal_2) {
  // 22.627417
  ck_assert_ldouble_eq_tol(sqrt(512), s21_sqrt(512), S21_EPS);
}
END_TEST

START_TEST(s21_sqrt_max_double) {
  // 13407807929942595611008317640802934282464207265959107021466054756094376573581619054852612241927956455650759996398703782412109633178814162067569513603268608.000000
  printf("\n%f\n%Lf\n\n", sqrt(S21_double_MAX), s21_sqrt(S21_double_MAX));
  ck_assert_double_eq_tol(sqrt(S21_double_MAX), s21_sqrt(S21_double_MAX), S21_EPS);
}
END_TEST

START_TEST(s21_sqrt_min_double) {
  // 0.0
  ck_assert_ldouble_eq_tol(s21_sqrt(S21_double_MIN), sqrt(S21_double_MIN), S21_EPS);
}
END_TEST

Suite *s21_sqrt_cases(void) {
  Suite *c = suite_create("s21_sqrt_cases");
  TCase *tc = tcase_create("s21_sqrt_tc");
  tcase_add_test(tc, s21_sqrt_negative);
  tcase_add_test(tc, s21_sqrt_inf);
  tcase_add_test(tc, s21_sqrt_inf_negative);
  tcase_add_test(tc, s21_sqrt_nan);
  tcase_add_test(tc, s21_sqrt_nan_negative);
  tcase_add_test(tc, s21_sqrt_normal_1);
  tcase_add_test(tc, s21_sqrt_normal_2);
  tcase_add_test(tc, s21_sqrt_max_double);
  tcase_add_test(tc, s21_sqrt_min_double);
  suite_add_tcase(c, tc);
  return c;
}
