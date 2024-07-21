#include "s21_matrix_oop.h"

bool S21Matrix::EqMatrix(const S21Matrix& other) {
  bool status = true;
  int count_diffs = 0;

  if (rows_ != other.rows_ || cols_ != other.cols_) {
    status = false;

  } else {
    for (int i = 0; i < rows_; i++) {
      for (int j = 0; j < cols_; j++) {
        if (fabs(matrix_[i][j] - other.matrix_[i][j]) > 1e-7) {
          count_diffs++;
        }
      }
    }

    status = (count_diffs == 0 && status != false) ? true : false;
  }

  return status;
}

void S21Matrix::SumMatrix(const S21Matrix& other) {
  if (rows_ != other.rows_ || cols_ != other.cols_)
    throw std::invalid_argument("Matrices should have the same size");

  for (int i = 0; i < rows_; i++) {
    for (int j = 0; j < cols_; j++) {
      matrix_[i][j] += other.matrix_[i][j];
    }
  }
}

void S21Matrix::SubMatrix(const S21Matrix& other) {
  if (rows_ != other.rows_ || cols_ != other.cols_)
    throw std::invalid_argument("Matrices should have the same size");

  for (int i = 0; i < rows_; i++) {
    for (int j = 0; j < cols_; j++) {
      matrix_[i][j] -= other.matrix_[i][j];
    }
  }
}

void S21Matrix::MulNumber(const double num) {
  for (int i = 0; i < rows_; i++) {
    for (int j = 0; j < cols_; j++) {
      matrix_[i][j] *= num;
    }
  }
}

void S21Matrix::MulMatrix(const S21Matrix& other) {
  if (cols_ != other.rows_)
    throw std::invalid_argument(
        "The number of columns of the 1st matrix must be equal to the number "
        "of rows of the 2nd matrix");

  S21Matrix result(rows_, other.cols_);

  for (int i = 0; i < rows_; i++) {
    for (int j = 0; j < other.cols_; j++) {
      for (int k = 0; k < other.rows_; k++) {
        result.matrix_[i][j] += matrix_[i][k] * other.matrix_[k][j];
      }
    }
  }

  *this = result;
}

S21Matrix S21Matrix::Transpose() {
  S21Matrix trans_matrix = S21Matrix(cols_, rows_);

  for (int i = 0; i < cols_; i++) {
    for (int j = 0; j < rows_; j++) {
      trans_matrix.matrix_[i][j] = matrix_[j][i];
    }
  }

  return trans_matrix;
}

double S21Matrix::Determinant() {
  double result = 0;

  if (rows_ != cols_) {
    throw std::invalid_argument("The matrix is not square");
  }

  if (rows_ == 1) {
    result = matrix_[0][0];

  } else if (rows_ == 2) {
    result = matrix_[0][0] * matrix_[1][1] - matrix_[0][1] * matrix_[1][0];

  } else {
    for (int i = 0; i < cols_; i++) {
      double multiplier = pow(-1, i) * matrix_[0][i];
      S21Matrix minor = Minor(0, i);
      result += multiplier * minor.Determinant();
    }
  }

  return result;
}

S21Matrix S21Matrix::CalcComplements() {
  S21Matrix calc_matrix = S21Matrix(rows_, cols_);

  for (int i = 0; i < rows_; i++) {
    for (int j = 0; j < cols_; j++) {
      calc_matrix.matrix_[i][j] = pow(-1, i + j) * Minor(i, j).Determinant();
      printf("\n\n\n%lf", calc_matrix.matrix_[i][j]);
    }
  }

  return calc_matrix;
}

S21Matrix S21Matrix::InverseMatrix() {
  double determinant = Determinant();

  if (abs(determinant) < 1e-7) {
    throw std::invalid_argument("The determinant of the matrix equals 0");
  }

  S21Matrix inverse_matrix = Transpose().CalcComplements();
  inverse_matrix.MulNumber(1 / determinant);

  return inverse_matrix;
}