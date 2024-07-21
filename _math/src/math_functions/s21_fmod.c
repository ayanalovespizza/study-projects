#include "../s21_math.h"

// остаток операции деления с плавающей точкой
long double s21_fmod(double x, double y) {
  long double result = 0;
  long long int mod = 0;

  if (x == 1 && y == 0)
    result = s21_NAN;
  else if (x == s21_INFINITY || x == -s21_INFINITY)
    result = s21_NAN;
  else if (y == s21_INFINITY || y == -s21_INFINITY)
    result = x;
  else {
    mod = x / y;
    result = x - mod * y;
  }

  return result;
}