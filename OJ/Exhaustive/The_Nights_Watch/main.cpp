#include <algorithm>
#include <iostream>
#include <vector>
//<7, 6, 2, 11, 8, 9, 4, 3>
//綜合了 exhaustive search & binary search?

using namespace std;
int main() {
  // freopen("input.txt", "r", stdin);
  int t;
  cin >> t;
  while (t--) {
    int n, m, k;
    vector<int> v;
    cin >> n >> m >> k;
    for (int i = 0; i < n; i++) {
      int num;
      cin >> num;
      v.push_back(num);
    }
    //我是第 mth e.g. 2
    //我前面的人會挑走 m - 1 個
    //我前面朋友以外會挑走 m -1-k
    int min = 0;
    if (k > m - 1) k = m - 1;
    for (int j = 0; j <= k; j++) {
      //從前面拿走 i 個
      int max_num = 1e9;
      //我朋友從前面拿 j 個
      // cout << n << " " << m << endl;

      for (int i = 0; i < m - k; i++) {
        // cout << i << " " << j << endl;
        int num = max(v[i + j], v[i + j + n - m]);
        // cout << "num: " << num << endl;
        if (num < max_num) max_num = num;
      }
      // cout << "max:" << max_num << endl;
      //找最小的
      if (max_num > min) min = max_num;
    }
    cout << min << endl;
  }
}