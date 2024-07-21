#include "../s21_math.h"

// вычисляет натуральный логарифм
long double s21_log(double x) {
  long double result = 0;
  long double near_result = 1;

  if (x == s21_INFINITY)
    result = s21_INFINITY;
  else if (x == 0)
    result = -s21_INFINITY;
  else if (x < 0 || x != x)
    result = s21_NAN;
  else {
    for (int i = 0; i < 500; i++) {
      result = near_result +
               2 * (x - s21_exp(near_result)) / (x + s21_exp(near_result));
      near_result = result;
    }
  }

  return result;
}