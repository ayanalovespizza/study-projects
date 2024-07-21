#include "s21_tests.h"

START_TEST(eq_matrix_test1) {
  matrix_t A = {0};
  matrix_t B = {0};
  int result = s21_eq_matrix(&A, &B);
  ck_assert_int_eq(0, result);
}

START_TEST(eq_matrix_test2) {
  matrix_t A = {0};
  matrix_t B = {0};
  s21_create_matrix(0, 0, &A);
  s21_create_matrix(0, 0, &B);
  int result = s21_eq_matrix(&A, &B);
  ck_assert_int_eq(0, result);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}

START_TEST(eq_matrix_test3) {
  matrix_t A = {0};
  matrix_t B = {0};
  s21_create_matrix(1, 1, &A);
  s21_create_matrix(1, 1, &B);
  A.matrix[0][0] = 1;
  B.matrix[0][0] = 1;
  int result = s21_eq_matrix(&A, &B);
  ck_assert_int_eq(SUCCESS, result);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}

START_TEST(eq_matrix_test4) {
  matrix_t A = {0};
  matrix_t B = {0};
  s21_create_matrix(1, 1, &A);
  s21_create_matrix(1, 1, &B);
  A.matrix[0][0] = 1;
  B.matrix[0][0] = 2;
  int result = s21_eq_matrix(&A, &B);
  ck_assert_int_eq(FAILURE, result);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}

START_TEST(eq_matrix_test5) {
  matrix_t A = {0};
  matrix_t B = {0};
  s21_create_matrix(2, 2, &A);
  s21_create_matrix(2, 2, &B);
  A.matrix[0][0] = 1;
  A.matrix[0][1] = 2;
  A.matrix[1][0] = 3;
  A.matrix[1][1] = 4;
  B.matrix[0][0] = 1;
  B.matrix[0][1] = 2;
  B.matrix[1][0] = 3;
  B.matrix[1][1] = 4;
  int result = s21_eq_matrix(&A, &B);
  ck_assert_int_eq(SUCCESS, result);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}

START_TEST(eq_matrix_test6) {
  matrix_t A = {0};
  matrix_t B = {0};
  s21_create_matrix(2, 2, &A);
  s21_create_matrix(2, 2, &B);
  A.matrix[0][0] = 1.01;
  A.matrix[0][1] = 2;
  A.matrix[1][0] = 3.05;
  A.matrix[1][1] = 4;
  B.matrix[0][0] = 1.01;
  B.matrix[0][1] = 2;
  B.matrix[1][0] = 3.05;
  B.matrix[1][1] = 4;
  int result = s21_eq_matrix(&A, &B);
  ck_assert_int_eq(SUCCESS, result);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}

START_TEST(eq_matrix_test7) {
  matrix_t A = {0};
  matrix_t B = {0};
  s21_create_matrix(2, 2, &A);
  s21_create_matrix(2, 2, &B);
  A.matrix[0][0] = 1.01;
  A.matrix[0][1] = -2;
  A.matrix[1][0] = 3.05;
  A.matrix[1][1] = -4;
  B.matrix[0][0] = 1.01;
  B.matrix[0][1] = -2;
  B.matrix[1][0] = 3.05;
  B.matrix[1][1] = -4;
  int result = s21_eq_matrix(&A, &B);
  ck_assert_int_eq(SUCCESS, result);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}

START_TEST(eq_matrix_test8) {
  matrix_t A = {0};
  matrix_t B = {0};
  s21_create_matrix(2, 2, &A);
  s21_create_matrix(2, 2, &B);
  A.matrix[0][0] = 1.00000000234;
  A.matrix[0][1] = 2;
  A.matrix[1][0] = 3.05;
  A.matrix[1][1] = 4;
  B.matrix[0][0] = 1;
  B.matrix[0][1] = 2;
  B.matrix[1][0] = 3.05000009;
  B.matrix[1][1] = 4;
  int result = s21_eq_matrix(&A, &B);
  ck_assert_int_eq(SUCCESS, result);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}

