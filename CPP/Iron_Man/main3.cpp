#include <iostream>

const int MAX_N = 1e6;
class Matrix {
 public:
  Matrix() {
    row = col = 0;
    memset(mat, 0, sizeof(mat));
  }
  Matrix(int r, int c);
  const int &getrow() { return row; }
  const int &getcol() { return col; }
  const int *operator[](const int &x) const { return mat[x]; }
  int *operator[](const int &x) {}
  Matrix operator+(const Matrix &m) const;
  friend Matrix operator*(const Matrix &x, const Matrix &y);

 private:
  int row;
  int col;
  int mat[MAX_N][MAX_N];
};

Matrix::Matrix(int r, int c) : row(r), col(c) { memset(mat, 0, sizeof(mat)); }
int *Matrix::operator[](const int &x) { return mat[x]; }
Matrix Matrix::operator+(const Matrix &x) const {
  Matrix m(row, col);
  for (int i = 0; i < row; i++) {
    for (int j = 0; j < x.col; j++) {
      m[i][j] = m[i][j] + mat[i][j] + x[i][j];
    }
  }
}

const int MOD = 1e4 + 7;
Matrix operator*(const Matrix &x, const Matrix &y) {
  Matrix res(x.row, y.col);
  for (int i = 0; i < x.row; i++) {
    for (int j = 0; j < y.col; j++) {
      for (int k = 0; k < x.col; k++) {
        res[i][j] = res[i][j] + x[i][k] * y[k][j] % MOD;
        res[i][j] = res[i][j] % MOD;
      }
    }
  }
  return res;
}