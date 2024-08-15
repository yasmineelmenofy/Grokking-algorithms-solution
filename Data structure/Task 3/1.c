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

void deleteList(int pos, int *pe, list *pl) {
    int i;
    listnode *q, *temp;

    if (pos == 0) {
        *pe = pl->head->entry;
        temp = pl->head->next;
        free(pl->head);
        pl->head = temp;
    } else {
        for (q = pl->head, i = 0; i < pos - 1; i++)
            q = q->next;
        *pe = q->next->entry;
        temp = q->next->next;
        free(q->next);
        q->next = temp;
    }
    pl->size--;
}


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

void visit(int entry) {
    printf("%d\n", entry);
}

void transverselist(list *pl, void (*visit)(int)) {
    listnode *p = pl->head;
    while (p) {
        (*visit)(p->entry);
        p = p->next;
    }
}

int main() {
    list myList;
    myList.head = NULL;
    myList.size = 0;
    int deletedValue;

    insertlist(0, 10, &myList);
    insertlist(1, 20, &myList);
    insertlist(2, 30, &myList);

    printf("Original list:\n");
    transverselist(&myList, visit);

    printf("\nDeleting the first node \n");
    deleteList(0, &deletedValue, &myList);
    printf("Deleted value: %d\n", deletedValue);
    transverselist(&myList, visit);

    printf("\nDeleting a middle node (20):\n");
    deleteList(1, &deletedValue, &myList);
    printf("Deleted value: %d\n", deletedValue);
    transverselist(&myList, visit);


    return 0;
}
