#ifndef BINARY_TREE_H
#define BINARY_TREE_H

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "../../linked_list/linked_list.h"

#ifndef FALSE
#define FALSE -1
#endif

#ifndef TRUE
#define TRUE 0
#endif

/* Data struct for binary search tree */
struct BinaryTree {
	int value;
	struct BinaryTree *left;
	struct BinaryTree *right;
};

int findNode(struct BinaryTree *root, int value);
void insertNode(struct BinaryTree **root, int value);
struct BinaryTree *create_balance_tree(int *list, int start, int end);
void create_linkedlist_from_tree(struct BinaryTree *root, struct SinglyLinkedList **ll);
void deallocate(struct BinaryTree *root);
int height(struct BinaryTree *node);
int max(int x, int y);
void display(struct BinaryTree *root);
void preorder(struct BinaryTree *root);
void inorder(struct BinaryTree *root);
void postorder(struct BinaryTree *root);

#endif
