typedef enum {
    ASIAN, EU_US;
} makeTYpe;

typedef enum {
    FALSE, TRUE;
} Boolean;

typedef struct {
    char brand[20];
    char model[20];
    int year;
    makeType carMake;
}

//Assumptions: data types stacks and queue are both defined. their deifinitions are unknown to the user.

typedef struct {
    Stack S;
    Queue Q;
} ComboSQ;

Given a car record and an anddress of the ComboSQ, write the code of the function searchCarModel(). The function search for a given car in the stack of the given ComboSQ if the car is Asian made; otherwise search the cra in the queue.
Car is uniquely identigied by it's model. If the given car is found in the ComboSQ, return TRUE; otherwise return FALSE.

Note that both stack and queue cannot be traversed and the order of elements before and after the operations should be the same. Functions whose prototypes are listed below should be called in the function if needed. 

void initStack(Stack *S);
void push(CarType c, Stack *S);
CarType pop(Stack *S);
Boolean isEmptyStack(Stack S);
Boolean isFullStack(Stack S);
void initQueue(Queue *Q);
void Enqueue(CarType c, Queue *Q);
CarType dequeue(Queue *Q);
Boolean isEmptyQueue(Queue Q);
Boolean isFullQueue(Queue Q);