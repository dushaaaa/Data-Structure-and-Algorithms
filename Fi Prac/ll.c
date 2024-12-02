#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct {
    int idNum;
    int age;
    char name[20];
} Stud;

typedef struct node {
    Stud data;
    struct node *link;
} *LIST;

void initList(LIST *L) {
    *L = NULL;
    //printf("yey");
}

void display(LIST L) {
    LIST trav;

    printf("  Age  |    Name   |  IdNum\n");
    printf("--------------------------\n");

    for(trav = L; trav != NULL; trav = trav->link) {
        printf("%5d  | %8s  |  %d\n", trav->data.age, trav->data.name, trav->data.idNum);
    }
}

void insertFirst(LIST *L, Stud newStud) {
    LIST *trav;
    
    for(trav = L; *trav != NULL && (*trav)->data.idNum != newStud.idNum; trav = &(*trav)->link) {}
    if(*trav == NULL) {
        LIST newNode = (LIST)malloc(sizeof(struct node));
        if(newNode != NULL) {
            newNode->data.age = newStud.age;
            strcpy(newNode->data.name, newStud.name);
            newNode->data.idNum = newStud.idNum;
            newNode->link = *L;
            *L = newNode;
        } else {
            printf("No more mem\n");
        }
    }
}

void insertLast(LIST *L, Stud newStud) {
    LIST *trav;

    for(trav = L; *trav != NULL && (*trav)->data.idNum != newStud.idNum; trav = &(*trav)->link) {}
    if(*trav == NULL) {
        LIST newNode = (LIST)malloc(sizeof(struct node));
        if (newNode != NULL) {
            newNode->data.age = newStud.age;
            newNode->data.idNum = newStud.idNum;
            strcpy(newNode->data.name, newStud.name);
            newNode->link = NULL;
            *trav = newNode;
        }
    }
}

void insertSorted(LIST *L, Stud newStud) {
    LIST *trav;

    for(trav = L; *trav != NULL && (*trav)->data.idNum < newStud.idNum; trav = &(*trav)->link) {}
    LIST newNode = (LIST)malloc(sizeof(struct node));
    if(newNode != NULL) {
        newNode->data.idNum = newStud.idNum;
        newNode->data.age = newStud.age;
        strcpy(newNode->data.name, newStud.name);
        newNode->link = *trav;
        *trav = newNode;
    }
}

void deleteElem(LIST *L, Stud newStud) {
    LIST *trav, temp;

    for(trav = L; *trav != NULL && (*trav)->data.idNum != newStud.idNum; trav = &(*trav)->link) {}
    if(*trav != NULL) {
        temp = *trav;
        *trav = temp->link;
        free(temp);
    }
}

int main(void) {
    LIST L;
    initList(&L);

   Stud stud1 = {101, 20, "Alice"};
    Stud stud2 = {102, 22, "Bob"};
    Stud stud3 = {103, 19, "Charlie"};
    Stud stud4 = {105, 30, "Dane"};
    Stud stud5 = {104, 23, "Elli"};

    insertFirst(&L, stud3);
    insertLast(&L, stud4);
    insertFirst(&L, stud1);
    insertSorted(&L, stud2);
    insertSorted(&L, stud5);

    deleteElem(&L, stud2);
    deleteElem(&L, stud5);

    display(L);


}