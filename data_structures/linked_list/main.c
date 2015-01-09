#include "linked_list.h"

void display_singly(struct SinglyLinkedList *head);
void free_singly(struct SinglyLinkedList **head);
void create_singly_cycle(struct SinglyLinkedList **cycle);

int main() {
  /* Initialize singly linked list */
  struct SinglyLinkedList *singly = (struct SinglyLinkedList*)malloc(sizeof(struct SinglyLinkedList));
  singly->data = 0;
  singly->next = NULL;
  struct SinglyLinkedList *singly_cycle = NULL;
  create_singly_cycle(&singly_cycle);

  display_singly(singly);

  /* Append data */
  singly_append(&singly, 1);
  display_singly(singly);

  /* Pop first  element from list */
  singly_pop(&singly);
  display_singly(singly);

  singly_remove(&singly, 1);
  display_singly(singly);
  printf("Expected not to be a cycle.\n");
  singly_detect_cycle(singly);
  //display_singly(singly_cycle);
  printf("Expected to be a cycle.\n");
  singly_detect_cycle(singly_cycle);

  /* Free memory */
  free_singly(&singly);

  return 0;
}

void create_singly_cycle(struct SinglyLinkedList **head) {
  /* Allocate memory */
  if ((*head) == NULL) {
    (*head) = (struct SinglyLinkedList*)malloc(sizeof(struct SinglyLinkedList));
  }
  (*head)->data = 0;
  /* Points to itself */
  (*head)->next = (*head);
}

void display_singly(struct SinglyLinkedList *head) {
  if (head == NULL)
    return;

  while(1) {
    printf("%i ", head->data);
    if (head->next != NULL)
      head = head->next;
    else
      break;
  }
  printf("\n");
}

void free_singly(struct SinglyLinkedList **head) {
  while (*head != NULL) {
    struct SinglyLinkedList *prev = *head;
    *head = (*head)->next;
    free(prev);
  }
}
