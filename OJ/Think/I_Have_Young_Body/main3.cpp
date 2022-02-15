#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;
vector<int> v;
vector<int> prefix;
int n, p, k;

int lower_bound() {
  int l = 0, r = n + 1;
  while (l < r) {
    int mid = (l + r) / 2;
    if (prefix[mid] < p)
      l = mid + 1;
    else
      r = mid;
  }
  return r;
}

int main() {
  freopen("input.txt", "r", stdin);
  int t;
  cin >> t;
  while (t--) {
    v.clear();
    prefix.clear();
    cin >> n >> p >> k;
    prefix = vector<int>(n + 1, 0);
    int val;
    for (int i = 0; i < n; i++) cin >> val, v.push_back(val);
    sort(v.begin(), v.end());
    for (auto i : v) cout << i << ",";
    cout << endl;

    for (int i = 1; i <= n; i++) {
      if (i % k)
        prefix[i] = prefix[i - 1] + v[i - 1];
      else
        prefix[i] = prefix[i - k] + v[i - 1];
    }
    for (auto i : prefix) cout << i << ",";
    cout << endl;
    int ans = 0;
    for (int i = n; i > 0; i--) {
      if (prefix[i] <= p) {
        ans = i;
        break;
      }
    }
    cout << ans << endl;
  }
}