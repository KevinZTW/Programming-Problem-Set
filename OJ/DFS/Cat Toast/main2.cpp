#include <iostream>

using namespace std;
int n, r;
int cat, blackhole;
const int MAX_IN = 1e5 + 1;
int x[MAX_IN], y[MAX_IN], visited[MAX_IN];

int dst2(int i, int j) {
  return (x[i] - x[j]) * (x[i] - x[j]) + (y[i] - y[j]) * (y[i] - y[j]);
}

int dfs(int now) {
  int res = 1;
  for (int i = 0; i < n; i++) {
    visited[now] = true;

    if (dst2(now, i) <= r * r && !visited[i]) {
      res += dfs(i);
    }
  }
  return res;
}

int main() {
  //   freopen("input.txt", "r", stdin);
  cin >> n >> r;
  for (int i = 0; i < n; i++) cin >> x[i] >> y[i];
  for (int i = 0; i < n; i++) {
    if (!visited[i]) {
      int count = dfs(i);
      if (count == 1)
        cat++;
      else
        blackhole++;
    }
  }
  cout << cat << " " << blackhole << endl;
}
