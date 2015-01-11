#ifndef BIN_TREE_H
#define BIN_TREE_H

#include <stdlib.h>
#include <stdbool.h>

typedef struct BinaryTree {
  int value;
  struct BinaryTree *left;
  struct BinaryTree *right
};

/* Implementation of depth-first search */
int dfs(struct BinaryTree *root, int data);
/* Implementation of breadth-first search */
int bfs(struct BinaryTree *root, int data);
/* Insert data */
void binary_insert(struct BinaryTree **root, int data);
int binary_lookup(struct BinaryTree *root, int data);

#endif
