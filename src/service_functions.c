#include "s21_math.h"

bool precision_check(long double value, long double check, bool extended_prec) {
  char buf1[512] = {0};
  char buf2[512] = {0};
  if (value >= 10000000000.0) {
    sprintf(buf1, "%.*Le", extended_prec ? 18 : 15, value);
    sprintf(buf2, "%.*Le", extended_prec ? 18 : 15, check);
  } else {
    sprintf(buf1, "%.*Lf", extended_prec ? 9 : 6, value);
    sprintf(buf2, "%.*Lf", extended_prec ? 9 : 6, check);
  }
  return strcmp(buf1, buf2);
}