#include <stdio.h>
#include <stdlib.h>

int arr[(int)(1e5 + 1)];

int cmp(const void* a, const void* b) { return *(int*)a - *(int*)b; }

int upper_bound_bst(int* arr, int n, int target) {
  // r = n 是因為超出 index 的狀況
  int l = 0, r = n;
  while (l < r) {
    int mid = (l + r) / 2;
    if (arr[mid] <= target)
      l = mid + 1;  // 2 2 4 5 6 7 9
    else
      r = mid;  //符合條件，但還不知道是不是最小，但先縮過來
  }
  return r;
}

int lower_bound_bst(int* arr, int n, int target) {
  // r = n 是因為超出 index 的狀況
  int l = 0, r = n;
  while (l < r) {
    int mid = (l + r) / 2;
    //這邊修改 r 什麼時候收進來?
    if (arr[mid] < target)
      l = mid + 1;
    else
      r = mid;
  }
  return r;
}

int main(void) {
  //   freopen("input.txt", "r", stdin);
  int n, q;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d", &arr[i]);
  }
  // sort arr
  qsort(arr, n, sizeof(int), cmp);
  scanf("%d", &q);
  while (q--) {
    int query;
    scanf("%d", &query);
    int upper = upper_bound_bst(arr, n, query);
    int lower = lower_bound_bst(arr, n, query);
    int ans = upper - lower;
    printf("%d\n", ans);
  }
}