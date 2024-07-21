#include "s21_tests.h"

START_TEST(transpose_test1) {
  ck_assert_int_eq(s21_transpose(NULL, NULL), INCORRECT);
}
END_TEST

START_TEST(transpose_test2) {
  ck_assert_int_eq(s21_transpose((void *)0, NULL), INCORRECT);
}
END_TEST

START_TEST(transpose_test3) {
  matrix_t A = {0}, result = {0};
  int rows = 3, columns = 5;
  s21_create_matrix(rows, columns, &A);
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < columns; j++) {
      A.matrix[i][j] = (double)(rand()) / RAND_MAX;
    }
  }
  ck_assert_int_eq(s21_transpose(&A, &result), OK);
  s21_remove_matrix(&A);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(transpose_test4) {
  matrix_t A = {0}, result = {0}, result_tmp = {0};
  int rows = 3, columns = 2;
  int sum = 0;
  s21_create_matrix(rows, columns, &A);
  A.matrix[0][0] = 1;
  A.matrix[0][1] = 4;
  A.matrix[1][0] = 2;
  A.matrix[1][1] = 5;
  A.matrix[2][0] = 3;
  A.matrix[2][1] = 6;
  s21_create_matrix(columns, rows, &result_tmp);
  result_tmp.matrix[0][0] = 1;
  result_tmp.matrix[0][1] = 2;
  result_tmp.matrix[0][2] = 3;
  result_tmp.matrix[1][0] = 4;
  result_tmp.matrix[1][1] = 5;
  result_tmp.matrix[1][2] = 6;
  s21_transpose(&A, &result);
  for (int i = 0; i < columns; i++) {
    for (int j = 0; j < rows; j++) {
      if (fabs(result_tmp.matrix[i][j] - result.matrix[i][j]) > 1e-8) {
        sum++;
      }
    }
  }
  ck_assert_int_eq(sum, 0);
  s21_remove_matrix(&A);
  s21_remove_matrix(&result);
  s21_remove_matrix(&result_tmp);
}
END_TEST

START_TEST(transpose_test5) {
  matrix_t A = {0}, result = {0};
  ck_assert_int_eq(INCORRECT, s21_transpose(&A, &result));
}

START_TEST(transpose_test6) {
  matrix_t A = {0}, result = {0};
  s21_create_matrix(0, 0, &A);
  ck_assert_int_eq(INCORRECT, s21_transpose(&A, &result));
}

START_TEST(transpose_test7) {
  matrix_t A = {0}, result = {0};
  s21_create_matrix(1, 1, &A);
  A.matrix[0][0] = 8.765;
  ck_assert_int_eq(OK, s21_transpose(&A, &result));
  ck_assert_ldouble_eq_tol(A.matrix[0][0], result.matrix[0][0], 1e-06);
  s21_remove_matrix(&A);
  s21_remove_matrix(&result);
}

START_TEST(transpose_test8) {
  matrix_t A = {0}, result = {0}, test_result = {0};
  s21_create_matrix(2, 1, &A);
  s21_create_matrix(1, 2, &test_result);
  A.matrix[0][0] = test_result.matrix[0][0] = 8.765;
  A.matrix[1][0] = test_result.matrix[0][1] = -58765.4;
  ck_assert_int_eq(OK, s21_transpose(&A, &result));
  ck_assert_ldouble_eq_tol(test_result.matrix[0][0], result.matrix[0][0],
                           1e-06);
  ck_assert_ldouble_eq_tol(test_result.matrix[0][1], result.matrix[0][1],
                           1e-06);
  s21_remove_matrix(&A);
  s21_remove_matrix(&test_result);
  s21_remove_matrix(&result);
}

START_TEST(transpose_test9) {
  matrix_t A = {0}, result = {0};
  A.rows = A.columns = 8;
  ck_assert_int_eq(INCORRECT, s21_transpose(&A, &result));
}

START_TEST(transpose_test10) {
  matrix_t A = {0}, result = {0};
  s21_create_matrix(2, 2, &A);
  A.matrix[0][0] = 1;
  A.matrix[0][1] = 2;
  A.matrix[1][0] = 3;
  A.matrix[1][1] = 4;
  ck_assert_int_eq(OK, s21_transpose(&A, &result));
  ck_assert_ldouble_eq_tol(1, result.matrix[0][0], 1e-06);
  ck_assert_ldouble_eq_tol(3, result.matrix[0][1], 1e-06);
  ck_assert_ldouble_eq_tol(2, result.matrix[1][0], 1e-06);
  ck_assert_ldouble_eq_tol(4, result.matrix[1][1], 1e-06);
  s21_remove_matrix(&A);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(transpose_test11) {
  matrix_t A = {0}, result = {0};
  s21_create_matrix(3, 2, &A);
  A.matrix[0][0] = -0.0000000001;
  A.matrix[0][1] = 3.453415;
  A.matrix[1][0] = 9534983493.4349;
  A.matrix[1][1] = 5648765.21876578678;
  A.matrix[2][0] = 1.1111111;
  A.matrix[2][1] = 0;
  ck_assert_int_eq(OK, s21_transpose(&A, &result));
  ck_assert_ldouble_eq_tol(A.matrix[0][0], result.matrix[0][0], 1e-06);
  ck_assert_ldouble_eq_tol(A.matrix[1][0], result.matrix[0][1], 1e-06);
  ck_assert_ldouble_eq_tol(A.matrix[2][0], result.matrix[0][2], 1e-06);
  ck_assert_ldouble_eq_tol(A.matrix[0][1], result.matrix[1][0], 1e-06);
  ck_assert_ldouble_eq_tol(A.matrix[1][1], result.matrix[1][1], 1e-06);
  ck_assert_ldouble_eq_tol(A.matrix[2][1], result.matrix[1][2], 1e-06);

  s21_remove_matrix(&A);
  s21_remove_matrix(&result);
}
END_TEST

Suite *transpose_suite() {
  Suite *s = suite_create("\033[35mTRANSPOSE MATRIX\033[0m");
  TCase *transpose_tests = tcase_create("TRANSPOSE MATRIX");
  suite_add_tcase(s, transpose_tests);
  tcase_add_test(transpose_tests, transpose_test1);
  tcase_add_test(transpose_tests, transpose_test2);
  tcase_add_test(transpose_tests, transpose_test3);
  tcase_add_test(transpose_tests, transpose_test4);
  tcase_add_test(transpose_tests, transpose_test5);
  tcase_add_test(transpose_tests, transpose_test6);
  tcase_add_test(transpose_tests, transpose_test7);
  tcase_add_test(transpose_tests, transpose_test8);
  tcase_add_test(transpose_tests, transpose_test9);
  tcase_add_test(transpose_tests, transpose_test10);
  tcase_add_test(transpose_tests, transpose_test11);

  return s;
}