#include "s21_math_test.h"

START_TEST(s21_fmod_inf_inf) {
  // -NAN
  ck_assert(!precision_check(s21_fmod(S21_INF, S21_INF), fmod(S21_INF, S21_INF),
                             false));
}
END_TEST

START_TEST(s21_fmod_inf_inf_neg) {
  // -NAN
  ck_assert(!precision_check(s21_fmod(S21_INF, -S21_INF),
                             fmod(S21_INF, -S21_INF), false));
}
END_TEST

START_TEST(s21_fmod_inf_nan) {
  // NAN
  ck_assert(!precision_check(s21_fmod(S21_INF, S21_NAN), fmod(S21_INF, S21_NAN),
                             false));
}
END_TEST

START_TEST(s21_fmod_inf_nan_neg) {
  // -NAN
  ck_assert(!precision_check(s21_fmod(S21_INF, -S21_NAN),
                             fmod(S21_INF, -S21_NAN), false));
}
END_TEST

START_TEST(s21_fmod_inf_neg_inf) {
  // -NAN
  ck_assert(!precision_check(s21_fmod(-S21_INF, S21_INF),
                             fmod(-S21_INF, S21_INF), false));
}
END_TEST

START_TEST(s21_fmod_inf_neg_inf_neg) {
  // -NAN
  ck_assert(!precision_check(s21_fmod(-S21_INF, -S21_INF),
                             fmod(-S21_INF, -S21_INF), false));
}
END_TEST

START_TEST(s21_fmod_inf_neg_nan) {
  // NAN
  ck_assert(!precision_check(s21_fmod(-S21_INF, S21_NAN),
                             fmod(-S21_INF, S21_NAN), false));
}
END_TEST

START_TEST(s21_fmod_inf_neg_nan_neg) {
  // -NAN
  ck_assert(!precision_check(s21_fmod(-S21_INF, -S21_NAN),
                             fmod(-S21_INF, -S21_NAN), false));
}
END_TEST

START_TEST(s21_fmod_nan_inf) {
  // NAN
  ck_assert(!precision_check(s21_fmod(S21_NAN, S21_INF), fmod(S21_NAN, S21_INF),
                             false));
}
END_TEST

START_TEST(s21_fmod_nan_inf_neg) {
  // NAN
  ck_assert(!precision_check(s21_fmod(S21_NAN, -S21_INF),
                             fmod(S21_NAN, -S21_INF), false));
}
END_TEST

START_TEST(s21_fmod_nan_nan) {
  // NAN
  ck_assert(!precision_check(s21_fmod(S21_NAN, S21_NAN), fmod(S21_NAN, S21_NAN),
                             false));
}
END_TEST

START_TEST(s21_fmod_nan_nan_neg) {
  // NAN
  ck_assert(!precision_check(s21_fmod(S21_NAN, -S21_NAN),
                             fmod(S21_NAN, -S21_NAN), false));
}
END_TEST

START_TEST(s21_fmod_nan_neg_inf) {
  // -NAN
  ck_assert(!precision_check(s21_fmod(-S21_NAN, S21_INF),
                             fmod(-S21_NAN, S21_INF), false));
}
END_TEST

START_TEST(s21_fmod_nan_neg_inf_neg) {
  // -NAN
  ck_assert(!precision_check(s21_fmod(-S21_NAN, -S21_INF),
                             fmod(-S21_NAN, -S21_INF), false));
}
END_TEST

START_TEST(s21_fmod_nan_neg_nan) {
  // -NAN
  ck_assert(!precision_check(s21_fmod(-S21_NAN, S21_NAN),
                             fmod(-S21_NAN, S21_NAN), false));
}
END_TEST

START_TEST(s21_fmod_nan_neg_nan_neg) {
  // -NAN
  ck_assert(!precision_check(s21_fmod(-S21_NAN, -S21_NAN),
                             fmod(-S21_NAN, -S21_NAN), false));
}
END_TEST

START_TEST(s21_fmod_value_inf) {
  // -2.0
  ck_assert(!precision_check(s21_fmod(-2, S21_INF), fmod(-2, S21_INF), false));
}
END_TEST

START_TEST(s21_fmod_value_inf_neg) {
  // -2.0
  ck_assert(
      !precision_check(s21_fmod(-2, -S21_INF), fmod(-2, -S21_INF), false));
}
END_TEST

START_TEST(s21_fmod_value_nan) {
  // NAN
  ck_assert(!precision_check(s21_fmod(-2, S21_NAN), fmod(-2, S21_NAN), false));
}
END_TEST

START_TEST(s21_fmod_value_nan_neg) {
  // -NAN
  ck_assert(
      !precision_check(s21_fmod(-2, -S21_NAN), fmod(-2, -S21_NAN), false));
}
END_TEST

START_TEST(s21_fmod_inf_value) {
  // -NAN
  ck_assert(!precision_check(s21_fmod(S21_INF, -2), fmod(S21_INF, -2), false));
}
END_TEST

START_TEST(s21_fmod_inf_neg_value) {
  // -NAN
  ck_assert(
      !precision_check(s21_fmod(-S21_INF, -2), fmod(-S21_INF, -2), false));
}
END_TEST

START_TEST(s21_fmod_nan_value) {
  // NAN
  ck_assert(!precision_check(s21_fmod(S21_NAN, -2), fmod(S21_NAN, -2), false));
}
END_TEST

START_TEST(s21_fmod_nan_neg_value) {
  // -NAN
  ck_assert(
      !precision_check(s21_fmod(-S21_NAN, -2), fmod(-S21_NAN, -2), false));
}
END_TEST

START_TEST(s21_fmod_div_by_zero) {
  // -NAN
  ck_assert(!precision_check(s21_fmod(2, 0), fmod(2, 0), false));
}
END_TEST

START_TEST(s21_fmod_double_max_one) {
  // -NAN
  ck_assert(!precision_check(s21_fmod(S21_double_MAX, 1),
                             fmod(S21_double_MAX, 1), false));
}
END_TEST

START_TEST(s21_fmod_double_max_neg_one) {
  // -NAN
  ck_assert(!precision_check(s21_fmod(-S21_double_MAX, 1),
                             fmod(-S21_double_MAX, 1), false));
}
END_TEST

START_TEST(s21_fmod_zero_neg_one) {
  // -NAN
  ck_assert(!precision_check(s21_fmod(-0.0, 1), fmod(-0.0, 1), false));
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
  tcase_add_test(tc, s21_fmod_value_inf);
  tcase_add_test(tc, s21_fmod_value_inf_neg);
  tcase_add_test(tc, s21_fmod_value_nan);
  tcase_add_test(tc, s21_fmod_value_nan_neg);
  tcase_add_test(tc, s21_fmod_inf_value);
  tcase_add_test(tc, s21_fmod_inf_neg_value);
  tcase_add_test(tc, s21_fmod_nan_value);
  tcase_add_test(tc, s21_fmod_nan_neg_value);
  tcase_add_test(tc, s21_fmod_div_by_zero);
  tcase_add_test(tc, s21_fmod_double_max_one);
  tcase_add_test(tc, s21_fmod_double_max_neg_one);
  tcase_add_test(tc, s21_fmod_zero_neg_one);
  suite_add_tcase(c, tc);
  return c;
}
