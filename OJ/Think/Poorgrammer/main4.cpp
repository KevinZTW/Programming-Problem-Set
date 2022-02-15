#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

vector<int> v;

int lower_bound(int n, int target) {
  int l = 1, r = n + 1;

  while (l < r) {
    int cup = 0;
    int code_gen = 0;
    int mid = (l + r) / 2;
    for (int j = 0; j < n; j++) {
      int deduct = cup / mid;
      if (v[cup] > deduct)
        code_gen += v[cup++] - deduct;
      else
        break;
    }
    // cout << "r: " << r << "mid: " << mid << "code_gen: " << code_gen << endl;
    if (code_gen >= target)
      r = mid;
    else
      l = mid + 1;
  }
  return r;
}

int main() {
  //   freopen("input.txt", "r", stdin);
  int t;
  cin >> t;
  while (t--) {
    v.clear();
    int n, target;
    cin >> n >> target;
    for (int i = 0; i < n; i++) {
      int num;
      cin >> num;
      v.push_back(num);
    }

    // for (auto i : v) cout << i << ", ";

    // if total i days, can i finish request target?
    int days = lower_bound(n, target);
    if (days > n)
      cout << -1 << endl;
    else
      cout << days << endl;
  }
}