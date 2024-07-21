#include <stdio.h>

#include "s21_matrix_oop.h"

void S21Matrix::MemoryAlloc() {
  matrix_ = new double *[rows_]();
  for (int i = 0; i < rows_; i++) {
    matrix_[i] = new double[cols_]();
  }
}

void S21Matrix::Free() {
  if (matrix_) {
    for (int i = 0; i < rows_; i++) {
      delete[] matrix_[i];
    }
    delete[] matrix_;

    matrix_ = nullptr;
    rows_ = 0;
    cols_ = 0;
  }
}

S21Matrix S21Matrix::Minor(int row, int col) {
  if (rows_ != cols_) {
    throw std::invalid_argument("The matrix is not square");
  }

  S21Matrix minor = S21Matrix(rows_ - 1, cols_ - 1);
  int m_row = 0, m_col = 0;

  for (int i = 0; i < rows_; i++) {
    if (i == row) continue;
    m_col = 0;

    for (int j = 0; j < cols_; j++) {
      if (j == col) continue;
      minor.matrix_[m_row][m_col] = matrix_[i][j];
      m_col++;
    }
    m_row++;
  }

  return minor;
}

void S21Matrix::CopyFromOther(const S21Matrix &other) {
  MemoryAlloc();
  for (int i = 0; i < rows_; i++) {
    for (int j = 0; j < cols_; j++) {
      matrix_[i][j] = other.matrix_[i][j];
    }
  }
}

int S21Matrix::GetRows() const { return rows_; }

int S21Matrix::GetCols() const { return cols_; }

void S21Matrix::SetRows(int new_rows) {
  if (new_rows <= 0) {
    throw std::invalid_argument(
        "Incorrect input, rows value must be greater than 0");
  }

  if (rows_ != new_rows) {
    S21Matrix new_matrix(new_rows, cols_);
    int min_rows = std::min(rows_, new_rows);

    for (int i = 0; i < min_rows; i++) {
      for (int j = 0; j < cols_; j++) {
        new_matrix.matrix_[i][j] = matrix_[i][j];
      }
    }

    if (new_rows > rows_) {
      for (int i = rows_; i < new_rows; i++) {
        for (int j = 0; j < cols_; j++) {
          new_matrix.matrix_[i][j] = 0.0;
        }
      }
    }

    *this = new_matrix;
  }
}

void S21Matrix::SetCols(int new_cols) {
  if (new_cols <= 0) {
    throw std::invalid_argument(
        "Incorrect input, rows value must be greater than 0");
  }

  if (cols_ != new_cols) {
    S21Matrix new_matrix(rows_, new_cols);
    int min_cols = std::min(cols_, new_cols);

    for (int i = 0; i < rows_; i++) {
      for (int j = 0; j < min_cols; j++) {
        new_matrix.matrix_[i][j] = matrix_[i][j];
      }
    }

    if (new_cols > cols_) {
      for (int i = 0; i < rows_; i++) {
        for (int j = cols_; j < new_cols; j++) {
          new_matrix.matrix_[i][j] = 0.0;
        }
      }
    }

    *this = new_matrix;
  }
}

// void S21Matrix::FillMatrix() {
//   double elem = 0;

//   for (int i = 0; i < rows_; i++) {
//     for (int j = 0; j < cols_; j++) {
//       std::cout << "Введите элемент матрицы [" << i << "][" << j << "]: ";
//       std::cin >> elem;

//       matrix_[i][j] = elem;
//     }
//   }
// }

void S21Matrix::PrintMatrix() {
  for (int i = 0; i < rows_; i++) {
    for (int j = 0; j < cols_; j++) {
      printf("%3.0lf ", matrix_[i][j]);
    }
    std::cout << std::endl;
  }
}