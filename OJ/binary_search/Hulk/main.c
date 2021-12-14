#include <stdio.h>
#include <stdlib.h>

int arr[(int)(1e5 + 1)];

int cmp(const void* a, const void* b) { return *(int*)a - *(int*)b; }

int find_upper(int* arr, int val, int l, int r) {
  // printf("%d %d\n", l, r);
  if (l == r || l > r) return r;
  int mid = (l + r) / 2;
  if (arr[mid] <= val)
    //就算找到了還是把左邊收過來
    return find_upper(arr, val, mid + 1, r);
  else
    return find_upper(arr, val, l, mid);
}

int find_lower(int* arr, int val, int l, int r) {
  // printf("%d %d\n", l, r);
  if (l == r || l > r) return r;
  int mid = (l + r) / 2;
  if (arr[mid] >= val)
    //就算找到了還是把右邊收過來
    return find_lower(arr, val, l, mid);
  else
    return find_lower(arr, val, mid + 1, r);
}

int main(void) {
  // freopen("input.txt", "r", stdin);
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
    int upper = find_upper(arr, query, 0, n);
    int lower = find_lower(arr, query, 0, n);
    int ans = upper - lower;
    printf("%d\n", ans);
  }
}