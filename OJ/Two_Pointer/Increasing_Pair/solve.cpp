#include <cstring>

#include "data.hpp"
#define ll long long int

ll count = 0;

int cmp(const void *a, const void *b) {
  ll tmpb = *(int *)b, tmpa = *(int *)a;
  // printf("cmp %lld %lld answer : %lld\n", *(ll *)b, *(ll *)a,
  //        *(ll *)b - *(ll *)a);
  // printf("tmp cmp %lld %lld answer : %lld\n", tmpb, tmpa, tmpb - tmpa);
  if ((tmpb - tmpa) < 0) return -1;
  if ((tmpa - tmpb) < 0) return 1;
  return 0;
}

void countPair(int *nums, int start, int mid, int end) {
  int l = start, r = mid + 1;
  while (l <= mid && r <= end) {
    ll left = nums[l], right = nums[r];
    // printf("cmp left : %lld left*2: %lld <= right:%lld ans:%d\n", left,
    //        left * 2, right, left * 2 <= right);
    if (left * 2 <= right) {
      count += (mid - l + 1);
      r++;
    } else {
      l++;
    }
  }
  qsort(&nums[start], end - start + 1, sizeof(int), cmp);
  // for (int i = start; i <= end; i++) {
  //   printf("%d ", nums[i]);
  // }
  // puts("");
  return;
}

void mergesort(int *nums, int start, int end) {
  if (start == end) return;

  int mid = (start + end) / 2;
  mergesort(nums, start, mid);
  mergesort(nums, mid + 1, end);
  countPair(nums, start, mid, end);
  return;
}

extern void solve(tTestData *t) {
  int caseNum = t->testcase_num;

  for (int i = 0; i < caseNum; i++) {
    count = 0;
    int num = t->seq_num[i];
    int *seq = (int *)malloc(sizeof(int) * num);
    memcpy(seq, t->seq[i], sizeof(int) * num);

    mergesort(seq, 0, num - 1);
    printf("%lld\n", count);
    free(seq);
  }
}

// Add below for local testing
// ============================
int main() {
  tTestData t;
  if (!load_data(&t)) return 1;
  solve(&t);
  return 0;
}
//==============================