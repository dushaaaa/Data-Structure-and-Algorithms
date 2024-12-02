#include <stdio.h>
#include <string.h>

#define SIZE 10

typedef struct {
	char Name[20];
	unsigned int ID;
	char course[8];
	int yearLevel;
} studtype;

typedef struct {
	studtype stud[SIZE];
	int count;
} ArrayList;

void display(ArrayList list) {

    printf("    Name   |   ID   |  Course  |  Year  \n");
    printf("-----------------------------------\n");

    for(int i = 0; i < list.count; i++) {
        printf(" %8s  | %5d  | %5s    | %3d \n", 
        list.stud[i].Name, 
        list.stud[i].ID, 
        list.stud[i].course,
        list.stud[i].yearLevel);
    }
}

void insert(ArrayList *list, studtype stud) {
    //if list is empty
    if(list->count == 0) {
        list->stud[0] = stud;
    } 
    else 
    {
        int pos, i;
        for(pos = 0; pos < list->count && (strcmp(list->stud[pos].Name, stud.Name) <= 0); pos++) {}

        for(i = list->count; i > pos; i--) {
            list->stud[i] = list->stud[i-1];
        }
        list->stud[pos] = stud;
    }
    list->count++;
}

void delete(ArrayList *list, studtype stud) {
    int pos, i;
    for(pos = 0; pos < list->count && (strcmp(list->stud[pos].Name, stud.Name) != 0); pos++) {}

    for(i = pos; i < list->count; i++) {
        list->stud[i] = list->stud[i+1];
    }
    list->count--;
}


int main(void) {

    ArrayList list = {0};
    studtype stud1 = {"Alice", 101, "CS", 2};
    studtype stud2 = {"Bob", 102, "IT", 3};
    studtype stud3 = {"Charlie", 103, "CS", 1};
    studtype stud4 = {"Xion", 104, "CS", 2};

    insert(&list, stud1);
    insert(&list, stud4);
    insert(&list, stud2);
    insert(&list, stud3);
    delete(&list, stud4);
    display(list);

    return 0;
}