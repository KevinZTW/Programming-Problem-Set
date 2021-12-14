#include <iostream>
#include <set>
#include <string>
#include <vector>
#define LL long long int

using namespace std;

int main() {
//   freopen("input.txt", "r", stdin);
  int n;
  LL sum = 0;
  cin >> n;
  string instruction;
  set<int> mySet;
  for (int i = 0; i < n; i++) {
    cin >> instruction;
    if (instruction == "insert") {
      int num;
      cin >> num;
      if (mySet.insert(num).second) {
        sum += num;
      }
    } else if (instruction == "min") {
      if (mySet.empty()) continue;
      cout << *mySet.begin() << endl;
    } else if (instruction == "range_erase") {
      int l, r;
      cin >> l >> r;

      for (auto it = mySet.lower_bound(l); it != mySet.upper_bound(r); it++) {
        sum -= *it;
      }
      mySet.erase(mySet.lower_bound(l), mySet.upper_bound(r));
    } else if (instruction == "print") {
      vector<int> v;
      for (auto it = mySet.begin(); it != mySet.end(); it++) {
        v.push_back(*it);
      }
      for (int i = 0; i < v.size(); i++) {
        cout << v[i] << ((i == v.size() - 1) ? "\n" : " ");
      }
    } else if (instruction == "sum") {
      cout << sum << endl;
    }
  }
}