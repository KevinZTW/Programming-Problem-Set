#include <cstring>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

const int MAX = 2003;
int group;
int visited[MAX] = {};
int vocab[MAX] = {};

void DFS(int i, int n) {
  visited[i] = 1;
  for (int j = 0; j < n; j++) {
    if (i == j) continue;
    if (!visited[j] && ((vocab[i] & vocab[j]) != 0)) DFS(j, n);
  }
}

int main() {
  //   freopen("input.txt", "r", stdin);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;

    // reset global data
    group = 0;
    memset(visited, 0, sizeof(visited));
    memset(vocab, 0, sizeof(visited));

    for (int i = 0; i < n; i++) {
      string input;
      cin >> input;

      for (int j = 0; j < input.size(); j++) {
        int k = input[j] - 'a';
        vocab[i] = vocab[i] | (1 << k);
      }
    }

    for (int i = 0; i < n; i++) {
      if (!visited[i]) {
        group++;
        DFS(i, n);
      }
    }
    cout << group << endl;
  }
}