START_TEST(eq_matrix_test9) {
  matrix_t A = {0};
  matrix_t B = {0};
  s21_create_matrix(2, 2, &A);
  s21_create_matrix(2, 2, &B);
  A.matrix[0][0] = 1.0001;
  A.matrix[0][1] = 2;
  A.matrix[1][0] = 3.05;
  A.matrix[1][1] = 4;
  B.matrix[0][0] = 1;
  B.matrix[0][1] = 2;
  B.matrix[1][0] = 3.05;
  B.matrix[1][1] = 4;
  int result = s21_eq_matrix(&A, &B);
  ck_assert_int_eq(FAILURE, result);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}

START_TEST(eq_matrix_test10) {
  matrix_t matrix_A;
  matrix_t matrix_B;
  int rows = 2;
  int columns = 2;

  double matrix_A1[2][2] = {{1, 2}, {3, 4}};
  double matrix_B1[2][2] = {{1, 2}, {3, 4}};

  int res1 = s21_create_matrix(rows, columns, &matrix_A);
  int res2 = s21_create_matrix(rows, columns, &matrix_B);

  ck_assert_int_eq(res1, 0);
  ck_assert_int_eq(res2, 0);

  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < columns; j++) {
      matrix_A.matrix[i][j] = matrix_A1[i][j];
      matrix_B.matrix[i][j] = matrix_B1[i][j];
    }
  }

  int res_eq = s21_eq_matrix(&matrix_A, &matrix_B);
  ck_assert_int_eq(res_eq, SUCCESS);

  if (res1 == 0) s21_remove_matrix(&matrix_A);
  if (res2 == 0) s21_remove_matrix(&matrix_B);
}
END_TEST

START_TEST(eq_matrix_test11) {
  matrix_t matrix_A;
  matrix_t matrix_B;
  int rows = 2;
  int columns = 2;

  double matrix_A1[2][2] = {{1.00000000234, 2}, {3, 4}};
  double matrix_B1[2][2] = {{1, 2}, {3, 4}};

  int res1 = s21_create_matrix(rows, columns, &matrix_A);
  int res2 = s21_create_matrix(rows, columns, &matrix_B);

  ck_assert_int_eq(res1, 0);
  ck_assert_int_eq(res2, 0);

  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < columns; j++) {
      matrix_A.matrix[i][j] = matrix_A1[i][j];
      matrix_B.matrix[i][j] = matrix_B1[i][j];
    }
  }

  int res_eq = s21_eq_matrix(&matrix_A, &matrix_B);
  ck_assert_int_eq(res_eq, SUCCESS);

  if (res1 == 0) s21_remove_matrix(&matrix_A);
  if (res2 == 0) s21_remove_matrix(&matrix_B);
}
END_TEST

START_TEST(eq_matrix_test12) {
  matrix_t matrix_A;
  matrix_t matrix_B;
  int rows = 2;
  int columns = 2;

  double matrix_A1[2][2] = {{1, 3}, {3, 4}};
  double matrix_B1[2][2] = {{1, 2}, {3, 4}};

  int res1 = s21_create_matrix(rows, columns, &matrix_A);
  int res2 = s21_create_matrix(rows, columns, &matrix_B);

  ck_assert_int_eq(res1, 0);
  ck_assert_int_eq(res2, 0);

  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < columns; j++) {
      matrix_A.matrix[i][j] = matrix_A1[i][j];
      matrix_B.matrix[i][j] = matrix_B1[i][j];
    }
  }

  int res_eq = s21_eq_matrix(&matrix_A, &matrix_B);
  ck_assert_int_eq(res_eq, FAILURE);

  if (res1 == 0) s21_remove_matrix(&matrix_A);
  if (res2 == 0) s21_remove_matrix(&matrix_B);
}
END_TEST

