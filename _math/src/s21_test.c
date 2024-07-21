#include <check.h>
#include <math.h>
#include <stdlib.h>

#include "s21_math.h"

// s21_abs() tests
START_TEST(abs_test1) {
  int a = -8;
  ck_assert_double_eq(abs(a), s21_abs(a));
}
END_TEST

START_TEST(abs_test2) {
  int a = -100;
  ck_assert_double_eq(abs(a), s21_abs(a));
}
END_TEST

START_TEST(abs_test3) {
  int a = 123;
  ck_assert_double_eq(abs(a), s21_abs(a));
}
END_TEST

START_TEST(abs_test4) {
  int a = 121212;
  ck_assert_double_eq(abs(a), s21_abs(a));
}
END_TEST

START_TEST(abs_test5) {
  int a = -121212;
  ck_assert_double_eq(abs(a), s21_abs(a));
}
END_TEST

START_TEST(abs_test6) {
  int a = 0;
  ck_assert_double_eq(abs(a), s21_abs(a));
}
END_TEST

// s21_fabs() tests
START_TEST(fabs_test1) {
  double a = INFINITY;
  double s21_a = s21_INFINITY;

  ck_assert_double_eq(fabs(a), s21_fabs(s21_a));
}
END_TEST

START_TEST(fabs_test2) {
  double a = -INFINITY;
  double s21_a = -s21_INFINITY;

  ck_assert_double_eq(fabs(a), s21_fabs(s21_a));
}
END_TEST

START_TEST(fabs_test3) {
  double a = NAN;
  double s21_a = s21_NAN;

  ck_assert_double_nan(fabs(a));
  ck_assert_double_nan(s21_fabs(s21_a));
}
END_TEST

START_TEST(fabs_test4) {
  double a = -7.0;
  ck_assert_double_eq(fabs(a), s21_fabs(a));
}
END_TEST

START_TEST(fabs_test5) {
  double a = -98.1;
  ck_assert_double_eq(fabs(a), s21_fabs(a));
}
END_TEST

START_TEST(fabs_test6) {
  double a = 123.02;
  ck_assert_double_eq(fabs(a), s21_fabs(a));
}
END_TEST

START_TEST(fabs_test7) {
  double a = 121212.0;
  ck_assert_double_eq(fabs(a), s21_fabs(a));
}
END_TEST

START_TEST(fabs_test8) {
  double a = -121212.555;
  ck_assert_double_eq(fabs(a), s21_fabs(a));
}
END_TEST

START_TEST(fabs_test9) {
  double a = -0.121212;
  ck_assert_double_eq(fabs(a), s21_fabs(a));
}
END_TEST

START_TEST(fabs_test10) {
  double a = -1e23;
  ck_assert_double_eq(fabs(a), s21_fabs(a));
}
END_TEST

// s21_ceil() tests
START_TEST(ceil_test1) {
  double a = INFINITY;
  double s21_a = s21_INFINITY;

  ck_assert_double_eq(ceil(a), s21_ceil(s21_a));
}
END_TEST

START_TEST(ceil_test2) {
  double a = -INFINITY;
  double s21_a = -s21_INFINITY;

  ck_assert_double_eq(ceil(a), s21_ceil(s21_a));
}
END_TEST

START_TEST(ceil_test3) {
  ck_assert_double_nan(ceil(NAN));
  ck_assert_double_nan(s21_ceil(s21_NAN));
}
END_TEST

START_TEST(ceil_test4) {
  double a = -7.0;
  ck_assert_double_eq(ceil(a), s21_ceil(a));
}
END_TEST

START_TEST(ceil_test5) {
  double a = -98.1;
  ck_assert_double_eq(ceil(a), s21_ceil(a));
}
END_TEST

START_TEST(ceil_test6) {
  double a = 123.02;
  ck_assert_double_eq(ceil(a), s21_ceil(a));
}
END_TEST

START_TEST(ceil_test7) {
  double a = 121212.00123;
  ck_assert_double_eq(ceil(a), s21_ceil(a));
}
END_TEST

START_TEST(ceil_test8) {
  double a = -121212.00123;
  ck_assert_double_eq(ceil(a), s21_ceil(a));
}
END_TEST

START_TEST(ceil_test9) {
  double a = -0.121212;
  ck_assert_double_eq(ceil(a), s21_ceil(a));
}
END_TEST

START_TEST(ceil_test10) {
  double a = -1e-23;
  ck_assert_double_eq(ceil(a), s21_ceil(a));
}
END_TEST

// s21_floor() tests
START_TEST(floor_test1) {
  double a = INFINITY;
  double s21_a = s21_INFINITY;

  ck_assert_double_eq(floor(a), s21_floor(s21_a));
}
END_TEST

