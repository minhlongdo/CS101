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
