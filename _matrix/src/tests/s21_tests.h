#ifndef S21_TESTS_H
#define S21_TESTS_H

#include <check.h>
#include <stdio.h>

#include "../s21_matrix.h"

Suite *create_matrix_suite();  // done
Suite *remove_matrix_suite();  // done

Suite *eq_matrix_suite();  // done

Suite *sum_matrix_suite();  // done
Suite *sub_matrix_suite();  // done

Suite *mult_number_suite();  // done
Suite *mult_matrix_suite();  // done

Suite *transpose_suite();         // done
Suite *determinant_suite();       // done
Suite *calc_complements_suite();  // done
Suite *inverse_matrix_suite();    // done

#endif