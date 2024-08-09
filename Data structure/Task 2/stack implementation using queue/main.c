#include <stdio.h>
#include <stdlib.h>
#include "stack implementation using queue.h"


int main() {
    Stack s;
    createStack(&s);
    push(&s, 10);
    push(&s, 20);

    printf("Stack elements after pushes: ");
    TraverseQueue(&s.q1, printElement);
    printf("\n");

    int data;
    while (!isStackEmpty(&s)) {
        if (pop(&s, &data)) {
            printf("Popped: %d\n", data);
        }
    }

    return 0;
}
