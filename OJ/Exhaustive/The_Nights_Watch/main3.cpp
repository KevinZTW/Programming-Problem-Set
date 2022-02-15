#include <iostream>
#include <vector>

using namespace std;

vector<int> v;

int main() {
  // freopen("input.txt", "r", stdin);
  int t;
  cin >> t;
  while (t--) {
    int n, m, k;
    cin >> n >> m >> k;
    v.clear();
    for (int i = 0; i < n; i++) {
      int num;
      cin >> num, v.push_back(num);
    }
    if (k > m - 1) k = m - 1;
    int max_value = 0;
    for (int i = 0; i <= k; i++) {
      // ask friend take i item from the front
      int min_value = 1e9;
      for (int j = 0; j < m - k; j++) {
        // other take j from the front
        int take = max(v[i + j], v[i + j + n - m]);
        if (take < min_value) min_value = take;
      }
      if (min_value > max_value) max_value = min_value;
    }
    cout << max_value << endl;
  }
}