START_TEST(floor_test2) {
  double a = -INFINITY;
  double s21_a = -s21_INFINITY;

  ck_assert_double_eq(floor(a), s21_floor(s21_a));
}
END_TEST

START_TEST(floor_test3) {
  ck_assert_double_nan(floor(NAN));
  ck_assert_double_nan(s21_floor(s21_NAN));
}
END_TEST

START_TEST(floor_test4) {
  double a = -7.0;
  ck_assert_double_eq(floor(a), s21_floor(a));
}
END_TEST

START_TEST(floor_test5) {
  double a = -98.1;
  ck_assert_double_eq(floor(a), s21_floor(a));
}
END_TEST

START_TEST(floor_test6) {
  double a = 121.21;
  ck_assert_double_eq(floor(a), s21_floor(a));
}
END_TEST

START_TEST(floor_test7) {
  double a = 121212.00121;
  ck_assert_double_eq(floor(a), s21_floor(a));
}
END_TEST

START_TEST(floor_test8) {
  double a = -121212.00121;
  ck_assert_double_eq(floor(a), s21_floor(a));
}
END_TEST

START_TEST(floor_test9) {
  double a = a = -0.00121;
  ck_assert_double_eq(floor(a), s21_floor(a));
}
END_TEST

START_TEST(floor_test10) {
  double a = -1e-23;
  ck_assert_double_eq(floor(a), s21_floor(a));
}
END_TEST

START_TEST(floor_test11) {
  double a = 123456789.5;
  ck_assert_double_eq(floor(a), s21_floor(a));
}
END_TEST

// s21_pow() tests
START_TEST(pow_test1) {
  for (double k = -9; k <= 9; k += 1.7) {
    for (double g = -5; g < 5; g += 1) {
      long double a = s21_pow(k, g);
      long double b = pow(k, g);
      if ((!isnan(a) && !isnan(b)) && !(a == INFINITY && b == INFINITY) &&
          !(a == -INFINITY && b == -INFINITY)) {
        ck_assert_double_eq_tol(a, b, s21_EPS);
      }
      a = s21_pow(g, k);
      b = pow(g, k);
      if ((!isnan(a) && !isnan(b)) && !(a == INFINITY && b == INFINITY) &&
          !(a == -INFINITY && b == -INFINITY)) {
        ck_assert_double_eq_tol(a, b, s21_EPS);
      }
    }
  }
}
END_TEST

START_TEST(pow_test2) {
  for (double k = -1e-1; k <= 1; k += 1.1e-1) {
    for (double g = -2.55; g < 2; g += 1.1) {
      long double a = s21_pow(k, g);
      long double b = pow(k, g);
      if ((!isnan(a) && !isnan(b)) && !(a == INFINITY && b == INFINITY) &&
          !(a == -INFINITY && b == -INFINITY)) {
        ck_assert_double_eq_tol(a, b, s21_EPS);
      }
      a = s21_pow(g, k);
      b = pow(g, k);
      if ((!isnan(a) && !isnan(b)) && !(a == INFINITY && b == INFINITY) &&
          !(a == -INFINITY && b == -INFINITY)) {
        ck_assert_double_eq_tol(a, b, s21_EPS);
      }
    }
  }
}
END_TEST

START_TEST(pow_test3) {
  double base = 1;
  double exp = 0;

  ck_assert_double_eq(pow(base, exp), s21_pow(base, exp));
}
END_TEST

START_TEST(pow_test4) {
  double base = -1;
  double exp = 3;

  ck_assert_double_eq_tol(pow(base, exp), s21_pow(base, exp), 1e-6);
}
END_TEST

START_TEST(pow_test5) {
  double base = -1;
  double exp = 4;

  ck_assert_double_eq_tol(pow(base, exp), s21_pow(base, exp), 1e-6);
}
END_TEST

START_TEST(pow_test6) {
  double base = 0;
  double exp = 0;

  ck_assert_double_eq_tol(pow(base, exp), s21_pow(base, exp), 1e-6);
}
END_TEST

START_TEST(pow_test7) {
  double base = 0;
  double exp = -1;

  ck_assert_double_eq(pow(base, exp), s21_pow(base, exp));
}
END_TEST

START_TEST(pow_test8) {
  double base = 0;
  double exp = 1;

  ck_assert_double_eq(pow(base, exp), s21_pow(base, exp));
}
END_TEST

START_TEST(pow_test9) {
  double base = INFINITY;
  double s21_base = s21_INFINITY;
  double exp = 0;

  ck_assert_double_eq(pow(base, exp), s21_pow(s21_base, exp));
}
END_TEST

