#include <iomanip>
#include <iostream>

const int MAX_N = 102;
class Matrix {
 public:
  Matrix() {
    row = col = 0;
    memset(mat, 0, sizeof(mat));
  }
  // TODO
  Matrix(int r, int c);
  const int &getrow() { return row; }
  const int &getcol() { return col; }
  // TODO
  int *operator[](const int &x);
  const int *operator[](const int &x) const { return mat[x]; }
  // TODO
  Matrix operator+(const Matrix &x) const;
  // TODO: note that this function is declared with the keyword "friend"
  friend Matrix operator*(const Matrix &x, const Matrix &y);
  void print() {
    for (int i = 0; i < row; i++) {
      if (i == 0)
        std::cout << "/";
      else if (i == row - 1)
        std::cout << "\\";
      else
        std::cout << "|";
      for (int j = 0; j < col; j++) {
        std::cout << std::right << std::setw(8) << mat[i][j];
      }
      if (i == 0)
        std::cout << " \\\n";
      else if (i == row - 1)
        std::cout << " /\n";
      else
        std::cout << " |\n";
    }
  }
  void print() const {
    for (int i = 0; i < row; i++) {
      if (i == 0)
        std::cout << "/";
      else if (i == row - 1)
        std::cout << "\\";
      else
        std::cout << "|";
      for (int j = 0; j < col; j++) {
        std::cout << std::right << std::setw(8) << mat[i][j];
      }
      if (i == 0)
        std::cout << " \\\n";
      else if (i == row - 1)
        std::cout << " /\n";
      else
        std::cout << " |\n";
    }
  }

 private:
  int mat[MAX_N][MAX_N];
  int row, col;
};

const int MOD = 10007;

Matrix Matrix::operator+(const Matrix &x) const {
  Matrix m(row, col);
  for (int i = 0; i < row; i++) {
    for (int j = 0; j < col; j++) {
      m[i][j] = (((mat[i][j] + x[i][j]) % MOD) + MOD) % MOD;
    }
  }
  return m;
}
Matrix operator*(const Matrix &x, const Matrix &y) {
  int row = x.row, col = y.col;
  Matrix m{row, col};
  for (int i = 0; i < row; i++) {
    for (int j = 0; j < col; j++) {
      for (int k = 0; k < x.col; k++) {
        m[i][j] = m[i][j] % MOD + (x[i][k] * y[k][j]) % MOD;
        m[i][j] = ((m[i][j] % MOD) + MOD) % MOD;
      }
    }
  }
  return m;
}

Matrix::Matrix(int r, int c) {
  row = r;
  col = c;
  memset(mat, 0, sizeof(mat));
}

int *Matrix::operator[](const int &x) { return mat[x]; }

int main(void) {
  freopen("input.txt", "r", stdin);
  int R, C, T;
  char OP;
  std::cin >> R >> C >> T >> OP;
  Matrix m{R, C};
  Matrix tmp{R, C};
  for (int i = 0; i < R; i++) {
    for (int j = 0; j < C; j++) {
      std::cin >> m[i][j];
      tmp[i][j] = m[i][j];
    }
  }

  if (OP == '*') {
    for (int i = 1; i < T; i++) {
      tmp = m * tmp;
    }
  } else if (OP == '+') {
    for (int i = 1; i < T; i++) {
      tmp = m + tmp;
    }
  }
  tmp.print();
}