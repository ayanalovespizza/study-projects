#include "../s21_matrix.h"

/**
 * @brief Определитель матрицы
 *        Определитель(детерминант) - это число, которое ставят в соответствие
 *        каждой квадратной матрице и вычисляют из элементов по специальным
 *        формулам
 *        Tip: определитель может быть вычислен только для квадратной матрицы.
 *
 * @return 0 - OK
 *         1 - Ошибка, некорректная матрица
 *         2 - Ошибка вычисления (несовпадающие размеры матриц;
 *             матрица, для которой нельзя провести вычисления и т.д.)
 */
int s21_determinant(matrix_t *A, double *result) {
  int res = 0;
  if (s21_is_correct(A)) {
    res = INCORRECT;
  } else if (A->rows != A->columns) {
    res = CALC_ERROR;
  } else {
    *result = s21_get_determinant(A);
  }
  return res;
}

double s21_get_determinant(matrix_t *A) {
  double result = 0.0;
  if (A->rows == 1) {
    result = A->matrix[0][0];

  } else {
    matrix_t tmp = {0};
    s21_create_matrix(A->rows - 1, A->columns - 1, &tmp);
    for (int i = 0; i < A->columns; i++) {
      s21_minor(0, i, A, &tmp);
      if (i % 2) {
        result -= A->matrix[0][i] * s21_get_determinant(&tmp);
      } else {
        result += A->matrix[0][i] * s21_get_determinant(&tmp);
      }
    }
    s21_remove_matrix(&tmp);
  }
  return result;
}