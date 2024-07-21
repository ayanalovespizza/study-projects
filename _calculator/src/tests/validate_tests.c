#include "tests.h"

/* VALIDATION IS OK */

START_TEST(InputValidation_OK_1) {
  char *sample = "2+2*2";
  int res = InsertionIsValid(sample);
  ck_assert_int_eq(res, OK);
}
END_TEST

START_TEST(InputValidation_OK_2) {
  char *sample = "2^2^3";
  int res = InsertionIsValid(sample);
  ck_assert_int_eq(res, OK);
}
END_TEST

START_TEST(InputValidation_OK_3) {
  char *sample = "cos(4)*sin(3)";
  int res = InsertionIsValid(sample);
  ck_assert_int_eq(res, OK);
}
END_TEST

START_TEST(InputValidation_OK_4) {
  char *sample = "3.1415-21/42+12tan(5)";
  int res = InsertionIsValid(sample);
  ck_assert_int_eq(res, OK);
}
END_TEST

START_TEST(InputValidation_OK_5) {
  char *sample = "-659.129+x(tan(cos(x)))";
  int res = InsertionIsValid(sample);
  ck_assert_int_eq(res, OK);
}
END_TEST

/* VALIDATION IS NOT OK */

START_TEST(InputValidation_ERROR_1) {
  char *sample = "ayanapishettests";
  int res = InsertionIsValid(sample);
  ck_assert_int_eq(res, ERROR);
}
END_TEST

START_TEST(InputValidation_ERROR_2) {
  char *sample = "3..15";
  int res = InsertionIsValid(sample);
  ck_assert_int_eq(res, ERROR);
}
END_TEST

START_TEST(InputValidation_ERROR_3) {
  char *sample = "29ep+cos(4)";
  int res = InsertionIsValid(sample);
  ck_assert_int_eq(res, ERROR);
}
END_TEST

START_TEST(InputValidation_ERROR_4) {
  char *sample = "atan5)+ln(3)";
  int res = InsertionIsValid(sample);
  ck_assert_int_eq(res, ERROR);
}
END_TEST

START_TEST(InputValidation_ERROR_5) {
  char *sample = "2*()";
  int res = InsertionIsValid(sample);
  ck_assert_int_eq(res, ERROR);
}
END_TEST

START_TEST(InputValidation_ERROR_6) {
  char *sample = "3+3.34.56";
  int res = InsertionIsValid(sample);
  ck_assert_int_eq(res, ERROR);
}
END_TEST

START_TEST(InputValidation_ERROR_7) {
  char *sample = NULL;
  int res = InsertionIsValid(sample);
  ck_assert_int_eq(res, ERROR);
}
END_TEST

START_TEST(InputValidation_ERROR_8) {
  char *sample = "";
  int res = InsertionIsValid(sample);
  ck_assert_int_eq(res, ERROR);
}
END_TEST

START_TEST(InputValidation_ERROR_9) {
  char *sample =
      "1+2+3+4+5+6+7+8+9+10+11+12+13+14+15+16+1+2+3+4+5+6+7+8+9+10+11+12+13+14+"
      "15+16+1+2+3+4+5+6+7+8+9+10+11+12+13+14+15+16+1+2+3+4+5+6+7+8+9+10+11+12+"
      "13+14+15+16+1+2+3+4+5+6+7+8+9+10+11+12+13+14+15+16+1+2+3+4+5+6+7+8+9+10+"
      "11+12+13+14+15+16+1+2+3+4+5+6+7+8+9+10+11+12+13+14+15+16+";
  int res = InsertionIsValid(sample);
  ck_assert_int_eq(res, ERROR);
}
END_TEST

START_TEST(InputValidation_ERROR_10) {
  char *sample = ".123+4";
  int res = InsertionIsValid(sample);
  ck_assert_int_eq(res, ERROR);
}
END_TEST

START_TEST(InputValidation_ERROR_11) {
  char *sample = "123+-4";
  int res = InsertionIsValid(sample);
  ck_assert_int_eq(res, ERROR);
}
END_TEST

START_TEST(InputValidation_ERROR_12) {
  char *sample = "*123+4";
  int res = InsertionIsValid(sample);
  ck_assert_int_eq(res, ERROR);
}
END_TEST

START_TEST(InputValidation_ERROR_13) {
  char *sample = "123*(^123+2)";
  int res = InsertionIsValid(sample);
  ck_assert_int_eq(res, ERROR);
}
END_TEST

START_TEST(InputValidation_ERROR_14) {
  char *sample = "123*(123+2)-";
  int res = InsertionIsValid(sample);
  ck_assert_int_eq(res, ERROR);
}
END_TEST

START_TEST(InputValidation_ERROR_15) {
  char *sample = "asin(";
  int res = InsertionIsValid(sample);
  ck_assert_int_eq(res, ERROR);
}
END_TEST

START_TEST(InputValidation_ERROR_16) {
  char *sample = "asin)";
  int res = InsertionIsValid(sample);
  ck_assert_int_eq(res, ERROR);
}
END_TEST

START_TEST(InputValidation_ERROR_17) {
  char *sample = "cos123";
  int res = InsertionIsValid(sample);
  ck_assert_int_eq(res, ERROR);
}
END_TEST

