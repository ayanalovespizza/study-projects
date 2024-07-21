#include "../s21_matrix.h"

/**
 * @brief Очистка матрицы
 */
void s21_remove_matrix(matrix_t *A) {
  // если матрица не пустая, то в обратную сторону повторяем шаги, как при
  // выделении памяти
  if (A->matrix != NULL) {
    for (int i = 0; i < A->rows; i++) {
      // сначала удалим подмассивы
      free(A->matrix[i]);
    }
    // затем и сам массив указателей
    free(A->matrix);
  }

  A->matrix = NULL;
  A->rows = 0;
  A->columns = 0;
}