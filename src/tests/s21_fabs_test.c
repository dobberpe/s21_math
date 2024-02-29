#include "s21_math_test.h"

START_TEST(s21_fabs_fn) {
  ck_assert_ldouble_eq_tol(s21_fabs(-612367.54783), fabs(-612367.54783), 1e-07);
  ck_assert_ldouble_eq_tol(s21_fabs(-45.345), fabs(-45.345), 1e-07);
  ck_assert_ldouble_eq_tol(s21_fabs(68845.345), fabs(68845.345), 1e-07);
  ck_assert_ldouble_eq_tol(s21_fabs(1.0), fabs(1.0), 1e-07);
  ck_assert_ldouble_eq_tol(s21_fabs(-1.1515), fabs(-1.1515), 1e-07);
  ck_assert_ldouble_eq_tol(s21_fabs(0), fabs(0), 1e-07);
  ck_assert_ldouble_eq_tol(s21_fabs(-0), fabs(-0), 1e-07);
  ck_assert_ldouble_eq(s21_fabs(NAN), fabs(NAN));
  ck_assert_ldouble_eq(s21_fabs(-NAN), fabs(-NAN));
  ck_assert_ldouble_eq(s21_fabs(INFINITY), fabs(INFINITY));
  ck_assert_ldouble_eq(s21_fabs(-INFINITY), fabs(-INFINITY));

}
END_TEST

Suite *s21_fabs_cases(void) {
  Suite *c = suite_create("s21_fabs_cases");
  TCase *tc = tcase_create("s21_fabs_tc");

  tcase_add_test(tc, s21_fabs_fn);

  suite_add_tcase(c, tc);

  return c;
}
