#include "binary_tree.h"

int main() {
	/* Constructed root of binary tree */
	printf("Construct root of binary tree\n");
	struct BinaryTree *root = (struct BinaryTree*)malloc(sizeof(struct BinaryTree));
	root->value = 10;
	root->left = NULL;
	root->right = NULL;

	int node_value = findNode(root, 10);
	assert (node_value == 0);

	node_value = findNode(root, 9);
	assert (node_value == -1);

	insertNode(&root, 9);
	node_value = findNode(root, 9);
	assert(node_value == 0);
	printf("Balancing tree\n");

	/* Create linked list */
	printf("Cleaning up\n");
	deallocate(root);

	/* Free memory at the end */
	return 0;
}
