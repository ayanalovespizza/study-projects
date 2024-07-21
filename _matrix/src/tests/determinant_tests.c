#include "s21_tests.h"

START_TEST(determinant_test1) {
  const int size = 5;
  matrix_t m = {0};
  s21_create_matrix(size, size, &m);

  for (int i = 0; i < size; i++)
    for (int j = 0; j < size; j++) m.matrix[i][j] = j;
  double res = 0;
  int code = s21_determinant(&m, &res);
  ck_assert_double_eq_tol(res, 0, 1e-6);
  ck_assert_int_eq(code, OK);

  s21_remove_matrix(&m);
}
END_TEST

START_TEST(determinant_test2) {
  const int size = 4;
  matrix_t m = {0};
  s21_create_matrix(size, size, &m);

  for (int i = 0; i < size; i++)
    for (int j = 0; j < size; j++) m.matrix[i][j] = j + i;

  double res = 0;
  int code = s21_determinant(&m, &res);
  ck_assert_double_eq_tol(res, 0, 1e-6);
  ck_assert_int_eq(code, OK);

  s21_remove_matrix(&m);
}
END_TEST

START_TEST(determinant_test3) {
  const int size = 5;
  matrix_t m = {0};
  s21_create_matrix(size, size, &m);
  m.matrix[0][1] = 6;
  m.matrix[0][2] = -2;
  m.matrix[0][3] = -1;
  m.matrix[0][4] = 5;
  m.matrix[1][3] = -9;
  m.matrix[1][4] = -7;
  m.matrix[2][1] = 15;
  m.matrix[2][2] = 35;
  m.matrix[3][1] = -1;
  m.matrix[3][2] = -11;
  m.matrix[3][3] = -2;
  m.matrix[3][4] = 1;
  m.matrix[4][0] = -2;
  m.matrix[4][1] = -2;
  m.matrix[4][2] = 3;
  m.matrix[4][4] = -2;

  double res = 0;
  int code = s21_determinant(&m, &res);
  ck_assert_double_eq_tol(res, 2480, 1e-6);
  ck_assert_int_eq(code, OK);

  s21_remove_matrix(&m);
}
END_TEST

START_TEST(determinant_test4) {
  const int size = 3;
  matrix_t m = {0};
  s21_create_matrix(size, size, &m);
  m.matrix[0][0] = 2;
  m.matrix[0][1] = 3;
  m.matrix[0][2] = 1;
  m.matrix[1][0] = 7;
  m.matrix[1][1] = 4;
  m.matrix[1][2] = 1;
  m.matrix[2][0] = 9;
  m.matrix[2][1] = -2;
  m.matrix[2][2] = 1;

  double res = 0;
  int code = s21_determinant(&m, &res);
  ck_assert_double_eq_tol(res, -32, 1e-6);
  ck_assert_int_eq(code, OK);

  s21_remove_matrix(&m);
}
END_TEST

START_TEST(determinant_test5) {
  const int size = 2;
  matrix_t m = {0};
  s21_create_matrix(size, size, &m);
  m.matrix[0][0] = -5;
  m.matrix[0][1] = -4;
  m.matrix[1][0] = -2;
  m.matrix[1][1] = -3;

  double res = 0;
  int code = s21_determinant(&m, &res);
  ck_assert_double_eq_tol(res, 7, 1e-6);
  ck_assert_int_eq(code, OK);

  s21_remove_matrix(&m);
}
END_TEST

START_TEST(determinant_test6) {
  const int size = 1;
  matrix_t m = {0};
  s21_create_matrix(size, size, &m);
  m.matrix[0][0] = -5;

  double res = 0;
  int code = s21_determinant(&m, &res);
  ck_assert_double_eq_tol(res, -5, 1e-6);
  ck_assert_int_eq(code, OK);

  s21_remove_matrix(&m);
}
END_TEST

START_TEST(determinant_test7) {
  int result = s21_determinant(NULL, NULL);
  ck_assert_int_eq(result, 1);
}
END_TEST

