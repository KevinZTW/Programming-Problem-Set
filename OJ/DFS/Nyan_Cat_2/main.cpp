#include <iostream>
#include <map>
#include <cstring>

int t, n, r, k;
int visited[(int)(1e4 + 1)], x[(int)(1e4 + 1)], y[(int)(1e4 + 1)];

int group_id;
using namespace std;
map<int, int> group;
int dst(int i, int j) {
  return (x[i] - x[j]) * (x[i] - x[j]) + (y[i] - y[j]) * (y[i] - y[j]);
}

int DP(int now) {
  int res = 1;
  visited[now] = 1;
  for (int j = 0; j < n; j++) {
    if (!visited[j] && dst(now, j) <= r * r) {
      res += DP(j);
    }
  }
  return res;
}

int main() {
  // freopen("input.txt", "r", stdin);

  cin >> t;
  while (t--) {
    cin >> n >> r >> k;
    group_id = 0;
    memset(visited, 0, n * sizeof(int));
    group.clear();

    for (int i = 0; i < n; i++) cin >> x[i] >> y[i];
    // dfs
    for (int i = 0; i < n; i++) {
      if (!visited[i]) {
        int count = DP(i);
        group[group_id++] = count;
      }
    }
    int less = 0, greater_equal = 0;
    for (auto i : group) {
      if (i.second < k)
        less++;
      else
        greater_equal++;
    }
    cout << less << " " << greater_equal << endl;
  }
}