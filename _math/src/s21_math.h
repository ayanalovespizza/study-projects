#ifndef S21_MATH_H
#define S21_MATH_H

#include <limits.h>
#include <stdlib.h>

#define s21_PI 3.14159265358979324
#define s21_E 2.71828182845904523
#define s21_EPS 1e-6
#define s21_INFINITY 1.0 / 0.0
#define s21_NAN 0.0 / 0.0

int s21_abs(int x);
long double s21_fabs(double x);

long double s21_ceil(double x);
long double s21_floor(double x);

long double s21_pow(double base, double exp);
long double s21_pow_int(double base, int exp);
long double s21_short_pow(double base, double exp);
long double s21_sqrt(double x);
long double s21_fmod(double x, double y);

long double s21_exp(double x);
long double s21_log(double x);

long double s21_cos(double x);
long double s21_sin(double x);
long double s21_tan(double x);

long double s21_acos(double x);
long double s21_asin(double x);
long double s21_atan(double x);

#endif