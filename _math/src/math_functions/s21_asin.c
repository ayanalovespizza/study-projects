#include "../s21_math.h"

// арксинус
long double s21_asin(double x) {
  long double result = 0;

  if (x == 1)
    result = s21_PI / 2;
  else if (x == -1)
    result = -s21_PI / 2;
  else if (x != x || x == s21_INFINITY || x == -s21_INFINITY)
    result = s21_NAN;
  else {
    if (x > -1 && x < 1) result = s21_atan(x / (s21_sqrt(1 - x * x)));
  }

  return result;
}