#include <math.h>
#include <stdio.h>

#include "s21_math.h"

int main() {
  printf("%Lf\n", s21_exp(1000));
  printf("%lf\n\n", exp(1000));

  printf("%Lf\n", s21_pow(2, 1000.1232));
  printf("%lf\n\n", pow(2, 1000.1232));
  return 0;
}