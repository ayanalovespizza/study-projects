#include "../s21_matrix.h"

/**
 * @brief Создание матрицы
 *
 * @return 0 - OK
 *         1 - Ошибка, некорректная матрица
 *         2 - Ошибка вычисления (несовпадающие размеры матриц; матрица, для
 *             которой нельзя провести вычисления и т.д.)
 */
int s21_create_matrix(int rows, int columns, matrix_t *result) {
  int status = OK;  // изначально считаем, что с матрицей все ок

  // если хотят сделать 0 и "-" столбцов или строк, то матрица некорректна
  if (rows < 1 || columns < 1)
    status = INCORRECT;

  else {
    // в ином случае создаем массив указателей
    result->rows = rows;
    result->columns = columns;
    result->matrix = (double **)calloc(rows, sizeof(double *));
  }

  // если память для указателей выделилась и calloc не вернул NULL, то выделяем
  // память для double чисел (каждому из элементов этого массива присвоить адрес
  // нового массива)
  if (result->matrix != NULL) {
    for (int i = 0; i < rows; i++)
      result->matrix[i] = (double *)calloc(columns, sizeof(double));
  }

  return status;
}