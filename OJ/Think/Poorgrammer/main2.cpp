#include <iostream>
#include <vector>

using namespace std;
int main() {
  //   freopen("input.txt", "r", stdin);
  int t;
  cin >> t;
  while (t--) {
    int n, goal;
    vector<int> coffee(n + 1);
    cin >> n >> goal;

    for (int i = 0; i < n; i++) {
      cin >> coffee[i];
    }
    int ans = -1;
    for (int i = 1; i <= n; i++) {
      // for only i day how many code ?
      int code_gen = 0;
      int cup = 0;
      while (cup < n) {
        int deduct = cup / i;
        int power = coffee[cup] - deduct;
        if (power < 0) break;
        code_gen += power;
        cup++;
      }
      if (code_gen >= goal) {
        ans = i;
        break;
      }
    }
    cout << ans << endl;
  }
}