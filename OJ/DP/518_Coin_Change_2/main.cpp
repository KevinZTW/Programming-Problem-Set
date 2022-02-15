#include <iostream>
#include <vector>

using namespace std;
int main() {
  freopen("input.txt", "r", stdin);
  int t;
  cin >> t;
  while (t--) {
    int target, n;
    cin >> target >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++) cin >> v[i];
    // i : 使用 ith coin
    // j : get j amount
    int DP[n + 1][target + 1];
    for (int i = 0; i < n; i++) {
      for (int j = 0; j <= target; j++) {
        DP[i][j] = 0;
      }
    }
    // cout << "1:" << DP[n - 1][target] << endl;
    DP[0][0] = 1;
    for (int i = 1; i <= n; i++) {
      DP[i][0] = 1;
      for (int j = 1; j <= target; j++) {
        int amount = v[i - 1];
        DP[i][j] = DP[i - 1][j] + (j >= amount ? DP[i][j - amount] : 0);
        // cout << "DP " << i << ", " << j << " => " << DP[i][j] << endl;
      }
    }

    cout << DP[n - 1][target] << endl;
  }
}