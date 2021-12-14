#include <stdio.h>
#include <stdlib.h>
#define MOD (int)(1e9 + 7)
#define ll long long int

typedef struct _Node {
  int id, val;
} Node;

Node arr[(int)1e6 + 1];

int cmp(const void* a, const void* b) {
  if (((Node*)a)->val > ((Node*)b)->val)
    return 1;
  else if (((Node*)a)->val < ((Node*)b)->val)
    return -1;
  else if (((Node*)a)->id > ((Node*)b)->id)
    return 1;
  else
    return -1;
}

int fast_pow(int num, int p) {
  if (p == 1) return num;
  ll tmp = fast_pow(num, p / 2) % MOD;
  if (p & 1) return tmp * tmp * num % MOD;
  return tmp * tmp % MOD;
}

int get_ans(int num) {
  if (num & 1)
    return 0;
  else
    return fast_pow(2, num / 2);
}
int binary_search_lower(Node* arr, int n, int target) {
  int l = 0, r = n - 1;
  while (l < r) {
    int mid = (l + r) / 2;
    if (arr[mid].val >= target)
      r = mid;
    else
      l = mid + 1;
  }
  if (arr[l].val == target) return arr[l].id;

  return 0;
}

int main(void) {
  //   freopen("input.txt", "r", stdin);
  int n, q;
  while (~scanf("%d %d", &n, &q)) {
    int num;
    for (int i = 0; i < n; i++) {
      scanf("%d(/`A`)/ ~I__I ", &num);
      int ans = get_ans(num);

      arr[i].id = i + 1;
      arr[i].val = ans;
    }
    // for (int i = 0; i < n; i++) {
    //   printf("%d ", arr[i].val);
    // }
    // printf("\n");
    qsort(arr, n, sizeof(Node), cmp);
    // for (int i = 0; i < n; i++) {
    //   printf("%d ", arr[i].val);
    // }
    // printf("\n");
    while (q--) {
      int query;
      scanf("%d", &query);
      int id = binary_search_lower(arr, n, query);
      if (id)
        printf("%d\n", id);
      else
        printf("Go Down Chicken 404\n");
    }
  }
}