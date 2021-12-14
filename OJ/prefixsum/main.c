#include <stdio.h>
#include <stdlib.h>

int data[(int)(1e5)];
int prefix[3000][(int)(1e5)];

int main(void) {
  freopen("input.txt", "r", stdin);
  int n, q;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d", &data[i]);
  }

  int num = n;
  for (int i = 1; i <= n; i++) {
    // build prefixSum
    for (int j = 1; j <= num; j++) {
      if (j & 1)
        prefix[i][j] = prefix[i][j - 1] - data[j - 1];
      else
        prefix[i][j] = prefix[i][j - 1] + data[j - 1];
    }

    // build next level array
    for (int i = 0; i < num - 1; i++) {
      data[i] = data[i + 1] - data[i];
    }
    num--;
  }
  num = n;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= num; j++) {
      printf("%d ", prefix[i][j]);
    }
    puts("");
    num--;
  }

  scanf("%d", &q);
  while (q--) {
    int query;
    scanf("%d", &query);
  }
}