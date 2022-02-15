#include <iostream>
#include <vector>

using namespace std;

struct Guard {
  int l, r, idx;
};
const int MAXN = 5001;
int main() {
  //   freopen("input.txt", "r", stdin);
  int t;
  cin >> t;
  while (t--) {
    int n, q;
    cin >> n >> q;
    vector<Guard> v;
    vector<int> wall(n + 1, 0);
    for (int i = 0; i < q; i++) {
      int l, r;
      cin >> l >> r;
      for (int j = l; j <= r; j++) wall[j]++;
      v.push_back(Guard{l, r, i});
    }
    int max = 0;

    for (auto i : v) {
      int count = 0;
      Guard pick1 = i;
      vector<int> temp = wall;

      for (int j = pick1.l; j <= pick1.r; j++) temp[j]--;
      // count guarded number after pick 1 person out
      for (int j = 1; j <= n; j++)
        if (temp[j] > 0) count++;
      // build the loss prefixsum
      vector<int> prefix(n + 1, 0);
      for (int k = 1; k <= n; k++) {
        prefix[k] = prefix[k - 1] + ((temp[k] == 1) ? 1 : 0);
      }
      int min_loss = 1e9;
      for (auto g : v) {
        Guard pick2 = g;
        if (pick1.idx == pick2.idx) continue;
        int loss = prefix[pick2.r] - prefix[pick2.l - 1];
        if (loss < min_loss) min_loss = loss;
      }
      count -= min_loss;
      if (count > max) max = count;
    }
    cout << max << endl;
  }
}