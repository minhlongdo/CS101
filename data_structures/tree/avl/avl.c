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

struct AVL_node *delete_node(struct AVL_Node *root, int value) {
  if (root == NULL)
    return NULL;

  if (root->value < value)
    root->right = deleteNode(node->right, value);
  else if (root->value > value)
    root->left = deleteNode(node->left, value);
  else {
    /* Arrived at the node */
    /* No child, or single child */
    if (root->left == NULL || root->right == NULL) {
      struct AVL_Node *temp = root->left ? root->left : root->right;
      /* No child case */
      if (temp == NULL) {
        /* Copy contents of the non-empty child*/
        temp = root;
        root = NULL;
      } else {
        /* Copy the contents of the non-empty child */
        *root = *temp;
      }
      free(temp);
    } else {
      /* Two children case */
      struct AVL_Node *temp = root->right;
      /* Get successor */
      while (temp->left != NULL)
        temp = temp->left;

      /* Copy key of the inorder successor */
      root->value = temp->value;
      /* Delete in order successor */
      root->right = deleteNode(root->right, temp->value);
    }
  }

  /* if tree has only one root then return */
  if (root == NULL)
    return root;

  /* Update height of the current node */
  root->height = max(height(root->left), height(root->right)) + 1;

  /* Get the balance factor of this node */
  int balance = getBalance(root);

  /* If node becomes unbalanced, there are 4 case */

  /* Left Left case */
  if (balance > 1 && getBalance(root->left) >= 0)
    return rightRotate(root);

  /* Left Right case */
  if (balance > 1 && getBalance(root->left) < 0) {
    root->left = leftRotate(root->left);
    return rightRotate(root);
  }

  /* Right Right case */
  if (balance < -1 && getBalance(root->right) <= 0)
    return leftRotate(root);

  if (balance < -1 && getBalance(root->right) > 0) {
    root->right = rightRotate(root->right);
    return leftRotate(root);
  }
}
