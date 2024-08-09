#ifndef QUEUE_IMPLEMENTATION_USING_AN_ARRAY_H_INCLUDED
#define QUEUE_IMPLEMENTATION_USING_AN_ARRAY_H_INCLUDED
#define MAXQUEUE 10
#include <stdio.h>


typedef struct Queue {
    int front;
    int rear;
    int size;
    int array[MAXQUEUE];
} Queue;





void createQueue(Queue *pq);
void Append(int data, Queue *pq);
void serve(int *pdata, Queue *pq);
int Queueempty(Queue *pq);
int Queuefull(Queue *pq);
int Queuesize(Queue *pq);
void clearQueue(Queue *pq);
void TraverseQueue(Queue *pq, void (*pf)(int));
void printElement(int element);

#endif // QUEUE_IMPLEMENTATION_USING_AN_ARRAY_H_INCLUDED
