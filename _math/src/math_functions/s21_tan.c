#include "../s21_math.h"

// тангенс
long double s21_tan(double x) {
  long double result = 0;

  result = s21_sin(x) / s21_cos(x);

  return result;
}