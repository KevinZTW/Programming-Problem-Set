// Practice vector, set
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <vector>
using namespace std;
struct Node {
 public:
  Node(int a, int b) : idx{a}, val{b} {};
  int idx;
  int val;

  bool operator<(const Node &n) const {
    if (val < n.val)
      return true;
    else if (val > n.val)
      return false;
    else if (idx < n.idx)
      return true;
    else
      return false;
  }
};

int main() {
  //   freopen("input1.txt", "r", stdin);
  int n;
  int num;
  cin >> n;
  string instruct;
  vector<int> v;
  set<Node> s;

  while (n--) {
    cin >> instruct;

    if (instruct == "max") {
      if (s.size() == 0) continue;
      cout << s.rbegin()->val << " " << s.rbegin()->idx << endl;
    } else if (instruct == "find") {
      cin >> num;
      if (s.size() == 0) continue;
      if (s.size() < n) continue;
      cout << v[num - 1] << endl;
    } else if (instruct == "pop_back") {
      if (s.size() == 0) continue;
      s.erase(Node{(int)v.size(), *v.rbegin()});
      v.pop_back();
    } else if (instruct == "push_back") {
      cin >> num;
      v.push_back(num);
      s.insert(Node{(int)v.size(), num});
    } else if (instruct == "min") {
      if (s.size() == 0) continue;
      cout << s.begin()->val << " " << s.begin()->idx << endl;
    }
  }
}