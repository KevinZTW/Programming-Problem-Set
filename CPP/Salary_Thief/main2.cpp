#include <iostream>
#define ll long long int

const int MAXN = 1e6;
const int MOD = 1e9 + 7;

using namespace std;
int main() {
  //   freopen("input.txt", "r", stdin);
  int n, r;

  cin >> n;
  while (n--) {
    string num;

    cin >> r >> num;
    // cout << "r:" << r << "num: " << num << endl;
    ll len = num.length(), back = num.length() - 1;
    for (int i = 0; i < r; i++) {
      ll repeat = num[i] - '0';
      back = (back * repeat) % MOD - 1;

      //   len = ((len - diff) * repeat) % MOD + diff;
      // 忘記這樣做的話 len 超過 MOD 會回到 0, len - diff < 0

      if (num.length() < MAXN) {
        string sub = num.substr(i + 1, num.length() - i - 1);
        for (int j = 1; j < repeat; j++) num += sub;
      }
    }
    cout << back + r + 1 << endl;
  }
}