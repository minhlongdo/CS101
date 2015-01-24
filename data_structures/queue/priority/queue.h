#ifndef QUEUE_H
#define QUEUE_H

struct Item {
  int item;
  int priority;
};

/* Insert item */
void insert_item(struct Item **heap, struct Item *item);
struct Item *createItem(int item, int priority);

#endif
