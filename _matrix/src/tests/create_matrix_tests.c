#include "s21_tests.h"

START_TEST(create_matrix_test1) {
  matrix_t matrix;
  int rows = 2;
  int columns = 2;

  int res = s21_create_matrix(rows, columns, &matrix);
  ck_assert_int_eq(res, 0);
  ck_assert_int_eq(rows, matrix.rows);
  ck_assert_int_eq(columns, matrix.columns);
  if (res == 0) s21_remove_matrix(&matrix);
}
END_TEST

START_TEST(create_matrix_test2) {
  matrix_t matrix;
  int rows = 10;
  int columns = 2;

  int res = s21_create_matrix(rows, columns, &matrix);
  ck_assert_int_eq(res, 0);
  ck_assert_int_eq(rows, matrix.rows);
  ck_assert_int_eq(columns, matrix.columns);
  if (res == 0) s21_remove_matrix(&matrix);
}
END_TEST

START_TEST(create_matrix_test3) {
  matrix_t matrix;
  int rows = 2;
  int columns = 10;

  int res = s21_create_matrix(rows, columns, &matrix);
  ck_assert_int_eq(res, 0);
  ck_assert_int_eq(rows, matrix.rows);
  ck_assert_int_eq(columns, matrix.columns);
  if (res == 0) s21_remove_matrix(&matrix);
}
END_TEST

START_TEST(create_matrix_test4) {
  matrix_t matrix;

  int res = s21_create_matrix(0, 5, &matrix);
  ck_assert_int_eq(res, 1);
  if (res == 0) s21_remove_matrix(&matrix);
}
END_TEST

START_TEST(create_matrix_test5) {
  matrix_t matrix;

  int res = s21_create_matrix(-4, 5, &matrix);
  ck_assert_int_eq(res, 1);
  if (res == 0) s21_remove_matrix(&matrix);
}
END_TEST

Suite *create_matrix_suite() {
  Suite *s = suite_create("\033[35mCREATE MATRIX\033[0m");
  TCase *create_matrix_tests = tcase_create("CREATE MATRIX");
  suite_add_tcase(s, create_matrix_tests);

  tcase_add_test(create_matrix_tests, create_matrix_test1);
  tcase_add_test(create_matrix_tests, create_matrix_test2);
  tcase_add_test(create_matrix_tests, create_matrix_test3);
  tcase_add_test(create_matrix_tests, create_matrix_test4);
  tcase_add_test(create_matrix_tests, create_matrix_test5);

  return s;
}