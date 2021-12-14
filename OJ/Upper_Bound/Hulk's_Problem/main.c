#include <stdio.h>
#include <stdlib.h>

int arr[(int)(1e5 + 1)];

int cmp(const void *a, const void *b) {
  int ia = *(int *)a, ib = *(int *)b;
  if (ia > ib)
    return 1;
  else if (ia == ib)
    return 0;
  else
    return -1;
}

int find_upper(int *arr, int num, int target) {
  int l = 0, r = num;
  while (l < r) {
    int mid = (l + r) / 2;
    if (arr[mid] > target)
      r = mid;
    else
      l = mid + 1;
  }
  return r;
}

int find_lower(int *arr, int num, int target) {
  int l = 0, r = num;
  while (l < r) {
    int mid = (l + r) / 2;
    if (arr[mid] >= target)
      r = mid;
    else
      l = mid + 1;
  }
  return r;
}

int main(void) {
  //   freopen("input.txt", "r", stdin);
  int n, q;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) scanf("%d", &arr[i]);

  qsort(arr, n, sizeof(int), cmp);

  scanf("%d", &q);
  int query;
  for (int i = 0; i < q; i++) {
    scanf("%d", &query);
    printf("%d\n", find_upper(arr, n, query) - find_lower(arr, n, query));
  }
}