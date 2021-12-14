#include <stdio.h>
#include <stdlib.h>

int arr[(int)(1e5 + 1)];

int cmp(const void* a, const void* b) { return *(int*)a - *(int*)b; }

int find_upper_bound(int* arr, int target, int nums) {
  int l = 0, r = nums;
  while (l < r) {
    int mid = (l + r) / 2;
    if (arr[mid] > target)
      r = mid;
    else
      l = mid + 1;
  }
  return r;
}
int find_lower_bound(int* arr, int target, int nums) {
  int l = 0, r = nums;
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
  freopen("input.txt", "r", stdin);
  int n, q;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d", &arr[i]);
  }
  qsort(arr, n, sizeof(int), cmp);
  scanf("%d", &q);
  while (q--) {
    int query;
    scanf("%d", &query);
    int upper = find_upper_bound(arr, query, n);
    int lower = find_lower_bound(arr, query, n);
    int ans = upper - lower;
    printf("%d\n", ans);
  }
}