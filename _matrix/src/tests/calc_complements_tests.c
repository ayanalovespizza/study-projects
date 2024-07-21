#include "s21_tests.h"

START_TEST(calc_complements_test1) {
  matrix_t m = {0};
  matrix_t result = {0};
  int code = s21_calc_complements(&m, &result);
  ck_assert_int_eq(code, INCORRECT);
}
END_TEST

START_TEST(calc_complements_test2) {
  matrix_t m = {0};
  matrix_t result = {0};
  int codec = s21_create_matrix(3, 4, &m);
  if (codec == OK) {
    int code = s21_calc_complements(&m, &result);
    ck_assert_int_eq(code, CALC_ERROR);
    s21_remove_matrix(&m);
  }
}
END_TEST

START_TEST(calc_complements_test3) {
  matrix_t expected = {0};
  matrix_t m = {0};
  matrix_t result = {0};
  int code1 = s21_create_matrix(3, 3, &m);
  int code2 = s21_create_matrix(3, 3, &expected);
  if (code1 == OK && code2 == OK) {
    m.matrix[0][0] = 1;
    m.matrix[0][1] = 2;
    m.matrix[0][2] = 3;

    m.matrix[1][0] = 0;
    m.matrix[1][1] = 4;
    m.matrix[1][2] = 2;

    m.matrix[2][0] = 5;
    m.matrix[2][1] = 2;
    m.matrix[2][2] = 1;

    expected.matrix[0][0] = 0;
    expected.matrix[0][1] = 10;
    expected.matrix[0][2] = -20;

    expected.matrix[1][0] = 4;
    expected.matrix[1][1] = -14;
    expected.matrix[1][2] = 8;

    expected.matrix[2][0] = -8;
    expected.matrix[2][1] = -2;
    expected.matrix[2][2] = 4;

    int code = s21_calc_complements(&m, &result);

    ck_assert_int_eq(s21_eq_matrix(&result, &expected), SUCCESS);
    ck_assert_int_eq(code, OK);
    s21_remove_matrix(&m);
    s21_remove_matrix(&result);
    s21_remove_matrix(&expected);
  }
}
END_TEST

START_TEST(calc_complements_test4) {
  matrix_t A = {0}, result = {0};
  ck_assert_int_eq(INCORRECT, s21_calc_complements(&A, &result));
}

START_TEST(calc_complements_test5) {
  matrix_t A = {0}, result = {0};
  s21_create_matrix(0, 0, &A);
  ck_assert_int_eq(INCORRECT, s21_calc_complements(&A, &result));
}

START_TEST(calc_complements_test6) {
  matrix_t A = {0}, result = {0};
  s21_create_matrix(1, 2, &A);
  ck_assert_int_eq(CALC_ERROR, s21_calc_complements(&A, &result));
  s21_remove_matrix(&A);
}

START_TEST(calc_complements_test7) {
  matrix_t A = {0}, result = {0};
  s21_create_matrix(2, 2, &A);
  A.matrix[0][0] = 1;
  A.matrix[0][1] = 2;
  A.matrix[1][0] = 3;
  A.matrix[1][1] = 4;
  ck_assert_int_eq(OK, s21_calc_complements(&A, &result));
  ck_assert_ldouble_eq_tol(result.matrix[0][0], A.matrix[1][1], 1e-06);
  ck_assert_ldouble_eq_tol(result.matrix[0][1], -A.matrix[1][0], 1e-06);
  ck_assert_ldouble_eq_tol(result.matrix[1][0], -A.matrix[0][1], 1e-06);
  ck_assert_ldouble_eq_tol(result.matrix[1][1], A.matrix[0][0], 1e-06);
  s21_remove_matrix(&A);
  s21_remove_matrix(&result);
}

START_TEST(calc_complements_test8) {
  matrix_t A = {0}, result = {0};
  s21_create_matrix(2, 2, &A);
  ck_assert_int_eq(OK, s21_calc_complements(&A, &result));
  ck_assert_ldouble_eq_tol(result.matrix[0][0], 0, 1e-06);
  ck_assert_ldouble_eq_tol(result.matrix[0][1], 0, 1e-06);
  ck_assert_ldouble_eq_tol(result.matrix[1][0], 0, 1e-06);
  ck_assert_ldouble_eq_tol(result.matrix[1][1], 0, 1e-06);
  s21_remove_matrix(&A);
  s21_remove_matrix(&result);
}

