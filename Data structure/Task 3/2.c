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

void reverseList(list *pl) {
    listnode *prev = NULL, *current = pl->head, *next = NULL;

    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }

    pl->head = prev;
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

    insertlist(0, 10, &myList);
    insertlist(1, 20, &myList);
    insertlist(2, 30, &myList);
    insertlist(3, 40, &myList);

    printf("Original list:\n");
    transverselist(&myList, visit);

    reverseList(&myList);

    printf("\nReversed list:\n");
    transverselist(&myList, visit);

    return 0;
}
