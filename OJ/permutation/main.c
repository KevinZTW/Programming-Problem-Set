#include <stdio.h>
#include <stdlib.h>

int picked[5];
int data[5];

void permutate(int n, int level) {
  if (n == level) {
    for (int i = 0; i < n; i++) {
      printf("%d, ", data[i]);
    }
    puts("");
    return;
  }

  for (int i = 0; i < n; i++) {
    if (picked[i]) continue;
    picked[i] = 1;
    data[level] = i + 1;
    permutate(n, level + 1);
    picked[i] = 0;
  }

  return;
}

int main(void) { permutate(5, 0); }