#include "s21_tests.h"

START_TEST(inverse_test1) {
  matrix_t A, C;
  s21_create_matrix(3, 3, &A);
  s21_create_matrix(3, 3, &C);
  C.matrix[0][0] = 1.0;
  C.matrix[0][1] = -1.0;
  C.matrix[0][2] = 1.0;
  C.matrix[1][0] = -38.0;
  C.matrix[1][1] = 41.0;
  C.matrix[1][2] = -34.0;
  C.matrix[2][0] = 27.0;
  C.matrix[2][1] = -29.0;
  C.matrix[2][2] = 24.0;
  A.matrix[0][0] = 2.0;
  A.matrix[0][1] = 5.0;
  A.matrix[0][2] = 7.0;
  A.matrix[1][0] = 6.0;
  A.matrix[1][1] = 3.0;
  A.matrix[1][2] = 4.0;
  A.matrix[2][0] = 5.0;
  A.matrix[2][1] = -2.0;
  A.matrix[2][2] = -3.0;
  matrix_t B;

  s21_inverse_matrix(&A, &B);
  int res = s21_eq_matrix(&B, &C);
  ck_assert_int_eq(res, SUCCESS);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&C);
}
END_TEST

START_TEST(inverse_test2) {
  matrix_t m = {0};
  matrix_t result = {0};
  int codec = s21_create_matrix(1, 1, &m);
  if (codec == OK) {
    int code = s21_inverse_matrix(&m, &result);
    ck_assert_int_eq(code, CALC_ERROR);
    s21_remove_matrix(&m);
  }
}
END_TEST

START_TEST(inverse_test3) {
  matrix_t m = {0};
  matrix_t result = {0};
  int code = s21_inverse_matrix(&m, &result);
  ck_assert_int_eq(code, INCORRECT);
}
END_TEST

START_TEST(inverse_test4) {
  const int size = 2;
  matrix_t m = {0};
  s21_create_matrix(size, size, &m);
  m.matrix[0][0] = 1;
  m.matrix[0][1] = 1;
  m.matrix[1][0] = 1;
  m.matrix[1][1] = 1;

  matrix_t result = {0};
  int code = s21_inverse_matrix(&m, &result);
  ck_assert_int_eq(code, CALC_ERROR);

  s21_remove_matrix(&m);
}
END_TEST

START_TEST(inverse_test5) {
  matrix_t m = {0};
  matrix_t result = {0};
  int codec = s21_create_matrix(1, 4, &m);
  if (codec == OK) {
    int code = s21_inverse_matrix(&m, &result);
    ck_assert_int_eq(code, CALC_ERROR);
    s21_remove_matrix(&m);
  }
}
END_TEST

START_TEST(inverse_test6) {
  matrix_t m = {0};
  matrix_t expected = {0};
  int codec1, codec2;
  codec1 = s21_create_matrix(3, 3, &m);
  if (codec1 == OK) codec2 = s21_create_matrix(3, 3, &expected);

  if (codec1 == OK && codec2 == OK) {
    m.matrix[0][0] = 2;
    m.matrix[0][1] = 5;
    m.matrix[0][2] = 7;

    m.matrix[1][0] = 6;
    m.matrix[1][1] = 3;
    m.matrix[1][2] = 4;

    m.matrix[2][0] = 5;
    m.matrix[2][1] = -2;
    m.matrix[2][2] = -3;

    expected.matrix[0][0] = 1;
    expected.matrix[0][1] = -1;
    expected.matrix[0][2] = 1;

    expected.matrix[1][0] = -38;
    expected.matrix[1][1] = 41;
    expected.matrix[1][2] = -34;

    expected.matrix[2][0] = 27;
    expected.matrix[2][1] = -29;
    expected.matrix[2][2] = 24;
    matrix_t result = {0};
    int code = s21_inverse_matrix(&m, &result);

    ck_assert_int_eq(s21_eq_matrix(&result, &expected), SUCCESS);
    ck_assert_int_eq(code, OK);

    s21_remove_matrix(&m);
    s21_remove_matrix(&result);
    s21_remove_matrix(&expected);
  }
}
END_TEST