START_TEST(InputValidation_ERROR_18) {
  char *sample = "cos)";
  int res = InsertionIsValid(sample);
  ck_assert_int_eq(res, ERROR);
}
END_TEST

START_TEST(InputValidation_ERROR_19) {
  char *sample = "ln1232314)";
  int res = InsertionIsValid(sample);
  ck_assert_int_eq(res, ERROR);
}
END_TEST

START_TEST(InputValidation_ERROR_20) {
  char *sample = "+log123";
  int res = InsertionIsValid(sample);
  ck_assert_int_eq(res, ERROR);
}
END_TEST

START_TEST(InputValidation_ERROR_21) {
  char *sample = "v(-25)";
  int res = InsertionIsValid(sample);
  ck_assert_int_eq(res, ERROR);
}
END_TEST

START_TEST(InputValidation_ERROR_22) {
  char *sample = "v3240912";
  int res = InsertionIsValid(sample);
  ck_assert_int_eq(res, ERROR);
}
END_TEST

START_TEST(InputValidation_ERROR_23) {
  char *sample = "ln()";
  int res = InsertionIsValid(sample);
  ck_assert_int_eq(res, ERROR);
}
END_TEST

START_TEST(InputValidation_ERROR_24) {
  char *sample = "ln12323";
  int res = InsertionIsValid(sample);
  ck_assert_int_eq(res, ERROR);
}
END_TEST

START_TEST(InputValidation_ERROR_25) {
  char *sample = "2+2*(2123.324^)";
  int res = InsertionIsValid(sample);
  ck_assert_int_eq(res, ERROR);
}
END_TEST

START_TEST(InputValidation_ERROR_26) {
  char *sample = "2+2*(/2123.324)";
  int res = InsertionIsValid(sample);
  ck_assert_int_eq(res, ERROR);
}
END_TEST

START_TEST(InputValidation_ERROR_27) {
  char *sample = "cos+3\0";
  int res = InsertionIsValid(sample);
  ck_assert_int_eq(res, ERROR);
}
END_TEST

Suite *InputIsValid() {
  Suite *s = suite_create("\033[35mVALID INPUT\033[0m");
  TCase *InputOK_tests = tcase_create("VALID INPUT");
  suite_add_tcase(s, InputOK_tests);

  tcase_add_test(InputOK_tests, InputValidation_OK_1);
  tcase_add_test(InputOK_tests, InputValidation_OK_2);
  tcase_add_test(InputOK_tests, InputValidation_OK_3);
  tcase_add_test(InputOK_tests, InputValidation_OK_4);
  tcase_add_test(InputOK_tests, InputValidation_OK_5);

  return s;
}

Suite *InputIsNotValid() {
  Suite *s = suite_create("\033[35mINVALID INPUT\033[0m");
  TCase *InputERROR_tests = tcase_create("INVALID INPUT");
  suite_add_tcase(s, InputERROR_tests);

  tcase_add_test(InputERROR_tests, InputValidation_ERROR_1);
  tcase_add_test(InputERROR_tests, InputValidation_ERROR_2);
  tcase_add_test(InputERROR_tests, InputValidation_ERROR_3);
  tcase_add_test(InputERROR_tests, InputValidation_ERROR_4);
  tcase_add_test(InputERROR_tests, InputValidation_ERROR_5);
  tcase_add_test(InputERROR_tests, InputValidation_ERROR_6);
  tcase_add_test(InputERROR_tests, InputValidation_ERROR_7);
  tcase_add_test(InputERROR_tests, InputValidation_ERROR_8);
  tcase_add_test(InputERROR_tests, InputValidation_ERROR_9);
  tcase_add_test(InputERROR_tests, InputValidation_ERROR_10);
  tcase_add_test(InputERROR_tests, InputValidation_ERROR_11);
  tcase_add_test(InputERROR_tests, InputValidation_ERROR_12);
  tcase_add_test(InputERROR_tests, InputValidation_ERROR_13);
  tcase_add_test(InputERROR_tests, InputValidation_ERROR_14);
  tcase_add_test(InputERROR_tests, InputValidation_ERROR_15);
  tcase_add_test(InputERROR_tests, InputValidation_ERROR_16);
  tcase_add_test(InputERROR_tests, InputValidation_ERROR_17);
  tcase_add_test(InputERROR_tests, InputValidation_ERROR_18);
  tcase_add_test(InputERROR_tests, InputValidation_ERROR_19);
  tcase_add_test(InputERROR_tests, InputValidation_ERROR_20);
  tcase_add_test(InputERROR_tests, InputValidation_ERROR_21);
  tcase_add_test(InputERROR_tests, InputValidation_ERROR_22);
  tcase_add_test(InputERROR_tests, InputValidation_ERROR_23);
  tcase_add_test(InputERROR_tests, InputValidation_ERROR_24);
  tcase_add_test(InputERROR_tests, InputValidation_ERROR_25);
  tcase_add_test(InputERROR_tests, InputValidation_ERROR_26);
  tcase_add_test(InputERROR_tests, InputValidation_ERROR_27);

  return s;
}