#include <iostream>
#include <vector>
using namespace std;

int main() {
  //   freopen("input.txt", "r", stdin);
  int t;
  cin >> t;
  while (t--) {
    int n, m, k;

    cin >> n >> m >> k;
    vector<int> data(n);
    for (int i = 0; i < n; i++) {
      cin >> data[i];
    }
    int max_value = 0;
    if (k > m - 1) k = m - 1;
    for (int j = 0; j <= k; j++) {
      //朋友先拿前面 j 個 最多拿到 k 個
      //這邊算出來要取最大的
      int min_value = 1e9;
      for (int i = 0; i < m - k; i++) {
        //剩下人拿前面 i 個，最多拿到 m-k-1
        //取最小的
        int num = max(data[i + j], data[i + j + n - m]);
        if (num < min_value) min_value = num;
      }
      if (min_value > max_value) max_value = min_value;
    }
    cout << max_value << endl;
  }
}