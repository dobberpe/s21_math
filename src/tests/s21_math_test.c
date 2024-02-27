#include "s21_math_test.h"

int main() {
  int number_failed;
  Suite *suite = NULL;
  SRunner *runner = srunner_create(suite);

  Suite *suits_list[] = {
      s21_sqrt_cases(), s21_pow_cases(), s21_fmod_cases(), NULL};

  for (Suite **current = suits_list; *current != NULL; current++)
    srunner_add_suite(runner, *current);

  srunner_run_all(runner, CK_NORMAL);
  number_failed = srunner_ntests_failed(runner);
  srunner_free(runner);

  return (number_failed == 0) ? 0 : 1;
}