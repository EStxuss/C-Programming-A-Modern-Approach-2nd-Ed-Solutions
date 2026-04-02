#include "queueADT.h"
#include <stdio.h>

int main(void) {
    Queue q1 = create();
    Queue q2 = create();

    for (int i = 0; !isFull(q1); ++i)
        enqueue(q1, i);

    print(q1, "q1");
    print(q2, "q2");

    printf("\ndequeue from q1 3 times\n\n");
    printf("front is %d\n", front(q1));
    dequeue(q1);
    printf("front is %d\n", front(q1));
    dequeue(q1);
    printf("front is %d\n", front(q1));
    dequeue(q1);
    print(q1, "q1");

    printf("\nenqueue q1 3 times\n\n");
    enqueue(q1, 1);
    enqueue(q1, 2);
    enqueue(q1, 3);

    print(q1, "q1");

    printf("\nenqueue q2 5 times\n\n");
    enqueue(q2, 1);
    enqueue(q2, 2);
    enqueue(q2, 3);
    enqueue(q2, 4);
    enqueue(q2, 5);

    print(q2, "q2");

    printf("\ndequeue from q2 3 times\n\n");
    printf("front is %d\n", front(q2));
    dequeue(q2);
    printf("front is %d\n", front(q2));
    dequeue(q2);
    printf("front is %d\n", front(q2));
    dequeue(q2);
    print(q2, "q2");

    printf("\nenqueue q2 5 times\n\n");
    enqueue(q2, 1);
    enqueue(q2, 2);
    enqueue(q2, 3);
    enqueue(q2, 4);
    print(q2, "q2");

    printf("\nFinal queue state:\n\n");

    print(q1, "q1");
    print(q2, "q2");

    destroy(q1);
    destroy(q2);

    return 0;
}