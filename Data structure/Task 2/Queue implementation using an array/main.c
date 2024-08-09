#include <stdio.h>
#include <stdlib.h>
#include "queue implementation using an array.h"

int main() {
    Queue q;
    int data;
    createQueue(&q);
    Append(10, &q);
    Append(20, &q);
    printf("Queue after appending elements:\n");
    TraverseQueue(&q, printElement);
    printf("\n");
    if (!QueueEmpty(&q)) {
        serve(&data, &q);
        printf("Served element: %d\n", data);
    }
    printf("Queue after serving an element:\n");
    TraverseQueue(&q, printElement);
    printf("\n");
    if (QueueEmpty(&q)) {
    printf("The queue is empty.\n");
} else {
    printf("The queue is not empty.\n");
}

if (QueueFull(&q)) {
    printf("The queue is full.\n");
} else {
    printf("The queue is not full.\n");
}
    clearQueue(&q);
    printf("Queue cleared.\n");
    printf("Queue after clearing:\n");
    TraverseQueue(&q, printElement);
    printf("\n");

    return 0;
}
