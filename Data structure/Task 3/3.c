#include <stdio.h>
#include <stdlib.h>

typedef struct listnode {
    int entry;
    struct listnode *next;
} listnode;

typedef struct list {
    listnode *head;
    int size;
} list;

void insertlist(int pos, int e, list *pl) {
    listnode *p, *q;
    int i;
    p = (listnode *)malloc(sizeof(listnode));
    p->entry = e;
    p->next = NULL;
    if (pos == 0) {
        p->next = pl->head;
        pl->head = p;
    } else {
        for (q = pl->head, i = 0; i < pos - 1; i++)
            q = q->next;
        p->next = q->next;
        q->next = p;
    }
    pl->size++;
}


int findMiddle(list *pl) {
    listnode *onenode = pl->head;
    listnode *twonodes = pl->head;
    if (pl->head == NULL) {
        return -1;
    }
    while (onenode != NULL && twonodes->next != NULL) {
        onenode = onenode->next;
        twonodes = twonodes->next->next;
    }

    return onenode->entry;
}

int main() {
    list myList;
    myList.head = NULL;
    myList.size = 0;

    insertlist(0, 10, &myList);
    insertlist(1, 20, &myList);
    insertlist(2, 30, &myList);
    printf("\nMiddle node value: %d\n", findMiddle(&myList));

    return 0;
}