START_TEST(pow_test10) {
  double base = INFINITY;
  double s21_base = s21_INFINITY;
  double exp = -1;

  ck_assert_double_eq(pow(base, exp), s21_pow(s21_base, exp));
}
END_TEST

START_TEST(pow_test11) {
  double base = 0;
  double exp = INFINITY;
  double s21_exp = s21_INFINITY;

  ck_assert_double_eq(pow(base, exp), s21_pow(base, s21_exp));
}
END_TEST

START_TEST(pow_test12) {
  double base = 0;
  double exp = NAN;
  double s21_exp = s21_NAN;

  ck_assert_double_nan(pow(base, exp));
  ck_assert_double_nan(s21_pow(base, s21_exp));
}
END_TEST

START_TEST(pow_test13) {
  double base = NAN;
  double s21_base = s21_NAN;
  double exp = 0;

  ck_assert_double_eq(pow(base, exp), s21_pow(s21_base, exp));
}
END_TEST

START_TEST(pow_test14) {
  ck_assert_double_nan(pow(NAN, NAN));
  ck_assert_double_nan(s21_pow(s21_NAN, s21_NAN));
}
END_TEST

START_TEST(pow_test15) {
  double base = INFINITY, exp = INFINITY;
  double s21_base = s21_INFINITY, s21_exp = s21_INFINITY;

  ck_assert_double_eq(pow(base, exp), s21_pow(s21_base, s21_exp));
}
END_TEST

START_TEST(pow_test16) {
  double base = INFINITY, exp = -INFINITY;
  double s21_base = s21_INFINITY, s21_exp = -s21_INFINITY;

  ck_assert_double_eq(pow(base, exp), s21_pow(s21_base, s21_exp));
}
END_TEST

START_TEST(pow_test17) {
  double base = -INFINITY, exp = -INFINITY;
  double s21_base = -s21_INFINITY, s21_exp = -s21_INFINITY;

  ck_assert_double_eq(pow(base, exp), s21_pow(s21_base, s21_exp));
}

START_TEST(pow_test18) {
  ck_assert_double_nan(pow(NAN, INFINITY));
  ck_assert_double_nan(s21_pow(s21_NAN, s21_INFINITY));
}
END_TEST

START_TEST(pow_test19) {
  ck_assert_double_nan(pow(INFINITY, NAN));
  ck_assert_double_nan(s21_pow(s21_INFINITY, s21_NAN));
}
END_TEST

START_TEST(pow_test20) {
  ck_assert_double_nan(pow(NAN, -INFINITY));
  ck_assert_double_nan(s21_pow(s21_NAN, -s21_INFINITY));
}
END_TEST

START_TEST(pow_test21) {
  ck_assert_double_nan(pow(-INFINITY, NAN));
  ck_assert_double_nan(s21_pow(-s21_INFINITY, s21_NAN));
}
END_TEST

START_TEST(pow_test22) {
  double base = 2;
  double exp = INFINITY;
  double s21_exp = s21_INFINITY;

  ck_assert_double_eq(pow(base, exp), s21_pow(base, s21_exp));
}
END_TEST

START_TEST(pow_test23) {
  double base = 0.5;
  double exp = INFINITY;
  double s21_exp = s21_INFINITY;

  ck_assert_double_eq(pow(base, exp), s21_pow(base, s21_exp));
}
END_TEST

START_TEST(pow_test24) {
  double base = 2;
  double exp = -INFINITY;
  double s21_exp = -s21_INFINITY;

  ck_assert_double_eq(pow(base, exp), s21_pow(base, s21_exp));
}
END_TEST

START_TEST(pow_test25) {
  double base = 0.5;
  double exp = -INFINITY;
  double s21_exp = -s21_INFINITY;

  ck_assert_double_eq(pow(base, exp), s21_pow(base, s21_exp));
}
END_TEST

START_TEST(pow_test26) {
  double base = -2;
  double exp = -INFINITY;
  double s21_exp = -s21_INFINITY;

  ck_assert_double_eq(pow(base, exp), s21_pow(base, s21_exp));
}
END_TEST

// s21_sqrt() tests
START_TEST(sqrt_test1) {
  for (double k = 0; k <= 100; k += 3)
    ck_assert_double_eq_tol(s21_sqrt(k), sqrt(k), 1e-6);
}
END_TEST

START_TEST(sqrt_test2) {
  ck_assert_double_nan(s21_sqrt(s21_NAN));
  ck_assert_double_nan(sqrt(NAN));
}
END_TEST

START_TEST(sqrt_test3) {
  ck_assert_double_eq(s21_sqrt(s21_INFINITY), sqrt(INFINITY));
}
END_TEST

START_TEST(sqrt_test4) {
  ck_assert_double_nan(s21_sqrt(-s21_INFINITY));
  ck_assert_double_nan(sqrt(-INFINITY));
}
END_TEST

