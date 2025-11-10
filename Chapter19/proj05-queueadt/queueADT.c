#include "queueADT.h"
#include <stdio.h>
#include <stdlib.h>

#define SIZE 7

void terminate(Queue, const char *errMsg);

struct queue_type {
    Item arr[SIZE];
    int front, end, size;
};

Queue create(void) {
    Queue new = malloc(sizeof(struct queue_type));
    if (new == NULL)
        terminate(NULL, "Failed to create Queue");

    new->front = new->end = new->size = 0;
    return new;
}

void destroy(Queue q) { free(q); }

void enqueue(Queue q, Item item) {
    if (isFull(q))
        terminate(q, "Tried to insert into full queue");

    q->arr[q->end] = item;
    q->end = (q->end + 1) % SIZE;
    ++q->size;
}

void dequeue(Queue q) {
    if (isEmpty(q))
        return;

    q->front = (q->front + 1) % SIZE;
    --q->size;
}

Item front(Queue q) {
    if (isEmpty(q))
        terminate(q, "Tried accessing value from empty queue");

    return q->arr[q->front];
}

Item end(Queue q) {
    if (isEmpty(q))
        terminate(q, "Tried accessing value from empty queue");

    int actualEnd = (q->end - 1 < 0) ? SIZE - 1 : q->end - 1;
    return q->arr[actualEnd];
}

bool isFull(Queue q) { return q->size == SIZE; }

bool isEmpty(Queue q) { return q->size == 0; }

void print(Queue q, const char *name) {
    printf("\n%s:\n", name);
    for (int i = 0; i < q->front; ++i)
        printf("  ");
    printf("▼f\n");
    for (int i = 0; i < SIZE; ++i) {
        if (q->size == SIZE)
            printf("%d ", q->arr[i]);
        else if ((q->front > q->end && (i >= q->front || i < q->end)) ||
                 (q->front < q->end && (i >= q->front && i < q->end)))
            printf("%d ", q->arr[i]);
        else
            printf("_ ");
    }
    printf("\n");
    int actualEnd = (q->end - 1 < 0) ? SIZE - 1 : q->end - 1;
    actualEnd = (q->size == 0) ? q->front : actualEnd;
    for (int i = 0; i < actualEnd; ++i)
        printf("  ");
    printf("▲e\n");
}

void terminate(Queue q, const char *errMsg) {
    free(q);
    printf("%s\n", errMsg);
    exit(EXIT_FAILURE);
}