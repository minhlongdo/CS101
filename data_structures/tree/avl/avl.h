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

#endif
