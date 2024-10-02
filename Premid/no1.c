#include <stdio.h>
#define SIZE 0XA

typedef struct {
    int data;
    int link;
} Nodetype;

typedef struct VHnode {
    Nodetype heap[SIZE];
    int availList;
} *VHeap; // shared by all cursorlist

typedef struct {
    int elemPtr; // points to the first element of the list
    VHeap VH; // points to the shared virtual heap
} cursorList;

Write a code fo the function getEven(), the function will remove all even numbers in the given list and put them in a newly created cursor list, which will be returned to the calling function.
Constraints:
   1)  Function getEven() cannot call user-defined functions.
   2)  One return statement only

Instructions:
1) Preformat answer, BOLDFACE and with FONT size 10
2) Remove unnecessary lines 
3) Deductions will be made if instructions are not followed