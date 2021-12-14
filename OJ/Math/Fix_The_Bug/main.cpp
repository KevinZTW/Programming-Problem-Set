#include <math.h>

#include <iostream>
#include <vector>
#define ll long long int

using namespace std;

int cmp(const void *a, const void *b) {
  ll tmpa = *(ll *)a, tmpb = *(ll *)b;
  if (tmpa > tmpb)
    return 1;
  else if (tmpa < tmpb)
    return -1;
  else
    return 0;
}

int get_digit(ll n) {
  int d = 0;
  while (n > 0) {
    n /= 10;
    d++;
  }
  return d;
}

int upper_bound(vector<ll> &v, int n, int target) {
  int l = 0, r = n;
  while (l < r) {
    int mid = (l + r) / 2;
    if (v[mid] <= target)
      l = mid + 1;
    else
      r = mid;
  }
  return r;
}

int lower_bound(vector<ll> &v, int n, int target) {
  int l = 0, r = n;
  while (l < r) {
    int mid = (l + r) / 2;
    if (v[mid] < target)
      l = mid + 1;
    else
      r = mid;
  }
  return r;
}

int main() {
  // freopen("input.txt", "r", stdin);
  ll n, k;
  while (cin >> n >> k) {
    int row = 12;
    int col = n * 2;
    vector<vector<ll>> v(row);
    for (int i = 0; i < row; i++) v[i] = vector<ll>(col);
    for (int i = 0; i < n; i++) cin >> v[0][i];
    for (int i = 1; i < row; i++) {
      for (int j = 0; j < n; j++) {
        v[i][j] = (v[i - 1][j] * 10) % k;
      }
      qsort(&v[i][0], n, sizeof(ll), cmp);
    }

    // for (int i = 0; i < row; i++) {
    //   for (int j = 0; j < n; j++) {
    //     cout << v[i][j] << " ";
    //   }
    //   cout << endl;
    // }
    ll ans = 0;
    for (int i = 0; i < n; i++) {
      ll base_num = v[0][i];

      ll left = (k - (base_num % k)) % k;
      int digit = get_digit(base_num);

      ans += upper_bound(v[digit], n, left) - lower_bound(v[digit], n, left);
      ll self = (base_num * (ll)pow(10, digit)) % k;
      if (left == self) ans--;
      //   cout << "base: " << base_num << "find :" << left << "self: " << self
      //        << endl;
    }
    cout << ans << endl;
  }
}