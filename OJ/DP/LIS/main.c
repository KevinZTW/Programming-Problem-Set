#include <stdio.h>
#include <stdlib.h>

int arr[(int)(1e6)];

int main(void) {
  int n;
  while (~scanf("%d", &n)) {
    for (int i = 0; i < n; i++) {
      scanf("%d", &arr[i]);
    }
  }
}