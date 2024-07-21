#include "../s21_matrix.h"

/**
 * @brief Умножение двух матриц
 *        Произведением матрицы A = m × k на матрицу B = k × n называется
 *        матрица C = m × n = A × B размера m × n, элементы которой определяются
 *        равенством C(i,j) = A(i,1) × B(1,j) + A(i,2) × B(2,j) + … + A(i,k) ×
 *        B(k,j).
 *
 * @return 0 - OK
 *         1 - Ошибка, некорректная матрица
 *         2 - Ошибка вычисления (несовпадающие размеры матриц; матрица, для
 *             которой нельзя провести вычисления и т.д.)
 */
int s21_mult_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  int status = OK;

  if (s21_is_correct(A) == INCORRECT || s21_is_correct(B) == INCORRECT) {
    return INCORRECT;

  } else if (A->columns != B->rows) {
    return CALC_ERROR;

  } else {
    status = s21_create_matrix(A->rows, B->columns, result);

    for (int i = 0; i < A->rows; i++) {
      for (int j = 0; j < B->columns; j++) {
        for (int k = 0; k < A->columns; k++) {
          result->matrix[i][j] += A->matrix[i][k] * B->matrix[k][j];
        }
      }
    }
  }

  return status;
}