START_TEST(sqrt_test5) {
  double a = -5;

  ck_assert_double_nan(s21_sqrt(a));
  ck_assert_double_nan(sqrt(a));
}
END_TEST

START_TEST(sqrt_test6) {
  double a = 1000;

  ck_assert_double_eq_tol(s21_sqrt(a), sqrt(a), 1e-6);
}
END_TEST

START_TEST(sqrt_test7) {
  double a = 1e+4;
  ck_assert_double_eq_tol(s21_sqrt(a), sqrt(a), 1e-6);
}

// s21_fmod() tests
START_TEST(fmod_test1) {
  for (double a = -1500; a < 1500; a += 123) {
    for (double b = -12; b < 12; b += 1.25) {
      ck_assert_double_eq(fmod(a, b), s21_fmod(a, b));
      ck_assert_double_eq(fmod(b, a), s21_fmod(b, a));
    }
  }
}
END_TEST

START_TEST(fmod_test2) {
  double x = 1;
  double y = 0;

  ck_assert_double_nan(fmod(x, y));
  ck_assert_double_nan(s21_fmod(x, y));
}
END_TEST

START_TEST(fmod_test3) {
  double x = 0;
  double y = -1;

  ck_assert_double_eq(fmod(x, y), s21_fmod(x, y));
}
END_TEST

START_TEST(fmod_test4) {
  double x = 0;
  double y = 1;

  ck_assert_double_eq(fmod(x, y), s21_fmod(x, y));
}
END_TEST

START_TEST(fmod_test5) {
  double x = INFINITY;
  double s21_x = s21_INFINITY;
  double y = -1;

  ck_assert_double_nan(fmod(x, y));
  ck_assert_double_nan(s21_fmod(s21_x, y));
}
END_TEST

START_TEST(fmod_test6) {
  double x = 21;
  double y = -INFINITY;
  double s21_y = -s21_INFINITY;

  ck_assert_double_eq(fmod(x, y), s21_fmod(x, s21_y));
}
END_TEST

START_TEST(fmod_test7) {
  double x = -21;
  double y = INFINITY;
  double s21_y = s21_INFINITY;

  ck_assert_double_eq(fmod(x, y), s21_fmod(x, s21_y));
}
END_TEST

START_TEST(fmod_test8) {
  double x = -21;
  double y = INFINITY;
  double s21_y = s21_INFINITY;

  ck_assert_double_eq(fmod(x, y), s21_fmod(x, s21_y));
}
END_TEST

START_TEST(fmod_test9) {
  ck_assert_double_nan(s21_fmod(0, s21_NAN));
  ck_assert_double_nan(fmod(0, NAN));
}
END_TEST

START_TEST(fmod_test10) {
  ck_assert_double_nan(s21_fmod(s21_NAN, s21_NAN));
  ck_assert_double_nan(fmod(NAN, NAN));
}
END_TEST

START_TEST(fmod_test11) {
  ck_assert_double_nan(s21_fmod(s21_NAN, s21_INFINITY));
  ck_assert_double_nan(fmod(NAN, INFINITY));
}
END_TEST

START_TEST(fmod_test12) {
  ck_assert_double_nan(s21_fmod(s21_INFINITY, s21_NAN));
  ck_assert_double_nan(fmod(INFINITY, NAN));
}
END_TEST

START_TEST(fmod_test13) {
  ck_assert_double_nan(s21_fmod(s21_NAN, -s21_INFINITY));
  ck_assert_double_nan(fmod(NAN, -INFINITY));
}
END_TEST

START_TEST(fmod_test14) {
  ck_assert_double_nan(s21_fmod(-s21_INFINITY, s21_NAN));
  ck_assert_double_nan(fmod(-INFINITY, NAN));
}
END_TEST

// s21_exp() tests
START_TEST(exp_test1) {
  for (double k = -21; k < 21; k += 1)
    ck_assert_double_eq_tol(s21_exp(k), exp(k), 1e-6);
}
END_TEST

START_TEST(exp_test2) {
  for (double k = -15; k < 15; k += 0.123)
    ck_assert_double_eq_tol(s21_exp(k), exp(k), 1e-6);
}
END_TEST

START_TEST(exp_test3) {
  for (double k = -5; k < 5; k += 0.00573)
    ck_assert_double_eq_tol(s21_exp(k), exp(k), 1e-6);
}
END_TEST

START_TEST(exp_test4) {
  ck_assert_double_nan(exp(NAN));
  ck_assert_double_nan(s21_exp(s21_NAN));
}
END_TEST

START_TEST(exp_test5) {
  ck_assert_double_eq(exp(INFINITY), s21_exp(s21_INFINITY));
}
END_TEST

