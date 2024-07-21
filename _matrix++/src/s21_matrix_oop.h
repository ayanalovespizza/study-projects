#ifndef __S21_MATRIX_OOP__H
#define __S21_MATRIX_OOP__H

#include <cmath>
#include <iostream>
#include <utility>

class S21Matrix {
 private:
  /* ~~~ закрытые поля ~~~ */
  int rows_, cols_;  // rows and columns
  double** matrix_;  // pointer to the memory where the matrix is allocated

 public:
  // ===> CORE.CPP
  S21Matrix() noexcept;
  S21Matrix(int rows, int cols);
  S21Matrix(const S21Matrix& other);
  S21Matrix(S21Matrix&& other) noexcept;
  ~S21Matrix() noexcept;

  // ===> OPERATIONS.CPP
  /* ~~~ основные операции ~~~ */
  bool EqMatrix(const S21Matrix& other);
  void SumMatrix(const S21Matrix& other);
  void SubMatrix(const S21Matrix& other);
  void MulNumber(const double num);
  void MulMatrix(const S21Matrix& other);
  S21Matrix Transpose();
  double Determinant();
  S21Matrix CalcComplements();
  S21Matrix InverseMatrix();

  // ===> OPERATORS.CPP
  /* ~~~ перегрузка операторов ~~~ */
  S21Matrix operator+(const S21Matrix& other);
  S21Matrix operator-(const S21Matrix& other);

  friend S21Matrix operator*(double num, S21Matrix& other);
  friend S21Matrix operator*(S21Matrix& other, double num);
  S21Matrix operator*(const S21Matrix& other);

  bool operator==(const S21Matrix& other);
  S21Matrix& operator=(const S21Matrix& other);

  S21Matrix& operator+=(const S21Matrix& other);
  S21Matrix& operator-=(const S21Matrix& other);
  S21Matrix& operator*=(const S21Matrix& other);
  S21Matrix& operator*=(const double num);

  const double& operator()(int i, int j) const;
  double& operator()(int i, int j);

  // ===> HELPERS.CPP
  /* ~~~ геттеры (accessors) для закрытых полей ~~~ */
  int GetRows() const;
  int GetCols() const;

  /* ~~~ сеттеры (mutators) для закрытых полей ~~~ */
  void SetRows(int new_rows);
  void SetCols(int new_cols);

  /* ~~~ вспомогательные методы ~~~ */
  void MemoryAlloc();
  void Free();
  S21Matrix Minor(int row, int col);
  void CopyFromOther(const S21Matrix& other);

  void FillMatrix();
  void PrintMatrix();
};

// выносим перегрузку оператора умножения на число вне класса для
// возможности умножать как число на матрицу, так и матрицу на число
S21Matrix operator*(double num, S21Matrix& other);
S21Matrix operator*(S21Matrix& other, double num);

#endif