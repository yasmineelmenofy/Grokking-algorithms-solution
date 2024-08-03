#include <stdio.h>
#define MAXSTACK 10

typedef struct stack
{
    int array[MAXSTACK];
    int top;
} stack;

typedef struct min_stack
{
    int array[MAXSTACK];
    int top;
} min_stack;

void createstack(stack *ps, min_stack *pms)
{
    ps->top = 0;
    pms->top = 0;
}

int stackfull(stack *ps)
{
    return ps->top == MAXSTACK;
}

int stackempty(stack *ps)
{
    return ps->top == 0;
}

void push(int e, stack *ps, min_stack *pms)
{
    if (!stackfull(ps))
    {
        ps->array[ps->top++] = e;
        if (pms->top == 0 || e <= pms->array[pms->top - 1])
        {
            pms->array[pms->top++] = e;
        }
        else
        {
            pms->array[pms->top] = pms->array[pms->top - 1];
            pms->top++;
        }
    }
    else
    {
        printf("Stack is full\n");
    }
}

int pop(stack *ps, min_stack *pms)
{
    if (!stackempty(ps))
    {
        pms->top--;
        return ps->array[--ps->top];
    }
    else
    {
        printf("Stack is empty\n");
        return -1;
    }
}

int stacktop(stack *ps)
{
    if (!stackempty(ps))
    {
        return ps->array[ps->top - 1];
    }
    else
    {
        printf("Stack is empty\n");
        return -1;
    }
}

int findMin(min_stack *pms)
{
    if (!stackempty(pms))
    {
        return pms->array[pms->top - 1];
    }
    else
    {
        printf("Stack is empty\n");
        return -1;
    }
}

int main()
{
    stack s;
    min_stack ms;
    createstack(&s, &ms);
    push(1, &s, &ms);
    push(3, &s, &ms);
    push(8, &s, &ms);
    push(5, &s, &ms);
    push(15, &s, &ms);
    printf("Minimum element: %d\n", findMin(&ms));
    return 0;
}

