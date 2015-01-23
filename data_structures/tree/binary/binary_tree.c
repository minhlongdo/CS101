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
				return;
			} else {
				/* Continue to tranverse*/
				head = head->left;
			}
		} else {
			if (head->right == NULL) {
				head->right = node;
				return;
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
			printf("Initial value: %i\n", root->value);
			(*ll)->data = root->value;
			return;
		} else {
			struct SinglyLinkedList *head = (*ll);
			/*To go the end of the linked list */
			while(head->next != NULL) {
				head = head->next;
			}
			/* Create node for linked list */
			struct SinglyLinkedList *ll_node = (struct SinglyLinkedList*)malloc(sizeof(struct SinglyLinkedList));
			ll_node->next = NULL;
			ll_node->data = root->value;
			head->next = ll_node;
		}
	}
}

struct BinaryTree *create_balance_tree(int *list, int start, int end) {
	if (start > end)
		return NULL;
	int mid = (start + end)/2;
	struct BinaryTree *root = (struct BinaryTree*)malloc(sizeof(struct BinaryTree));
	root->value = list[mid];
	root->left = create_balance_tree(list, start, mid - 1);
	root->right = create_balance_tree(list, mid + 1, end);

	return root;
}

int max(int x, int y) {
	if (x >= y)
		return x;
	else
		return y;
}

/*
Calculate the "height" of a tree.
Height is the number of nodes along the longest path
from the root node down to the farthest leaf node.
*/
int height(struct BinaryTree *node) {
	/* Base case tree is empty */
	if (node == NULL)
		return 0;
	return 1 + max(height(node->left), height(node->right));
}

void display(struct BinaryTree *root) {
	if (root == NULL)
		return;
	display(root->left);
	display(root->right);
	printf("%i\n", root->value);
}

/*
Preorder tree traversal
root - left - right
*/
void preorder(struct BinaryTree *root) {
	if (root == NULL)
		return;
	printf("%i ", root->value);
	preorder(root->left);
	preorder(root->right);
}

/*
Inorder tree traversal
left - root - right
*/
void inorder(struct BinaryTree *root) {
	if (root == NULL)
		return;
	inorder(root->left);
	printf("%i ", root->value);
	inorder(root->right);
}

/*
Postorder
left - right - root
*/
void postorder(struct BinaryTree *root) {
	if (root == NULL)
		return;
	postorder(root->left);
	postorder(root->right);
	printf("%i ", root->value);
}
