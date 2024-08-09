#ifndef STACK_IMPLEMENTATION_USING_QUEUE_H_INCLUDED
#define STACK_IMPLEMENTATION_USING_QUEUE_H_INCLUDED
#include "queue implementation using an array.h"

typedef struct {
    Queue q1;
    Queue q2;
} Stack;


void createStack(Stack *s);
void push(Stack *s, int data);
int pop(Stack *s, int *data);
int isStackEmpty(Stack *s);
int getStackSize(Stack *s);





#endif // STACK_IMPLEMENTATION_USING_QUEUE_H_INCLUDED
