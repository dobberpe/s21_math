#include "s21_math_test.h"

int main() {
  int number_failed;
  Suite *suite = NULL;
  SRunner *runner = srunner_create(suite);

  Suite *suits_list[] = {
      s21_sin_cases(),   s21_cos_cases(),  s21_tan_cases(),  s21_acos_cases(),
      s21_asin_cases(),  s21_atan_cases(), s21_exp_cases(),  s21_fabs_cases(),
      s21_floor_cases(), s21_fmod_cases(), s21_log_cases(),  s21_pow_cases(),
      s21_sqrt_cases(),  s21_abs_cases(),  s21_ceil_cases(), NULL};

  for (Suite **current = suits_list; *current != NULL; current++)
    srunner_add_suite(runner, *current);

  srunner_set_fork_status(runner, CK_NOFORK);
  srunner_run_all(runner, CK_NORMAL);
  number_failed = srunner_ntests_failed(runner);
  srunner_free(runner);

  return (number_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}