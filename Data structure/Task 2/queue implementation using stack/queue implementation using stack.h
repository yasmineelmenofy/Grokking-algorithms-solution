#ifndef QUEUE_IMPLEMENTATION_USING_STACK_H_INCLUDED
#define QUEUE_IMPLEMENTATION_USING_STACK_H_INCLUDED
#define MAXSTACK 10

typedef struct Stack {
    int array[MAXSTACK];
    int top;
} Stack;

typedef struct Queue {
    Stack stack1;
    Stack stack2;
} Queue;

void createStack(Stack *s);
int isStackFull(Stack *s);
int isStackEmpty(Stack *s);
void push(Stack *s, int data);
int pop(Stack *s, int *data);

void createQueue(Queue *q);
void Append(int data, Queue *q);
void serve(int *data, Queue *q);
int QueueEmpty(Queue *q);
int Queuesize(Queue *q);




#endif // QUEUE_IMPLEMENTATION_USING_STACK_H_INCLUDED
