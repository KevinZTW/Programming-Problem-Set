#include <iostream>
#include <queue>
#include <vector>
/*
Input: graph = [[1,2],[3],[3],[]]
Output: [[0,1,3],[0,2,3]]
Explanation: There are two paths: 0 -> 1 -> 3 and 0 -> 2 -> 3.
*/
using namespace std;
class Solution {
 public:
  vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
    vector<int> path;
    dfs(graph, path, 0);
    return ans;
  }
  void dfs(vector<vector<int>>& graph, vector<int>& path, int i) {
    path.push_back(i);
    if (i == graph.size() - 1) ans.push_back(path);
    for (int j = 0; j < graph[i].size(); j++) {
      dfs(graph, path, graph[i][j]);
    }
    path.pop_back();
  }
  queue<int> q;
  vector<vector<int>> ans;
};

int main() {
  freopen("input.txt", "r", stdin);
  vector<vector<int>> graph;
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    int c;
    int num;
    cin >> c;
    vector<int> v;
    for (int i = 0; i < c; i++) {
      cin >> num;
      v.push_back(num);
    }
    graph.push_back(v);
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < graph[i].size(); j++) {
      cout << graph[i][j] << ", ";
    }
    cout << endl;
  }
  Solution s;

  auto ans = s.allPathsSourceTarget(graph);
  for (int i = 0; i < ans.size(); i++) {
    for (int j = 0; j < ans[i].size(); j++) {
      cout << ans[i][j] << " ";
    }
    cout << endl;
  }
}