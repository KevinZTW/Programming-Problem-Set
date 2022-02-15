#include <iostream>
#include <set>
using namespace std;
int main() {
  freopen("input.txt", "r", stdin);
  int L = 0, R = 0;
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    char c;
    cin >> c;
    if (c == 'L')
      L++;
    else
      R++;
  }
  //   set<int> ans;
  // take i# of L
  //   for (int i = 0; i <= L; i++) {
  //     for (int j = 0; j <= R; j++) {
  //       ans.insert(j - i);
  //     }
  //   }
  cout << R + L << endl;
}