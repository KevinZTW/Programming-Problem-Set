#include <iostream>
#include <queue>
#include <vector>
#define MAX_N (int)1e3 + 5
#define F first
#define S second
using namespace std;
queue<pair<int, int>> q;
vector<vector<char>> store(MAX_N);
int n, m;
int enemy_amount = 0;
int ans;
int visited[MAX_N][MAX_N];
const int dx[] = {1, -1, 0, 0};
const int dy[] = {0, 0, 1, -1};

void bfs() {
  while (!q.empty()) {
    // TA 提醒要記住自己設下的規則
    auto now = q.front();
    q.pop();
    auto dist = q.front();
    q.pop();
    if (visited[now.F][now.S]) continue;
    visited[now.F][now.S] = dist.F;
    if (store[now.F][now.S] == 'T') {
      enemy_amount--;
    }
    if (enemy_amount == 0) ans = dist.F;

    for (int i = 0; i < 4; i++) {
      int nx = now.F + dx[i], ny = now.S + dy[i];
      // nx, ny out of place
      if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
      // exclude visited & the people
      if (visited[nx][ny] || store[nx][ny] == 'C') continue;
      q.push({nx, ny});
      q.push({dist.F + 1, 0});
    }
  }
}

int main() {
  //   freopen("input.txt", "r", stdin);
  int start_i, start_j;
  cin >> n >> m;

  for (int i = 0; i < m; i++) store[i] = vector<char>(m);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> store[i][j];
      if (store[i][j] == 'T') enemy_amount++;
      if (store[i][j] == 'I') {
        start_i = i;
        start_j = i;
      }
    }
  }
  q.push({start_i, start_j});
  q.push({0, 0});
  bfs();
  if (ans == 0)
    cout << ans << endl;
  else
    cout << -1 << endl;
}