#include <iostream>
#include <set>
#include <vector>
using namespace std;

class Node {
 public:
  Node();
  Node(int a, int b) {
    idx = a;
    val = b;
  }
  int idx;
  int val;
  int operator<(const Node& b) const {
    if (val < b.val)
      return true;
    else if (val > b.val)
      return false;
    else if (idx < b.idx)
      return true;
    else
      return false;
  }
};

int main() {
  //   freopen("input1.txt", "r", stdin);
  int n;
  vector<int> vec;
  set<Node> dict;
  string instruct;
  cin >> n;
  while (n--) {
    cin >> instruct;
    if (instruct == "push_back") {
      int num;
      cin >> num;
      vec.push_back(num);
      dict.insert(Node(vec.size(), num));
    } else if (instruct == "pop_back") {
      if (vec.size() == 0) continue;
      dict.erase(Node(vec.size(), *vec.rbegin()));
      vec.pop_back();
    } else if (instruct == "max") {
      if (vec.size() == 0) continue;
      cout << dict.rbegin()->val << " " << dict.rbegin()->idx << endl;
    } else if (instruct == "min") {
      if (vec.size() == 0) continue;
      cout << dict.begin()->val << " " << dict.begin()->idx << endl;
    } else if (instruct == "find") {
      int num;
      cin >> num;
      if (vec.size() == 0) continue;
      if (num - 1 > vec.size()) continue;
      cout << vec[num - 1] << endl;
    }
  }
}