#include <algorithm>
#include <iostream>
#include <map>
#include <set>
using namespace std;

void printSet(set<int> s) {
  auto it = s.begin();
  if (it == s.end()) return;
  for (; it != prev(s.end()); it++) {
    cout << *it << " ";
  }
  cout << *it << endl;
}

void range_erase(set<int> &s, int l, int r) {
  // could use
  // low = s.lower_bound(l);
  // high = s.high_bound(r);
  // s.erase(low, high);
  if (s.begin() == s.end()) return;
  for (auto it = s.begin(); it != s.end();) {
    if (*it > r)
      break;

    else if (*it >= l && *it <= r) {
      it = s.erase(it);
    }

    else
      it++;
  }
}
int main(void) {
  freopen("input.txt", "r", stdin);
  int n;

  set<int> mySet;
  scanf("%d", &n);

  while (n--) {
    string instruction;
    cin >> instruction;
    if (instruction == "range_erase") {
      int l, r;
      cin >> l >> r;
      //   cout << "l:" << l << "r:" << r << endl;

      range_erase(mySet, l, r);
    } else if (instruction == "print") {
      printSet(mySet);
    } else if (instruction == "insert") {
      int num;
      cin >> num;
      //   cout << "insert:" << num << endl;
      mySet.insert(num);
    } else if (instruction == "min") {
      if (mySet.begin() != mySet.end()) cout << *mySet.begin() << endl;
    }
  }
}