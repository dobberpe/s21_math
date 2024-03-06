#include "s21_math_test.h"

START_TEST(s21_pow_inf_inf) {
  // INF
  ck_assert(!precision_check(s21_pow(S21_INF, S21_INF), pow(S21_INF, S21_INF),
                             false));
}
END_TEST

START_TEST(s21_pow_inf_inf_neg) {
  // 0.0
  ck_assert(!precision_check(s21_pow(S21_INF, -S21_INF), pow(S21_INF, -S21_INF),
                             false));
}
END_TEST

START_TEST(s21_pow_inf_nan) {
  // NAN
  ck_assert(!precision_check(s21_pow(S21_INF, S21_NAN), pow(S21_INF, S21_NAN),
                             false));
}
END_TEST

START_TEST(s21_pow_inf_nan_neg) {
  // -NAN
  ck_assert(!precision_check(s21_pow(S21_INF, -S21_NAN), pow(S21_INF, -S21_NAN),
                             false));
}
END_TEST

START_TEST(s21_pow_inf_neg_inf) {
  // INF
  ck_assert(!precision_check(s21_pow(-S21_INF, S21_INF), pow(-S21_INF, S21_INF),
                             false));
}
END_TEST

START_TEST(s21_pow_inf_neg_inf_neg) {
  // 0.0
  ck_assert(!precision_check(s21_pow(-S21_INF, -S21_INF),
                             pow(-S21_INF, -S21_INF), false));
}
END_TEST

START_TEST(s21_pow_inf_neg_nan) {
  // NAN
  ck_assert(isnan(s21_pow(-S21_INF, S21_NAN)) && isnan(pow(-S21_INF, S21_NAN)));
}
END_TEST

START_TEST(s21_pow_inf_neg_nan_neg) {
  // -NAN
  ck_assert(!precision_check(s21_pow(-S21_INF, -S21_NAN),
                             pow(-S21_INF, -S21_NAN), false));
}
END_TEST

START_TEST(s21_pow_nan_inf) {
  // NAN
  ck_assert(!precision_check(s21_pow(S21_NAN, S21_INF), pow(S21_NAN, S21_INF),
                             false));
}
END_TEST

START_TEST(s21_pow_nan_inf_neg) {
  // NAN
  ck_assert(!precision_check(s21_pow(S21_NAN, -S21_INF), pow(S21_NAN, -S21_INF),
                             false));
}
END_TEST

START_TEST(s21_pow_nan_nan) {
  // NAN
  ck_assert(!precision_check(s21_pow(S21_NAN, S21_NAN), pow(S21_NAN, S21_NAN),
                             false));
}
END_TEST

START_TEST(s21_pow_nan_nan_neg) {
  // NAN
  ck_assert(!precision_check(s21_pow(S21_NAN, -S21_NAN), pow(S21_NAN, -S21_NAN),
                             false));
}
END_TEST

START_TEST(s21_pow_nan_neg_inf) {
  // -NAN
  ck_assert(!precision_check(s21_pow(-S21_NAN, S21_INF), pow(-S21_NAN, S21_INF),
                             false));
}
END_TEST

START_TEST(s21_pow_nan_neg_inf_neg) {
  // -NAN
  ck_assert(!precision_check(s21_pow(-S21_NAN, -S21_INF),
                             pow(-S21_NAN, -S21_INF), false));
}
END_TEST

START_TEST(s21_pow_nan_neg_nan) {
  // -NAN
  ck_assert(!precision_check(s21_pow(-S21_NAN, S21_NAN), pow(-S21_NAN, S21_NAN),
                             false));
}
END_TEST

START_TEST(s21_pow_nan_neg_nan_neg) {
  // -NAN
  ck_assert(!precision_check(s21_pow(-S21_NAN, -S21_NAN),
                             pow(-S21_NAN, -S21_NAN), false));
}
END_TEST