START_TEST(exp_test6) {
  ck_assert_double_eq(exp(-INFINITY), s21_exp(-s21_INFINITY));
}
END_TEST

START_TEST(exp_test7) {
  double a = 0;
  ck_assert_double_eq(exp(a), s21_exp(a));
}
END_TEST

START_TEST(exp_test8) {
  double a = 1;
  ck_assert_double_eq_tol(exp(a), s21_exp(a), s21_EPS);
}
END_TEST

// s21_log() tests
START_TEST(log_test1) {
  for (double k = 1; k < 100; k += 13.2)
    ck_assert_double_eq_tol(s21_log(k), log(k), s21_EPS);
}
END_TEST

START_TEST(log_test2) {
  for (double k = 0.1; k < 4; k += 0.24)
    ck_assert_double_eq_tol(s21_log(k), log(k), s21_EPS);
}
END_TEST

START_TEST(log_test3) {
  for (double k = 0.1; k < 10000; k += 123)
    ck_assert_double_eq_tol(s21_log(k), log(k), s21_EPS);
}
END_TEST

START_TEST(log_test4) {
  for (double k = 0.000005; k < 1; k *= 5)
    ck_assert_double_eq_tol(s21_log(k), log(k), s21_EPS);
}
END_TEST

START_TEST(log_test5) {
  ck_assert_double_nan(s21_log(s21_NAN));
  ck_assert_double_nan(log(NAN));
}
END_TEST

START_TEST(log_test6) {
  double a = 0;
  ck_assert_double_eq(log(a), s21_log(a));
}
END_TEST

START_TEST(log_test7) {
  double a = 0;
  ck_assert_double_eq(log(a), s21_log(a));
}
END_TEST

START_TEST(log_test8) {
  double a = -3;
  ck_assert_double_nan(s21_log(a));
  ck_assert_double_nan(log(a));
}
END_TEST

START_TEST(log_tets9) {
  ck_assert_double_eq(log(INFINITY), s21_log(s21_INFINITY));
}
END_TEST

START_TEST(log_test10) {
  ck_assert_double_nan(s21_log(-s21_INFINITY));
  ck_assert_double_nan(log(-INFINITY));
}
END_TEST

START_TEST(log_test11) {
  double a = 1;
  ck_assert_double_eq_tol(log(a), s21_log(a), s21_EPS);
}
END_TEST

START_TEST(log_test12) {
  ck_assert_double_eq_tol(log(M_E), s21_log(s21_E), s21_EPS);
}

START_TEST(log_test13) {
  double a = 6e-1;
  ck_assert_double_eq_tol(log(a), s21_log(a), s21_EPS);
}
END_TEST

// s21_cos() tests
START_TEST(cos_test1) {
  for (int R = 20; R >= -20; R -= 4) {
    for (double k = 2 * s21_PI; k > -2 * s21_PI; k -= s21_PI / 17) {
      ck_assert_double_eq_tol(cos(k + R * s21_PI), s21_cos(k + R * s21_PI),
                              s21_EPS);
    }
  }
}
END_TEST

START_TEST(cos_test2) {
  ck_assert_double_nan(cos(NAN));
  ck_assert_double_nan(s21_cos(s21_NAN));
}
END_TEST

START_TEST(cos_test3) {
  ck_assert_double_nan(cos(INFINITY));
  ck_assert_double_nan(s21_cos(s21_INFINITY));
}
END_TEST

START_TEST(cos_test4) {
  ck_assert_double_nan(cos(-INFINITY));
  ck_assert_double_nan(s21_cos(-s21_INFINITY));
}
END_TEST

// s21_sin() tests
START_TEST(sin_test1) {
  for (int R = 20; R >= -20; R -= 4) {
    for (double k = 2 * s21_PI; k > -2 * s21_PI; k -= s21_PI / 17) {
      ck_assert_double_eq_tol(sin(k + R * s21_PI), s21_sin(k + R * s21_PI),
                              1e-6);
    }
  }
}
END_TEST

START_TEST(sin_test2) {
  ck_assert_double_nan(sin(NAN));
  ck_assert_double_nan(s21_sin(s21_NAN));
}
END_TEST

START_TEST(sin_test3) {
  ck_assert_double_nan(sin(INFINITY));
  ck_assert_double_nan(s21_sin(s21_INFINITY));
}
END_TEST

START_TEST(sin_test4) {
  ck_assert_double_nan(sin(-INFINITY));
  ck_assert_double_nan(s21_sin(-s21_INFINITY));
}
END_TEST

