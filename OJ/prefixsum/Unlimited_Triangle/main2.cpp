#include <cstring>
#include <iostream>
#define ll long long int

using namespace std;
const int MAXN = 1e5 + 20;
int t;
int sum[MAXN];

int main() {
  //   freopen("input.txt", "r", stdin);

  cin >> t;

  while (t--) {
    int A, B, C, D;
    cin >> A >> B >> C >> D;
    memset(sum, 0, sizeof(sum));

    for (int i = A; i <= B; i++) {
      // count total how many amount for different combination (side1 , side2)
      sum[i + B] += 1;
      sum[i + C + 1] -= 1;
    }
    // get amount for each number
    for (int i = A; i <= B + C; i++) sum[i] = sum[i] + sum[i - 1];
    // get accumulated ammount
    for (int i = A; i <= B + C; i++) sum[i] = sum[i] + sum[i - 1];

    ll ans = 0;
    for (int i = C; i <= D; i++) {
      // for each side 3, get amount for possible (side 1, side 2)
      if (i < B + C) ans += (ll)(sum[B + C] - sum[i]);
    }
    cout << ans << endl;
  }
}