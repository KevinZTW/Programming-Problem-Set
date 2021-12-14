#include <cstdlib>
#include <iostream>

using namespace std;
int main() {
  int max = (int)(1e9 + 1);
  freopen("test.txt", "w", stdout);
  int n = (int)(2e5);
  cout << n << " " << (int)(10e9) << endl;
  for (int i = 0; i < n; i++) {
    cout << rand() % max << " ";
  }
}