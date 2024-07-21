#include "s21_matrix_oop.h"

S21Matrix::S21Matrix() noexcept : rows_(0), cols_(0), matrix_(0) {}

S21Matrix::S21Matrix(int rows, int cols) : rows_(rows), cols_(cols) {
  if (rows < 1 || cols < 1) {
    throw std::invalid_argument(
        "Count of rows or collumns should be more than 1");
  }
  MemoryAlloc();
}

S21Matrix::S21Matrix(const S21Matrix& other)
    : rows_(other.rows_), cols_(other.cols_) {
  MemoryAlloc();
  for (int i = 0; i < rows_; i++) {
    std::memcpy(matrix_[i], other.matrix_[i], other.cols_ * sizeof(double));
  }
}

S21Matrix::S21Matrix(S21Matrix&& other) noexcept
    : rows_(other.rows_), cols_(other.cols_), matrix_(other.matrix_) {
  other.rows_ = 0;
  other.cols_ = 0;
  other.matrix_ = nullptr;
}

S21Matrix::~S21Matrix() noexcept {
  Free();

  rows_ = 0;
  cols_ = 0;
}