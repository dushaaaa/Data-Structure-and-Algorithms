#include <stdio.h>
#include <stdlib.h>
#define MAX 10

typedef struct node{
    int data;
    struct node *link;
} *Node;

typedef Node Dictionary[MAX];

void initDict(Dictionary D) {
    int i;
    for (i = 0; i < MAX; i++) {
        D[i] = NULL;
    }
}

int hash(int num) {

    return num % MAX;
}

void insert(Dictionary *D, int num) {
    int hashVal = hash(num);
    Node *trav, newNode;

    for (trav = &(*D)[hashVal]; *trav != NULL && num > (*trav)->data; trav = &(*trav)->link) {}
    if (*trav != NULL && (*trav)->data == num) {
        printf("%d is already in the set\n\n", num);
    } else {
        newNode = (Node)malloc(sizeof(struct node));
        if (newNode != NULL) {
            newNode->data = num;
            newNode->link = *trav;
            *trav = newNode;
        }
    }
    
    
}

void delete(Dictionary *D, int num) {
    int hashVal = hash(num);
    Node *trav, temp;

    for (trav = &(*D)[hashVal]; *trav != NULL && (*trav)->data != num; trav = &(*trav)->link) {}
    temp = *trav;
    *trav = temp->link;
    free(temp);
}

void populate(Dictionary *D, int *set, int size) { //u can use int set[]
    int i;
    for (i = 0; i < size; i++) {
        insert(D, set[i]);
    }
}


void display(Dictionary D) {
    int i;
    Node trav;

    for (i = 0; i < MAX; i++) {
        printf("%d", i);

        for (trav = D[i]; trav != NULL; trav = trav->link) {
            printf(" -> %d", trav->data);
        }
        printf("\n");
    }
}





int main(void) {
    printf("hello there~~~\n");

    Dictionary D;
    initDict(D);

    int setA[] = { 0, 13, 20, 28, 30, 33, 45, 48, 48, 108 };
    int size = sizeof(setA) / sizeof(setA[0]);

    populate(&D, setA, size);

    
    // insert(&D, 108);
    // insert(&D, 48);
    // insert(&D, 23);
    // insert(&D, 28);
    // insert(&D, 20);
    // insert(&D, 55);
    // insert(&D, 0);
    // insert(&D, 13);

    delete(&D, 28);
    delete(&D, 13);
    delete(&D, 30);
    display(D);

    return 0;
}