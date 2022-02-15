#include <iostream>
#include <vector>

using namespace std;

class Guard {
 public:
  int idx;
  int l;
  int r;
};
const int MAXN = 5001;

int main() {
  //   freopen("input.txt", "r", stdin);
  int t;
  cin >> t;
  while (t--) {
    vector<int> data(MAXN);
    int n, q;
    vector<Guard> v;
    cin >> n >> q;
    for (int i = 0; i < q; i++) {
      int l, r;
      cin >> l >> r;
      v.push_back(Guard{i, l, r});
      for (int i = l; i <= r; i++) {
        data[i]++;
      }
    }
    int max = 0;
    for (auto g : v) {
      int total = 0;
      vector<int> d = data;
      for (int i = g.l; i <= g.r; i++) {
        d[i]--;
      }
      // get guarded number after minus 1 man
      for (int i = 0; i <= n; i++)
        if (d[i] > 0) total++;

      vector<int> prefix_sum(MAXN, 0);
      if (d[0] == 1) prefix_sum[0] = 1;
      for (int i = 1; i <= n; i++) {
        prefix_sum[i] = prefix_sum[i - 1] + ((d[i] == 1) ? 1 : 0);
      }

      int min_deduct = 1e9;
      for (auto g2 : v) {
        if (g2.idx == g.idx) continue;
        int deduct = prefix_sum[g2.r] - prefix_sum[g2.l - 1];
        if (deduct < min_deduct) min_deduct = deduct;
      }
      total -= min_deduct;
      if (total > max) max = total;
    }
    cout << max << endl;
  }
}