START_TEST(calc_complements_test9) {
  matrix_t A = {0}, result = {0};
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
  ck_assert_int_eq(OK, s21_calc_complements(&A, &result));
  ck_assert_ldouble_eq_tol(result.matrix[0][0], 436.726159471151, 1e-06);
  ck_assert_ldouble_eq_tol(result.matrix[0][1], 486.306584999124, 1e-06);
  ck_assert_ldouble_eq_tol(result.matrix[0][2], 1.37166666541839, 1e-06);
  ck_assert_ldouble_eq_tol(result.matrix[1][0], -979.59844350429432, 1e-06);
  ck_assert_ldouble_eq_tol(result.matrix[1][1], -1149.2111956676457, 1e-06);
  ck_assert_ldouble_eq_tol(result.matrix[1][2], -77.1139569867462, 1e-06);
  ck_assert_ldouble_eq_tol(result.matrix[2][0], 3517.3289917098917, 1e-06);
  ck_assert_ldouble_eq_tol(result.matrix[2][1], 30165.583680876545, 1e-06);
  ck_assert_ldouble_eq_tol(result.matrix[2][2], 85.0844444294795, 1e-06);
  s21_remove_matrix(&A);
  s21_remove_matrix(&result);
}

START_TEST(calc_complements_test10) {
  matrix_t A = {0}, result = {0};
  s21_create_matrix(4, 4, &A);
  A.matrix[0][0] = 4;
  A.matrix[0][1] = 3.66564577;
  A.matrix[0][2] = -10;
  A.matrix[0][3] = 0.643;
  A.matrix[1][0] = 0.01;
  A.matrix[1][1] = -0.9;
  A.matrix[1][2] = 0.0000000005646;
  A.matrix[1][3] = 5.55757435;
  A.matrix[2][0] = 1.867;
  A.matrix[2][1] = -1.7;
  A.matrix[2][2] = 0.87988678;
  A.matrix[2][3] = 8.8687678877;
  A.matrix[3][0] = -1.867546867;
  A.matrix[3][1] = 1.7657868;
  A.matrix[3][2] = -0.87988678;
  A.matrix[3][3] = -8.8687678877;
  ck_assert_int_eq(OK, s21_calc_complements(&A, &result));
  ck_assert_ldouble_eq_tol(result.matrix[0][0], -0.321699833115385, 1e-06);
  ck_assert_ldouble_eq_tol(result.matrix[0][1], -0.00267419942353712, 1e-06);
  ck_assert_ldouble_eq_tol(result.matrix[0][2], 0.675967087634449, 1e-06);
  ck_assert_ldouble_eq_tol(result.matrix[0][3], 0.000145786348016985, 1e-06);

  ck_assert_ldouble_eq_tol(result.matrix[1][0], 5.87169860634816, 1e-06);
  ck_assert_ldouble_eq_tol(result.matrix[1][1], 0.0488097642955267, 1e-06);
  ck_assert_ldouble_eq_tol(result.matrix[1][2], 2.27319192970328, 1e-06);
  ck_assert_ldouble_eq_tol(result.matrix[1][3], -1.45224639873153, 1e-06);

  ck_assert_ldouble_eq_tol(result.matrix[2][0], 0.118327686999265, 1e-06);
  ck_assert_ldouble_eq_tol(result.matrix[2][1], -122.457915972232, 1e-06);
  ck_assert_ldouble_eq_tol(result.matrix[2][2], -46.1165485501433, 1e-06);
  ck_assert_ldouble_eq_tol(result.matrix[2][3], -19.8311890556789, 1e-06);

  ck_assert_ldouble_eq_tol(result.matrix[3][0], 3.77447800950895, 1e-06);
  ck_assert_ldouble_eq_tol(result.matrix[3][1], -122.427523432112, 1e-06);
  ck_assert_ldouble_eq_tol(result.matrix[3][2], -44.6430541297268, 1e-06);
  ck_assert_ldouble_eq_tol(result.matrix[3][3], -19.8328459328286, 1e-06);

  s21_remove_matrix(&A);
  s21_remove_matrix(&result);
}

Suite *calc_complements_suite() {
  Suite *s = suite_create("\033[35mCALC COMPLEMENTS\033[0m");
  TCase *calc_complements_tests = tcase_create("CALC COMPLEMENTS");
  suite_add_tcase(s, calc_complements_tests);
  tcase_add_test(calc_complements_tests, calc_complements_test1);
  tcase_add_test(calc_complements_tests, calc_complements_test2);
  tcase_add_test(calc_complements_tests, calc_complements_test3);
  tcase_add_test(calc_complements_tests, calc_complements_test4);
  tcase_add_test(calc_complements_tests, calc_complements_test5);
  tcase_add_test(calc_complements_tests, calc_complements_test6);
  tcase_add_test(calc_complements_tests, calc_complements_test7);
  tcase_add_test(calc_complements_tests, calc_complements_test8);
  tcase_add_test(calc_complements_tests, calc_complements_test9);
  tcase_add_test(calc_complements_tests, calc_complements_test10);

  return s;
}