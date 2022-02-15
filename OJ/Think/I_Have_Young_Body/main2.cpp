#include <iostream>
#include <vector>

using namespace std;
int main() {
  //   freopen("input.txt", "r", stdin);
  int t;
  cin >> t;
  while (t--) {
    int n, p, k;
    cin >> n >> p >> k;
    // cout << n << p << k;
    vector<int> items;
    vector<int> price(n + 1, 0);

    for (int i = 0; i < n; i++) {
      int num;
      cin >> num;
      items.push_back(num);
    }
    sort(items.begin(), items.end());
    for (int i = 1; i <= n; i++) {
      // buy i items
      if (i >= k)
        price[i] = price[i - k] + items[i - 1];
      else
        price[i] = price[i - 1] + items[i - 1];
    }
    int ans = 0;
    for (int i = 1; i <= n; i++) {
      if (price[i] <= p) {
        ans = i;
      }
    }
    cout << ans << endl;
  }
}