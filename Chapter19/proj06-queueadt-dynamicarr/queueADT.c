#include "queueADT.h"
#include <stdio.h>
#include <stdlib.h>

void terminate(Queue, const char *errMsg);

struct queue_type {
    Item *arr;
    int front, end, size, maxSize;
};

Queue create(int size) {
    Queue new = malloc(sizeof(struct queue_type));
    if (new == NULL)
        terminate(NULL, "Failed to create Queue");

    new->arr = malloc(size * sizeof(Item));
    if (new->arr == NULL) {
        terminate(new, "Failed to allocate memory for queue array");
    }

    new->maxSize = size;
    new->front = new->end = new->size = 0;
    return new;
}

void destroy(Queue q) {
    free(q->arr);
    free(q);
}

void enqueue(Queue q, Item item) {
    if (isFull(q))
        terminate(q, "Tried to insert into full queue");

    q->arr[q->end] = item;
    q->end = (q->end + 1) % q->maxSize;
    ++q->size;
}

void dequeue(Queue q) {
    if (isEmpty(q))
        return;

    q->front = (q->front + 1) % q->maxSize;
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

    int actualEnd = (q->end - 1 < 0) ? q->maxSize - 1 : q->end - 1;
    return q->arr[actualEnd];
}

bool isFull(Queue q) { return q->size == q->maxSize; }

bool isEmpty(Queue q) { return q->size == 0; }

void print(Queue q, const char *name) {
    printf("\n%s:\n", name);
    for (int i = 0; i < q->front; ++i)
        printf("  ");
    printf("▼f\n");
    for (int i = 0; i < q->maxSize; ++i) {
        if (q->size == q->maxSize)
            printf("%d ", q->arr[i]);
        else if ((q->front > q->end && (i >= q->front || i < q->end)) ||
                 (q->front < q->end && (i >= q->front && i < q->end)))
            printf("%d ", q->arr[i]);
        else
            printf("_ ");
    }
    printf("\n");
    int actualEnd = (q->end - 1 < 0) ? q->maxSize - 1 : q->end - 1;
    actualEnd = (q->size == 0) ? q->front : actualEnd;
    for (int i = 0; i < actualEnd; ++i)
        printf("  ");
    printf("▲e\n");
}

void terminate(Queue q, const char *errMsg) {
    destroy(q);
    printf("%s\n", errMsg);
    exit(EXIT_FAILURE);
}