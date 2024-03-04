#include "s21_math_test.h"

START_TEST(fabs_fn) {
  ck_assert(!precision_check(s21_fabs(-612367.54783), fabs(-612367.54783), false));
  ck_assert(!precision_check(s21_fabs(-45.345), fabs(-45.345), false));
  ck_assert(!precision_check(s21_fabs(1.0), fabs(1.0), false));
  // ck_assert_ldouble_eq(s21_fabs(-612367.54783), fabs(-612367.54783));
  // ck_assert_ldouble_eq(s21_fabs(-45.345), fabs(-45.345));
  // ck_assert_ldouble_eq(s21_fabs(1.0), fabs(1.0));
  // ck_assert_ldouble_eq(s21_fabs(S21_INF), fabs(S21_INF));
  // ck_assert_ldouble_eq(s21_fabs(-S21_INF), fabs(-S21_INF));
  // ld_bits check = {fabs(S21_NAN)};
  // ld_bits result = {s21_fabs(S21_NAN)};
  // for (int i = 0; i < 5; ++i) ck_assert_uint_eq(check.bits[i], result.bits[i]);
  // check.full = fabs(-S21_NAN);
  // result.full = s21_fabs(-S21_NAN);
  // for (int i = 0; i < 5; ++i) ck_assert_uint_eq(check.bits[i], result.bits[i]);
}
END_TEST

START_TEST(s21_fabs_inf) {
  // INF
  ck_assert(!precision_check(s21_fabs(S21_INF), fabs(S21_INF), false));
  // ck_assert_ldouble_eq(fabs(S21_INF), s21_fabs(S21_INF));
}
END_TEST

START_TEST(s21_fabs_inf_negative) {
  // INF
  ck_assert(!precision_check(s21_fabs(-S21_INF), fabs(-S21_INF), false));
  // ck_assert_ldouble_eq(fabs(-S21_INF), s21_fabs(-S21_INF));
}
END_TEST

START_TEST(s21_fabs_nan) {
  // NAN
  ck_assert(!precision_check(s21_fabs(S21_NAN), fabs(S21_NAN), false));
  // ld_bits check = {fabs(S21_NAN)};
  // ld_bits result = {s21_fabs(S21_NAN)};
  // for (int i = 0; i < 5; ++i)  ck_assert_uint_eq(check.bits[i], result.bits[i]);
}
END_TEST

START_TEST(s21_fabs_nan_negative) {
  // NAN
  ck_assert(!precision_check(s21_fabs(-S21_NAN), fabs(-S21_NAN), false));
  // ld_bits check = {fabs(-S21_NAN)};
  // ld_bits result = {s21_fabs(-S21_NAN)};
  // for (int i = 0; i < 5; ++i)  ck_assert_uint_eq(check.bits[i], result.bits[i]);
  }
END_TEST

START_TEST(s21_fabs_max_double) {
  // S21_double_MAX
  ck_assert(!precision_check(s21_fabs(S21_double_MAX), fabs(S21_double_MAX), false));
  // ck_assert_double_eq_tol(fabs(S21_double_MAX), s21_fabs(S21_double_MAX), S21_EPS);
}
END_TEST

START_TEST(s21_fabs_max_double_neg) {
  // S21_double_MAX
  ck_assert(!precision_check(s21_fabs(-S21_double_MAX), fabs(-S21_double_MAX), false));
  // ck_assert_double_eq_tol(fabs(S21_double_MAX), s21_fabs(S21_double_MAX), S21_EPS);
}
END_TEST

START_TEST(s21_fabs_min_double) {
  // 0.0
  ck_assert(!precision_check(s21_fabs(S21_double_MIN), fabs(S21_double_MIN), false));
  // ck_assert_ldouble_eq_tol(s21_fabs(S21_double_MIN), fabs(S21_double_MIN), S21_EPS);
}
END_TEST

START_TEST(s21_fabs_min_double_neg) {
  // 0.0
  ck_assert(!precision_check(s21_fabs(-S21_double_MIN), fabs(-S21_double_MIN), false));
  // ck_assert_ldouble_eq_tol(s21_fabs(S21_double_MIN), fabs(S21_double_MIN), S21_EPS);
}
END_TEST

START_TEST(s21_fabs_fn) {
  ck_assert(!precision_check(s21_fabs(-612367.54783), fabs(-612367.54783), false));
  ck_assert(!precision_check(s21_fabs(-45.345), fabs(-45.345), false));
  ck_assert(!precision_check(s21_fabs(68845.345), fabs(68845.345), false));
  ck_assert(!precision_check(s21_fabs(1.0), fabs(1.0), false));
  ck_assert(!precision_check(s21_fabs(-1.1515), fabs(-1.1515), false));
  ck_assert(!precision_check(s21_fabs(0.0), fabs(0.0), false));
  // printf("\n%Lf\n%f\n\n", s21_fabs(-0.0), fabs(-0.0));
  ck_assert(!precision_check(s21_fabs(-0.0), fabs(-0.0), false));
  // ck_assert_ldouble_eq_tol(s21_fabs(-612367.54783), fabs(-612367.54783), 1e-07);
  // ck_assert_ldouble_eq_tol(s21_fabs(-45.345), fabs(-45.345), 1e-07);
  // ck_assert_ldouble_eq_tol(s21_fabs(68845.345), fabs(68845.345), 1e-07);
  // ck_assert_ldouble_eq_tol(s21_fabs(1.0), fabs(1.0), 1e-07);
  // ck_assert_ldouble_eq_tol(s21_fabs(-1.1515), fabs(-1.1515), 1e-07);
  // ck_assert_ldouble_eq_tol(s21_fabs(0.0), fabs(0.0), 1e-07);
  // ck_assert_ldouble_eq_tol(s21_fabs(-0.0), fabs(-0.0), 1e-07);
  // ck_assert_ldouble_eq(s21_fabs(NAN), fabs(NAN));
  //ck_assert_ldouble_eq(s21_fabs(-NAN), fabs(-NAN));
  // ck_assert_ldouble_eq(s21_fabs(INFINITY), fabs(INFINITY));
  // ck_assert_ldouble_eq(s21_fabs(-INFINITY), fabs(-INFINITY));

}
END_TEST

Suite *s21_fabs_cases(void) {
  Suite *c = suite_create("s21_fabs_cases");
  TCase *tc = tcase_create("s21_fabs_tc");

  tcase_add_test(tc, fabs_fn);
  tcase_add_test(tc, s21_fabs_inf);
  tcase_add_test(tc, s21_fabs_inf_negative);
  tcase_add_test(tc, s21_fabs_nan);
  tcase_add_test(tc, s21_fabs_nan_negative);
  tcase_add_test(tc, s21_fabs_fn);
  tcase_add_test(tc, s21_fabs_max_double);
  tcase_add_test(tc, s21_fabs_max_double_neg);
  tcase_add_test(tc, s21_fabs_min_double);
  tcase_add_test(tc, s21_fabs_min_double_neg);
  suite_add_tcase(c, tc);

  return c;
}
