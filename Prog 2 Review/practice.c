// A list is implemented as a pointer to a structure containing two arrays box and next. 
// Each element in the list corresponds to a pair (box[x], next[x]), where box[x] is the value of the element, and next[x] is the index of the next element in the list.
// Given, next[0] holds the index of first element of the list and the index x whose next[x] is 0 indicates the last element of the list.

#define MAX 10

typedef struct {
    char box[MAX];
    int next[MAX];
} *CursorList;

Based on the definition, write the code of function isMember().
The function will return 1 if given element is a member of the given list.
Constraints:
- function will have only one return statement
- no exit or break statement
- condition should be logical and relational expression

int isMember(CursorList *CL, char elem) {
    for (int x = CL->next[0]; x!=0 && CL->box[next]!=elem; x = CL->box[next]){}

    return (CL->box[next] == elem) ? 1:0;
}


typedef struct {
    char FN[24], LN[16], MI;
} nameType;

typedef struct {
    char ID[10];
    nameType name;
    char course[8]; //BSIT, BSCS, BSIS only
    int yrLevel;
} studRec;

typedef struct node {
    studRec stud;
    struct node *link;
} *StudLink;

#define MAX 0xA
typedef struct arr {
    studRec stud[MAX];
    int count;
} *StudArray;

typedef struct {
    StudLink CS; //CS list
    StudArray IT; // IT list
} Combolist;


Combolist *distributeStuds(StudLink *list) {
    Combolist *combo = (Combolist*)malloc(sizeof(struct node));
    combo->CS = NULL:
    combo->IT =(StudArray)malloc(sizeof(struct array));
    combo->IT->count = 0;

    for (trav = list; *trav != NULL; trav = &(*trav)->link) {
        if (strcmp((*trav)->stud.course, "BSCS")== 0) {
            StudLink newNode = (StudLink)malloc(sizeof(struct node));
            if (newNode != NULL) {
                newNode->stud = (*trav)->stud;
                newNode->link = combo->CS;
                combo->CS = newNode;
            }
            StudLink temp = *trav;
            *trav = (*trav)->link;
            free(temp);
        } else if (strcmp((*trav)->stud.course, "BSIT") == 0) {
            if (combo->IT->count < MAX) {
                combo->IT->stud[combo->IT->count] = (*trav)->stud;
                combo->IT->count;
            }
            StudLink temp = *trav;
            *trav = (*trav)->link;
            free(temp);
        }
    }
    return Combolist;
}