// s21_tan() tests
START_TEST(tan_test1) {
  for (int R = 20; R >= -20; R -= 4) {
    for (double k = 2 * s21_PI; k > -2 * s21_PI; k -= s21_PI / 9) {
      ck_assert_double_eq_tol(tan(k + R * s21_PI), s21_tan(k + R * s21_PI),
                              1e-6);
    }
  }
}
END_TEST

START_TEST(tan_test2) {
  ck_assert_double_nan(tan(NAN));
  ck_assert_double_nan(tan(s21_NAN));
}
END_TEST

START_TEST(tan_test3) {
  ck_assert_double_nan(tan(INFINITY));
  ck_assert_double_nan(s21_tan(s21_INFINITY));
}
END_TEST

START_TEST(tan_test4) {
  ck_assert_double_nan(tan(-INFINITY));
  ck_assert_double_nan(s21_tan(-s21_INFINITY));
}
END_TEST

// s21_acos() tests
START_TEST(acos_test1) {
  for (float k = -1; k <= 1; k += 0.1)
    ck_assert_double_eq_tol(s21_acos(k), acos(k), s21_EPS);
}
END_TEST

START_TEST(acos_test2) {
  for (float k = -1; k <= 1; k += 0.0305)
    ck_assert_double_eq_tol(s21_acos(k), acos(k), s21_EPS);
}
END_TEST

START_TEST(acos_test3) {
  double a = -1;
  ck_assert_double_eq(s21_acos(a), acos(a));
}
END_TEST

START_TEST(acos_test4) {
  double a = 1;
  ck_assert_double_eq(s21_acos(a), acos(a));
}
END_TEST

START_TEST(acos_test5) {
  double a = 0;
  ck_assert_double_eq(s21_acos(a), acos(a));
}
END_TEST

START_TEST(acos_test6) {
  ck_assert_double_nan(s21_acos(s21_INFINITY));
  ck_assert_double_nan(acos(INFINITY));
}
END_TEST

START_TEST(acos_test7) {
  ck_assert_double_nan(s21_acos(-s21_INFINITY));
  ck_assert_double_nan(acos(-INFINITY));
}
END_TEST

START_TEST(acos_test8) {
  ck_assert_double_nan(s21_acos(s21_NAN));
  ck_assert_double_nan(acos(NAN));
}
END_TEST

// s21_asin() tests
START_TEST(asin_test1) {
  for (float k = -1; k <= 1; k += 0.1)
    ck_assert_double_eq_tol(s21_asin(k), asin(k), s21_EPS);
}
END_TEST

START_TEST(asin_test2) {
  double a = 1;
  ck_assert_double_eq_tol(asin(a), s21_asin(a), s21_EPS);
}
END_TEST

START_TEST(asin_test3) {
  for (float k = -1; k <= 1; k += 0.0771) {
    ck_assert_double_eq_tol(s21_asin(k), asin(k), s21_EPS);
  }
}
END_TEST

START_TEST(asin_test4) {
  ck_assert_double_nan(s21_asin(s21_INFINITY));
  ck_assert_double_nan(asin(INFINITY));
}
END_TEST

START_TEST(asin_test5) {
  ck_assert_double_nan(s21_asin(-s21_INFINITY));
  ck_assert_double_nan(asin(-INFINITY));
}
END_TEST

START_TEST(asin_test6) {
  ck_assert_double_nan(s21_asin(s21_NAN));
  ck_assert_double_nan(asin(NAN));
}
END_TEST

// s21_atan() tests
START_TEST(atan_test1) {
  for (float k = -10; k <= 10; k += 4)
    ck_assert_double_eq_tol(s21_atan(k), atan(k), s21_EPS);
}
END_TEST

START_TEST(atan_test2) {
  ck_assert_double_eq(s21_atan(s21_INFINITY), atan(INFINITY));
}
END_TEST

START_TEST(atan_test3) {
  ck_assert_double_eq(s21_atan(-s21_INFINITY), atan(-INFINITY));
}
END_TEST

START_TEST(atan_test4) {
  double a = 1;
  ck_assert_double_eq(s21_atan(a), atan(a));
}
END_TEST

START_TEST(atan_test5) {
  double a = -1;
  ck_assert_double_eq(s21_atan(a), atan(a));
}
END_TEST

START_TEST(atan_test6) {
  ck_assert_double_nan(atan(NAN));
  ck_assert_double_nan(s21_atan(s21_NAN));
}
END_TEST

