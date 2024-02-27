#include "s21_math_test.h"

START_TEST(s21_fmod_inf_inf) {
  // -NAN
  ld_bits check = {fmod(__builtin_inf (), __builtin_inf ())};
  ld_bits result = {s21_fmod(__builtin_inf (), __builtin_inf ())};
  for (int i = 0; i < 5; ++i) ck_assert_uint_eq(check.bits[i], result.bits[i]);
}
END_TEST

START_TEST(s21_fmod_inf_inf_neg) {
  // -NAN
  ld_bits check = {fmod(__builtin_inf (), -__builtin_inf ())};
  ld_bits result = {s21_fmod(__builtin_inf (), -__builtin_inf ())};
  for (int i = 0; i < 5; ++i) ck_assert_uint_eq(check.bits[i], result.bits[i]);
}
END_TEST

START_TEST(s21_fmod_inf_nan) {
  // NAN
  ld_bits check = {fmod(__builtin_inf (), NAN)};
  ld_bits result = {s21_fmod(__builtin_inf (), NAN)};
  for (int i = 0; i < 5; ++i) ck_assert_uint_eq(check.bits[i], result.bits[i]);
}
END_TEST

START_TEST(s21_fmod_inf_nan_neg) {
  // -NAN
  ld_bits check = {fmod(__builtin_inf (), -NAN)};
  ld_bits result = {s21_fmod(__builtin_inf (), -NAN)};
  for (int i = 0; i < 5; ++i) ck_assert_uint_eq(check.bits[i], result.bits[i]);
}
END_TEST

START_TEST(s21_fmod_inf_neg_inf) {
  // -NAN
  ld_bits check = {fmod(-__builtin_inf (), __builtin_inf ())};
  ld_bits result = {s21_fmod(-__builtin_inf (), __builtin_inf ())};
  for (int i = 0; i < 5; ++i) ck_assert_uint_eq(check.bits[i], result.bits[i]);
}
END_TEST

START_TEST(s21_fmod_inf_neg_inf_neg) {
  // -NAN
  ld_bits check = {fmod(-__builtin_inf (), -__builtin_inf ())};
  ld_bits result = {s21_fmod(-__builtin_inf (), -__builtin_inf ())};
  for (int i = 0; i < 5; ++i) ck_assert_uint_eq(check.bits[i], result.bits[i]);
}
END_TEST

START_TEST(s21_fmod_inf_neg_nan) {
  // NAN
  ld_bits check = {fmod(-__builtin_inf (), NAN)};
  ld_bits result = {s21_fmod(-__builtin_inf (), NAN)};
  for (int i = 0; i < 5; ++i) ck_assert_uint_eq(check.bits[i], result.bits[i]);
}
END_TEST

START_TEST(s21_fmod_inf_neg_nan_neg) {
  // -NAN
  ld_bits check = {fmod(-__builtin_inf (), -NAN)};
  ld_bits result = {s21_fmod(-__builtin_inf (), -NAN)};
  for (int i = 0; i < 5; ++i) ck_assert_uint_eq(check.bits[i], result.bits[i]);
}
END_TEST

START_TEST(s21_fmod_nan_inf) {
  // NAN
  ld_bits check = {fmod(NAN, __builtin_inf ())};
  ld_bits result = {s21_fmod(NAN, __builtin_inf ())};
  for (int i = 0; i < 5; ++i) ck_assert_uint_eq(check.bits[i], result.bits[i]);
}
END_TEST

START_TEST(s21_fmod_nan_inf_neg) {
  // NAN
  ld_bits check = {fmod(NAN, -__builtin_inf ())};
  ld_bits result = {s21_fmod(NAN, -__builtin_inf ())};
  for (int i = 0; i < 5; ++i) ck_assert_uint_eq(check.bits[i], result.bits[i]);
}
END_TEST

START_TEST(s21_fmod_nan_nan) {
  // NAN
  ld_bits check = {fmod(NAN, NAN)};
  ld_bits result = {s21_fmod(NAN, NAN)};
  for (int i = 0; i < 5; ++i) ck_assert_uint_eq(check.bits[i], result.bits[i]);
}
END_TEST

START_TEST(s21_fmod_nan_nan_neg) {
  // NAN
  ld_bits check = {fmod(NAN, -NAN)};
  ld_bits result = {s21_fmod(NAN, -NAN)};
  for (int i = 0; i < 5; ++i) ck_assert_uint_eq(check.bits[i], result.bits[i]);
}
END_TEST

