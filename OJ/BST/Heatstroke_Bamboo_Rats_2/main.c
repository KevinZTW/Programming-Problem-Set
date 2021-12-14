#include <stdio.h>

typedef struct _NODE {
  int level;
  struct _NODE *left_child, *right_child;
} Node;

#define left left_child
#define right right_child

void build_tree(Node **now, int *arr, int l, int r) {
  if (l > r) {
    (*now) = NULL;
    return;
  };
  (*now) = (Node *)malloc(sizeof(Node));
  int mid = (l + r) / 2;
  (*now)->level = arr[mid];
  // why in here is mid - 1, and upper_bound it's mid?
  build_tree(&(*now)->left, arr, l, mid - 1);
  build_tree(&(*now)->right, arr, mid + 1, r);
  return;
}

int query_heatstroke(Node *now, int x) {
  if (now == NULL)
    return 0;
  else if (x == now->level)
    return 1;
  else if (x > now->level)
    return query_heatstroke(now->right, x);
  else
    return query_heatstroke(now->left, x);
}

void eat_rat(Node **root, int x) {
  while ((*root)->level != x) {
    if ((*root)->level > x)
      root = &(*root)->left;
    else
      root = &(*root)->right;
  }
  if ((*root)->left == NULL && (*root)->right == NULL) {
    free(*root);
    (*root) = NULL;
  }
}
void buy_rat(Node **root, int x) {
  if ((*root) == NULL) {
    (*root) = (Node *)malloc(sizeof(Node));
    (*root)->level = x;
    (*root)->left = (*root)->right = NULL;
  } else if ((*root)->level > x)
    buy_rat(&(*root)->left, x);
  else
    buy_rat(&(*root)->right, x);
}
