#include <stdio.h>
#include "implementation of queue using linked list.h"

 int main() {
    Queue q;
    int data;
    createQueue(&q);
    Append(10, &q);
    Append(20, &q);
    printf("Queue after Appending elements:\n");
    TraverseQueue(&q, printElement);
    printf("\n");
    printf("Queue size: %d\n", getSize(&q));
    if (!isEmpty(&q)) {
        serve(&data, &q);
        printf("served element: %d\n", data);
    }
    printf("Queue after serving an element:\n");
    TraverseQueue(&q, printElement);
    printf("\n");

    printf("Queue size after dequeue: %d\n", getSize(&q));

    Clear_Queue(&q);
    printf("Queue cleared.\n");

    printf("Queue size after clearing: %d\n", getSize(&q));

    return 0;
}
