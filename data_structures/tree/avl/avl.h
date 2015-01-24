#ifndef AVL_H
#define AVL_H

#include <stdlib.h>
#include <stdio.h>

/* AVL node data structure */
struct AVL_Node {
  int value;
  int height;
  struct AVL_Node *left;
  struct AVL_Node *right;
};

int max(int a, int b);
int height(struct AVL_Node *node);
struct AVL_Node *newNode(int value);
struct AVL_Node *rightRotate(struct AVL_Node *node);
struct AVL_Node *leftRotate(struct AVL_node *node);
int getBalance(struct AVL_node *node);

#endif