START_TEST(determinant_test8) {
  matrix_t A;
  double det;
  s21_create_matrix(10, 10, &A);
  A.rows = 0;
  int res = s21_determinant(&A, &det);
  ck_assert_int_eq(res, 1);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(determinant_test9) {
  matrix_t A;
  double det;
  s21_create_matrix(10, 9, &A);
  int res = s21_determinant(&A, &det);
  ck_assert_int_eq(res, 2);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(determinant_test10) {
  matrix_t A;
  double det;
  double det_true = 984.1238;
  s21_create_matrix(1, 1, &A);
  A.matrix[0][0] = 984.1238;
  int res = s21_determinant(&A, &det);
  ck_assert_double_eq_tol(det, det_true, 1e+08);
  ck_assert_int_eq(res, 0);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(determinant_test11) {
  matrix_t A;
  double det;
  double det_true = -347879921061.47;
  double A_nums[9] = {18248.2488, 91293.124898, 300.1,  390.1123, 44.5, 0,
                      1,          1238.4,       9999.99};
  s21_create_matrix(3, 3, &A);
  s21_set(A_nums, &A);
  int res = s21_determinant(&A, &det);
  ck_assert_double_eq_tol(det, det_true, 1e+08);
  ck_assert_int_eq(res, 0);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(determinant_test12) {
  matrix_t A;
  double det;
  double det_true = -40;
  double A_nums[9] = {1, 2, 3, 0, 4, 2, 5, 2, 1};
  s21_create_matrix(3, 3, &A);
  s21_set(A_nums, &A);
  int res = s21_determinant(&A, &det);
  ck_assert_double_eq_tol(det, det_true, 1e+08);
  ck_assert_int_eq(res, 0);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(determinant_test13) {
  matrix_t A;
  double det;
  double det_true = -1369800;
  double A_nums[25] = {1,  2,  3,   4, 5,  6,  7,  8,  9,  10, 11, 12, 49,
                       14, 15, 161, 7, 18, 19, 20, 64, 48, 1,  2,  3};
  s21_create_matrix(5, 5, &A);
  s21_set(A_nums, &A);
  int res = s21_determinant(&A, &det);
  ck_assert_double_eq_tol(det, det_true, 1e+08);
  ck_assert_int_eq(res, 0);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(determinant_test14) {
  matrix_t A;
  double det;
  double det_true = 17187;
  double A_nums[4] = {9, 2, 96, 1931};
  s21_create_matrix(2, 2, &A);
  s21_set(A_nums, &A);
  int res = s21_determinant(&A, &det);
  ck_assert_double_eq_tol(det, det_true, 1e+08);
  ck_assert_int_eq(res, 0);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(determinant_test15) {
  matrix_t A = {0};
  double result;
  ck_assert_int_eq(INCORRECT, s21_determinant(&A, &result));
}

START_TEST(determinant_test16) {
  matrix_t A = {0};
  double result;
  s21_create_matrix(0, 0, &A);
  ck_assert_int_eq(INCORRECT, s21_determinant(&A, &result));
}

START_TEST(determinant_test17) {
  matrix_t A = {0};
  double result;
  s21_create_matrix(1, 1, &A);
  ck_assert_int_eq(OK, s21_determinant(&A, &result));
  ck_assert_int_eq(0, result);
  s21_remove_matrix(&A);
}

START_TEST(determinant_test18) {
  matrix_t A = {0};
  double result;
  s21_create_matrix(2, 1, &A);
  ck_assert_int_eq(CALC_ERROR, s21_determinant(&A, &result));
  s21_remove_matrix(&A);
}

START_TEST(determinant_test19) {
  matrix_t A = {0};
  double result;
  s21_create_matrix(8, 7, &A);
  ck_assert_int_eq(CALC_ERROR, s21_determinant(&A, &result));
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(determinant_test20) {
  matrix_t A = {0};
  double result;
  s21_create_matrix(1, 1, &A);
  A.matrix[0][0] = -6575.456343;
  ck_assert_int_eq(OK, s21_determinant(&A, &result));
  ck_assert_double_eq_tol(result, A.matrix[0][0], 1e-06);

  s21_remove_matrix(&A);
}
END_TEST

START_TEST(determinant_test21) {
  matrix_t A = {0};
  double result;
  A.rows = A.columns = 8;
  ck_assert_int_eq(INCORRECT, s21_determinant(&A, &result));
}

START_TEST(determinant_test22) {
  matrix_t A = {0};
  double result;
  s21_create_matrix(2, 2, &A);
  A.matrix[0][0] = 1;
  A.matrix[0][1] = 2;
  A.matrix[1][0] = 3;
  A.matrix[1][1] = 4;
  ck_assert_int_eq(OK, s21_determinant(&A, &result));
  ck_assert_ldouble_eq_tol(
      A.matrix[0][0] * A.matrix[1][1] - (A.matrix[0][1] * A.matrix[1][0]),
      result, 1e-06);

  s21_remove_matrix(&A);
}

START_TEST(determinant_test23) {
  matrix_t A = {0};
  double result;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 1;
  A.matrix[0][1] = 2;
  A.matrix[0][2] = 2;
  A.matrix[1][0] = 3;
  A.matrix[1][1] = 4;
  A.matrix[1][2] = 4;
  A.matrix[2][0] = 2;
  A.matrix[2][1] = 2;
  A.matrix[2][2] = 3;

  ck_assert_int_eq(OK, s21_determinant(&A, &result));
  ck_assert_ldouble_eq_tol(-2, result, 1e-06);

  s21_remove_matrix(&A);
}

START_TEST(determinant_test24) {
  matrix_t A = {0};
  double result;
  s21_create_matrix(2, 2, &A);
  A.matrix[0][0] = 1;
  A.matrix[0][1] = 2;
  A.matrix[1][0] = 3;
  A.matrix[1][1] = 4;
  ck_assert_int_eq(OK, s21_determinant(&A, &result));
  ck_assert_ldouble_eq_tol(
      A.matrix[0][0] * A.matrix[1][1] - (A.matrix[0][1] * A.matrix[1][0]),
      result, 1e-06);

  s21_remove_matrix(&A);
}

START_TEST(determinant_test25) {
  matrix_t A = {0};
  double result;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = -76.576;
  A.matrix[0][1] = 6.45645;
  A.matrix[0][2] = 876.54567897655678;
  A.matrix[1][0] = 0.000000001;
  A.matrix[1][1] = -1.111111111;
  A.matrix[1][2] = 393.93;
  A.matrix[2][0] = 1.2345;
  A.matrix[2][1] = -1.11111111199;
  A.matrix[2][2] = 0.87645678765;
  double test_result = A.matrix[0][0] * A.matrix[1][1] * A.matrix[2][2] +
                       A.matrix[0][1] * A.matrix[1][2] * A.matrix[2][0] +
                       A.matrix[0][2] * A.matrix[1][0] * A.matrix[2][1] -
                       (A.matrix[0][2] * A.matrix[1][1] * A.matrix[2][0]) -
                       (A.matrix[0][0] * A.matrix[1][2] * A.matrix[2][1]) -
                       (A.matrix[0][1] * A.matrix[1][0] * A.matrix[2][2]);
  ck_assert_int_eq(OK, s21_determinant(&A, &result));
  ck_assert_ldouble_eq_tol(test_result, result, 1e-06);
  s21_remove_matrix(&A);
}

START_TEST(determinant_test26) {
  matrix_t A = {0};
  double result;
  s21_create_matrix(4, 4, &A);
  A.matrix[0][0] = 47545;
  A.matrix[0][1] = 3.66564577;
  A.matrix[0][2] = -10;
  A.matrix[0][3] = 0.643;
  A.matrix[1][0] = 765789.01;
  A.matrix[1][1] = -99.999999999;
  A.matrix[1][2] = 0.0000000005646;
  A.matrix[1][3] = 5.55757435;
  A.matrix[2][0] = 1.867546867;
  A.matrix[2][1] = -1.7657868;
  A.matrix[2][2] = 0.87988678;
  A.matrix[2][3] = 8.8687678877;
  A.matrix[3][0] = -1.867546867;
  A.matrix[3][1] = 1.7657868;
  A.matrix[3][2] = -0.87988678;
  A.matrix[3][3] = -8.8687678877;

  ck_assert_int_eq(OK, s21_determinant(&A, &result));
  ck_assert_ldouble_eq_tol(0, result, 1e-06);
  s21_remove_matrix(&A);
}

START_TEST(determinant_test27) {
  matrix_t A = {0};
  double result = 0.;
  ck_assert_int_eq(s21_determinant(&A, &result), INCORRECT);
}
END_TEST

START_TEST(determinant_test28) {
  //   matrix_t A = {0};
  double result = 0.;
  ck_assert_int_eq(s21_determinant(NULL, &result), INCORRECT);
}
END_TEST

START_TEST(determinant_test29) {
  //   matrix_t A = {0};
  double result = 0.;
  ck_assert_int_eq(s21_determinant((void *)0, &result), INCORRECT);
}
END_TEST

START_TEST(determinant_test30) {
  matrix_t A = {0};
  s21_create_matrix(4, 4, &A);
  double result = 0;
  A.matrix[0][0] = 1;
  A.matrix[0][1] = 2;
  A.matrix[0][2] = 3;
  A.matrix[0][3] = 4;
  A.matrix[1][0] = 5;
  A.matrix[1][1] = 6;
  A.matrix[1][2] = 7;
  A.matrix[1][3] = 8;
  A.matrix[2][0] = 9;
  A.matrix[2][1] = 10;
  A.matrix[2][2] = 11;
  A.matrix[2][3] = 12;
  A.matrix[3][0] = 13;
  A.matrix[3][1] = 14;
  A.matrix[3][2] = 15;
  A.matrix[3][3] = 16;
  int answer = s21_determinant(&A, &result);
  ck_assert_int_eq(answer, 0);
  ck_assert_double_eq(result, 0);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(determinant_test31) {
  matrix_t A = {0};
  s21_create_matrix(3, 3, &A);
  double result = 0;
  A.matrix[0][0] = 6;
  A.matrix[0][1] = 7;
  A.matrix[0][2] = 8;
  A.matrix[1][0] = 10;
  A.matrix[1][1] = 11;
  A.matrix[1][2] = 12;
  A.matrix[2][0] = 14;
  A.matrix[2][1] = 15;
  A.matrix[2][2] = 16;

  int answer = s21_determinant(&A, &result);
  ck_assert_int_eq(answer, 0);
  ck_assert_double_eq(result, 0);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(determinant_test32) {
  matrix_t A = {0};
  s21_create_matrix(3, 3, &A);
  double result = 0;
  A.matrix[0][0] = 1.;
  A.matrix[0][1] = 2.;
  A.matrix[0][2] = 3.;
  A.matrix[1][0] = 4.;
  A.matrix[1][1] = 5.;
  A.matrix[1][2] = 6.;
  A.matrix[2][0] = 7.;
  A.matrix[2][1] = 8.;
  A.matrix[2][2] = 9.;
  int answer = s21_determinant(&A, &result);
  ck_assert_int_eq(answer, 0);
  ck_assert_double_eq(result, 0.);
  s21_remove_matrix(&A);
}
END_TEST

Suite *determinant_suite() {
  Suite *s = suite_create("\033[35mDETERMINANT MATRIX\033[0m");
  TCase *determinant_tests = tcase_create("DETERMINANT MATRIX");
  suite_add_tcase(s, determinant_tests);
  tcase_add_test(determinant_tests, determinant_test1);
  tcase_add_test(determinant_tests, determinant_test2);
  tcase_add_test(determinant_tests, determinant_test3);
  tcase_add_test(determinant_tests, determinant_test4);
  tcase_add_test(determinant_tests, determinant_test5);
  tcase_add_test(determinant_tests, determinant_test6);
  tcase_add_test(determinant_tests, determinant_test7);
  tcase_add_test(determinant_tests, determinant_test8);
  tcase_add_test(determinant_tests, determinant_test9);
  tcase_add_test(determinant_tests, determinant_test10);
  tcase_add_test(determinant_tests, determinant_test11);
  tcase_add_test(determinant_tests, determinant_test12);
  tcase_add_test(determinant_tests, determinant_test13);
  tcase_add_test(determinant_tests, determinant_test14);
  tcase_add_test(determinant_tests, determinant_test15);
  tcase_add_test(determinant_tests, determinant_test16);
  tcase_add_test(determinant_tests, determinant_test17);
  tcase_add_test(determinant_tests, determinant_test18);
  tcase_add_test(determinant_tests, determinant_test19);
  tcase_add_test(determinant_tests, determinant_test20);
  tcase_add_test(determinant_tests, determinant_test21);
  tcase_add_test(determinant_tests, determinant_test22);
  tcase_add_test(determinant_tests, determinant_test23);
  tcase_add_test(determinant_tests, determinant_test24);
  tcase_add_test(determinant_tests, determinant_test25);
  tcase_add_test(determinant_tests, determinant_test26);
  tcase_add_test(determinant_tests, determinant_test27);
  tcase_add_test(determinant_tests, determinant_test28);
  tcase_add_test(determinant_tests, determinant_test29);
  tcase_add_test(determinant_tests, determinant_test30);
  tcase_add_test(determinant_tests, determinant_test31);
  tcase_add_test(determinant_tests, determinant_test32);

  return s;
}