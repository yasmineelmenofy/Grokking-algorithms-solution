#include <stdio.h>
#include "queue implementation using stack.h"


void createStack(Stack *s) {
    s->top = -1;
}

int isStackFull(Stack *s) {
    return s->top == MAXSTACK - 1;
}

int isStackEmpty(Stack *s) {
    return s->top == -1;
}

void push(Stack *s, int data) {
    if (!isStackFull(s)) {
        s->array[++s->top] = data;
    } else {
        printf("Stack is full\n");
    }
}

int pop(Stack *s, int *data) {
    if (!isStackEmpty(s)) {
        *data = s->array[s->top--];
        return 1;
    } else {
        printf("Stack is empty\n");
        return 0;
    }
}


void createQueue(Queue *q) {
    createStack(&q->stack1);
    createStack(&q->stack2);
}

void Append(int data, Queue *q) {
    if (isStackFull(&q->stack1)) {
        printf("Queue is full\n");
        return;
    }
    push(&q->stack1, data);
}

void serve(int *data, Queue *q) {
    if (isStackEmpty(&q->stack2)) {
        while (!isStackEmpty(&q->stack1)) {
            int temp;
            pop(&q->stack1, &temp);
            push(&q->stack2, temp);
        }
    }
    pop(&q->stack2, data);
}

int QueueEmpty(Queue *q) {
    return isStackEmpty(&q->stack1) && isStackEmpty(&q->stack2);
}

int Queuesize(Queue *q) {
    return (q->stack1.top + 1) + (q->stack2.top + 1);
}
