typedef struct node {
    int num;
    struct node *next;
} *Stack;

Write the code of the function popFactors(). Given the stack of integers and an integer N, the function will remove the given stack all factors of N and put them in a new stack which will be returned to the calling function.
Note:  x is a factor of N is N is exactly divisible by x.

Constraints:
    1. Function popFactors() cannot call user-defined functions.
    2. There should be 1 retyrn statement only.

