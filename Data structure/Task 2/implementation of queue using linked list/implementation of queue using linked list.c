#include <stdio.h>
#include <stdlib.h>
#include "implementation of queue using linked list.h"

void createQueue(Queue *pq) {
    pq->front = NULL;
    pq->rear = NULL;
}

void Append(int data , Queue *pq) {
    Node *pnew = (Node *)malloc(sizeof(Node));
    pnew->data = data;
    pnew->next = NULL;

    if (! pq->rear ) {
        pq->front = pnew;
    } else {
        pq->rear->next = pnew;
    }
    pq->rear = pnew;
    pq->size ++;
}
void serve(int *pdata,Queue *pq) {
    Node *pn = pq->front;
    *pdata = pn->data;
    pq->front = pn->next;
    if (!pq->front) {
        pq->rear = NULL;
    }
    free(pn);
    pq->size --;

}

int isEmpty(Queue *pq) {
    return !pq->front;
}

int getSize(Queue *pq) {
    return pq->size;
}
void Clear_Queue(Queue *pq)
{
    Node *pn = pq->front;
    Node *qn = pq->rear;

    while (pn)
    {
        qn = pn->next;
        free(pn);
        pn = qn;
    }

    pq->size = 0;
    pq->front = NULL;
    pq->rear = NULL;
}

void TraverseQueue(Queue *pq, void (*pf)(Node *)) {
    Node *current = pq->front;
    while (current != NULL) {
        pf(current);
        current = current->next;
    }
}

void printElement(Node *node) {
    if (node != NULL) {
        printf("%d ", node->data);
    }
}

