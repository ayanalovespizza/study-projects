#include "s21_tests.h"

START_TEST(mult_matrix_test1) {
  const int rows = 2;
  const int cols = 3;
  matrix_t m = {0};
  s21_create_matrix(rows, cols, &m);
  matrix_t mtx = {0};
  s21_create_matrix(cols, rows, &mtx);

  for (int i = 0, c = 1; i < rows; i++)
    for (int j = 0; j < cols; j++) m.matrix[i][j] = c++;

  for (int i = 0, c = 7; i < cols; i++)
    for (int j = 0; j < rows; j++) mtx.matrix[i][j] = c++;

  matrix_t check = {0};
  s21_create_matrix(m.rows, mtx.columns, &check);
  check.matrix[0][0] = 58;
  check.matrix[0][1] = 64;
  check.matrix[1][0] = 139;
  check.matrix[1][1] = 154;

  matrix_t res = {0};
  ck_assert_int_eq(s21_mult_matrix(&m, &mtx, &res), OK);
  ck_assert_int_eq(s21_eq_matrix(&check, &res), SUCCESS);

  s21_remove_matrix(&m);
  s21_remove_matrix(&mtx);
  s21_remove_matrix(&res);
  s21_remove_matrix(&check);
}
END_TEST

START_TEST(mult_matrix_test2) {
  matrix_t m = {0};
  int rows = 2;
  int cols = 3;
  s21_create_matrix(rows, cols, &m);
  matrix_t mtx = {0};
  int rows1 = 4;
  int cols1 = 5;
  s21_create_matrix(rows1, cols1, &mtx);

  matrix_t check = {0};
  s21_create_matrix(m.rows, mtx.columns, &check);

  matrix_t res = {0};
  ck_assert_int_eq(s21_mult_matrix(&m, &mtx, &res), CALC_ERROR);

  s21_remove_matrix(&m);
  s21_remove_matrix(&mtx);
  s21_remove_matrix(&res);
  s21_remove_matrix(&check);
}
END_TEST

START_TEST(mult_matrix_test3) {
  matrix_t A = {0}, B = {0}, result = {0};
  ck_assert_int_eq(INCORRECT, s21_mult_matrix(&A, &B, &result));
}

START_TEST(mult_matrix_test4) {
  matrix_t A = {0}, B = {0}, result = {0};
  s21_create_matrix(0, 0, &A);
  s21_create_matrix(0, 0, &B);
  ck_assert_int_eq(INCORRECT, s21_mult_matrix(&A, &B, &result));
}

START_TEST(mult_matrix_test5) {
  matrix_t A = {0}, B = {0}, result = {0};
  s21_create_matrix(1, 1, &A);
  s21_create_matrix(1, 2, &B);
  ck_assert_int_eq(0, s21_mult_matrix(&A, &B, &result));

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&result);
}

START_TEST(mult_matrix_test6) {
  matrix_t A = {0}, B = {0}, result = {0};
  s21_create_matrix(2, 1, &A);
  s21_create_matrix(1, 2, &B);
  ck_assert_int_eq(OK, s21_mult_matrix(&A, &B, &result));
  ck_assert_ldouble_eq_tol(0, result.matrix[0][0], 1e-06);
  ck_assert_ldouble_eq_tol(0, result.matrix[0][1], 1e-06);
  ck_assert_ldouble_eq_tol(0, result.matrix[1][0], 1e-06);
  ck_assert_ldouble_eq_tol(0, result.matrix[1][1], 1e-06);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&result);
}

START_TEST(mult_matrix_test7) {
  matrix_t A = {0}, B = {0}, result = {0};
  A.rows = A.columns = B.rows = B.columns = 8;
  ck_assert_int_eq(INCORRECT, s21_mult_matrix(&A, &B, &result));
}

START_TEST(mult_matrix_test8) {
  matrix_t A = {0}, B = {0}, result = {0};
  s21_create_matrix(2, 2, &B);
  B.matrix[0][0] = 1;
  B.matrix[0][1] = 2;
  B.matrix[1][0] = 3;
  B.matrix[1][1] = 4;
  ck_assert_int_eq(INCORRECT, s21_mult_matrix(&A, &B, &result));
  s21_remove_matrix(&B);
}

START_TEST(mult_matrix_test9) {
  matrix_t A = {0}, B = {0}, result = {0};
  s21_create_matrix(2, 2, &A);
  A.matrix[0][0] = 1;
  A.matrix[0][1] = 2;
  A.matrix[1][0] = 3;
  A.matrix[1][1] = 4;
  ck_assert_int_eq(INCORRECT, s21_mult_matrix(&A, &B, &result));
  s21_remove_matrix(&A);
}

