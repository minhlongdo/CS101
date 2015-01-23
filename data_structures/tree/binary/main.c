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

	insertNode(&root, 8);
	node_value = findNode(root, 8);
	assert(node_value == 0);

	printf("Postorder traversal\n");
	postorder(root);
	printf("\n");

	/* Create linked list */
	struct SinglyLinkedList *ll = NULL;
	create_linkedlist_from_tree(root, &ll);
	printf("Content\n");
	int ll_len = 0, i = 0;
	struct SinglyLinkedList *head = ll;
	if (head != NULL) {
		while(head != NULL) {
			printf("%i ", head->data);
			ll_len++;
			head = head->next;
		}
		printf("\n");
	}

	printf("Length: %i\n", ll_len);
	int *values = (int*)malloc(sizeof(int)*ll_len);

	printf("Balancing tree\n");
	printf("Cleaning up\n");

	while (ll != NULL) {
		int temp = ll->data;
		//printf("Temp: %i\n", temp);
		values[i] = temp;
		ll = ll->next;
		i++;
	}

	/* Free list */
	while (ll != NULL) {
		struct SinglyLinkedList *prev = ll;
		ll = ll->next;
		free(prev);
	}
	for (i=0; i<ll_len; i++)
		printf("%i ", values[i]);
	printf("\n");
	printf("\n");
	/* Create balanced tree */
	struct BinaryTree *balanced = create_balance_tree(values, 0, ll_len-1);
	printf("Root: %i\n", balanced->value);
	if (balanced->left != NULL)
		printf("Left: %i\n", (balanced->left)->value);
	if (balanced->right != NULL)
		printf("Right: %i\n", (balanced->right)->value);
		if ((balanced->right)->left != NULL)
			printf("Right Left: %i\n", ((balanced->right)->left)->value);
		if ((balanced->right)->right != NULL)
			printf("Right Left: %i\n", ((balanced->right)->right)->value);
	printf("\n");

	printf("Preorder traversal\n");
	preorder(root);
	printf("\n");

	printf("Inorder traversal\n");
	inorder(root);
	printf("\n");

	printf("Postorder traversal\n");
	postorder(root);
	printf("\n");

	free(values);
	deallocate(root);
	deallocate(balanced);

	/* Free memory at the end */
	return 0;
}
