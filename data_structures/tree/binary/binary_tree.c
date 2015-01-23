#include "binary_tree.h"

int findNode(struct BinaryTree *root, int value) {
	if (root == NULL) {
		return FALSE;
	}
	if (root->value == value)
		return TRUE;
	else if (root->value < value) {
		return findNode(root->left, value);
	}
	else if (root->value > value){
		return findNode(root->right, value);
	}
	return FALSE;
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
				break;
			} else {
				/* Continue to tranverse*/
				head = head->left;
			}
		} else {
			if (head->right == NULL) {
				head->right = node;
				break;
			} else {
				head = head->right;
			}
		}
	}
	return;
}

/* Deallocate memory allocated to each node in the binary tree */
void deallocate(struct BinaryTree *root) {
	if (root == NULL)
		return;
	deallocate(root->left);
	deallocate(root->right);
	free(root);
}

void create_linkedlist_from_tree(struct BinaryTree *root, struct SinglyLinkedList **ll) {
	if (root == NULL)
		return;
	else {
		create_linkedlist_from_tree(root->left, &(*ll));
		create_linkedlist_from_tree(root->right, &(*ll));
		/*
		Allocate memory for linked list if it does not exist.
		No need to go through the whole thing.
		*/
		if (*ll == NULL) {
			(*ll) = (struct SinglyLinkedList*)malloc(sizeof(struct SinglyLinkedList));
			(*ll)->next = NULL;
			(*ll)->data = root->value;
			return;
		}
		/*To go the end of the linked list */
		while((*ll)->next != NULL) {
			(*ll) = (*ll)->next;
		}
		/* Create node for linked list */
		struct SinglyLinkedList *ll_node = (struct SinglyLinkedList*)malloc(sizeof(struct SinglyLinkedList));
		ll_node->next = NULL;
		ll_node->data = root->value;
		(*ll)->next = ll_node;
	}
}

struct BinaryTree *create_balance_tree(int *list, int start, int end) {
	if (start > end)
		return NULL;
	int mid = (start + end)/2;
	struct BinaryTree *root = (struct BinaryTree*)malloc(sizeof(struct BinaryTree));
	root->value = list[mid];
	root->left = create_balance_tree(list, 0, mid - 1);
	root->right = create_balance_tree(list, mid + 1, end);

	return root;
}

void balance_tree(struct BinaryTree **root) {
	struct BinaryTree *head = *root;
	struct SinglyLinkedList *ll = NULL;
	/* Create a linked list from binary search tree */
	create_linkedlist_from_tree(head, &ll);
	if (ll != NULL) {
		while(ll != NULL) {
			printf("%i ", ll->data);
		}
		printf("\n");
	}
	/* Free list */
	while (ll != NULL) {
		struct SinglyLinkedList *prev = ll;
		ll = ll->next;
		free(prev);
	}
}

void display(struct BinaryTree *root) {
	if (root == NULL)
		return;
	display(root->left);
	display(root->right);
	printf("%i\n", root->value);
}
