#include "../s21_math.h"

// вычисляет квадратный корень
long double s21_sqrt(double x) {
  long double result = 0;
  long double near_result = 1;

  if (x == 0)
    result = 0;
  else if (x != x || x < 0 || x == -s21_INFINITY)
    result = s21_NAN;
  else if (x == s21_INFINITY)
    result = s21_INFINITY;
  else {
    for (int i = 0; i < 500; i++) {
      result = 0.5 * (near_result + x / near_result);
      near_result = result;
    }
  }

  return result;
}