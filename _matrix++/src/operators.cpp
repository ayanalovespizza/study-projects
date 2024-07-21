#include "s21_matrix_oop.h"

S21Matrix S21Matrix::operator+(const S21Matrix& other) {
  S21Matrix result = *this;
  result.SumMatrix(other);

  return result;
}

S21Matrix S21Matrix::operator-(const S21Matrix& other) {
  S21Matrix result = *this;
  result.SubMatrix(other);

  return result;
}

S21Matrix operator*(double num, S21Matrix& other) {
  S21Matrix result = other;
  result.MulNumber(num);

  return result;
}

S21Matrix operator*(S21Matrix& other, double num) {
  S21Matrix result = other;
  result.MulNumber(num);

  return result;
}

S21Matrix S21Matrix::operator*(const S21Matrix& other) {
  S21Matrix result = *this;
  result.MulMatrix(other);

  return result;
}

bool S21Matrix::operator==(const S21Matrix& other) { return EqMatrix(other); }

S21Matrix& S21Matrix::operator=(const S21Matrix& other) {
  if (this != &other) {
    Free();
    rows_ = other.rows_;
    cols_ = other.cols_;
    CopyFromOther(other);
  }
  return *this;
}

S21Matrix& S21Matrix::operator+=(const S21Matrix& other) {
  SumMatrix(other);
  return *this;
}

S21Matrix& S21Matrix::operator-=(const S21Matrix& other) {
  SubMatrix(other);
  return *this;
}

S21Matrix& S21Matrix::operator*=(const S21Matrix& other) {
  MulMatrix(other);
  return *this;
}

S21Matrix& S21Matrix::operator*=(const double num) {
  MulNumber(num);
  return *this;
}

// чтение элемента
// const double& S21Matrix::operator()(int i, int j) const {
//   if (i < 0 || i >= rows_ || j < 0 || j >= cols_) {
//     throw std::invalid_argument("Index out of range");
//   }
//   return matrix_[i][j];
// }

// изменение значений в матрице
double& S21Matrix::operator()(int i, int j) {
  if (i < 0 || i >= rows_ || j < 0 || j >= cols_) {
    throw std::invalid_argument("Index out of range");
  }
  return matrix_[i][j];
}