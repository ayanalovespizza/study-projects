#include "../s21_matrix.h"

/**
 * @brief Обратная матрица
 *        Матрицу A в степени -1 называют обратной к квадратной матрице А, если
 *        произведение этих матриц равняется единичной матрице. Обратной матрицы
 *        не существует, если определитель равен 0.
 *
 * @return 0 - OK
 *         1 - Ошибка, некорректная матрица
 *         2 - Ошибка вычисления (несовпадающие размеры матриц; матрица, для
 *             которой нельзя провести вычисления и т.д.)
 */
int s21_inverse_matrix(matrix_t *A, matrix_t *result) {
  int status = OK;
  if (s21_is_correct(A) == INCORRECT) {
    return INCORRECT;

  } else if (A->rows != A->columns) {
    return CALC_ERROR;

  } else {
    // считаем определитель. если определитель == 0, то матрица вырожденная
    double det = 0;
    s21_determinant(A, &det);
    if (fabs(det) < 1e-7) {
      return CALC_ERROR;
    }

    status = s21_create_matrix(A->rows, A->columns, result);

    // инверсируем матрицу
    matrix_t trans_matrix = {0};
    s21_create_matrix(A->columns, A->rows, &trans_matrix);
    s21_transpose(A, &trans_matrix);

    // из инверсированной матрицы делаем матрицу алгебраических дополнений
    matrix_t calc_matrix = {0};
    s21_create_matrix(trans_matrix.columns, trans_matrix.rows, &calc_matrix);
    s21_calc_complements(&trans_matrix, &calc_matrix);

    // матрицу алгебраических дополнений умножанем на 1/det => обратная матрица
    status = s21_mult_number(&calc_matrix, 1 / det, result);

    s21_remove_matrix(&trans_matrix);
    s21_remove_matrix(&calc_matrix);
  }

  return status;
}