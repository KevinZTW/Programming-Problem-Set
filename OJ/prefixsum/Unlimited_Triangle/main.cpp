#include <cstring>
#include <iostream>
#include <vector>

#define ll long long int

using namespace std;
const int MAX = 1e5 + 1;
int prefix[MAX];
int main() {
  // freopen("input.txt", "r", stdin);
  int t;
  cin >> t;
  while (t--) {
    int A, B, C, D;
    cin >> A >> B >> C >> D;

    memset(prefix, 0, sizeof(prefix));
    for (int i = A; i <= B; i++) {
      prefix[i + B] += 1;
      prefix[i + C + 1] -= 1;
    }

    for (int i = A; i <= B + C; i++) {
      prefix[i] = prefix[i] + prefix[i - 1];
    }
    for (int i = A; i <= B + C; i++) {
      prefix[i] = prefix[i] + prefix[i - 1];
    }
    ll ans = 0;
    for (int i = C; i <= D; i++) {
      // for i is the third edge, find total amount for first + second bigger
      // than it
      if (i < B + C) ans += (ll)(prefix[B + C] - prefix[i]);
    }

    cout << ans << endl;
  }
}