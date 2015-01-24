#include "queue.h"

struct Item *createItem(int item, int priority) {
  struct Item *item = (struct Item*)malloc(sizeof(struct Item));
  item->item = item;
  item->priority = priority;

  return item;
}