START_TEST(s21_pow_two_point_five_inf) {
  // INF
  ck_assert(!precision_check(s21_pow(2.5, S21_INF), pow(2.5, S21_INF), false));
}
END_TEST

START_TEST(s21_pow_two_point_five_inf_neg) {
  // -0.0
  ck_assert(
      !precision_check(s21_pow(2.5, -S21_INF), pow(2.5, -S21_INF), false));
}
END_TEST

START_TEST(s21_pow_two_point_five_nan) {
  // NAN
  ck_assert(!precision_check(s21_pow(2.5, S21_NAN), pow(2.5, S21_NAN), false));
}
END_TEST

START_TEST(s21_pow_two_point_five_nan_neg) {
  // -NAN
  ck_assert(
      !precision_check(s21_pow(2.5, -S21_NAN), pow(2.5, -S21_NAN), false));
}
END_TEST

START_TEST(s21_pow_inf_two_point_five) {
  // INF
  ck_assert(!precision_check(s21_pow(S21_INF, 2.5), pow(S21_INF, 2.5), false));
}
END_TEST

START_TEST(s21_pow_inf_neg_two_point_five) {
  // INF
  ck_assert(
      !precision_check(s21_pow(-S21_INF, 2.5), pow(-S21_INF, 2.5), false));
}
END_TEST

START_TEST(s21_pow_nan_two_point_five) {
  // NAN
  ck_assert(!precision_check(s21_pow(S21_NAN, 2.5), pow(S21_NAN, 2.5), false));
}
END_TEST

START_TEST(s21_pow_nan_neg_two_point_five) {
  // -NAN
  ck_assert(
      !precision_check(s21_pow(-S21_NAN, 2.5), pow(-S21_NAN, 2.5), false));
}
END_TEST

START_TEST(s21_pow_two_point_five_neg_inf) {
  // INF
  ck_assert(
      !precision_check(s21_pow(-2.5, S21_INF), pow(-2.5, S21_INF), false));
}
END_TEST

START_TEST(s21_pow_two_point_five_neg_inf_neg) {
  // -0.0
  ck_assert(
      !precision_check(s21_pow(-2.5, -S21_INF), pow(-2.5, -S21_INF), false));
}
END_TEST

START_TEST(s21_pow_two_point_five_neg_nan) {
  // NAN
  ck_assert(isnan(s21_pow(-2.5, S21_NAN)) && isnan(pow(-2.5, S21_NAN)));
}
END_TEST

START_TEST(s21_pow_two_point_five_neg_nan_neg) {
  // -NAN
  ck_assert(
      !precision_check(s21_pow(-2.5, -S21_NAN), pow(-2.5, -S21_NAN), false));
}
END_TEST

START_TEST(s21_pow_inf_two_point_five_neg) {
  // 0.0
  ck_assert(
      !precision_check(s21_pow(S21_INF, -2.5), pow(S21_INF, -2.5), false));
}
END_TEST

START_TEST(s21_pow_inf_neg_two_point_five_neg) {
  // 0.0
  ck_assert(
      !precision_check(s21_pow(-S21_INF, -2.5), pow(-S21_INF, -2.5), false));
}
END_TEST

START_TEST(s21_pow_nan_two_point_five_neg) {
  // NAN
  ck_assert(
      !precision_check(s21_pow(S21_NAN, -2.5), pow(S21_NAN, -2.5), false));
}
END_TEST

START_TEST(s21_pow_nan_neg_two_point_five_neg) {
  // -NAN
  ck_assert(
      !precision_check(s21_pow(-S21_NAN, -2.5), pow(-S21_NAN, -2.5), false));
}
END_TEST

START_TEST(s21_pow_two_inf) {
  // INF
  ck_assert(!precision_check(s21_pow(2, S21_INF), pow(2, S21_INF), false));
}
END_TEST

START_TEST(s21_pow_two_inf_neg) {
  // -0.0
  ck_assert(!precision_check(s21_pow(2, -S21_INF), pow(2, -S21_INF), false));
}
END_TEST

