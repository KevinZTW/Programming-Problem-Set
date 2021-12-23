#include <cmath>
#include <iostream>
#include <vector>
#define ll long long int
using namespace std;

int upper_bound(vector<long long> &v, int len, long long target) {
  int l = 0, r = len, m;
  while (l < r) {
    m = (l + r) / 2;
    if (v[m] > target)
      r = m;
    else
      l = m + 1;
  }
  return r;
}

int lower_bound(vector<long long> &v, int len, long long target) {
  int l = 0, r = len, m;
  while (l < r) {
    m = (l + r) / 2;
    if (v[m] >= target)
      r = m;
    else
      l = m + 1;
  }
  return r;
}

int cmp(const void *a, const void *b) {
  return *(long long *)a - *(long long *)b;
}

int get_digit(long long num) {
  int d = 0;
  while (num > 0) {
    num /= 10;
    d++;
  }
  return d;
}

int main() {
  int n, k;
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

    //
    int ans = 0;
    for (int i = 0; i < n; i++) {
      //   if (n != 1) {
      long long cur = v[0][i];
      long long target = (k - (cur % k)) % k;
      long long check = ((cur) * ((long long)pow(10, get_digit(cur)))) % k;
      ans += upper_bound(v[get_digit(cur)], n, target) -
             lower_bound(v[get_digit(cur)], n, target);
      if (target == check) ans--;
      //   } else if (v[0][i] % k == 0)
      // ans++;
    }
    cout << ans << endl;
  }
}