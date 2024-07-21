#include "../s21_math.h"

// возводит число в заданную степень
long double s21_pow(double base, double exp) {
  long double result;
  long double copy = base;

  if (exp != 0) {
    if (copy != copy || copy == s21_INFINITY || copy == -s21_INFINITY)
      result = copy;

    if (copy < 0) {
      copy = -copy;
      result = s21_exp(exp * s21_log(copy));
      if (s21_fmod(exp, 2) != 0) {
        result = -result;
      }
    } else {
      result = s21_exp(exp * s21_log(base));
    }
  } else
    result = 1;

  return result;
}