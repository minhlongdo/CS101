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

void singly_remove(struct SinglyLinkedList **ll, int position) {
  /* Start from position 0 */
  struct SinglyLinkedList *head = *ll;
  int pos = 0;
  if (head == NULL)
    return;
  else if (position == 0) {
    singly_pop(&(*ll));
    return;
  }

  while(head != NULL) {
    struct SinglyLinkedList *temp = head;
    head = head->next;
    pos++;
    if (pos == position) {
      if (head == NULL) {
        printf("Removing position %i rejected.\n");
        return;
      }
      /* Start removing this block */
      struct SinglyLinkedList *next_node = head->next;
      temp->next = next_node;
      free(head);
      break;
    }
  }
}

/* Remove all keys */
void singly_remove_all(struct SinglyLinkedList **ll, int key) {
  struct SinglyLinkedList *head = *ll;
  struct SinglyLinkedList *temp = NULL;

  while(head != NULL) {
    /* Remove node */
    if (head->data == key) {
      /* Indicates that this is the first node */
      if (temp == NULL) {
        singly_pop(&head);
      } else {
        /*
        Remove this node.
        Connect the previous with the next one.
        */
        struct SinglyLinkedList *next_node = head->next;
        temp->next = next_node;
        free(head);
      }
    }
  }
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

void singly_detect_cycle(struct SinglyLinkedList *ll) {
  struct SinglyLinkedList *fast = ll;
  /* Empty Linked List */
  if (fast == NULL) {
    printf("There is no element in the Linked List.\n");
  }
  else if (fast->next == NULL) {
    printf("There is only 1 element in the Linked List which points to nothing.\n");
  }

  struct SinglyLinkedList *slow = fast;

  while (1) {
    if (slow->next != NULL)
      slow = slow->next;
    else {
      printf("There is no cycle.\n");
      return;
    }
    if (fast->next != NULL)
      if ((fast->next)->next != NULL)
        fast = (fast->next)->next;
      else {
        printf("There is no cycle\n");
        return;
      }
    else {
      printf("There is no cycle.\n");
      return;
    }
    /* Check if they are the same */
    //printf("Slow mem_addr: %p\n", slow);
    //printf("Fast mem_addr: %p\n", fast);
    if (slow == fast) {
      printf("There is a cycle\n");
      return;
    }
  }
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
