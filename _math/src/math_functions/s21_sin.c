#include "../s21_math.h"

// синус
long double s21_sin(double x) {
  x = s21_fmod(x, 2 * s21_PI);
  double result, add_value, i;
  result = x;
  add_value = x;
  i = 0;

  while (add_value > s21_EPS || add_value < -s21_EPS) {
    add_value *= (-1) * s21_pow_int(x, 2) / ((2 * i + 2) * (2 * i + 3));
    result += add_value;
    i++;
  }

  return result;
}