START_TEST(mult_matrix_test10) {
  matrix_t A = {0}, B = {0}, result = {0};
  s21_create_matrix(3, 2, &A);
  s21_create_matrix(3, 2, &B);
  ck_assert_int_eq(CALC_ERROR, s21_mult_matrix(&A, &B, &result));
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(mult_matrix_test11) {
  matrix_t A = {0}, B = {0}, result = {0};
  s21_create_matrix(1, 1, &A);
  s21_create_matrix(1, 1, &B);
  A.matrix[0][0] = 9668.9786796878867;
  B.matrix[0][0] = 97.689698767;
  ck_assert_int_eq(OK, s21_mult_matrix(&A, &B, &result));
  ck_assert_ldouble_eq_tol(A.matrix[0][0] * B.matrix[0][0], result.matrix[0][0],
                           1e-06);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(mult_matrix_test12) {
  matrix_t A = {0}, B = {0}, result = {0}, test_result = {0};
  s21_create_matrix(2, 1, &A);
  s21_create_matrix(1, 2, &B);
  s21_create_matrix(2, 2, &result);

  A.matrix[0][0] = 0;
  A.matrix[1][0] = 0.00000000032324;
  B.matrix[0][0] = 0.1;
  B.matrix[0][1] = -98087.987987098798;

  result.matrix[0][0] = A.matrix[0][0] * B.matrix[0][0];
  result.matrix[0][1] = A.matrix[0][0] * B.matrix[0][1];

  result.matrix[1][0] = A.matrix[1][0] * B.matrix[0][0];

  result.matrix[1][1] = A.matrix[1][0] * B.matrix[0][1];

  ck_assert_int_eq(OK, s21_mult_matrix(&A, &B, &test_result));
  ck_assert_int_eq(SUCCESS, s21_eq_matrix(&result, &test_result));
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&result);
  s21_remove_matrix(&test_result);
}
END_TEST

START_TEST(mult_matrix_test13) {
  matrix_t A = {0}, B = {0}, result = {0}, test_result = {0};
  s21_create_matrix(1, 2, &A);
  s21_create_matrix(2, 1, &B);
  s21_create_matrix(1, 1, &result);

  A.matrix[0][0] = 0;
  A.matrix[0][1] = 0.00000000032324;
  B.matrix[0][0] = 0.1;
  B.matrix[1][0] = -98087.987987098798;

  result.matrix[0][0] =
      A.matrix[0][0] * B.matrix[0][0] + A.matrix[0][1] * B.matrix[1][0];

  ck_assert_int_eq(OK, s21_mult_matrix(&A, &B, &test_result));
  ck_assert_int_eq(SUCCESS, s21_eq_matrix(&result, &test_result));
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&result);
  s21_remove_matrix(&test_result);
}
END_TEST

START_TEST(mult_matrix_test14) {
  matrix_t result = {0};
  ck_assert_int_eq(s21_mult_matrix((void *)0, NULL, &result), INCORRECT);
}
END_TEST

START_TEST(mult_matrix_test15) {
  matrix_t result = {0};
  ck_assert_int_eq(s21_mult_matrix(NULL, NULL, &result), INCORRECT);
}
END_TEST

START_TEST(mult_matrix_test16) {
  matrix_t A = {0}, B = {0}, result = {0};
  int Arows = 3, Acolumns = 5;
  int Brows = 5, Bcolumns = 6;
  s21_create_matrix(Arows, Acolumns, &A);
  s21_create_matrix(Brows, Bcolumns, &B);
  for (int i = 0; i < Arows; i++) {
    for (int j = 0; j < Acolumns; j++) {
      A.matrix[i][j] = (double)(rand()) / RAND_MAX;
    }
  }
  for (int i = 0; i < Brows; i++) {
    for (int j = 0; j < Bcolumns; j++) {
      B.matrix[i][j] = (double)(rand()) / RAND_MAX;
    }
  }
  ck_assert_int_eq(s21_mult_matrix(&A, &B, &result), OK);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(mult_matrix_test17) {
  matrix_t A = {0};
  matrix_t B = {0};
  matrix_t result = {0};
  s21_create_matrix(1, 2, &A);
  s21_create_matrix(3, 1, &B);
  A.matrix[0][0] = 1.;
  A.matrix[0][1] = 2.;
  B.matrix[0][0] = 2.;
  B.matrix[1][0] = 1.;
  B.matrix[2][0] = 2.;
  int answer = s21_mult_matrix(&A, &B, &result);
  ck_assert_int_eq(answer, 2);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&result);
}
END_TEST

Suite *mult_matrix_suite() {
  Suite *s = suite_create("\033[35mMULT MATRICES\033[0m");
  TCase *mult_matrix_tests = tcase_create("MULT MATRICES");
  suite_add_tcase(s, mult_matrix_tests);
  tcase_add_test(mult_matrix_tests, mult_matrix_test1);
  tcase_add_test(mult_matrix_tests, mult_matrix_test2);
  tcase_add_test(mult_matrix_tests, mult_matrix_test3);
  tcase_add_test(mult_matrix_tests, mult_matrix_test4);
  tcase_add_test(mult_matrix_tests, mult_matrix_test5);
  tcase_add_test(mult_matrix_tests, mult_matrix_test6);
  tcase_add_test(mult_matrix_tests, mult_matrix_test7);
  tcase_add_test(mult_matrix_tests, mult_matrix_test8);
  tcase_add_test(mult_matrix_tests, mult_matrix_test9);
  tcase_add_test(mult_matrix_tests, mult_matrix_test10);
  tcase_add_test(mult_matrix_tests, mult_matrix_test11);
  tcase_add_test(mult_matrix_tests, mult_matrix_test12);
  tcase_add_test(mult_matrix_tests, mult_matrix_test13);
  tcase_add_test(mult_matrix_tests, mult_matrix_test14);
  tcase_add_test(mult_matrix_tests, mult_matrix_test15);
  tcase_add_test(mult_matrix_tests, mult_matrix_test16);
  tcase_add_test(mult_matrix_tests, mult_matrix_test17);

  return s;
}
