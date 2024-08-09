#include "queue implementation using an array.h"
#include <stdio.h>

void createQueue(Queue *pq) {
    pq->front = 0;
    pq->rear = -1;
    pq->size = 0;
}

void Append(int data, Queue *pq) {
    if (QueueFull(pq)) {
        printf("Queue is full\n");
        return;
    }
    pq->rear = (pq->rear + 1) % MAXQUEUE;
    pq->array[pq->rear] = data;
    pq->size++;
}

void serve(int *pdata, Queue *pq) {
    if (QueueEmpty(pq)) {
        printf("Queue is empty\n");
        return;
    }
    *pdata = pq->array[pq->front];
    pq->front = (pq->front + 1) % MAXQUEUE;
    pq->size--;
}

int QueueEmpty(Queue *pq) {
    return pq->size == 0;
}

int QueueFull(Queue *pq) {
    return pq->size == MAXQUEUE;
}

void clearQueue(Queue *pq) {
    pq->front = 0;
    pq->rear = -1;
    pq->size = 0;
}

void TraverseQueue(Queue *pq, void (*pf)(int)) {
    int pos = pq->front;
    for (int s = 0; s < pq->size; s++) {
        (*pf)(pq->array[pos]);
        pos = (pos + 1) % MAXQUEUE;
    }
}

int Queuesize(Queue *pq) {
    return pq->size;
}

void printElement(int element) {
    printf("%d ", element);
}



