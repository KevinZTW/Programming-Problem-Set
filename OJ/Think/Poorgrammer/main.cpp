/*
原本都在想一杯咖啡要不要今天喝掉，不要的話天數加一

解 : 找出給定天數可以完成的數量

注意 :
    - lower_bound 天數、咖啡數的 index 有點錯亂要重想一遍
    - 特判
        get_code_num(){
            if (day == 0) return 0;
        }

*/

#include <iostream>
const int MAXN = 2e5 + 1;
int store[MAXN];
int n, m;

using namespace std;

int get_code_num(int day) {
  if (day == 0) return 0;
  int res = 0, add = 0, id = 0;
  while (id < n) {
    int deduct = id / day;
    add = store[id++] - deduct;
    if (add <= 0) break;
    res += add;
  }
  return res;
}

int lower_bound(int target) {
  int l = 0, r = n + 1;
  while (l < r) {
    int mid = (l + r) / 2;
    if (get_code_num(mid) < target) {
      l = mid + 1;
    } else {
      r = mid;
    }
  }
  return r;
}

int main() {
  //   freopen("input.txt", "r", stdin);
  int t;
  cin >> t;
  while (t--) {
    cin >> n >> m;
    for (int i = 0; i < n; i++) cin >> store[i];
    int ans = lower_bound(m);

    if (ans <= n)
      cout << ans << endl;
    else
      cout << -1 << endl;
  }
}
