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

	/* Create linked list */
	struct SinglyLinkedList *ll = NULL;
	create_linkedlist_from_tree(root, &ll);
	printf("Content\n");
	int ll_len = 0;
	if (ll != NULL) {
		while(ll != NULL) {
			printf("%i ", ll->data);
			ll_len++;
			ll = ll->next;
		}
		printf("\n");
	}

	printf("Length: %i\n", ll_len);

	printf("Balancing tree\n");
	printf("Cleaning up\n");

	/* Free list */
	while (ll != NULL) {
		struct SinglyLinkedList *prev = ll;
		ll = ll->next;
		free(prev);
	}

	deallocate(root);

	/* Free memory at the end */
	return 0;
}
