#include "queueADT.h"
#include <stdio.h>

void operation(Queue q, const char *name, const char *op, int item);

int main(void) {
    Queue q1 = create();
    Queue q2 = create();

    for (int i = 0; i < 5; ++i)
        operation(q1, "q1", "enqueue", i);

    for (int i = 0; i < 3; ++i)
        operation(q2, "q2", "enqueue", i);

    for (int i = 0; i < 3; ++i)
        operation(q1, "q1", "dequeue", -1);

    for (int i = 0; i < 2; ++i)
        operation(q2, "q2", "dequeue", -1);

    operation(q1, "q1", "front", -1);
    operation(q1, "q1", "end", -1);

    operation(q2, "q2", "front", -1);
    operation(q2, "q2", "end", -1);

    destroy(q1);
    destroy(q2);

    return 0;
}

void operation(Queue q, const char *name, const char *op, int item) {
    if (op == "enqueue") {
        enqueue(q, item);
        printf("\nadded %d to end of queue %s\n", item, name);
    } else if (op == "dequeue") {
        int popped = front(q);
        dequeue(q);
        printf("\nRemoved %d from front of queue %s\n", popped, name);
    } else if (op == "makeEmpty") {
        makeEmpty(q);
        printf("\nMade queue %s empty\n", name);
    } else if (op == "front") {
        printf("\nThe front item of queue %s is %d\n", name, front(q));
    } else if (op == "end") {
        printf("\nThe last item of queue %s is %d\n", name, end(q));
    } else {
        printf("\n--Uknown operation--\n");
    }
}