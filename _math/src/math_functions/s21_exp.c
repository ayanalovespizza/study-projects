#include "../s21_math.h"

// возвращает значение e, возведенное в заданную степень
long double s21_exp(double x) {
  long double add_value = 1, result = 1, i = 1;

  if (x == s21_INFINITY)
    result = s21_INFINITY;
  else if (x == -s21_INFINITY)
    result = 0;
  else if (x != x)
    result = s21_NAN;

  else {
    while (s21_fabs(add_value) > 1e-17 && (result != s21_INFINITY)) {
      add_value *= x / i;
      i += 1;
      result += add_value;
    }
  }

  return result;
}