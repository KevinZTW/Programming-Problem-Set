#include <math.h>

#include <iostream>
#define ll long long int

using namespace std;

int find_k(ll i, ll y) {
  int l = 0, r = 1e9;
  while (l < r) {
    int mid = (l + r) / 2;
    ll calc = mid * 2 + 1;
    ll ii = pow(2, i);

    // overflow 部分直接跳過往左縮??
    if (calc > (2e18 / ii)) {
      r = mid;
      continue;
    }
    // cout << "i: " << i << "k: " << calc << endl;
    //要注意這邊 long long 所以小數點後就不見了
    ll front = (ll)(ii - 1) * calc;
    ll back = (calc * (ll)(calc - 1) / (ll)2);
    // cout << "f: " << front << "b: " << back << endl;
    ll calculation = front + back;
    // cout << calculation << " vs " << y << endl;
    if (calculation > y)
      r = mid;
    else if (calculation < y)
      l = mid + 1;
    else
      return calc;
  }
  return -1;
}

int main() {
  //   freopen("input.txt", "r", stdin);
  int n;
  cin >> n;
  while (n--) {
    ll y;
    cin >> y;
    // x = 2^i * k

    ll minx = 2e18;
    bool find = false;
    for (int i = 0; i < 64; i++) {
      ll k = find_k(i, y);

      if (k != -1) {
        find = true;
        // cout << k << endl;
        ll x = pow(2, i) * k;
        if (x > 0 && x < minx) minx = x;
      }
    }
    if (find)
      cout << minx << endl;
    else
      cout << -1 << endl;
    // cout << "-------" << endl;
  }
}