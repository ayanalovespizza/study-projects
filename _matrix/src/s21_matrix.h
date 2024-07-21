#ifndef S21_MATRIX_H
#define S21_MATRIX_H

#include <math.h>
#include <stdio.h>
#include <stdlib.h>

// для сравнения
#define SUCCESS 1
#define FAILURE 0

// для остальных функций
#define OK 0
#define INCORRECT 1
#define CALC_ERROR 2

typedef struct matrix_struct {
  double **matrix;
  int rows;
  int columns;
} matrix_t;

int s21_create_matrix(int rows, int columns, matrix_t *result);  // done
void s21_remove_matrix(matrix_t *A);                             // done

int s21_eq_matrix(matrix_t *A, matrix_t *B);  // done

int s21_sum_matrix(matrix_t *A, matrix_t *B, matrix_t *result);  // done
int s21_sub_matrix(matrix_t *A, matrix_t *B, matrix_t *result);  // done

int s21_mult_number(matrix_t *A, double number, matrix_t *result);  // done
int s21_mult_matrix(matrix_t *A, matrix_t *B, matrix_t *result);    // done

int s21_transpose(matrix_t *A, matrix_t *result);         // done
int s21_determinant(matrix_t *A, double *result);         // done
int s21_calc_complements(matrix_t *A, matrix_t *result);  // done
int s21_inverse_matrix(matrix_t *A, matrix_t *result);    // done

int s21_is_correct(matrix_t *A);
void s21_set(double *nums, matrix_t *A);
void s21_minor(int row, int col, matrix_t *A, matrix_t *result);
double s21_get_determinant(matrix_t *A);

#endif