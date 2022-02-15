#include <cstring>
#include <iostream>
#include <string>

using namespace std;

int graph[2027][2027];
int visited[2027];

void DFS(int i, int n) {
  visited[i] = 1;
  for (int j = 0; j < 26 + n; j++) {
    if (i == j) continue;
    if (!visited[j] && graph[i][j]) DFS(j, n);
  }
}

int main() {
  //   freopen("input.txt", "r", stdin);
  int t;
  char num[1001];
  cin >> t;
  while (t--) {
    memset(graph, 0, sizeof(graph));
    memset(visited, 0, sizeof(visited));
    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
      cin >> num;
      int id = 0;
      while (num[id] != '\0') {
        int ch = num[id++] - 'a';
        graph[ch][i + 26] = 1;
        graph[i + 26][ch] = 1;
      }
    }
    int group = 0;
    for (int i = 26; i < n + 26; i++) {
      if (!visited[i]) {
        group++;
        DFS(i, n);
      }
    }
    cout << group << endl;
  }
}