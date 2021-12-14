#include <iostream>
#include <set>
#include <vector>

using namespace std;

class Solution {
 public:
  struct Node {
    Node(int a, int b) : i(a), j(b) {}
    int i;
    int j;
  };

  int DP(int i, int j, vector<vector<char>>& board,
         vector<vector<int>>& visited, vector<vector<Node>>& parent) {}

  void solve(vector<vector<char>>& board) {
    vector<vector<Node>> parent;
    vector<vector<int>> visited;
    int size = board.size();
    // init
    for (int i = 0; i < size; i++) {
      vector<int> row;
      vector<Node> row2;
      for (int j = 0; j < size; i++) {
        row.push_back(0);
        row2.push_back(Node(-1, -1));
      }
      visited.push_back(row);
      parent.push_back(row2);
    }
    for (int i = 0; i < size; i++) {
      for (int j = 0; j < size; i++) {
        if (visited[i][j]) continue;
        visited[i][j] = true;
        // true means reach the edge
        if (!DP(i, j, board, visited, parent)) {
                }
      }
    }
  }
};