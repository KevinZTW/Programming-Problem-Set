#include <iostream>
#include <vector>

using namespace std;

int enemy_number = 0;
int max_distance = 0;
void DP(vector<vector<char>> &maze, int i, int j, int distance) {
  if (enemy_number == 0) return;
  if (distance > max_distance && maze[i][j] == 'T') max_distance = distance;

  if (maze[i][j] == 'T') {
    enemy_number--;
  }
  maze[i][j] = 'V';
  if (j + 1 < maze.size() && maze[i][j + 1] != 'C' && maze[i][j + 1] != 'V')
    DP(maze, i, j + 1, distance + 1);
  if (j - 1 >= 0 && maze[i][j - 1] != 'C' && maze[i][j - 1] != 'V')
    DP(maze, i, j - 1, distance + 1);
  if (i + 1 < maze.size() && maze[i + 1][j] != 'C' && maze[i + 1][j] != 'V')
    DP(maze, i + 1, j, distance + 1);
  if (i - 1 >= 0 && maze[i - 1][j] != 'C' && maze[i - 1][j] != 'V')
    DP(maze, i - 1, j, distance + 1);
}

int main() {
  freopen("input.txt", "r", stdin);
  int row, col, startRow, startCol;
  char c;
  cin >> row >> col;
  vector<vector<char>> maze;
  for (int i = 0; i < row; i++) {
    vector<char> tmp;
    for (int j = 0; j < col; j++) {
      cin >> c;
      if (c == 'I') {
        startRow = i;
        startCol = j;
      } else if (c == 'T') {
        enemy_number++;
      }
      tmp.push_back(c);
    }
    maze.push_back(tmp);
  }
  DP(maze, startRow, startCol, 0);

  if (enemy_number == 0)
    cout << max_distance << endl;
  else
    cout << -1 << endl;
}