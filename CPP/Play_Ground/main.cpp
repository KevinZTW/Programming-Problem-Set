// #include <iostream>
// #include <map>
// #include <queue>
// #include <set>
// #include <vector>

// const int MAX = 1e6 + 5;

// using namespace std;

// map<string, string> names;
// vector<pair<int, int>> vec;
// queue<pair<int, int>> q;
// map<int, vector<queue<pair<string, string>>>> store;

// int main() {
//   cout << "hell0" << endl;
//   cout << names["kevin"] << endl;

//   vec.push_back({6, 2});
//   q.push({2, 2});
//   q.push({11, 0});

//   cout << q.front().first << endl;
//   cout << q.back().first << endl;
// }

/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>
#include <stdlib.h>
typedef struct _Node {
  int val;
  struct _Node *next;
} Node;

int main(void) {
  Node **pp;
  Node *p, *head = NULL;
  int i;
  printf("Part 1:\n");
  for (i = 3; i > 0; --i) {
    p = (Node *)malloc(sizeof(Node));
    p->val = i;
    p->next = head;
    head = p;
  }
  p = head;
  while (p) {
    printf("%p: %d | %p | %p\n", p, p->val, &(p->next), p->next);
    p = p->next;
  }
  pp = &head;
  // printf("%p\n", pp);
  p = head;
  // printf("head's add: %p\n", &head);
  // printf("Part 2:\n");
  // printf("%p\n", p);
  // printf("%p\n", *pp);
  Node **k = &head;
  while (p) {
    // printf("%d\n", p->val);
    if (p->val == 2) *pp = p->next;
    pp = &p->next;
    // printf("%p\n", pp);
    p = p->next;
  }
  // printf("head's add: %p\n", head->val);
  // printf("Part 3:\n");

  p = head;

  while (p) {
    printf("%p: %d | %p\n", p, p->val, p->next);
    p = p->next;
  }
  return 0;
}