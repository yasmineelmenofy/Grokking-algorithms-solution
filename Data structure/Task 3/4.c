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

int sum(list *pl) {
    listnode *current = pl->head;
    int sum = 0;
    while (current != NULL) {
        sum += current->entry;
        current = current->next;
    }

    return sum;
}

int main() {
    list myList;
    myList.head = NULL;
    myList.size = 0;

    insertlist(0, 10, &myList);
    insertlist(1, 20, &myList);
    insertlist(2, 30, &myList);

    printf("\nSum of all nodes: %d\n", sum(&myList));

    return 0;
}
