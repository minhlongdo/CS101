#include "avl.h"

int max(int a, int b) {
  if (a < b)
    return b;
  else
    return a;
}

int height(struct AVL_Node *node) {
  if (node == NULL)
    return 0;
  return node->height;
}

struct AVL_Node *newNode(int value) {
  struct AVL_Node *new_node = (struct AVL_Node*)malloc(sizeof(struct AVL_Node));
  new_node->value = value;
  new_node->height = 1;
  new_node->left = NULL;
  new_node->right = NULL;

  return new_node;
}

struct AVL_Node *rightRotate(struct AVL_Node *y) {
  struct AVL_Node *x = y->left;
  struct AVL_node *T2 = x->right;

  /* Perform rotation */
  y->left = x;
  x->right = T2;

  /* Update heights */
  x->height = max(height(x->left), height(x->right)) + 1;
  y->height = max(height(y->left), height(y->right)) + 1;

  return y;
}
