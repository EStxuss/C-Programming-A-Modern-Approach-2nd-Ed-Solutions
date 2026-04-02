#ifndef STACK_H
#define STACK_H

#include <stdbool.h>

typedef char Item;

struct stack;
typedef struct stack *Stack;

Stack stackCreate(void);
void stackDestroy(Stack);
void stackPush(Stack, Item); // returns true if successful push
Item stackPop(Stack);
void stackMakeEmpty(Stack);
bool stackIsEmpty(Stack);
bool stackIsFull(Stack);

#endif
