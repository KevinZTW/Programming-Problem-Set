#include <stdlib.h>

#include <iostream>
#include <set>
#include <vector>

using namespace std;
int findLower(int* arr, int n, int target);
int findUpper(int* arr, int n, int target);

int findUpper(int* arr, int n, int target) {
  int l = 0, r = n;  // 注意是 n 不是 n - 1 超出沒關係嗎 ?
  int match_idx = -1;
  //要<= 還是 < ?
  while (l < r) {
    int mid = (l + r) / 2;
    if (arr[mid] > target) {
      r = mid;
    } else {
      if (arr[mid] == target) match_idx = mid;
      l = mid + 1;
      //左邊一定要動，因為 {0,1} mid = 0, 不加 1 會停在原處，那會不會略過重要的?
      //煩喔之前想很久的忘光光
    }
  }
  /*不管有沒有找到，r 都會座落在目標位置的下一位，為什麼呢？我試圖找到規律或是
  counter example 但失敗中 {1}, 1 => 1 {1, 2, 5}, 2 => 2

   終止時 l >= r  因此必然如下 l = mid = r - 1 ?
   是否找得到 arr[l] = arr[l] = target ?
    l      r
   mid

  */

  cout << "upper r: " << r << endl;
  cout << "upper id: " << match_idx << endl;
  return match_idx;
}

int findLower(int* arr, int n, int target) {
  int l = 0, r = n;  //注意是 n 不是 n-1 超出沒關係嗎?
  int match_idx = -1;
  //要<= 還是 < ?
  while (l < r) {
    int mid = (l + r) / 2;
    if (arr[mid] >= target) {
      if (arr[mid] == target) match_idx = mid;
      r = mid;
    } else {
      l = mid + 1;
    }
  }
  return match_idx;
}

//找不到的情況，upper loewr 分別會是什麼?
//

int* searchRange(int* nums, int numsSize, int target, int* returnSize) {
  *returnSize = 2;
  int* ans = (int*)malloc(sizeof(int) * 2);

  ans[0] = findLower(nums, numsSize, target);
  ans[1] = findUpper(nums, numsSize, target);
  return ans;
}

int main() {
  int arr[] = {2, 2, 2, 2, 2, 5};
  //   int upper = findUpper(arr, 6, 22);
  //   int lower = findLower(arr, 6, 22);
  //   printf("%d\n", upper);
  //   printf("%d\n", lower);
  int size;
  int* ans = searchRange(arr, 6, 2, &size);
  printf("[%d, %d]\n", ans[0], ans[1]);
}