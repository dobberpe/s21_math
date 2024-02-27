#ifndef TEST_H
#define TEST_H

#include <check.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#include "../s21_math.h"

Suite *s21_abs_cases(void);
Suite *s21_ceil_cases(void);
Suite *s21_floor_cases(void);
Suite *s21_fabs_cases(void);
Suite *s21_sqrt_cases(void);
Suite *s21_pow_cases(void);
Suite *s21_exp_cases(void);
Suite *s21_log_cases(void);
Suite *s21_fmod_cases(void);
Suite *s21_sin_cases(void);
Suite *s21_cos_cases(void);
Suite *s21_tan_cases(void);
Suite *s21_asin_cases(void);
Suite *s21_acos_cases(void);
Suite *s21_atan_cases(void);

#endif
