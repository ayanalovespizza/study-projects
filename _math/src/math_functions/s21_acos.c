#include "../s21_math.h"

// арккосинус
long double s21_acos(double x) {
  long double result = 0;

  if (x == 0)
    result = s21_PI / 2;
  else if (x == 1)
    result = 0;
  else if (x == -1)
    result = s21_PI;
  else if (x != x || x == s21_INFINITY || x == -s21_INFINITY)
    result = s21_NAN;
  else {
    if (x > 0 && x < 1)
      result = s21_atan(s21_sqrt(1 - x * x) / x);
    else if (x > -1 && x < 0)
      result = s21_PI + s21_atan(s21_sqrt(1 - x * x) / x);
  }

  return result;
}