#ifndef QUEUEADT_H
#define QUEUEADT_H

#include <stdbool.h>

typedef int Item;

struct queue_type;
typedef struct queue_type *Queue;

Queue create(void);
void destroy(Queue);
void enqueue(Queue, Item);
void dequeue(Queue);
Item front(Queue);
Item end(Queue);
bool isEmpty(Queue);
bool isFull(Queue);
void print(Queue, const char *);

#endif