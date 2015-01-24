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

/* Find parent of a given node */
struct BinaryTree *findParent(struct BinaryTree *root, int value) {
	if (root == NULL)
		return NULL;
	/* If either children have the value return this parent node */
	else {
		/* Check if it is NULL before accessing, prevent segmentation fault */
		if (root->left != NULL)
			if ((root->left)->value == value)
				return root;
		if (root->right != NULL)
			if ((root->right)->value == value)
				return root;
	}
	/* Otherwise proceed as normal */
	if (root->value <= value)
		return findParent(root->left, value);
	else
		return findParent(root->right, value);
}

/* Get node */
struct BinaryTree *getNode(struct BinaryTree *root, int value) {
	if (root == NULL)
		return NULL;
	if (root->value <= value)
		return getNode(root->left, value);
	else
		return getNode(root->right, value);
}

/* Search for parent root, and node */
void search(struct BinaryTree **root, struct BinaryTree **parent, struct BinaryTree **node, int value) {
	struct BinaryTree *q = (*root);
	if (q == NULL) {
		printf("Empty tree");
		return;
	}
	printf("Searching for node: %i\n", value);
	*parent = q;
	while (q != NULL) {
		printf("Current node: %i\n", q->value);
		printf("Checking for equality: %i %i\n", q->value, value);
		int number = q->value;
		if (number == value) {
			*node = q;
			return;
		}
		else {
			*parent = q;
			printf("Comparing Q'values with value: %i %i\n", q->value, value);
			if (q->value >= value) {
				if (q->left != NULL)
					q = q->left;
				else
					break;
			}
			else if (q->value < value) {
				if (q->right != NULL)
					q = q->right;
				else
					break;
			}
		}
	}
	/* Couldnt find node therefore couldnt find its parent */
	*parent = NULL;
	*node = NULL;
	return;
}

/* Remove node from binary tree */
void removeNode(struct BinaryTree **root, int value) {
	if ((*root) == NULL) {
		printf("Empty tree");
		return;
	}
	/* Find node */
	struct BinaryTree *node, *parent, *xsuccessor;
	search(&(*root), &parent, &node, value);
	if (node == NULL) {
		printf("Node couldnt be found.\n");
		return;
	}

	printf("Parent node: %i\n", parent->value);
	printf("To be deleted node: %i\n", node->value);

	if ( (node->left != NULL && node->right != NULL) || parent == node ) {
		parent = node;
		xsuccessor = node->right;

		while(xsuccessor->left != NULL) {
			parent = xsuccessor;
			xsuccessor = xsuccessor->left;
		}
		/* Exchange value */
		node->value = xsuccessor->value;
		/* Move the node pointer to the successor */
		node = xsuccessor;
	}

	if (node->left == NULL && node->right == NULL) {
		printf("Leaf node case\n");
		if (parent->left == node)
			parent->left = NULL;
		else if (parent->right == node)
			parent->right = NULL;
		free(node);
	}

	/* Single child parent to be removed node */
	if (node->left != NULL && node->right == NULL) {
		printf("Left only.\n");
		if (parent->left == node)
			parent->left = node->left;
		else if (parent->right == node)
			parent->right = node->left;
		free(node);
	}

	if (node->left == NULL && node->right != NULL) {
		printf("Right only.\n");
		if (parent->left == node)
			parent->left = node->right;
		else if (parent->right == node)
			parent->right = node->right;
		free(node);
	}
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
