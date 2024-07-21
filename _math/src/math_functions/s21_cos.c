#include "../s21_math.h"

// косинус
long double s21_cos(double x) {
  x = s21_fmod(x, 2 * s21_PI);
  double result, add_value, i;
  result = 1;
  add_value = 1;
  i = 1;

  while (add_value > s21_EPS || add_value < -s21_EPS) {
    add_value *= (-1) * x * x / ((2 * i - 1) * (2 * i));
    result += add_value;
    i++;
  }

  return result;
}