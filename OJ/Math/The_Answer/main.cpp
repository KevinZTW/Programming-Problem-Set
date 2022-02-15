#include <iostream>
using namespace std;
#define ll long long int

ll G[110];
int main() {
  ll n;
  //   freopen("input.txt", "r", stdin);
  while (cin >> n) {
    if (n == 0) {
      cout << 0 << endl;
      continue;
    }
    G[0] = 1, G[1] = 0;
    for (int i = 2; i < 94; i++) {
      G[i] = G[i - 1] + G[i - 2];
    }
    ll min = 2e18;
    for (int i = 1; i < 93; i++) {
      if ((n - G[i]) % G[i + 1] == 0) {
        ll f1 = (n - G[i]) / G[i + 1];
        if (f1 < min) min = f1;
      }
    }
    cout << min << endl;
  }
}