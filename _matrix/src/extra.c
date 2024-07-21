#include "s21_matrix.h"

/**
 * @brief Проверка коррекотности матрицы
 *        Матрицу будем считать корректной, если она не пустая, а также имеет
 *        положительное количество строчек и столбцов
 *
 * @return OK - 0 - с матрица корректна
 *         INCORRECT - 1 - матрица некорректна
 */
int s21_is_correct(matrix_t *A) {
  int status = OK;
  if (A == NULL || A->matrix == NULL || A->rows < 1 || A->columns < 1) {
    status = INCORRECT;
  }

  return status;
}

void s21_set(double *nums, matrix_t *A) {
  int count = 0;
  for (int i = 0; i < A->rows; i++) {
    for (int j = 0; j < A->columns; j++) {
      A->matrix[i][j] = nums[count];
      count++;
    }
  }
}