START_TEST(eq_matrix_test13) {
  matrix_t matrix_A;
  matrix_t matrix_B;
  int rows = 2;
  int columns = 2;

  double matrix_A1[2][2] = {{1.001, 3}, {3, 4}};
  double matrix_B1[2][2] = {{1, 2}, {3, 4}};

  int res1 = s21_create_matrix(rows, columns, &matrix_A);
  int res2 = s21_create_matrix(rows, columns, &matrix_B);

  ck_assert_int_eq(res1, 0);
  ck_assert_int_eq(res2, 0);

  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < columns; j++) {
      matrix_A.matrix[i][j] = matrix_A1[i][j];
      matrix_B.matrix[i][j] = matrix_B1[i][j];
    }
  }

  int res_eq = s21_eq_matrix(&matrix_A, &matrix_B);
  ck_assert_int_eq(res_eq, FAILURE);

  if (res1 == 0) s21_remove_matrix(&matrix_A);
  if (res2 == 0) s21_remove_matrix(&matrix_B);
}
END_TEST

START_TEST(eq_matrix_test14) {
  matrix_t matrix_A;
  matrix_t matrix_B;
  int rows = 2;
  int columns = 2;

  double matrix_A1[2][2] = {{0, 0}, {0.000001, 0}};
  double matrix_B1[2][2] = {{0, 0}, {0, 0}};

  int res1 = s21_create_matrix(rows, columns, &matrix_A);
  int res2 = s21_create_matrix(rows, columns, &matrix_B);

  ck_assert_int_eq(res1, 0);
  ck_assert_int_eq(res2, 0);

  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < columns; j++) {
      matrix_A.matrix[i][j] = matrix_A1[i][j];
      matrix_B.matrix[i][j] = matrix_B1[i][j];
    }
  }

  int res_eq = s21_eq_matrix(&matrix_A, &matrix_B);
  ck_assert_int_eq(res_eq, FAILURE);

  if (res1 == 0) s21_remove_matrix(&matrix_A);
  if (res2 == 0) s21_remove_matrix(&matrix_B);
}
END_TEST

START_TEST(eq_matrix_test15) {
  matrix_t matrix_A = {0, 4, 0};
  matrix_t matrix_B = {0, 4, 0};

  int res_eq = s21_eq_matrix(&matrix_A, &matrix_B);
  ck_assert_int_eq(res_eq, FAILURE);
}
END_TEST

Suite *eq_matrix_suite() {
  Suite *s = suite_create("\033[35mEQUALITY MATRIX\033[0m");
  TCase *eq_matrix_tests = tcase_create("EQUALITY MATRIX");
  suite_add_tcase(s, eq_matrix_tests);
  tcase_add_test(eq_matrix_tests, eq_matrix_test1);
  tcase_add_test(eq_matrix_tests, eq_matrix_test2);
  tcase_add_test(eq_matrix_tests, eq_matrix_test3);
  tcase_add_test(eq_matrix_tests, eq_matrix_test4);
  tcase_add_test(eq_matrix_tests, eq_matrix_test5);
  tcase_add_test(eq_matrix_tests, eq_matrix_test6);
  tcase_add_test(eq_matrix_tests, eq_matrix_test7);
  tcase_add_test(eq_matrix_tests, eq_matrix_test8);
  tcase_add_test(eq_matrix_tests, eq_matrix_test9);
  tcase_add_test(eq_matrix_tests, eq_matrix_test10);
  tcase_add_test(eq_matrix_tests, eq_matrix_test11);
  tcase_add_test(eq_matrix_tests, eq_matrix_test12);
  tcase_add_test(eq_matrix_tests, eq_matrix_test13);
  tcase_add_test(eq_matrix_tests, eq_matrix_test14);
  tcase_add_test(eq_matrix_tests, eq_matrix_test15);

  return s;
}