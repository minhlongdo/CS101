#ifndef LINKED_LIST_H
#define LINKED_LIST_H

/* Singly linked list */
typedef struct SinglyLinkedList {
  int data;
  SinglyLinkedList *next;

};

/* Doubly linked list */
typedef struct DoublyLinkedList {
  int data;
  DoublyLinkedList *prev;
  DoublyLinkedList *next;
};

/* Operations of a Singly Linked List */
void singly_append(SinglyLinkedList **ll, int key);
void singly_remove(SinglyLinkedList **ll, int key);
void singly_pop(SinglyLinkedList **ll);

/* Operations of a Doubly Linked List */
void doubly_append(DoublyLinkedList **ll, int key);
void doubly_remove(DoublyLinkedList **ll, int key);
void doubly_pop(DoublyLinkedList **ll);
int detect_cycle(DoublyLinkedList *ll);

#endif
