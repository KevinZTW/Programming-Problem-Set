#include <algorithm>
#include <iostream>
#include <vector>
#define ll long long int

using namespace std;
int main() {
  //   freopen("input.txt", "r", stdin);
  int t;
  cin >> t;
  while (t--) {
    vector<ll> s;
    ll num;
    for (int i = 0; i < 3; i++) {
      cin >> num;
      s.push_back(num);
    }
    sort(s.begin(), s.end());
    ll a = s[0], b = s[1], c = s[2];

    if (c - a > b)
      cout << a + b << endl;
    else
      cout << a + (b + c - a) / (ll)2 << endl;
  }
}