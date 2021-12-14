#include <iostream>
#include <set>

struct Item {
  Item(int w, int v, int a);
  int weight;
  int value;
};

using namespace std;

void DP(set<Item> items) { int }

// weight   value     amount
// 10       100         3
// 100       30         20
// 40       60           5
int main(void) {
  set<Item> items{Item(10, 100, 3), Item(30, 30, 20), Item(40, 60, 5)};
}