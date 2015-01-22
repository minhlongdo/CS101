#ifndef BINARY_TREE_H
#define BINARY_TREE_H

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#define FALSE -1
#define TRUE 0

/* Data struct for binary search tree */
struct BinaryTree {
	int value;
	struct BinaryTree *left;
	struct BinaryTree *right;
};

int findNode(struct BinaryTree *root, int value);

#endif
