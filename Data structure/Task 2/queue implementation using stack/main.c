#include <stdio.h>
#include <stdlib.h>
#include "queue implementation using stack.h"

int main() {
    Queue q;
    createQueue(&q);
    Append(10, &q);
    Append(20, &q);

    printf("Queue elements after Appending: ");
    int data;
    while (!QueueEmpty(&q)) {
        serve(&data, &q);
        printf("%d ", data);
    }


    return 0;
}
