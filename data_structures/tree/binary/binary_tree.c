#include "binary_tree.h"

int findNode(struct BinaryTree *root, int value) {
	if (root == NULL) {
		return FALSE;
	}
	else if (root->value == value) {
		return TRUE;
	}
	else if (root->value <= value) {
		return findNode(root->left, value);
	}
	else if (root->value > value) {
		return findNode(root->right, value);
	}
}

void insertNode(struct BinaryTree **root, int value) {
	struct BinaryTree *head = *root;
	/* Construct node */
	struct BinaryTree *node = (struct BinaryTree*)malloc(sizeof(struct BinaryTree));
	node->value = value;
	node->left = NULL;
	node->right = NULL;

	while(head != NULL) {
		if (head->value <= value) {
			if (head->left == NULL) {
				/* Insert into tree */
				head->left = node;
			} else {
				/* Continue to tranverse*/
				head = head->left;
			}
		} else {
			if (head->right == NULL) {
				head->right = node;
			} else {
				head = head->right;
			}
		}
	}
	return;
}
