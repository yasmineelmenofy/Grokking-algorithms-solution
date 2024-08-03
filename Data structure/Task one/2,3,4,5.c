
#include <stdio.h>
#define MAXSTACK 10
#include <string.h>
typedef struct stack
{
    int array[MAXSTACK];
    int top;
} stack;
int stackempty(stack *ps)
{
    return ps->top == 0;
}

//2.
int firstElement(stack *ps) {
    if (!stackempty(ps)) {
        return ps->array[0];
    } else {
        printf("Stack is empty\n");
        return -1;
    }
}

//3.
void destroyStack(stack *ps) {
    ps->top = 0;


}

//4
void copyStack(stack *from, stack *to) {
    for (int i = 0; i < from->top; i++) {
        to->array[i] = from->array[i];
    }
    to->top = from->top;
}

//5
int stacksize(stack *ps) {
    return ps->top;
}







