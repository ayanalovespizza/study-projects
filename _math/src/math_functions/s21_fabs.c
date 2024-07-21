#include "../s21_math.h"

// модуль числа с плавающей точкой
long double s21_fabs(double x) {
  if (x < 0) x = x * (-1);

  return x;
}