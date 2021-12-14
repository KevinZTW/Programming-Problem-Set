#include <iostream>
#include <map>
#include <queue>
#include <vector>
/*
Input: graph = [[1,2],[3],[3],[]]
Output: [[0,1,3],[0,2,3]]
Explanation: There are two paths: 0 -> 1 -> 3 and 0 -> 2 -> 3.
*/
using namespace std;
const int MAX = 201;
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};
pair<int, int> record[MAX][MAX];
int visited[MAX][MAX];

class Solution {
 public:
  vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
    int m = heights.size(), n = heights[0].size();
    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        auto p = dfs(i, j, m, n);
        if (p.first && p.second) {
          vector<int> tmp;
          tmp[0] = i;
          tmp[1] = j;
          ans.push_back(tmp);
        }
      }
    }
    return ans;
  }
  pair<int, int> dfs(int i, int j, int m, int n) {
    if (i < 0 || i >= m || j < 0 || j >= n) return pair<int, int>{0, 0};
    cout << "i: " << i << "j: " << j << endl;

    if (visited[i][j]) return record[i][j];
    visited[i][j] = 1;
    //<could pacific, could alantic>
    pair<int, int> p{0, 0};
    if (i == 0 || j == 0) p.first = 1;
    if (i == m - 1 || j == n - 1) p.second = 1;
    for (int k = 0; k < 4; k++) {
      // check boundary
      int nx = i + dx[k];
      int ny = j + dy[k];
      if (nx < 0 || nx >= m || ny < 0 || ny >= n) continue;
      //   cout << "   i: " << i << " j:" << j << endl;
      //   cout << "   dx[i]: " << dx[i] << " dy[i]:" << dy[i] << endl;
      cout << "   go nx: " << nx << " ny:" << ny << endl;
      auto res = dfs(nx, ny, m, n);
      if (res.first == 1) p.first = 1;
      if (res.second == 1) p.second = 1;
    }
    record[i][j] = p;
    return p;
  }
  vector<vector<int>> ans;
};

// class Solution {
//  public:
//   vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
//     vector<int> path;
//     dfs(graph, path, 0);
//     return ans;
//   }
//   void dfs(vector<vector<int>>& graph, vector<int>& path, int i) {
//     path.push_back(i);
//     if (i == graph.size() - 1) ans.push_back(path);
//     for (int j = 0; j < graph[i].size(); j++) {
//       dfs(graph, path, graph[i][j]);
//     }
//     path.pop_back();
//   }
//   queue<int> q;
//   vector<vector<int>> ans;
// };

int main() {
  freopen("input.txt", "r", stdin);
  vector<vector<int>> graph;
  int m, n;
  cin >> m >> n;

  // read data
  for (int i = 0; i < n; i++) {
    int num;
    vector<int> v;
    for (int j = 0; j < n; j++) {
      cin >> num;
      v.push_back(num);
    }
    graph.push_back(v);
  }

  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      cout << graph[i][j] << ", ";
    }
    cout << endl;
  }
  Solution s;

  auto ans = s.pacificAtlantic(graph);
  for (int i = 0; i < ans.size(); i++) {
    for (int j = 0; j < ans[i].size(); j++) {
      cout << ans[i][j] << " ";
    }
    cout << endl;
  }
}