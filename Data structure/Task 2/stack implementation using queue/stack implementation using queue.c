
#include "stack implementation using queue.h"

void createStack(Stack *s) {
    createQueue(&s->q1);
    createQueue(&s->q2);
}

void push(Stack *s, int data) {
    Append(data, &s->q2);

    while (!QueueEmpty(&s->q1)) {
        int temp;
        serve(&temp, &s->q1);
        Append(temp, &s->q2);
    }
    Queue temp = s->q1;
    s->q1 = s->q2;
    s->q2 = temp;
}

int pop(Stack *s, int *data) {
    if (QueueEmpty(&s->q1)) {
        return 0;
    }

    serve(data, &s->q1);
    return 1;
}

int isStackEmpty(Stack *s) {
    return QueueEmpty(&s->q1);
}

int getStackSize(Stack *s) {
    return Queuesize(&s->q1);
}
