#include "linked_list.h"

/* Operations for a Singly Linked List */

void singly_append(struct SinglyLinkedList **ll, int key) {
  if (*ll == NULL)
    return;
  struct SinglyLinkedList *head = *ll;

  struct SinglyLinkedList *new_node = (struct SinglyLinkedList*)malloc(sizeof(struct SinglyLinkedList));
  new_node->data = key;
  new_node->next = NULL;

  while(head->next != NULL){
    head = head->next;
  }

  head->next = new_node;
}

void singly_remove(struct SinglyLinkedList **ll, int key) {

}

/* Remove first element from linked list */
void singly_pop(struct SinglyLinkedList **ll) {
  struct SinglyLinkedList *head = *ll;

  /* nothing to pop */
  if (head == NULL)
    return;
  free(head);
  /* Move head to the next one */
  *ll = (*ll)->next;
  return;
}

/* Operations for a Doubly Linked List */

void doubly_append(struct DoublyLinkedList **ll, int key) {

}

void doubly_remove(struct DoublyLinkedList **ll, int key) {

}

void doubly_pop(struct DoublyLinkedList **ll) {

}

int detect_cycle(struct DoublyLinkedList *ll) {

}
