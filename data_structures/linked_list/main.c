#include "linked_list.h"

void display_singly(struct SinglyLinkedList *head);
void free_singly(struct SinglyLinkedList **head);

int main() {
  /* Initialize singly linked list */
  struct SinglyLinkedList *singly = (struct SinglyLinkedList*)malloc(sizeof(struct SinglyLinkedList));
  singly->data = 0;
  singly->next = NULL;
  display_singly(singly);

  /* Append data */
  singly_append(&singly, 1);
  display_singly(singly);

  /* Pop first  element from list */
  singly_pop(&singly);
  display_singly(singly);

  /* Free memory */
  free_singly(&singly);

  return 0;
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