START_TEST(s21_fmod_nan_neg_inf) {
  // -NAN
  ld_bits check = {fmod(-NAN, __builtin_inf ())};
  ld_bits result = {s21_fmod(-NAN, __builtin_inf ())};
  for (int i = 0; i < 5; ++i) ck_assert_uint_eq(check.bits[i], result.bits[i]);
}
END_TEST

START_TEST(s21_fmod_nan_neg_inf_neg) {
  // -NAN
  ld_bits check = {fmod(-NAN, -__builtin_inf ())};
  ld_bits result = {s21_fmod(-NAN, -__builtin_inf ())};
  for (int i = 0; i < 5; ++i) ck_assert_uint_eq(check.bits[i], result.bits[i]);
}
END_TEST

START_TEST(s21_fmod_nan_neg_nan) {
  // -NAN
  ld_bits check = {fmod(-NAN, NAN)};
  ld_bits result = {s21_fmod(-NAN, NAN)};
  for (int i = 0; i < 5; ++i) ck_assert_uint_eq(check.bits[i], result.bits[i]);
}
END_TEST

START_TEST(s21_fmod_nan_neg_nan_neg) {
  // -NAN
  ld_bits check = {fmod(-NAN, -NAN)};
  ld_bits result = {s21_fmod(-NAN, -NAN)};
  for (int i = 0; i < 5; ++i) ck_assert_uint_eq(check.bits[i], result.bits[i]);
}
END_TEST

START_TEST(s21_fmod_value_inf) {
  // -2.0
  ck_assert_ldouble_eq_tol(fmod(-2, __builtin_inf ()), s21_fmod(-2, __builtin_inf ()), S21_EPS);
}
END_TEST

START_TEST(s21_fmod_value_inf_neg) {
  // -NAN
  printf("\nmy: %Lf\nor: %f\n\n", s21_fmod(-2, __builtin_inf ()), fmod(-2, __builtin_inf ()));
  ck_assert_ldouble_eq_tol(fmod(-2, -__builtin_inf ()), s21_fmod(-2, -__builtin_inf ()), S21_EPS);
}
END_TEST

START_TEST(s21_fmod_value_nan) {
  // NAN
  ld_bits check = {fmod(-2, NAN)};
  ld_bits result = {s21_fmod(-2, NAN)};
  for (int i = 0; i < 5; ++i) ck_assert_uint_eq(check.bits[i], result.bits[i]);
}
END_TEST

START_TEST(s21_fmod_value_nan_neg) {
  // -NAN
  ld_bits check = {fmod(-2, -NAN)};
  ld_bits result = {s21_fmod(-2, -NAN)};
  for (int i = 0; i < 5; ++i) ck_assert_uint_eq(check.bits[i], result.bits[i]);
}
END_TEST

START_TEST(s21_fmod_inf_value) {
  // -NAN
  ld_bits check = {fmod(__builtin_inf (), -2)};
  ld_bits result = {s21_fmod(__builtin_inf (), -2)};
  for (int i = 0; i < 5; ++i) ck_assert_uint_eq(check.bits[i], result.bits[i]);
}
END_TEST

START_TEST(s21_fmod_inf_neg_value) {
  // -NAN
  ld_bits check = {fmod(-__builtin_inf (), -2)};
  ld_bits result = {s21_fmod(-__builtin_inf (), -2)};
  for (int i = 0; i < 5; ++i) ck_assert_uint_eq(check.bits[i], result.bits[i]);
}
END_TEST

START_TEST(s21_fmod_nan_value) {
  // NAN
  ld_bits check = {fmod(NAN, -2)};
  ld_bits result = {s21_fmod(NAN, -2)};
  for (int i = 0; i < 5; ++i) ck_assert_uint_eq(check.bits[i], result.bits[i]);
}
END_TEST

START_TEST(s21_fmod_nan_neg_value) {
  // -NAN
  ld_bits check = {fmod(-NAN, -2)};
  ld_bits result = {s21_fmod(-NAN, -2)};
  for (int i = 0; i < 5; ++i) ck_assert_uint_eq(check.bits[i], result.bits[i]);
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
  suite_add_tcase(c, tc);
  return c;
}
