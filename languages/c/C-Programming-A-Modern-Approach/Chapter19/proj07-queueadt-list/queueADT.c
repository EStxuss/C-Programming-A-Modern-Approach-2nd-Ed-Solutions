#include "queueADT.h"
#include <stdio.h>
#include <stdlib.h>

void terminate(Queue, const char *errMsg);

struct node {
    Item data;
    struct node *next;
};

struct queue_type {
    struct node *front;
    struct node *end;
    int size;
};

Queue create(void) {
    Queue new = malloc(sizeof(struct queue_type));
    if (new == NULL)
        terminate(NULL, "Failed to create Queue");

    new->front = new->end = NULL;
    new->size = 0;
    return new;
}

void destroy(Queue q) {
    makeEmpty(q);
    free(q);
}

void enqueue(Queue q, Item item) {
    if (isFull(q))
        terminate(q, "Tried to insert into full queue");

    struct node *newNode = malloc(sizeof(struct node));
    if (newNode == NULL)
        terminate(q, "Failed to allocate new queue item");
    newNode->data = item;

    if (q->size == 0)
        q->front = q->end = newNode;
    else {
        q->end->next = newNode;
        q->end = q->end->next;
    }

    ++q->size;
}

void dequeue(Queue q) {
    if (isEmpty(q))
        return;

    if (q->size == 1)
        q->end = NULL;

    struct node *toFree = q->front;
    q->front = q->front->next;
    free(toFree);

    --q->size;
}

Item front(Queue q) {
    if (isEmpty(q))
        terminate(q, "Tried accessing value from empty queue");

    return q->front->data;
}

Item end(Queue q) {
    if (isEmpty(q))
        terminate(q, "Tried accessing value from empty queue");

    return q->end->data;
}

void makeEmpty(Queue q) {
    for (struct node *p = q->front; p != NULL && p != q->end;) {
        struct node *toFree = p;
        p = p->next;
        free(toFree);
    }
    free(q->end);
    q->front = NULL;
    q->end = NULL;
    q->size = 0;
}

bool isFull(Queue q) { return false; }

bool isEmpty(Queue q) { return q->size == 0; }

void terminate(Queue q, const char *errMsg) {
    destroy(q);
    printf("%s\n", errMsg);
    exit(EXIT_FAILURE);
}