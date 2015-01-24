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

void insert_node(struct AVL_Node **avl_tree, int value) {
  struct AVL_Node *node = newNode(value);
  struct AVL_node *root = (*avl_tree);
  if (root == NULL)
    return;
  /* Already exists */
  if (root->value == value)
    return;

  while(1) {
    if (root->value < value) {
      if (root->right != NULL)
        root = root->right;
      else {
        root->right = node;
        break;
      }
    } else if (root->value > value) {
      if (root->left != NULL)
        root = root->left;
      else {
        root->left = node;
        break;
      }
    } else if (root->value == value) {
      printf("Value already exists")
      break;
    }
  }
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

struct AVL_Node *leftRotate(struct AVL_Node *y) {
  struct AVL_Node *x = y->right;
  struct AVL_node *T2 = y->left;

  /* perform rotation */
  y->left = x;
  x->right = T2;

  x->height = max(height(x->left), height(x->right)) + 1;
  y->height = max(height(y->left), height(y->right)) + 1;

  return y;
}

int getBalance(struct AVL_node *node) {
  if (N == NULL)
    return 0;
  return height(N->left) - height(N->right);
}

struct AVL_Node *insert(struct AVL_Node *node, int value) {
  if (node == NULL)
    return newNode(value);

  if (value < node->key)
    node->left = insert(node->left, value);
  else
    node->right = insert(node->right, value);

  node->height = max(height(node->left), height(node->right)) + 1;

  int balance = getBalance(node);

  /* Left left case */
  if (balance > 1 && key < node->left->key)
    return rightRotate(node);

  /* Right right case */
  if (balance > 1 && key < node->left->key)
    return leftRotate(node);

  /* Left right case */
  if (balance > 1 && key > node->left->key) {
    node->left = leftRotate(node->left);
    return rightRotate(node);
  }

  /* Right left case */
  if (balance < -1 && key < node->right->key) {
    node->right = rightRotate(node->right);
    return leftRotate(node);
  }
  return node;
}
