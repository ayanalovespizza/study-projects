#include "../s21_math.h"

// арктангенс
long double s21_atan(double x) {
  long double result = 0;

  if (x == s21_INFINITY)
    result = s21_PI / 2;
  else if (x == -s21_INFINITY)
    result = -s21_PI / 2;
  else if (x != x)
    result = s21_NAN;
  else if (x == 1)
    result = s21_PI / 4;
  else if (x == -1)
    result = -s21_PI / 4;
  else {
    int in_range = (x > -1 && x < 1);

    if (in_range) {
      for (int i = 0; i < 1500; i++)
        result +=
            (s21_pow_int(-1, i) * s21_pow_int(x, 2 * i + 1)) / (2 * i + 1);
    } else {
      for (int i = 0; i < 1500; i++)
        result +=
            (s21_pow_int(-1, i) * s21_pow_int(x, -2 * i - 1)) / (2 * i + 1);
      result = (s21_PI * s21_fabs(x) / (2 * x)) - result;
    }
  }

  return result;
}