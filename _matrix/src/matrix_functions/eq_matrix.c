#include "../s21_matrix.h"

/**
 * @brief Сравнение матриц
 *        Две матрицы A, B совпадают |A = B|, если совпадают их размеры и
 *        соответствующие элементы равны, то есть при всех i, j A(i,j) = B(i,j).
 *        Сравнение должно происходить вплоть до 7 знака после запятой
 *        включительно.
 *
 * @return SUCCESS - 1 - матрицы равны
 *         FAILURE - 0 - матрицы не равны
 */
int s21_eq_matrix(matrix_t *A, matrix_t *B) {
  int status = SUCCESS;  // изначально считаем, что матрицы равны
  int count_diffs = 0;

  // проверяем, все ли ок с матрицами и сравниваеи количество столбцов и строк
  if (s21_is_correct(A) == INCORRECT || s21_is_correct(B) == INCORRECT ||
      A->columns != B->columns || A->rows != B->rows) {
    status = FAILURE;

    // если все ок, то начинаем сравнивать элементы
  } else {
    for (int i = 0; i < A->rows; i++) {
      for (int j = 0; j < A->columns; j++) {
        if (fabs(A->matrix[i][j] - B->matrix[i][j]) > 1e-7) {
          count_diffs++;
        }
      }
    }
  }

  status = (count_diffs == 0 && status != FAILURE) ? SUCCESS : FAILURE;
  return status;
}