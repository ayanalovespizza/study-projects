#include "s21_tests.h"

START_TEST(test_remove_matrix_1) {
  matrix_t matrix;
  int rows = 2;
  int columns = 2;

  int res = s21_create_matrix(rows, columns, &matrix);
  if (res == 0) s21_remove_matrix(&matrix);
  ck_assert_ptr_eq(matrix.matrix, NULL);
  ck_assert_int_eq(0, matrix.rows);
  ck_assert_int_eq(0, matrix.columns);
}
END_TEST

START_TEST(test_remove_matrix_2) {
  matrix_t matrix;
  int rows = 10;
  int columns = 2;

  int res = s21_create_matrix(rows, columns, &matrix);
  if (res == 0) s21_remove_matrix(&matrix);
  ck_assert_ptr_eq(matrix.matrix, NULL);
  ck_assert_int_eq(0, matrix.rows);
  ck_assert_int_eq(0, matrix.columns);
}
END_TEST

START_TEST(test_remove_matrix_3) {
  matrix_t matrix;
  int rows = 2;
  int columns = 10;

  int res = s21_create_matrix(rows, columns, &matrix);
  if (res == 0) s21_remove_matrix(&matrix);
  ck_assert_ptr_eq(matrix.matrix, NULL);
  ck_assert_int_eq(0, matrix.rows);
  ck_assert_int_eq(0, matrix.columns);
}
END_TEST

Suite *remove_matrix_suite() {
  Suite *s = suite_create("\033[35mREMOVE MATRIX\033[0m");
  TCase *remove_matrix_tests = tcase_create("REMOVE MATRIX");
  suite_add_tcase(s, remove_matrix_tests);

  tcase_add_test(remove_matrix_tests, test_remove_matrix_1);
  tcase_add_test(remove_matrix_tests, test_remove_matrix_2);
  tcase_add_test(remove_matrix_tests, test_remove_matrix_3);

  return s;
}