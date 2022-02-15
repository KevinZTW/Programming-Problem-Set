#include <iostream>
#define ll long long int

using namespace std;

int lower_bound(int i, ll target) {
  int l = 0, r = 1e9;
  while (l < r) {
    int mid = (l + r) / 2;
    ll calc = mid * 2 + 1;
    ll ii = pow(2, i);
    if (calc > (2e18 / ii)) {
      r = mid;
      continue;
    }

    ll front = (ll)(ii - 1) * calc;
    ll back = (calc * (ll)(calc - 1) / (ll)2);

    ll ans = front + back;
    cout << ans << endl;
    if (ans > target)
      r = mid;
    else if (ans < target)
      l = mid + 1;
    else
      return calc;
  }
  return -1;
}

int main() {
  freopen("input.txt", "r", stdin);
  int t;
  cin >> t;
  while (t--) {
    ll n;
    cin >> n;
    ll min = 1e18;
    bool find = false;
    for (int i = 0; i < 64; i++) {
      ll k = lower_bound(i, n);
      if (k != -1) {
        find = true;
        ll ans = (ll)pow(2, i) * k;
        if (ans < min) min = ans;
      }
    }
    if (find)
      cout << min << endl;
    else
      cout << -1 << endl;
  }
}