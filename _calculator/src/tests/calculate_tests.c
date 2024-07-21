#include "tests.h"

START_TEST(InputCalculation_1) {
  char *sample = "2+2*2";

  lexem_list *result_polish = ToPolish(sample);
  char *result_cur = SolvePolish(result_polish);
  char *result_exp = "6";
  ck_assert_str_eq(result_cur, result_exp);
}
END_TEST

START_TEST(InputCalculation_2) {
  char *sample = "(2+2)*2";

  lexem_list *result_polish = ToPolish(sample);
  char *result_cur = SolvePolish(result_polish);
  char *result_exp = "8";
  ck_assert_str_eq(result_cur, result_exp);
}
END_TEST

START_TEST(InputCalculation_3) {
  char *sample = "(2+2)2";

  lexem_list *result_polish = ToPolish(sample);
  char *result_cur = SolvePolish(result_polish);
  char *result_exp = "8";
  ck_assert_str_eq(result_cur, result_exp);
}
END_TEST

START_TEST(InputCalculation_4) {
  char *sample = "(2+2)^2";

  lexem_list *result_polish = ToPolish(sample);
  char *result_cur = SolvePolish(result_polish);
  char *result_exp = "16";
  ck_assert_str_eq(result_cur, result_exp);
}
END_TEST

START_TEST(InputCalculation_5) {
  char *sample = "log(100)";

  lexem_list *result_polish = ToPolish(sample);
  char *result_cur = SolvePolish(result_polish);
  char *result_exp = "2";
  ck_assert_str_eq(result_cur, result_exp);
}
END_TEST

START_TEST(InputCalculation_6) {
  char *sample = "ln(123)";

  lexem_list *result_polish = ToPolish(sample);
  char *result_cur = SolvePolish(result_polish);
  long double result_cur_ld = 0;
  sscanf(result_cur, "%Lf", &result_cur_ld);
  ck_assert_ldouble_eq_tol(result_cur_ld, logl(123), 1e-7);
}
END_TEST

START_TEST(InputCalculation_7) {
  char *sample = "cos(439.1)+sin(213.23)";

  lexem_list *result_polish = ToPolish(sample);
  char *result_cur = SolvePolish(result_polish);
  long double result_cur_ld = 0;
  sscanf(result_cur, "%Lf", &result_cur_ld);
  ck_assert_ldouble_eq_tol(result_cur_ld, cosl(439.1) + sinl(213.23), 1e-7);
}
END_TEST

START_TEST(InputCalculation_8) {
  char *sample = "acos(0.909)+atan(12.23)";

  lexem_list *result_polish = ToPolish(sample);
  char *result_cur = SolvePolish(result_polish);
  long double result_cur_ld = 0;
  sscanf(result_cur, "%Lf", &result_cur_ld);
  ck_assert_ldouble_eq_tol(result_cur_ld, acosl(0.909) + atanl(12.23), 1e-7);
}
END_TEST

START_TEST(InputCalculation_9) {
  char *sample = "-1+v(25)";

  lexem_list *result_polish = ToPolish(sample);
  char *result_cur = SolvePolish(result_polish);
  long double result_cur_ld = 0;
  sscanf(result_cur, "%Lf", &result_cur_ld);
  ck_assert_ldouble_eq_tol(result_cur_ld, -1 + sqrt(25), 1e-7);
}
END_TEST

START_TEST(InputCalculation_10) {
  char *sample = "(-1+25)*1";

  lexem_list *result_polish = ToPolish(sample);
  char *result_cur = SolvePolish(result_polish);
  long double result_cur_ld = 0;
  sscanf(result_cur, "%Lf", &result_cur_ld);
  ck_assert_ldouble_eq_tol(result_cur_ld, (-1 + 25) * 1, 1e-7);
}
END_TEST

START_TEST(InputCalculation_11) {
  char *sample = "1/0";

  lexem_list *result_polish = ToPolish(sample);
  char *result_cur = SolvePolish(result_polish);
  char *result_exp = "inf";
  ck_assert_str_eq(result_cur, result_exp);
}
END_TEST

START_TEST(InputCalculation_12) {
  char *sample = "-1/0";

  lexem_list *result_polish = ToPolish(sample);
  char *result_cur = SolvePolish(result_polish);
  char *result_exp = "-inf";
  ck_assert_str_eq(result_cur, result_exp);
}
END_TEST

START_TEST(InputCalculation_13) {
  char *sample = "0/0";

  lexem_list *result_polish = ToPolish(sample);
  char *result_cur = SolvePolish(result_polish);
  char *result_exp = "ERROR";
  ck_assert_str_eq(result_cur, result_exp);
}
END_TEST

START_TEST(InputCalculation_14) {
  char *sample = "234.324%123";

  lexem_list *result_polish = ToPolish(sample);
  char *result_cur = SolvePolish(result_polish);
  long double result_cur_ld = 0;
  sscanf(result_cur, "%Lf", &result_cur_ld);
  ck_assert_ldouble_eq_tol(result_cur_ld, fmodl(234.324, 123), 1e-7);
}
END_TEST

START_TEST(InputCalculation_15) {
  char *sample = "tan(0.234)*asin(0.34)";

  lexem_list *result_polish = ToPolish(sample);
  char *result_cur = SolvePolish(result_polish);
  long double result_cur_ld = 0;
  sscanf(result_cur, "%Lf", &result_cur_ld);
  ck_assert_ldouble_eq_tol(result_cur_ld, tanl(0.234) * asinl(0.34), 1e-7);
}
END_TEST

Suite *CalculationSuite() {
  Suite *s = suite_create("\033[35mSOLVE POLISH NOTATION\033[0m");
  TCase *Calculation_tests = tcase_create("SOLVE POLISH NOTATION");
  suite_add_tcase(s, Calculation_tests);

  tcase_add_test(Calculation_tests, InputCalculation_1);
  tcase_add_test(Calculation_tests, InputCalculation_2);
  tcase_add_test(Calculation_tests, InputCalculation_3);
  tcase_add_test(Calculation_tests, InputCalculation_4);
  tcase_add_test(Calculation_tests, InputCalculation_5);
  tcase_add_test(Calculation_tests, InputCalculation_6);
  tcase_add_test(Calculation_tests, InputCalculation_7);
  tcase_add_test(Calculation_tests, InputCalculation_8);
  tcase_add_test(Calculation_tests, InputCalculation_9);
  tcase_add_test(Calculation_tests, InputCalculation_10);
  tcase_add_test(Calculation_tests, InputCalculation_11);
  tcase_add_test(Calculation_tests, InputCalculation_12);
  tcase_add_test(Calculation_tests, InputCalculation_13);
  tcase_add_test(Calculation_tests, InputCalculation_14);
  tcase_add_test(Calculation_tests, InputCalculation_15);

  return s;
}