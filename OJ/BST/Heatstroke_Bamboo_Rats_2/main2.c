#include <stdio.h>
#include <stdlib.h>

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
  }

  int mid = (l + r) / 2;
  (*now) = (Node *)malloc(sizeof(Node));
  (*now)->level = arr[mid];
  build_tree(&((*now)->left), arr, l, mid - 1);
  build_tree(&((*now)->right), arr, mid + 1, r);
}
int query_heatstroke(Node *now, int x) {
  if (now == NULL) return 0;
  if (now->level == x)
    return 1;
  else if (now->level > x)
    return query_heatstroke(now->left, x);
  else
    return query_heatstroke(now->right, x);
}
void eat_rat(Node **root, int x) {
  while ((*root) != NULL && (*root)->level != x) {
    if ((*root)->level > x)
      root = &((*root)->left);
    else
      root = &((*root)->right);
  }
  if ((*root) == NULL) return;

  if ((*root)->left == NULL && (*root)->right == NULL) {
    free(*root);
    (*root) = NULL;
  } else if ((*root)->left != NULL && (*root)->right != NULL) {
    Node *tmp = (*root)->right;
    while (tmp->left != NULL) tmp = tmp->left;

    (*root)->level = tmp->level;
    eat_rat(&tmp, tmp->level);

  } else {
    Node *tmp = ((*root)->left != NULL) ? (*root)->left : (*root)->right;
    free(*root);
    (*root) = tmp;
  }
}
void buy_rat(Node **root, int x) {
  while (*root != NULL) {
    if ((*root)->level > x)
      root = &((*root)->left);
    else
      root = &((*root)->right);
  }
  (*root) = (Node *)malloc(sizeof(Node));
  (*root)->level = x;
  (*root)->left = (*root)->right = NULL;
}

int main() { freopen("input.txt", "r", stdin); }