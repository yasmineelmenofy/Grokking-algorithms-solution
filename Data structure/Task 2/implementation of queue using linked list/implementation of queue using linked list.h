#ifndef IMPLEMENTATION_OF_QUEUE_USING_LINKED_LIST_H_INCLUDED
#define IMPLEMENTATION_OF_QUEUE_USING_LINKED_LIST_H_INCLUDED

typedef struct Node {
    int data;
    struct Node *next;
} Node;

typedef struct Queue {
    Node *front;
    Node *rear;
    int size
} Queue;

void createQueue(Queue *pq);
void Append(int data, Queue *pq);
void serve(int *pdata, Queue *pq);
int isEmpty(Queue *pq);
int getSize(Queue *pq);
void Clear_Queue(Queue *pq);
void TraverseQueue(Queue *pq, void (*pf)(Node *));
void printElement(Node *node);



#endif // IMPLEMENTATION_OF_QUEUE_USING_LINKED_LIST_H_INCLUDED
