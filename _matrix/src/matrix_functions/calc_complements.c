#include "../s21_matrix.h"

/**
 * @brief Матрица алгебраических дополнений
 *        Минором M(i,j) называется определитель (n-1)-го порядка, полученный
 *        вычёркиванием из матрицы A i-й строки и j-го столбца
 *        Алгебраическим дополнением элемента матрицы является значение минора
 *        умноженное на -1^(i+j).
 *
 * @return 0 - OK
 *         1 - Ошибка, некорректная матрица
 *         2 - Ошибка вычисления (несовпадающие размеры матриц; матрица, для
 *             которой нельзя провести вычисления и т.д.)
 */
int s21_calc_complements(matrix_t *A, matrix_t *result) {
  int status = OK;

  if (s21_is_correct(A) == INCORRECT) {
    return INCORRECT;

  } else if (A->columns != A->rows) {
    return CALC_ERROR;

  } else {
    status = s21_create_matrix(A->rows, A->columns, result);

    for (int i = 0; i < A->rows; i++) {
      for (int j = 0; j < A->columns; j++) {
        matrix_t minor = {0};
        double det = 0;
        s21_create_matrix(A->rows - 1, A->columns - 1, &minor);
        s21_minor(i, j, A, &minor);
        s21_determinant(&minor, &det);
        result->matrix[i][j] = pow(-1, (i + j)) * det;
        s21_remove_matrix(&minor);
      }
    }
  }
  return status;
}

void s21_minor(int row, int col, matrix_t *A, matrix_t *result) {
  int m_row = 0;
  int m_col = 0;
  for (int i = 0; i < A->rows; i++) {
    if (i == row) {
      continue;
    }
    m_col = 0;
    for (int j = 0; j < A->columns; j++) {
      if (j == col) {
        continue;
      }
      result->matrix[m_row][m_col] = A->matrix[i][j];
      m_col++;
    }
    m_row++;
  }
}