START_TEST(inverse_test7) {
  const int size = 3;
  matrix_t m = {0};
  s21_create_matrix(size, size, &m);

  m.matrix[0][0] = 2;
  m.matrix[0][1] = 5;
  m.matrix[0][2] = 7;
  m.matrix[1][0] = 6;
  m.matrix[1][1] = 3;
  m.matrix[1][2] = 4;
  m.matrix[2][0] = 5;
  m.matrix[2][1] = -2;
  m.matrix[2][2] = -3;

  matrix_t res = {0};
  s21_inverse_matrix(&m, &res);

  matrix_t expected = {0};
  s21_create_matrix(size, size, &expected);
  expected.matrix[0][0] = 1;
  expected.matrix[0][1] = -1;
  expected.matrix[0][2] = 1;
  expected.matrix[1][0] = -38;
  expected.matrix[1][1] = 41;
  expected.matrix[1][2] = -34;
  expected.matrix[2][0] = 27;
  expected.matrix[2][1] = -29;
  expected.matrix[2][2] = 24;

  ck_assert_int_eq(s21_eq_matrix(&expected, &res), SUCCESS);

  s21_remove_matrix(&expected);
  s21_remove_matrix(&res);
  s21_remove_matrix(&m);
}
END_TEST

START_TEST(inverse_test8) {
  ck_assert_int_eq(s21_inverse_matrix(NULL, NULL), INCORRECT);
}
END_TEST

START_TEST(inverse_test9) {
  ck_assert_int_eq(s21_inverse_matrix((void *)0, (void *)0), INCORRECT);
}
END_TEST

