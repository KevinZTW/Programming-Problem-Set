#include <iostream>
#include <vector>

struct Item {
  Item(int w, int v, int a);
  int weight;
  int value;
};

using namespace std;

void DP(vector<Item> items) { return; }

// weight   value     amount
// 10       100         3
// 100       30         20
// 40       60           5
int main(void) {
  vector<Item> items{Item(10, 100, 3), Item(30, 30, 20), Item(40, 60, 5)};
}