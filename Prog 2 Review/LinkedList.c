#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *link;
} *LIST;

void initList(LIST *L) {
    *L = NULL;
    printf("succ\n");
}

void displayList(LIST L) {
    LIST trav;
    for(trav = L; trav != NULL; trav = trav->link) {
        printf("%d ", trav->data);
    }
}

void insertFirst(LIST *L, int elem) {
    LIST *trav;
    for(trav = L; *trav != NULL && (*trav)->data != elem; trav = &(*trav)->link) {}
    if (*trav == NULL) {
        LIST newNode = (LIST)malloc(sizeof(struct node));
        if (newNode != NULL) {
            newNode->data = elem;
            newNode->link = *L;
            *L = newNode;
        }
    }
    
}

void insertLast(LIST *L, int elem) {
    LIST temp, *trav;

    for (trav = L; *trav != NULL && (*trav)->data != elem; trav = &(*trav)->link){}
    if (*trav == NULL) {
        temp = (LIST)malloc(sizeof(struct node));
        if (temp != NULL) {
            temp->data = elem;
            temp->link = NULL;
            *trav = temp;
        }
    }
}

void insertSorted (LIST *L, int elem) {
    LIST *trav, newNode;
    for (trav = L; *trav != NULL && (*trav)->data > elem; trav = &(*trav)->link) {}
    newNode = (LIST)malloc(sizeof(struct node));
    if (newNode != NULL) {
        newNode->data = elem;
        newNode->link = *trav;
        *trav = newNode;
    }
}

void deleteFirst(LIST *L) {
    if (*L == NULL) {
        printf("List is empty.");
        return;
    }
    LIST temp = *L;
    *L = temp->link;
    free(temp);
}

void deleteElem(LIST *L, int elem) {
    LIST *trav, temp;
    for (trav = L; *trav != NULL && (*trav)->data != elem; trav = &(*trav)->link) {}
    if (*trav != NULL) {
        temp = *trav;
        *trav = temp->link;
        free(temp);
    }
}

int main(void) {
    printf("iss linked lists\n");

    LIST list;
    initList(&list);

    insertFirst(&list, 1);
    //insertFirst(&list, 2);
    insertFirst(&list, 3);
    insertLast(&list, 0);
    insertLast(&list, -1);
    insertLast(&list, 1);
    //insertFirst(&list, 4);
    insertFirst(&list, 5);
    insertSorted(&list, 4);
    insertSorted(&list, 2);

    deleteFirst(&list);
    deleteElem(&list, 2);
    deleteElem(&list, 0);

    displayList(list);
}
