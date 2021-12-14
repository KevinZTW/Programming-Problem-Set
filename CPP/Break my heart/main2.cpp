#include <iostream>
#include <set>
#include <string>
#include <vector>
#define LL long long int

using namespace std;
int main() {
  // freopen("input.txt", "r", stdin);
  set<int> s;
  int n;
  LL sum;
  string query;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> query;
    if (query == "insert") {
      int num;
      cin >> num;
      if (s.insert(num).second) sum += num;
    } else if (query == "print") {
      vector<int> v;
      for (auto i : s) v.push_back(i);
      for (int i = 0; i < v.size(); i++)
        cout << v[i] << ((i == v.size() - 1) ? "\n" : " ");
    } else if (query == "min") {
      if (s.empty()) continue;
      cout << *s.begin() << endl;
    } else if (query == "range_erase") {
      int l, r;
      cin >> l >> r;
      for (auto it = s.lower_bound(l); it != s.upper_bound(r); it++) sum -= *it;
      s.erase(s.lower_bound(l), s.upper_bound(r));
    } else if (query == "sum") {
      cout << sum << endl;
    }
  }
}