Suite *math_suite() {
  Suite *s1 = suite_create("MATH_TESTS");
  TCase *abs_tests = tcase_create("ABS");
  suite_add_tcase(s1, abs_tests);
  tcase_add_test(abs_tests, abs_test1);
  tcase_add_test(abs_tests, abs_test2);
  tcase_add_test(abs_tests, abs_test3);
  tcase_add_test(abs_tests, abs_test4);
  tcase_add_test(abs_tests, abs_test5);
  tcase_add_test(abs_tests, abs_test6);

  TCase *fabs_tests = tcase_create("FABS");
  suite_add_tcase(s1, fabs_tests);
  tcase_add_test(abs_tests, fabs_test1);
  tcase_add_test(abs_tests, fabs_test2);
  tcase_add_test(abs_tests, fabs_test3);
  tcase_add_test(abs_tests, fabs_test4);
  tcase_add_test(abs_tests, fabs_test5);
  tcase_add_test(abs_tests, fabs_test6);
  tcase_add_test(abs_tests, fabs_test7);
  tcase_add_test(abs_tests, fabs_test8);
  tcase_add_test(abs_tests, fabs_test9);
  tcase_add_test(abs_tests, fabs_test10);

  TCase *ceil_tests = tcase_create("CEIL");
  suite_add_tcase(s1, ceil_tests);
  tcase_add_test(ceil_tests, ceil_test1);
  tcase_add_test(ceil_tests, ceil_test2);
  tcase_add_test(ceil_tests, ceil_test3);
  tcase_add_test(ceil_tests, ceil_test4);
  tcase_add_test(ceil_tests, ceil_test5);
  tcase_add_test(ceil_tests, ceil_test6);
  tcase_add_test(ceil_tests, ceil_test7);
  tcase_add_test(ceil_tests, ceil_test8);
  tcase_add_test(ceil_tests, ceil_test9);
  tcase_add_test(ceil_tests, ceil_test10);

  TCase *floor_tests = tcase_create("FLOOR");
  suite_add_tcase(s1, floor_tests);
  tcase_add_test(floor_tests, floor_test1);
  tcase_add_test(floor_tests, floor_test2);
  tcase_add_test(floor_tests, floor_test3);
  tcase_add_test(floor_tests, floor_test4);
  tcase_add_test(floor_tests, floor_test5);
  tcase_add_test(floor_tests, floor_test6);
  tcase_add_test(floor_tests, floor_test7);
  tcase_add_test(floor_tests, floor_test8);
  tcase_add_test(floor_tests, floor_test9);
  tcase_add_test(floor_tests, floor_test10);
  tcase_add_test(floor_tests, floor_test11);

  TCase *pow_tests = tcase_create("POW");
  suite_add_tcase(s1, pow_tests);
  tcase_add_test(pow_tests, pow_test1);
  tcase_add_test(pow_tests, pow_test2);
  tcase_add_test(pow_tests, pow_test3);
  tcase_add_test(pow_tests, pow_test4);
  tcase_add_test(pow_tests, pow_test5);
  tcase_add_test(pow_tests, pow_test6);
  tcase_add_test(pow_tests, pow_test7);
  tcase_add_test(pow_tests, pow_test8);
  tcase_add_test(pow_tests, pow_test9);
  tcase_add_test(pow_tests, pow_test10);
  tcase_add_test(pow_tests, pow_test11);
  tcase_add_test(pow_tests, pow_test12);
  tcase_add_test(pow_tests, pow_test13);
  tcase_add_test(pow_tests, pow_test14);
  tcase_add_test(pow_tests, pow_test15);
  tcase_add_test(pow_tests, pow_test16);
  tcase_add_test(pow_tests, pow_test17);
  tcase_add_test(pow_tests, pow_test18);
  tcase_add_test(pow_tests, pow_test19);
  tcase_add_test(pow_tests, pow_test20);
  tcase_add_test(pow_tests, pow_test21);
  tcase_add_test(pow_tests, pow_test22);
  tcase_add_test(pow_tests, pow_test23);
  tcase_add_test(pow_tests, pow_test24);
  tcase_add_test(pow_tests, pow_test25);
  tcase_add_test(pow_tests, pow_test26);

  TCase *sqrt_tests = tcase_create("SQRT");
  suite_add_tcase(s1, sqrt_tests);
  tcase_add_test(sqrt_tests, sqrt_test1);
  tcase_add_test(sqrt_tests, sqrt_test2);
  tcase_add_test(sqrt_tests, sqrt_test3);
  tcase_add_test(sqrt_tests, sqrt_test4);
  tcase_add_test(sqrt_tests, sqrt_test5);
  tcase_add_test(sqrt_tests, sqrt_test6);
  tcase_add_test(sqrt_tests, sqrt_test7);

  TCase *fmod_tests = tcase_create("FMOD");
  suite_add_tcase(s1, fmod_tests);
  tcase_add_test(fmod_tests, fmod_test1);
  tcase_add_test(fmod_tests, fmod_test2);
  tcase_add_test(fmod_tests, fmod_test3);
  tcase_add_test(fmod_tests, fmod_test4);
  tcase_add_test(fmod_tests, fmod_test5);
  tcase_add_test(fmod_tests, fmod_test6);
  tcase_add_test(fmod_tests, fmod_test7);
  tcase_add_test(fmod_tests, fmod_test8);
  tcase_add_test(fmod_tests, fmod_test9);
  tcase_add_test(fmod_tests, fmod_test10);
  tcase_add_test(fmod_tests, fmod_test11);
  tcase_add_test(fmod_tests, fmod_test12);
  tcase_add_test(fmod_tests, fmod_test13);
  tcase_add_test(fmod_tests, fmod_test14);

  TCase *exp_tests = tcase_create("EXP");
  suite_add_tcase(s1, exp_tests);
  tcase_add_test(exp_tests, exp_test1);
  tcase_add_test(exp_tests, exp_test2);
  tcase_add_test(exp_tests, exp_test3);
  tcase_add_test(exp_tests, exp_test4);
  tcase_add_test(exp_tests, exp_test5);
  tcase_add_test(exp_tests, exp_test6);
  tcase_add_test(exp_tests, exp_test7);
  tcase_add_test(exp_tests, exp_test8);

  TCase *log_tests = tcase_create("LOG");
  suite_add_tcase(s1, log_tests);
  tcase_add_test(log_tests, log_test1);
  tcase_add_test(log_tests, log_test2);
  tcase_add_test(log_tests, log_test3);
  tcase_add_test(log_tests, log_test4);
  tcase_add_test(log_tests, log_test5);
  tcase_add_test(log_tests, log_test6);
  tcase_add_test(log_tests, log_test7);
  tcase_add_test(log_tests, log_test8);
  tcase_add_test(log_tests, log_tets9);
  tcase_add_test(log_tests, log_test10);
  tcase_add_test(log_tests, log_test11);
  tcase_add_test(log_tests, log_test12);
  tcase_add_test(log_tests, log_test13);

  TCase *cos_tests = tcase_create("COS");
  suite_add_tcase(s1, cos_tests);
  tcase_add_test(cos_tests, cos_test1);
  tcase_add_test(cos_tests, cos_test2);
  tcase_add_test(cos_tests, cos_test3);
  tcase_add_test(cos_tests, cos_test4);

  TCase *sin_tests = tcase_create("SIN");
  suite_add_tcase(s1, sin_tests);
  tcase_add_test(sin_tests, sin_test1);
  tcase_add_test(sin_tests, sin_test2);
  tcase_add_test(sin_tests, sin_test3);
  tcase_add_test(sin_tests, sin_test4);

  TCase *tan_tests = tcase_create("TAN");
  suite_add_tcase(s1, tan_tests);
  tcase_add_test(tan_tests, tan_test1);
  tcase_add_test(tan_tests, tan_test2);
  tcase_add_test(tan_tests, tan_test3);
  tcase_add_test(tan_tests, tan_test4);

  TCase *acos_tests = tcase_create("ACOS");
  suite_add_tcase(s1, acos_tests);
  tcase_add_test(acos_tests, acos_test1);
  tcase_add_test(acos_tests, acos_test2);
  tcase_add_test(acos_tests, acos_test3);
  tcase_add_test(acos_tests, acos_test4);
  tcase_add_test(acos_tests, acos_test5);
  tcase_add_test(acos_tests, acos_test6);
  tcase_add_test(acos_tests, acos_test7);
  tcase_add_test(acos_tests, acos_test8);

  TCase *asin_tests = tcase_create("ASIN");
  suite_add_tcase(s1, asin_tests);
  tcase_add_test(asin_tests, asin_test1);
  tcase_add_test(asin_tests, asin_test2);
  tcase_add_test(asin_tests, asin_test3);
  tcase_add_test(asin_tests, asin_test4);
  tcase_add_test(asin_tests, asin_test5);
  tcase_add_test(asin_tests, asin_test6);

  TCase *atan_tests = tcase_create("ATAN");
  suite_add_tcase(s1, atan_tests);
  tcase_add_test(atan_tests, atan_test1);
  tcase_add_test(atan_tests, atan_test2);
  tcase_add_test(atan_tests, atan_test3);
  tcase_add_test(atan_tests, atan_test4);
  tcase_add_test(atan_tests, atan_test5);
  tcase_add_test(atan_tests, atan_test6);

  return s1;
}

int main() {
  Suite *s1 = math_suite();
  SRunner *runner_math = srunner_create(s1);

  int number_fails;
  srunner_run_all(runner_math, CK_NORMAL);
  number_fails = srunner_ntests_failed(runner_math);
  srunner_free(runner_math);

  return number_fails == 0 ? 0 : 1;
}