#include "../s21_math.h"

// модуль целого числа
int s21_abs(int x) {
  if (x < 0) x = x * (-1);

  return x;
}