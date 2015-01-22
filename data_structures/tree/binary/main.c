#include "binary_tree.h"

int main() {
	/* Constructed root of binary tree */
	struct BinaryTree *root = (struct BinaryTree*)malloc(sizeof(struct BinaryTree));
	root->value = 10;
	root->left = NULL;
	root->right = NULL;

	int node_value = findNode(root, 10);
	assert (node_value == TRUE);

	node_value = findNode(root, 9);
	assert (node_value == FALSE);

	insertNode(&root, 9);
	node_value = findNode(root, 9);
	assert(node_value == TRUE);

	return 0;
}
