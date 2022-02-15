#include <cstring>
#include <iostream>
#include <string>

const int MAXN = 2026 + 1;

int graph[MAXN][MAXN];
int visited[MAXN];

using namespace std;

void DFS(int i, int n) {
  // cout << " " << i << endl;
  // i is index before adjustment
  visited[i] = 1;
  for (int j = 0; j < n + 26; j++) {
    // go through all nodes

    if (i == j) continue;
    if (!visited[j] && graph[i][j]) {
      DFS(j, n);
    }
  }
}

int main() {
  // freopen("input.txt", "r", stdin);
  int t;
  cin >> t;
  while (t--) {
    memset(graph, 0, sizeof(graph));
    memset(visited, 0, sizeof(visited));

    int n;
    cin >> n;

    string str;
    for (int i = 0; i < n; i++) {
      cin >> str;
      for (int j = 0; j < str.size(); j++) {
        int character = str[j] - 'a';
        graph[i + 26][character] = 1;
        graph[character][i + 26] = 1;
      }
    }
    int ans = 0;
    for (int i = 26; i < 26 + n; i++) {
      if (!visited[i]) {
        // cout << "visit" << i << endl;
        ans++;
        DFS(i, n);
      }
    }
    cout << ans << endl;
  }
}