START_TEST(inverse_test10) {
  matrix_t A = {0}, result = {0}, result_true = {0};
  int rows = 3, columns = 3;
  s21_create_matrix(rows, columns, &A);
  s21_create_matrix(rows, columns, &result_true);
  A.matrix[0][0] = 2;
  A.matrix[0][1] = 5;
  A.matrix[0][2] = 7;
  A.matrix[1][0] = 6;
  A.matrix[1][1] = 3;
  A.matrix[1][2] = 4;
  A.matrix[2][0] = 5;
  A.matrix[2][1] = -2;
  A.matrix[2][2] = -3;
  result_true.matrix[0][0] = 1;
  result_true.matrix[0][1] = -1;
  result_true.matrix[0][2] = 1;
  result_true.matrix[1][0] = -38;
  result_true.matrix[1][1] = 41;
  result_true.matrix[1][2] = -34;
  result_true.matrix[2][0] = 27;
  result_true.matrix[2][1] = -29;
  result_true.matrix[2][2] = 24;
  ck_assert_int_eq(s21_inverse_matrix(&A, &result), OK);
  ck_assert_int_eq(s21_eq_matrix(&result, &result_true), SUCCESS);
  s21_remove_matrix(&A);
  s21_remove_matrix(&result_true);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(inverse_test11) {
  matrix_t A = {0};
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 1;
  A.matrix[0][1] = 6;
  A.matrix[0][2] = 9;
  A.matrix[1][0] = 0;
  A.matrix[1][1] = 1;
  A.matrix[1][2] = 6;
  A.matrix[2][0] = 0;
  A.matrix[2][1] = 0;
  A.matrix[2][2] = 1;
  matrix_t res;
  int return_value = s21_inverse_matrix(&A, &res);
  ck_assert_int_eq(return_value, OK);
  matrix_t C;
  s21_create_matrix(3, 3, &C);
  C.matrix[0][0] = 1;
  C.matrix[0][1] = -6;
  C.matrix[0][2] = 27;
  C.matrix[1][0] = 0.0;
  C.matrix[1][1] = 1;
  C.matrix[1][2] = -6;
  C.matrix[2][0] = 0;
  C.matrix[2][1] = 0.0;
  C.matrix[2][2] = 1;
  if (return_value == OK) return_value = s21_eq_matrix(&res, &C);
  ck_assert_int_eq(return_value, SUCCESS);
  s21_remove_matrix(&C);
  s21_remove_matrix(&A);
  s21_remove_matrix(&res);
}
END_TEST

START_TEST(inverse_test12) {
  matrix_t A = {0}, result = {0};
  ck_assert_int_eq(INCORRECT, s21_inverse_matrix(&A, &result));
}

START_TEST(inverse_test13) {
  matrix_t A = {0}, result = {0};
  s21_create_matrix(0, 0, &A);
  ck_assert_int_eq(INCORRECT, s21_inverse_matrix(&A, &result));
}

START_TEST(inverse_test14) {
  matrix_t A = {0}, result = {0};
  s21_create_matrix(1, 1, &A);
  ck_assert_int_eq(CALC_ERROR, s21_inverse_matrix(&A, &result));
  s21_remove_matrix(&A);
}

START_TEST(inverse_test15) {
  matrix_t A = {0}, result = {0};
  s21_create_matrix(1, 2, &A);
  ck_assert_int_eq(CALC_ERROR, s21_inverse_matrix(&A, &result));
  s21_remove_matrix(&A);
}

START_TEST(inverse_test16) {
  matrix_t A = {0}, result = {0};
  A.rows = A.columns = 8;
  ck_assert_int_eq(INCORRECT, s21_inverse_matrix(&A, &result));
}

START_TEST(inverse_test17) {
  matrix_t A = {0}, result = {0};
  s21_create_matrix(2, 2, &A);
  A.matrix[0][0] = 5;
  A.matrix[0][1] = 0;
  A.matrix[1][0] = 6564.53;
  A.matrix[1][1] = -9.54;
  ck_assert_int_eq(OK, s21_inverse_matrix(&A, &result));

  ck_assert_ldouble_eq_tol(result.matrix[0][0], 0.200000000000000, 1e-06);
  ck_assert_ldouble_eq_tol(result.matrix[0][1], 0, 1e-06);
  ck_assert_ldouble_eq_tol(result.matrix[1][0], 137.621174004193, 1e-06);
  ck_assert_ldouble_eq_tol(result.matrix[1][1], -0.104821802935010, 1e-06);

  s21_remove_matrix(&A);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(inverse_test18) {
  matrix_t A = {0}, result = {0};
  s21_create_matrix(2, 2, &A);
  A.matrix[0][0] = 1;
  A.matrix[0][1] = 2;
  A.matrix[1][0] = 3;
  A.matrix[1][1] = 4;
  ck_assert_int_eq(OK, s21_inverse_matrix(&A, &result));

  ck_assert_ldouble_eq_tol(result.matrix[0][0], -2, 1e-06);
  ck_assert_ldouble_eq_tol(result.matrix[0][1], 1, 1e-06);
  ck_assert_ldouble_eq_tol(result.matrix[1][0], 1.5, 1e-06);
  ck_assert_ldouble_eq_tol(result.matrix[1][1], -0.5, 1e-06);

  s21_remove_matrix(&A);
  s21_remove_matrix(&result);
}

START_TEST(inverse_test19) {
  matrix_t A = {0}, result = {0};
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 0.64454;
  A.matrix[0][1] = 65.4534356;
  A.matrix[0][2] = -6.666;
  A.matrix[1][0] = 0.1;
  A.matrix[1][1] = 1;
  A.matrix[1][2] = 17;
  A.matrix[2][0] = 0.88;
  A.matrix[2][1] = -0.0000001;
  A.matrix[2][2] = 88;
  ck_assert_int_eq(OK, s21_inverse_matrix(&A, &result));

  ck_assert_ldouble_eq_tol(result.matrix[0][0], 0.188930901137859, 1e-06);
  ck_assert_ldouble_eq_tol(result.matrix[0][1], -12.3661763301536, 1e-06);
  ck_assert_ldouble_eq_tol(result.matrix[0][2], 2.40323194317724, 1e-06);

  ck_assert_ldouble_eq_tol(result.matrix[1][0], 0.0132251628241640, 1e-06);
  ck_assert_ldouble_eq_tol(result.matrix[1][1], 0.134367654293507, 1e-06);
  ck_assert_ldouble_eq_tol(result.matrix[1][2], -0.0249555816773152, 1e-06);

  ck_assert_ldouble_eq_tol(result.matrix[2][0], -0.00188930899635000, 1e-06);
  ck_assert_ldouble_eq_tol(result.matrix[2][1], 0.123661763454227, 1e-06);
  ck_assert_ldouble_eq_tol(result.matrix[2][2], -0.0126686830964946, 1e-06);

  s21_remove_matrix(&A);
  s21_remove_matrix(&result);
}
END_TEST

Suite *inverse_matrix_suite() {
  Suite *s = suite_create("\033[35mINVERSE MATRIX\033[0m");
  TCase *inverse_tests = tcase_create("INVERSE MATRIX");
  suite_add_tcase(s, inverse_tests);
  tcase_add_test(inverse_tests, inverse_test1);
  tcase_add_test(inverse_tests, inverse_test2);
  tcase_add_test(inverse_tests, inverse_test3);
  tcase_add_test(inverse_tests, inverse_test4);
  tcase_add_test(inverse_tests, inverse_test5);
  tcase_add_test(inverse_tests, inverse_test6);
  tcase_add_test(inverse_tests, inverse_test7);
  tcase_add_test(inverse_tests, inverse_test8);
  tcase_add_test(inverse_tests, inverse_test9);
  tcase_add_test(inverse_tests, inverse_test10);
  tcase_add_test(inverse_tests, inverse_test11);
  tcase_add_test(inverse_tests, inverse_test12);
  tcase_add_test(inverse_tests, inverse_test13);
  tcase_add_test(inverse_tests, inverse_test14);
  tcase_add_test(inverse_tests, inverse_test15);
  tcase_add_test(inverse_tests, inverse_test16);
  tcase_add_test(inverse_tests, inverse_test17);
  tcase_add_test(inverse_tests, inverse_test18);
  tcase_add_test(inverse_tests, inverse_test19);

  return s;
}