#ifndef BINARY_TREE_H
#define BINARY_TREE_H

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "../../linked_list/linked_list.h"

#define FALSE -1
#define TRUE 0

/* Data struct for binary search tree */
struct BinaryTree {
	int value;
	struct BinaryTree *left;
	struct BinaryTree *right;
};

int findNode(struct BinaryTree *root, int value);
void insertNode(struct BinaryTree **root, int value);
void balance_tree(struct BinaryTree **root);
void create_linkedlist_from_tree(struct BinaryTree *root, struct SinglyLinkedList **ll);
void deallocate(struct BinaryTree *root);

#endif
