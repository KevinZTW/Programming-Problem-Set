#include <iostream>
#include <queue>
#include <vector>
using namespace std;
const int MAX = 1000;

int n, m;
int enemy_amount = 0, ans = 0;
int start_i, start_j;
queue<pair<int, int>> q;
char store[MAX][MAX];
int visited[MAX][MAX];
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

void dfs() {
  while (q.size() > 0) {
    auto now = q.front();

    q.pop();
    auto dist = q.front();
    q.pop();
    if (visited[now.first][now.second]) continue;
    visited[now.first][now.second] = dist.first;
    if (store[now.first][now.second] == 'T') {
      enemy_amount--;
      if (enemy_amount == 0) ans = dist.first;
    }
    for (int i = 0; i < 4; i++) {
      int nx = now.first + dx[i];
      int ny = now.second + dy[i];
      if (nx < 0 || nx >= n || ny < 0 || ny >= m || store[nx][ny] == 'C' ||
          visited[nx][ny])
        continue;
      q.push({nx, ny});
      q.push({dist.first + 1, 0});
    }
  }
}

int main() {
  //   freopen("input.txt", "r", stdin);
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> store[i][j];
      if (store[i][j] == 'T') enemy_amount++;
      if (store[i][j] == 'I') start_i = i, start_j = j;
    }
  }
  q.push({start_i, start_j});
  q.push({0, 0});
  dfs();

  if (enemy_amount == 0)
    cout << ans << endl;
  else
    cout << -1 << endl;
}