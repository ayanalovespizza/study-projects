#include "../s21_matrix.h"

/**
 * @brief Умножение матрицы на число
 *        Произведением матрицы A = m × n на число λ называется матрица
 *        B = m × n = λ × A, элементы которой определяются равенствами
 *        B = λ × A(i,j)
 *
 * @return 0 - OK
 *         1 - Ошибка, некорректная матрица
 *         2 - Ошибка вычисления (несовпадающие размеры матриц; матрица, для
 *             которой нельзя провести вычисления и т.д.)
 */
int s21_mult_number(matrix_t *A, double number, matrix_t *result) {
  int status = OK;

  if (s21_is_correct(A) == INCORRECT || result == NULL) {
    return INCORRECT;

  } else {
    status = s21_create_matrix(A->rows, A->columns, result);
    for (int i = 0; i < A->rows; i++) {
      for (int j = 0; j < A->columns; j++) {
        result->matrix[i][j] = number * A->matrix[i][j];
      }
    }
  }

  return status;
}
