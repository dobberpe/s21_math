#include "s21_math_test.h"

START_TEST(s21_sqrt_negative) {
  // -NAN
  ck_assert(!precision_check(s21_sqrt(-2), sqrt(-2), false));
}
END_TEST

START_TEST(s21_sqrt_inf) {
  // INF
  ck_assert(!precision_check(s21_sqrt(S21_INF), sqrt(S21_INF), false));
}
END_TEST

START_TEST(s21_sqrt_inf_negative) {
  // -NAN
  ck_assert(!precision_check(s21_sqrt(-S21_INF), sqrt(-S21_INF), false));
}
END_TEST

START_TEST(s21_sqrt_nan) {
  // NAN
  ck_assert(!precision_check(s21_sqrt(S21_NAN), sqrt(S21_NAN), false));
}
END_TEST

START_TEST(s21_sqrt_nan_negative) {
  // -NAN
  ck_assert(!precision_check(s21_sqrt(-S21_NAN), sqrt(-S21_NAN), false));
}
END_TEST

START_TEST(s21_sqrt_normal_1) {
  // 2.0
  ck_assert(!precision_check(s21_sqrt(4), sqrt(4), false));
}
END_TEST

START_TEST(s21_sqrt_normal_2) {
  // 22.627417
  ck_assert(!precision_check(s21_sqrt(512), sqrt(512), false));
}
END_TEST

START_TEST(s21_sqrt_max_double) {
  // 13407807929942595611008317640802934282464207265959107021466054756094376573581619054852612241927956455650759996398703782412109633178814162067569513603268608.000000
  ck_assert(
      !precision_check(s21_sqrt(S21_double_MAX), sqrt(S21_double_MAX), false));
}
END_TEST

START_TEST(s21_sqrt_max_double_neg) {
  // 13407807929942595611008317640802934282464207265959107021466054756094376573581619054852612241927956455650759996398703782412109633178814162067569513603268608.000000
  ck_assert(!precision_check(s21_sqrt(-S21_double_MAX), sqrt(-S21_double_MAX),
                             false));
}
END_TEST

START_TEST(s21_sqrt_min_double) {
  // 0.0
  ck_assert(
      !precision_check(s21_sqrt(S21_double_MIN), sqrt(S21_double_MIN), false));
}
END_TEST

START_TEST(s21_sqrt_min_double_neg) {
  // 0.0
  ck_assert(!precision_check(s21_sqrt(-S21_double_MIN), sqrt(-S21_double_MIN),
                             false));
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
  tcase_add_test(tc, s21_sqrt_max_double_neg);
  tcase_add_test(tc, s21_sqrt_min_double);
  tcase_add_test(tc, s21_sqrt_min_double_neg);
  suite_add_tcase(c, tc);
  return c;
}
