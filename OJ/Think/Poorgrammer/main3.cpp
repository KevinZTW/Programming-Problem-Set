#include <iostream>
#include <vector>

using namespace std;

int n, goal;
vector<int> coffee;

int get_code_gen(int day) {
  // for only i day how many code ?
  int code_gen = 0;
  int cup = 0;
  while (cup < n) {
    int deduct = cup / day;
    int power = coffee[cup] - deduct;
    if (power < 0) break;
    code_gen += power;
    cup++;
  }
  return code_gen;
}

int lower_bound() {
  int l = 1, r = n + 1;
  while (l < r) {
    int mid = (l + r) / 2;
    int outcome = get_code_gen(mid);
    if (outcome >= goal)
      r = mid;
    else
      l = mid + 1;
  }
  return r;
}

int main() {
  //   freopen("input.txt", "r", stdin);
  int t;
  cin >> t;
  while (t--) {
    cin >> n >> goal;
    coffee = vector<int>(n + 10000);

    for (int i = 0; i < n; i++) {
      cin >> coffee[i];
    }

    int days = lower_bound();

    if (days > n)
      cout << -1 << endl;
    else
      cout << days << endl;
  }
}