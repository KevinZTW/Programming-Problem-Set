#include <iostream>

using namespace std;
const int MAXN = 3e3 + 5;
int edge[MAXN][MAXN];
int visited[MAXN];
int ans;

/*
    採用深度搜尋，從任何一個節點開始走，掃一輪 edge
    如果自己跟任何一個節點有連結就走過去，為了避免走回頭路變成無限循環，用了一個
    prev 記下自己從哪裡來的 這樣操作如果在沒有
   cycle的樹應該是會每個節點都剛好踩過一次(?)
    但今天有循環的關係所以在循環的地方那個節點就會被踩兩次
*/

void dfs(int now, int prev, int n) {
  visited[now]++;
  if (visited[now] > 1) {
    ans = now;
    return;
  }
  for (int i = 0; i < n; i++) {
    if (edge[now][i] == 1 && i != prev) {
      dfs(i, now, n);
    }
  }
}

int main() {
  freopen("input.txt", "r", stdin);
  int n;
  cin >> n;
  int x, y;
  for (int i = 0; i < n; i++) {
    cin >> x >> y;
    edge[x][y] = edge[y][x] = 1;
  }
  // 隨邊挑一個節點作起點，因為 input 說最大到 3000 (?) 所以 prev
  // 設為絕對不會存在的 3001
  dfs(x, 3001, n);
  cout << ans << endl;
}