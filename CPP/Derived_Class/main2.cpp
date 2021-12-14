#include <deque>
#include <iostream>
#include <list>
#include <map>
#include <unordered_map>
#include <vector>

using namespace std;
struct Node {
  int x;
  int y;
  Node(int a, int b) : x{a}, y{b} {};
};
int main() {
  // map 用字串來查可以來記錄他的出現次數
  map<string, int> m;
  unordered_map<string, int> m2;

  //   string str;
  //   while (cin >> str) {
  //     if (m.count(str) == 0) {
  //       m[str] = 1;
  //     } else {
  //       m[str]++;
  //     }
  //     for (auto e : m) {
  //       cout << e.first << e.second << endl;
  //     }
  //   }
  // vector 蕭能比較好但是只能 Pushback
  // list
  list<int> l;
  l.push_back(2);
  l.push_front(99);
  for (auto i : l) cout << i << endl;

  deque<int> q;
  q.push_front(2);
  q.push_back(9);
  cout << q[1];

  vector<Node> v;
  //這樣就可以避免中途擴充容量，一開始就準備好空間
  v.reserve(1000);

  for (int i = 0; i < 1000; ++i) {
    // v.push_back(Node{i * 3, i * 4});
    v.emplace_back(i * 3, i * 4);
  }

  cout << v[900].y << endl;
  //但這樣產出的 Node 是在 Stack 上吧?? 晚點測試一下
}