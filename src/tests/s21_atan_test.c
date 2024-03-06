#include "s21_math_test.h"

START_TEST(atan_09) {
  for (double i = 0.9; i > -1; i -= 0.4) {
    ck_assert(!precision_check(s21_atan(i), atan(i), false));
  };
}
END_TEST

START_TEST(atan_2) {
  ck_assert(!precision_check(s21_atan(0.99999999), atan(0.99999999), false));
  ck_assert(!precision_check(s21_atan(-0.99999999), atan(-0.99999999), false));
}

START_TEST(atan_1) {
  ck_assert(!precision_check(s21_atan(1), atan(1), false));
  ck_assert(!precision_check(s21_atan(-1), atan(-1), false));
}
END_TEST

START_TEST(atan_100) {
  for (double i = 100; i >= -100; i -= 50) {
    ck_assert(!precision_check(s21_atan(i), atan(i), false));
  }
}
END_TEST

START_TEST(atan_100000) {
  for (double i = 100000; i >= -100000; i -= 50000) {
    ck_assert(!precision_check(s21_atan(i), atan(i), false));
  }
}
END_TEST

START_TEST(atan_NAN) {
  // NAN
  ck_assert(!precision_check(s21_atan(S21_NAN), atan(S21_NAN), false));
}
END_TEST

START_TEST(atan_NAN2) {
  // -NAN
  ck_assert(!precision_check(s21_atan(-S21_NAN), atan(-S21_NAN), false));
}
END_TEST

START_TEST(atan_S21_INF) {
  // 1.570796
  ck_assert(!precision_check(s21_atan(S21_INF), atan(S21_INF), false));
}
END_TEST

START_TEST(atan_S21_INF2) {
  // -1.570796
  ck_assert(!precision_check(s21_atan(-S21_INF), atan(-S21_INF), false));
}
END_TEST

START_TEST(s21_atan_max_double) {
  // 1.570796
  ck_assert(
      !precision_check(s21_atan(S21_double_MAX), atan(S21_double_MAX), false));
}
END_TEST

START_TEST(s21_atan_max_double_neg) {
  // 1.570796
  ck_assert(!precision_check(s21_atan(-S21_double_MAX), atan(-S21_double_MAX),
                             false));
}
END_TEST

START_TEST(s21_atan_min_double) {
  // 0.0
  ck_assert(
      !precision_check(s21_atan(S21_double_MIN), atan(S21_double_MIN), false));
}
END_TEST

START_TEST(s21_atan_min_double_neg) {
  // 0.0
  ck_assert(!precision_check(s21_atan(-S21_double_MIN), atan(-S21_double_MIN),
                             false));
}
END_TEST

Suite *s21_atan_cases(void) {
  Suite *c = suite_create("s21_atan_cases");
  TCase *tc = tcase_create("s21_atan_tc");

  tcase_add_test(tc, atan_09);
  tcase_add_test(tc, atan_1);
  tcase_add_test(tc, atan_100);
  tcase_add_test(tc, atan_100000);
  tcase_add_test(tc, atan_NAN);
  tcase_add_test(tc, atan_NAN2);
  tcase_add_test(tc, atan_S21_INF);
  tcase_add_test(tc, atan_S21_INF2);
  tcase_add_test(tc, atan_2);
  tcase_add_test(tc, s21_atan_max_double);
  tcase_add_test(tc, s21_atan_max_double_neg);
  tcase_add_test(tc, s21_atan_min_double);
  tcase_add_test(tc, s21_atan_min_double_neg);

  suite_add_tcase(c, tc);
  return c;
}
