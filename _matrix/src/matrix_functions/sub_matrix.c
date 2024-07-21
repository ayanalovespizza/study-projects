#include "../s21_matrix.h"

/**
 * @brief Вычитание матриц
 *        Разностью двух матриц A = m × n и B = m × n одинаковых размеров
 *        называется матрица C = m × n = A - B тех же размеров, элементы которой
 *        определяются равенствами C(i,j) = A(i,j) - B(i,j).
 *
 * @return 0 - OK
 *         1 - Ошибка, некорректная матрица
 *         2 - Ошибка вычисления (несовпадающие размеры матриц; матрица, для
 *             которой нельзя провести вычисления и т.д.)
 */
int s21_sub_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  int status = OK;

  if (s21_is_correct(A) == INCORRECT || s21_is_correct(B) == INCORRECT ||
      result == NULL) {
    return INCORRECT;

  } else if (A->columns != B->columns || A->rows != B->rows) {
    return CALC_ERROR;

  } else {
    status = s21_create_matrix(A->rows, A->columns, result);
    for (int i = 0; i < A->rows; i++) {
      for (int j = 0; j < A->columns; j++) {
        result->matrix[i][j] = A->matrix[i][j] - B->matrix[i][j];
      }
    }
  }

  return status;
}