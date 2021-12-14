#include <iostream>
#include <vector>

const int MAX = 1e4 + 5;
int x[MAX], y[MAX];

bool visited[MAX];
int n, k, r;
using namespace std;

// still not 內化 about how the func could do

int dst2(int a, int b) {
  return (x[a] - x[b]) * (x[a] - x[b]) + (y[a] - y[b]) * (y[a] - y[b]);
}
int dfs(int now, int len) {
  visited[now] = true;
  int res = 1;
  for (int i = 0; i < len; i++) {
    if (!visited[i] && dst2(now, i) <= r * r) res += dfs(i, len);
  }
  return res;
}

int main() {
  //   freopen("input.txt", "r", stdin);
  int t;
  cin >> t;

  while (t--) {
    cin >> n >> r >> k;

    for (int i = 0; i < n; i++) {
      cin >> x[i] >> y[i];
      visited[i] = false;
    }
    int less = 0, greql = 0;
    for (int i = 0; i < n; i++) {
      if (visited[i]) continue;
      int group_num = dfs(i, n);
      if (group_num >= k)
        greql++;
      else
        less++;
    }
    cout << less << " " << greql << endl;
  }
}