START_TEST(s21_pow_two_nan) {
  // NAN
  ck_assert(!precision_check(s21_pow(2, S21_NAN), pow(2, S21_NAN), false));
}
END_TEST

START_TEST(s21_pow_two_nan_neg) {
  // -NAN
  ck_assert(!precision_check(s21_pow(2, -S21_NAN), pow(2, -S21_NAN), false));
}
END_TEST

START_TEST(s21_pow_inf_two) {
  // INF
  ck_assert(!precision_check(s21_pow(S21_INF, 2), pow(S21_INF, 2), false));
}
END_TEST

START_TEST(s21_pow_inf_neg_two) {
  // INF
  ck_assert(!precision_check(s21_pow(-S21_INF, 2), pow(-S21_INF, 2), false));
}
END_TEST

START_TEST(s21_pow_nan_two) {
  // NAN
  ck_assert(!precision_check(s21_pow(S21_NAN, 2), pow(S21_NAN, 2), false));
}
END_TEST

START_TEST(s21_pow_nan_neg_two) {
  // -NAN
  ck_assert(!precision_check(s21_pow(-S21_NAN, 2), pow(-S21_NAN, 2), false));
}
END_TEST

START_TEST(s21_pow_two_neg_inf) {
  // INF
  ck_assert(!precision_check(s21_pow(-2, S21_INF), pow(-2, S21_INF), false));
}
END_TEST

START_TEST(s21_pow_two_neg_inf_neg) {
  // -0.0
  ck_assert(!precision_check(s21_pow(-2, -S21_INF), pow(-2, -S21_INF), false));
}
END_TEST

START_TEST(s21_pow_two_neg_nan) {
  // NAN
  ck_assert(isnan(s21_pow(-2, S21_NAN)) && isnan(pow(-2, S21_NAN)));
}
END_TEST

START_TEST(s21_pow_two_neg_nan_neg) {
  // -NAN
  ck_assert(!precision_check(s21_pow(-2, -S21_NAN), pow(-2, -S21_NAN), false));
}
END_TEST

START_TEST(s21_pow_inf_two_neg) {
  // 0.0
  ck_assert(!precision_check(s21_pow(S21_INF, -2), pow(S21_INF, -2), false));
}
END_TEST

START_TEST(s21_pow_inf_neg_two_neg) {
  // 0.0
  ck_assert(!precision_check(s21_pow(-S21_INF, -2), pow(-S21_INF, -2), false));
}
END_TEST

START_TEST(s21_pow_nan_two_neg) {
  // NAN
  ck_assert(!precision_check(s21_pow(S21_NAN, -2), pow(S21_NAN, -2), false));
}
END_TEST

START_TEST(s21_pow_nan_neg_two_neg) {
  // -NAN
  ck_assert(!precision_check(s21_pow(-S21_NAN, -2), pow(-S21_NAN, -2), false));
}
END_TEST

START_TEST(s21_pow_one_point_five_inf) {
  // INF
  ck_assert(!precision_check(s21_pow(1.5, S21_INF), pow(1.5, S21_INF), false));
}
END_TEST

START_TEST(s21_pow_one_point_five_inf_neg) {
  // -0.0
  ck_assert(
      !precision_check(s21_pow(1.5, -S21_INF), pow(1.5, -S21_INF), false));
}
END_TEST

START_TEST(s21_pow_one_point_five_nan) {
  // NAN
  ck_assert(!precision_check(s21_pow(1.5, S21_NAN), pow(1.5, S21_NAN), false));
}
END_TEST

START_TEST(s21_pow_one_point_five_nan_neg) {
  // -NAN
  ck_assert(
      !precision_check(s21_pow(1.5, -S21_NAN), pow(1.5, -S21_NAN), false));
}
END_TEST

START_TEST(s21_pow_inf_one_point_five) {
  // INF
  ck_assert(!precision_check(s21_pow(S21_INF, 1.5), pow(S21_INF, 1.5), false));
}
END_TEST

