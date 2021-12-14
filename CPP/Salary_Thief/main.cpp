#include <sys/shm.h>
#include <sys/time.h>

#include <iostream>
#include <string>
using namespace std;
const int MOD = 1e9 + 7;
int main() {
  freopen("input.txt", "r", stdin);
  //   freopen("output.txt", "w", stdout);
  int n;
  cin >> n;
  while (n--) {
    int x;
    string str;
    cin >> x >> str;
    long long int count, back, length, partion;
    length = str.length();
    back = length - 1;

    for (int i = 1; i <= x; i++) {
      int times = (str[i - 1] - '0');
      //   cout << "count:" << count << "i: " << i << "times:" << times << endl;
      partion = length - i;
      back = (times * back - 1) % MOD;

      if (length < 1e6) {
        string tmp = str.substr(i, length);
        for (int j = 1; j < times; j++) {
          str += tmp;
          length += partion;

          if (length > 1e6) break;
        }
      }
    }
    count = (back + x + 1) % MOD;
    cout << count << endl;
  }
}
