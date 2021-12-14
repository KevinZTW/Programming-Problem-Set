#include <iostream>
#include <string>
using namespace std;
/*
 assume Z = LCS (X, Y) for
 X = x1, x2....xn
 Y = y1, y2....ym
 Z = z1, z2...zi

 1. if xi = yj then zk = xi = yj
 2. if xi != yj then zk = max {LCS(xi+1, yj) LCS(xi, yj+1)}

 LCS = (xi==yj)? xi + LCS(xi+1, yj+1) : max {LCS(xi+1, yj) LCS(xi, yj+1)}

 sub problem :L[i, j] = LCS(A[:i], B[:j]))
 relative : if A[i] == B[j] 1+LCS(xi-1, yj-1) else  max {LCS(xi-1, yj)
 LCS(xi,yj-1)} topo : for base case : L[0, j] = L[i, 0] = 0 origin : L[n, m] to

*/

int main() {
  string X, Y;
  freopen("input.txt", "r", stdin);
  cin >> X >> Y;

  int n = X.size(), m = Y.size();
  // cout << X << n << Y << m << endl;
  int L[n + 1][m + 1];

  // base case, 0 element in X or Y
  for (int i = 0; i <= n; i++) L[i][0] = 0;
  for (int i = 0; i <= m; i++) L[0][i] = 0;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      // cout << L[i - 1][j] << ", " << L[i][j - 1] << endl;
      if (X[i - 1] == Y[j - 1])
        L[i][j] = L[i - 1][j - 1] + 1;
      else if (L[i - 1][j] >= L[i][j - 1])
        L[i][j] = L[i - 1][j];
      else
        L[i][j] = L[i][j - 1];
      // cout << "L[" << i << "," << j << "]"
      //      << "=" << L[i][j] << endl;
    }
  }
  cout << L[n][m] << endl;
}