START_TEST(s21_pow_inf_neg_one_point_five) {
  // INF
  ck_assert(
      !precision_check(s21_pow(-S21_INF, 1.5), pow(-S21_INF, 1.5), false));
}
END_TEST

START_TEST(s21_pow_nan_one_point_five) {
  // NAN
  ck_assert(!precision_check(s21_pow(S21_NAN, 1.5), pow(S21_NAN, 1.5), false));
}
END_TEST

START_TEST(s21_pow_nan_neg_one_point_five) {
  // -NAN
  ck_assert(
      !precision_check(s21_pow(-S21_NAN, 1.5), pow(-S21_NAN, 1.5), false));
}
END_TEST

START_TEST(s21_pow_one_point_five_neg_inf) {
  // INF
  ck_assert(
      !precision_check(s21_pow(-1.5, S21_INF), pow(-1.5, S21_INF), false));
}
END_TEST

START_TEST(s21_pow_one_point_five_neg_inf_neg) {
  // -0.0
  ck_assert(
      !precision_check(s21_pow(-1.5, -S21_INF), pow(-1.5, -S21_INF), false));
}
END_TEST

START_TEST(s21_pow_one_point_five_neg_nan) {
  // NAN
  ck_assert(isnan(s21_pow(-1.5, S21_NAN)) && isnan(pow(-1.5, S21_NAN)));
}
END_TEST

START_TEST(s21_pow_one_point_five_neg_nan_neg) {
  // -NAN
  ck_assert(
      !precision_check(s21_pow(-1.5, -S21_NAN), pow(-1.5, -S21_NAN), false));
}
END_TEST

START_TEST(s21_pow_inf_one_point_five_neg) {
  // 0.0
  ck_assert(
      !precision_check(s21_pow(S21_INF, -1.5), pow(S21_INF, -1.5), false));
}
END_TEST

START_TEST(s21_pow_inf_neg_one_point_five_neg) {
  // 0.0
  ck_assert(
      !precision_check(s21_pow(-S21_INF, -1.5), pow(-S21_INF, -1.5), false));
}
END_TEST

START_TEST(s21_pow_nan_one_point_five_neg) {
  // NAN
  ck_assert(
      !precision_check(s21_pow(S21_NAN, -1.5), pow(S21_NAN, -1.5), false));
}
END_TEST

START_TEST(s21_pow_nan_neg_one_point_five_neg) {
  // -NAN
  ck_assert(
      !precision_check(s21_pow(-S21_NAN, -1.5), pow(-S21_NAN, -1.5), false));
}
END_TEST

START_TEST(s21_pow_one_inf) {
  // INF
  ck_assert(!precision_check(s21_pow(1., S21_INF), pow(1., S21_INF), false));
}
END_TEST

START_TEST(s21_pow_one_inf_neg) {
  // -0.0
  ck_assert(!precision_check(s21_pow(1., -S21_INF), pow(1., -S21_INF), false));
}
END_TEST

START_TEST(s21_pow_one_nan) {
  // NAN
  ck_assert(!precision_check(s21_pow(1., S21_NAN), pow(1., S21_NAN), false));
}
END_TEST

START_TEST(s21_pow_one_nan_neg) {
  // -NAN
  ck_assert(!precision_check(s21_pow(1., -S21_NAN), pow(1., -S21_NAN), false));
}
END_TEST

START_TEST(s21_pow_inf_one) {
  // INF
  ck_assert(!precision_check(s21_pow(S21_INF, 1.), pow(S21_INF, 1.), false));
}
END_TEST

START_TEST(s21_pow_inf_neg_one) {
  // INF
  ck_assert_ldouble_eq(s21_pow(-S21_INF, 1.), pow(-S21_INF, 1.));
}
END_TEST

START_TEST(s21_pow_nan_one) {
  // NAN
  ck_assert(!precision_check(s21_pow(S21_NAN, 1.), pow(S21_NAN, 1.), false));
}
END_TEST

