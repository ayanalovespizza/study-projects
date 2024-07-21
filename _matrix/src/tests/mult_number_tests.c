#include "s21_tests.h"

START_TEST(mult_number_test1) {
  double number = 10;
  matrix_t A = {0}, result = {0};
  ck_assert_int_eq(INCORRECT, s21_mult_number(&A, number, &result));
}

START_TEST(mult_number_test2) {
  double number = 10;
  matrix_t result;
  ck_assert_int_eq(INCORRECT, s21_mult_number(NULL, number, &result));
}
END_TEST

START_TEST(mult_number_test3) {
  double number = 10;
  matrix_t A = {0}, result = {0};
  s21_create_matrix(0, 0, &A);
  ck_assert_int_eq(INCORRECT, s21_mult_number(&A, number, &result));
}

START_TEST(mult_number_test4) {
  double number = 10;
  matrix_t A = {0}, result = {0};
  A.rows = A.columns = 8;
  ck_assert_int_eq(INCORRECT, s21_mult_number(&A, number, &result));
}

START_TEST(mult_number_test5) {
  double number = 0;
  matrix_t A = {0}, result = {0};
  s21_create_matrix(2, 2, &A);
  A.matrix[0][0] = 1;
  A.matrix[0][1] = 2;
  A.matrix[1][0] = 3;
  A.matrix[1][1] = 4;
  ck_assert_int_eq(OK, s21_mult_number(&A, number, &result));
  ck_assert_ldouble_eq_tol(0, result.matrix[0][0], 1e-06);
  ck_assert_ldouble_eq_tol(0, result.matrix[0][1], 1e-06);
  ck_assert_ldouble_eq_tol(0, result.matrix[1][0], 1e-06);
  ck_assert_ldouble_eq_tol(0, result.matrix[1][1], 1e-06);
  s21_remove_matrix(&A);
  s21_remove_matrix(&result);
}

START_TEST(mult_number_test6) {
  double number = 8;
  matrix_t A = {0}, result = {0};
  s21_create_matrix(2, 2, &A);
  ck_assert_int_eq(OK, s21_mult_number(&A, number, &result));
  ck_assert_ldouble_eq_tol(0, result.matrix[0][0], 1e-06);
  ck_assert_ldouble_eq_tol(0, result.matrix[0][1], 1e-06);
  ck_assert_ldouble_eq_tol(0, result.matrix[1][0], 1e-06);
  ck_assert_ldouble_eq_tol(0, result.matrix[1][1], 1e-06);
  s21_remove_matrix(&A);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(mult_number_test7) {
  double number = 46.75757000000000001;
  matrix_t A = {0}, result = {0};
  s21_create_matrix(2, 2, &A);
  A.matrix[0][0] = 1.57576575;
  A.matrix[0][1] = 87626456.5;
  A.matrix[1][0] = -45698.765699876;
  A.matrix[1][1] = 5687647;
  ck_assert_int_eq(OK, s21_mult_number(&A, number, &result));
  ck_assert_ldouble_eq_tol(number * A.matrix[0][0], result.matrix[0][0], 1e-06);
  ck_assert_ldouble_eq_tol(number * A.matrix[0][1], result.matrix[0][1], 1e-06);
  ck_assert_ldouble_eq_tol(number * A.matrix[1][0], result.matrix[1][0], 1e-06);
  ck_assert_ldouble_eq_tol(number * A.matrix[1][1], result.matrix[1][1], 1e-06);
  s21_remove_matrix(&A);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(mult_number_test8) {
  double number = 0.1;
  matrix_t A = {0}, result = {0};
  s21_create_matrix(3, 1, &A);
  A.matrix[0][0] = 0.0000000000000001;
  A.matrix[1][0] = 4564.66436563;
  A.matrix[2][0] = 1.000001;
  ck_assert_int_eq(OK, s21_mult_number(&A, number, &result));
  ck_assert_ldouble_eq_tol(number * A.matrix[0][0], result.matrix[0][0], 1e-06);
  ck_assert_ldouble_eq_tol(number * A.matrix[1][0], result.matrix[1][0], 1e-06);
  ck_assert_ldouble_eq_tol(number * A.matrix[2][0], result.matrix[2][0], 1e-06);
  s21_remove_matrix(&A);
  s21_remove_matrix(&result);
}
// END_TEST

START_TEST(mult_number_test9) {
  matrix_t A = {0};
  s21_create_matrix(1, 1, &A);
  ck_assert_int_eq(s21_mult_number(&A, 5., NULL), INCORRECT);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(mult_number_test10) {
  matrix_t A = {0};
  s21_create_matrix(1, 1, &A);
  ck_assert_int_eq(s21_mult_number(&A, 5., (void *)0), INCORRECT);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(mult_number_test11) {
  matrix_t A = {0}, result = {0};
  int rows = 5, columns = 5;
  double number = (double)(rand()) / RAND_MAX;
  s21_create_matrix(rows, columns, &A);
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < columns; j++) {
      A.matrix[i][j] = (double)(rand()) / RAND_MAX;
    }
  }
  ck_assert_int_eq(s21_mult_number(&A, number, &result), OK);
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < columns; j++) {
      ck_assert_double_eq_tol(A.matrix[i][j] * number, result.matrix[i][j],
                              1e-8);
    }
  }
  s21_remove_matrix(&A);
  s21_remove_matrix(&result);
}
END_TEST

Suite *mult_number_suite() {
  Suite *s = suite_create("\033[35mMULT NUMBER\033[0m");
  TCase *mult_number_tests = tcase_create("MULT NUMBER");
  suite_add_tcase(s, mult_number_tests);
  tcase_add_test(mult_number_tests, mult_number_test1);
  tcase_add_test(mult_number_tests, mult_number_test2);
  tcase_add_test(mult_number_tests, mult_number_test3);
  tcase_add_test(mult_number_tests, mult_number_test4);
  tcase_add_test(mult_number_tests, mult_number_test5);
  tcase_add_test(mult_number_tests, mult_number_test6);
  tcase_add_test(mult_number_tests, mult_number_test7);
  tcase_add_test(mult_number_tests, mult_number_test8);
  tcase_add_test(mult_number_tests, mult_number_test9);
  tcase_add_test(mult_number_tests, mult_number_test10);
  tcase_add_test(mult_number_tests, mult_number_test11);

  return s;
}