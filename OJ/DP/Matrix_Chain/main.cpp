#include <iostream>
#include <limits>
#include <map>
#include <vector>

using namespace std;

class Matrix {
 public:
  int row;
  int col;
};

void matrixChainOrder(std::vector<int> p) {
  int n = p.size() - 1;
  // initialized
  // plus one because matrix index start from 1 (A1, A2 ....An)
  long long int m[n + 1][n + 1], s[n + 1][n + 1];
  for (int i = 0; i <= n; i++) m[i][i] = 0;

  // l is the chain length
  for (int l = 2; l <= n; l++) {
    for (int i = 1; i <= (n - l + 1); i++) {
      int j = i + l - 1;
      m[i][j] = std::numeric_limits<long long int>::max();

      for (int k = i; k < j; k++) {
        cout << "i: " << i << "j: " << j << "k:" << k << endl;
        int q = m[i][k] + m[k + 1][j] + p[i - 1] * p[k] * p[j];
        if (q < m[i][j]) {
          m[i][j] = q;
          s[i][j] = k;
        }
      }
    }
  }
  for (int i = 1; i <= n; i++) {
    for (int j = i; j <= n; j++) {
      std::cout << m[i][j] << ", ";
    }
    cout << endl;
  }

  std::cout << m[1][n] << std::endl;
  //   std::cout << m[i][j] << " " << s[i][j] << std::endl;
}
int main() {
  std::vector<int> p{30, 35, 15, 5, 10, 20, 25};

  matrixChainOrder(p);
}