START_TEST(s21_pow_nan_neg_one) {
  // -NAN
  ck_assert(!precision_check(s21_pow(-S21_NAN, 1.), pow(-S21_NAN, 1.), false));
}
END_TEST

START_TEST(s21_pow_one_neg_inf) {
  // INF
  ck_assert(!precision_check(s21_pow(-1., S21_INF), pow(-1., S21_INF), false));
}
END_TEST

START_TEST(s21_pow_one_neg_inf_neg) {
  // -0.0
  ck_assert(
      !precision_check(s21_pow(-1., -S21_INF), pow(-1., -S21_INF), false));
}
END_TEST

START_TEST(s21_pow_one_neg_nan) {
  // NAN
  ck_assert(isnan(s21_pow(-1., S21_NAN)) && isnan(pow(-1., S21_NAN)));
}
END_TEST

START_TEST(s21_pow_one_neg_nan_neg) {
  // -NAN
  ck_assert(
      !precision_check(s21_pow(-1., -S21_NAN), pow(-1., -S21_NAN), false));
}
END_TEST

START_TEST(s21_pow_inf_one_neg) {
  // 0.0
  ck_assert(!precision_check(s21_pow(S21_INF, -1.), pow(S21_INF, -1.), false));
}
END_TEST

START_TEST(s21_pow_inf_neg_one_neg) {
  // 0.0
  ck_assert(
      !precision_check(s21_pow(-S21_INF, -1.), pow(-S21_INF, -1.), false));
}
END_TEST

START_TEST(s21_pow_nan_one_neg) {
  // NAN
  ck_assert(!precision_check(s21_pow(S21_NAN, -1.), pow(S21_NAN, -1.), false));
}
END_TEST

START_TEST(s21_pow_nan_neg_one_neg) {
  // -NAN
  ck_assert(
      !precision_check(s21_pow(-S21_NAN, -1.), pow(-S21_NAN, -1.), false));
}
END_TEST

START_TEST(s21_pow_zero_inf) {
  // INF
  ck_assert(!precision_check(s21_pow(0., S21_INF), pow(0., S21_INF), false));
}
END_TEST

START_TEST(s21_pow_zero_inf_neg) {
  // -0.0
  ck_assert(!precision_check(s21_pow(0., -S21_INF), pow(0., -S21_INF), false));
}
END_TEST

START_TEST(s21_pow_zero_nan) {
  // NAN
  ck_assert(!precision_check(s21_pow(0., S21_NAN), pow(0., S21_NAN), false));
}
END_TEST

START_TEST(s21_pow_zero_nan_neg) {
  // -NAN
  ck_assert(!precision_check(s21_pow(0., -S21_NAN), pow(0., -S21_NAN), false));
}
END_TEST

START_TEST(s21_pow_inf_zero) {
  // INF
  ck_assert(!precision_check(s21_pow(S21_INF, 0.), pow(S21_INF, 0.), false));
}
END_TEST

START_TEST(s21_pow_inf_neg_zero) {
  // INF
  ck_assert(!precision_check(s21_pow(-S21_INF, 0.), pow(-S21_INF, 0.), false));
}
END_TEST

START_TEST(s21_pow_nan_zero) {
  // NAN
  ck_assert(!precision_check(s21_pow(S21_NAN, 0.), pow(S21_NAN, 0.), false));
}
END_TEST

START_TEST(s21_pow_nan_neg_zero) {
  // -NAN
  ck_assert(!precision_check(s21_pow(-S21_NAN, 0.), pow(-S21_NAN, 0.), false));
}
END_TEST

START_TEST(s21_pow_zero_neg_inf) {
  // INF
  ck_assert(
      !precision_check(s21_pow(-0.0, S21_INF), pow(-0.0, S21_INF), false));
}
END_TEST

START_TEST(s21_pow_zero_neg_inf_neg) {
  // -0.0
  ck_assert(
      !precision_check(s21_pow(-0.0, -S21_INF), pow(-0.0, -S21_INF), false));
}
END_TEST

