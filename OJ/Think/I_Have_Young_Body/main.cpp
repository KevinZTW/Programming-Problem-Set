//第一次實作失敗！
//買 2, 3  + 4 跟買 2  3,4 不同!只要調整一個小地方
// 2, 3, 4, 5, 7 建立出來的前綴和是 =>
// 2, 3, 6, 8, 13 而不是 2, 3, 7, 8, 15
//(重點在於當我沒辦法湊出 k 個的時候我應該拿大的去湊(從右邊開始湊而不是左邊))

#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
int main() {
  freopen("input.txt", "r", stdin);
  int t;
  cin >> t;
  while (t--) {
    int n, p, k;
    vector<int> product;

    cin >> n >> p >> k;
    vector<int> price(n + 1);
    for (int i = 0; i < n; i++) {
      int num;
      cin >> num;
      product.push_back(num);
    }
    sort(product.begin(), product.end());

    price[0] = 0;
    for (int i = 1; i <= n; i++) {
      if (i >= k)
        price[i] = price[i - k] + product[i - 1];
      else
        price[i] = price[i - 1] + product[i - 1];
    }

    int ans = 0;

    for (int i = 1; i <= n; i++) {
      if (price[i] <= p) ans = i;
    }
    cout << ans << endl;
  }
}