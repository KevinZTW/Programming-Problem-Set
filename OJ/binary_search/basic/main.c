#include <stdio.h>
#include <stdlib.h>
int arr[100];

// if any match, return the biggest match index, else return the biggest index
// that value < target val
// 1 2 3 3 5
// find 3 : 3
// find 4 : 3

// l +r /2 的特性是兩者差一的時候會等於 l 所以 mid 當作左邊的話一定要加一
//一開始的狀態是 l<r 所以我一定只能用  l >r 當終止條件，而 l > r
//想要拿到 Match 的最後一個不可能? 1333334  最後一個 3
//表示相加過頭了 因此 答案都是留在 r

int binary_upper1(int *arr, int l, int r, int val) {
  if (l == r || l > r) return r;
  int mid = (l + r) / 2;
  printf("l:%d r:%d val: %d\n", l, r, arr[mid]);

  if (arr[mid] < val)
    return binary_upper1(arr, mid + 1, r, val);
  else if (arr[mid] == val)
    return mid;
  else
    return binary_upper1(arr, l, mid, val);
}

// if any match, return the smallest match index, else return the biggest index
// that value < target val
// 1 2 3 3 5
// find 3 : 2
// find 4 : 3
int binary_lower(int *arr, int l, int r, int val) { return 1; }

int main(void) {
  freopen("input.txt", "r", stdin);
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d", &arr[i]);
  }
  int upper1 = binary_upper1(arr, 0, n - 1, 23);
  printf("index: %d, val : %d", upper1, arr[upper1]);
}