START_TEST(s21_pow_zero_neg_nan) {
  // NAN
  ck_assert(
      !precision_check(s21_pow(-0.0, S21_NAN), pow(-0.0, S21_NAN), false));
}
END_TEST

START_TEST(s21_pow_zero_neg_nan_neg) {
  // -NAN
  ck_assert(
      !precision_check(s21_pow(-0.0, -S21_NAN), pow(-0.0, -S21_NAN), false));
}
END_TEST

START_TEST(s21_pow_inf_zero_neg) {
  // 0.0
  ck_assert(
      !precision_check(s21_pow(S21_INF, -0.0), pow(S21_INF, -0.0), false));
}
END_TEST

START_TEST(s21_pow_inf_neg_zero_neg) {
  // 0.0
  ck_assert(
      !precision_check(s21_pow(-S21_INF, -0.0), pow(-S21_INF, -0.0), false));
}
END_TEST

START_TEST(s21_pow_nan_zero_neg) {
  // NAN
  ck_assert(
      !precision_check(s21_pow(S21_NAN, -0.0), pow(S21_NAN, -0.0), false));
}
END_TEST

START_TEST(s21_pow_nan_neg_zero_neg) {
  // -NAN
  ck_assert(
      !precision_check(s21_pow(-S21_NAN, -0.0), pow(-S21_NAN, -0.0), false));
}
END_TEST

START_TEST(s21_pow_frac_inf) {
  // -NAN
  ck_assert(!precision_check(s21_pow(0.1, S21_INF), pow(0.1, S21_INF), false));
}
END_TEST

START_TEST(s21_pow_frac_neg_inf) {
  // -NAN
  ck_assert(
      !precision_check(s21_pow(-0.1, S21_INF), pow(-0.1, S21_INF), false));
}
END_TEST

START_TEST(s21_pow_frac_inf_neg) {
  // -NAN
  ck_assert(
      !precision_check(s21_pow(0.1, -S21_INF), pow(0.1, -S21_INF), false));
}
END_TEST

START_TEST(s21_pow_frac_neg_inf_neg) {
  // -NAN
  ck_assert(
      !precision_check(s21_pow(-0.1, -S21_INF), pow(-0.1, -S21_INF), false));
}
END_TEST

START_TEST(s21_pow_value_inf) {
  // -NAN
  ck_assert(!precision_check(s21_pow(1.1, S21_INF), pow(1.1, S21_INF), false));
}
END_TEST

START_TEST(s21_pow_value_neg_inf) {
  // -NAN
  ck_assert(
      !precision_check(s21_pow(-1.1, S21_INF), pow(-1.1, S21_INF), false));
}
END_TEST

START_TEST(s21_pow_value_inf_neg) {
  // -NAN
  ck_assert(
      !precision_check(s21_pow(1.1, -S21_INF), pow(1.1, -S21_INF), false));
}
END_TEST

START_TEST(s21_pow_value_neg_inf_neg) {
  // -NAN
  ck_assert(
      !precision_check(s21_pow(-1.1, -S21_INF), pow(-1.1, -S21_INF), false));
}
END_TEST

START_TEST(s21_pow_inf_frac) {
  // -NAN
  ck_assert(!precision_check(s21_pow(S21_INF, 0.1), pow(S21_INF, 0.1), false));
}
END_TEST

START_TEST(s21_pow_inf_frac_neg) {
  // -NAN
  ck_assert(
      !precision_check(s21_pow(S21_INF, -0.1), pow(S21_INF, -0.1), false));
}
END_TEST

START_TEST(s21_pow_inf_neg_frac) {
  // -NAN
  ck_assert(
      !precision_check(s21_pow(-S21_INF, 0.1), pow(-S21_INF, 0.1), false));
}
END_TEST

START_TEST(s21_pow_inf_neg_frac_neg) {
  // -NAN
  ck_assert(
      !precision_check(s21_pow(-S21_INF, -0.1), pow(-S21_INF, -0.1), false));
}
END_TEST

