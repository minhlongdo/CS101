#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <stdio.h>
#include <stdlib.h>

/* Singly linked list */
struct SinglyLinkedList {
  int data;
  struct SinglyLinkedList *next;

};

/* Doubly linked list */
struct DoublyLinkedList {
  int data;
  struct DoublyLinkedList *prev;
  struct DoublyLinkedList *next;
};

/* Operations of a Singly Linked List */
void singly_append(struct SinglyLinkedList **ll, int key);
void singly_remove(struct SinglyLinkedList **ll, int position);
void singly_remove_all(struct SinglyLinkedList **ll, int key);
void singly_pop(struct SinglyLinkedList **ll);

/* Operations of a Doubly Linked List */
void doubly_append(struct DoublyLinkedList **ll, int key);
void doubly_remove(struct DoublyLinkedList **ll, int key);
void doubly_pop(struct DoublyLinkedList **ll);
int detect_cycle(struct DoublyLinkedList *ll);

#endif
