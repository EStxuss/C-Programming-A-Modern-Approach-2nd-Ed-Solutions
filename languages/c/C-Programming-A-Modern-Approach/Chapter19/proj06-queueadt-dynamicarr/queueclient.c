#include "queueADT.h"
#include <stdio.h>

int main(void) {
    Queue q1 = create(5);
    Queue q2 = create(10);

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

    printf("\nenqueue q1 2 times\n\n");
    for (int i = 0; i < 2; ++i)
        enqueue(q1, i);

    print(q1, "q1");

    printf("\nenqueue q2 7 times\n\n");
    for (int i = 0; i < 7; ++i)
        enqueue(q2, i);

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
    for (int i = 0; i < 5; ++i)
        enqueue(q2, i);
    print(q2, "q2");

    printf("\nFinal queue state:\n\n");

    print(q1, "q1");
    print(q2, "q2");

    destroy(q1);
    destroy(q2);

    return 0;
}