START_TEST(s21_pow_inf_value) {
  // -NAN
  ck_assert(!precision_check(s21_pow(S21_INF, 1.1), pow(S21_INF, 1.1), false));
}
END_TEST

START_TEST(s21_pow_inf_value_neg) {
  // -NAN
  ck_assert(
      !precision_check(s21_pow(S21_INF, -1.1), pow(S21_INF, -1.1), false));
}
END_TEST

START_TEST(s21_pow_inf_neg_value) {
  // -NAN
  ck_assert(
      !precision_check(s21_pow(-S21_INF, 1.1), pow(-S21_INF, 1.1), false));
}
END_TEST

START_TEST(s21_pow_inf_neg_value_neg) {
  // -NAN
  ck_assert(
      !precision_check(s21_pow(-S21_INF, -1.1), pow(-S21_INF, -1.1), false));
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
  tcase_add_test(tc, s21_pow_two_point_five_inf);
  tcase_add_test(tc, s21_pow_two_point_five_inf_neg);
  tcase_add_test(tc, s21_pow_two_point_five_nan);
  tcase_add_test(tc, s21_pow_two_point_five_nan_neg);
  tcase_add_test(tc, s21_pow_inf_two_point_five);
  tcase_add_test(tc, s21_pow_inf_neg_two_point_five);
  tcase_add_test(tc, s21_pow_nan_two_point_five);
  tcase_add_test(tc, s21_pow_nan_neg_two_point_five);
  tcase_add_test(tc, s21_pow_two_point_five_neg_inf);
  tcase_add_test(tc, s21_pow_two_point_five_neg_inf_neg);
  tcase_add_test(tc, s21_pow_two_point_five_neg_nan);
  tcase_add_test(tc, s21_pow_two_point_five_neg_nan_neg);
  tcase_add_test(tc, s21_pow_inf_two_point_five_neg);
  tcase_add_test(tc, s21_pow_inf_neg_two_point_five_neg);
  tcase_add_test(tc, s21_pow_nan_two_point_five_neg);
  tcase_add_test(tc, s21_pow_nan_neg_two_point_five_neg);
  tcase_add_test(tc, s21_pow_two_inf);
  tcase_add_test(tc, s21_pow_two_inf_neg);
  tcase_add_test(tc, s21_pow_two_nan);
  tcase_add_test(tc, s21_pow_two_nan_neg);
  tcase_add_test(tc, s21_pow_inf_two);
  tcase_add_test(tc, s21_pow_inf_neg_two);
  tcase_add_test(tc, s21_pow_nan_two);
  tcase_add_test(tc, s21_pow_nan_neg_two);
  tcase_add_test(tc, s21_pow_two_neg_inf);
  tcase_add_test(tc, s21_pow_two_neg_inf_neg);
  tcase_add_test(tc, s21_pow_two_neg_nan);
  tcase_add_test(tc, s21_pow_two_neg_nan_neg);
  tcase_add_test(tc, s21_pow_inf_two_neg);
  tcase_add_test(tc, s21_pow_inf_neg_two_neg);
  tcase_add_test(tc, s21_pow_nan_two_neg);
  tcase_add_test(tc, s21_pow_nan_neg_two_neg);
  tcase_add_test(tc, s21_pow_one_point_five_inf);
  tcase_add_test(tc, s21_pow_one_point_five_inf_neg);
  tcase_add_test(tc, s21_pow_one_point_five_nan);
  tcase_add_test(tc, s21_pow_one_point_five_nan_neg);
  tcase_add_test(tc, s21_pow_inf_one_point_five);
  tcase_add_test(tc, s21_pow_inf_neg_one_point_five);
  tcase_add_test(tc, s21_pow_nan_one_point_five);
  tcase_add_test(tc, s21_pow_nan_neg_one_point_five);
  tcase_add_test(tc, s21_pow_one_point_five_neg_inf);
  tcase_add_test(tc, s21_pow_one_point_five_neg_inf_neg);
  tcase_add_test(tc, s21_pow_one_point_five_neg_nan);
  tcase_add_test(tc, s21_pow_one_point_five_neg_nan_neg);
  tcase_add_test(tc, s21_pow_inf_one_point_five_neg);
  tcase_add_test(tc, s21_pow_inf_neg_one_point_five_neg);
  tcase_add_test(tc, s21_pow_nan_one_point_five_neg);
  tcase_add_test(tc, s21_pow_nan_neg_one_point_five_neg);
  tcase_add_test(tc, s21_pow_one_inf);
  tcase_add_test(tc, s21_pow_one_inf_neg);
  tcase_add_test(tc, s21_pow_one_nan);
  tcase_add_test(tc, s21_pow_one_nan_neg);
  tcase_add_test(tc, s21_pow_inf_one);
  tcase_add_test(tc, s21_pow_inf_neg_one);
  tcase_add_test(tc, s21_pow_nan_one);
  tcase_add_test(tc, s21_pow_nan_neg_one);
  tcase_add_test(tc, s21_pow_one_neg_inf);
  tcase_add_test(tc, s21_pow_one_neg_inf_neg);
  tcase_add_test(tc, s21_pow_one_neg_nan);
  tcase_add_test(tc, s21_pow_one_neg_nan_neg);
  tcase_add_test(tc, s21_pow_inf_one_neg);
  tcase_add_test(tc, s21_pow_inf_neg_one_neg);
  tcase_add_test(tc, s21_pow_nan_one_neg);
  tcase_add_test(tc, s21_pow_nan_neg_one_neg);
  tcase_add_test(tc, s21_pow_zero_inf);
  tcase_add_test(tc, s21_pow_zero_inf_neg);
  tcase_add_test(tc, s21_pow_zero_nan);
  tcase_add_test(tc, s21_pow_zero_nan_neg);
  tcase_add_test(tc, s21_pow_inf_zero);
  tcase_add_test(tc, s21_pow_inf_neg_zero);
  tcase_add_test(tc, s21_pow_nan_zero);
  tcase_add_test(tc, s21_pow_nan_neg_zero);
  tcase_add_test(tc, s21_pow_zero_neg_inf);
  tcase_add_test(tc, s21_pow_zero_neg_inf_neg);
  tcase_add_test(tc, s21_pow_zero_neg_nan);
  tcase_add_test(tc, s21_pow_zero_neg_nan_neg);
  tcase_add_test(tc, s21_pow_inf_zero_neg);
  tcase_add_test(tc, s21_pow_inf_neg_zero_neg);
  tcase_add_test(tc, s21_pow_nan_zero_neg);
  tcase_add_test(tc, s21_pow_nan_neg_zero_neg);
  tcase_add_test(tc, s21_pow_frac_inf);
  tcase_add_test(tc, s21_pow_frac_neg_inf);
  tcase_add_test(tc, s21_pow_frac_inf_neg);
  tcase_add_test(tc, s21_pow_frac_neg_inf_neg);
  tcase_add_test(tc, s21_pow_value_inf);
  tcase_add_test(tc, s21_pow_value_neg_inf);
  tcase_add_test(tc, s21_pow_value_inf_neg);
  tcase_add_test(tc, s21_pow_value_neg_inf_neg);
  tcase_add_test(tc, s21_pow_inf_frac);
  tcase_add_test(tc, s21_pow_inf_frac_neg);
  tcase_add_test(tc, s21_pow_inf_neg_frac);
  tcase_add_test(tc, s21_pow_inf_neg_frac_neg);
  tcase_add_test(tc, s21_pow_inf_value);
  tcase_add_test(tc, s21_pow_inf_value_neg);
  tcase_add_test(tc, s21_pow_inf_neg_value);
  tcase_add_test(tc, s21_pow_inf_neg_value_neg);
  suite_add_tcase(c, tc);
  return c;
}
