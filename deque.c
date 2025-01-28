#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#define MAX 100
struct DeQueue{
    int arr[MAX];
    int front;
    int rear;
};
bool isFull(struct DeQueue *dq){
    return ((dq->rear + 1)% MAX == dq->front);
}

bool isEmpty(struct DeQueue *dq){
    return dq->front == -1;
}

void initDeQueue(struct DeQueue *dq){
    dq->front = dq->rear = -1;
}

void pushFront(struct DeQueue *dq,int val){
    if(isFull(dq)){
        perror("DeQueue Overflow\n");
        return;
    }
    else if(isEmpty(dq))
       dq->front = dq->rear = 0;
    else
       dq->front = (dq->front - 1 + MAX) % MAX;
    dq->arr[dq->front] = val;
    
}

void pushBack(struct DeQueue *dq,int val){
    if(isFull(dq)){
        perror("DeQueue Overflow\n");
        return;
    }
    else if(isEmpty(dq))
        dq->front = dq->rear = 0;
    else
        dq->rear = (dq->rear + 1)%MAX;
    dq->arr[dq->rear] =  val;
}

void popFront(struct DeQueue *dq){
    if(isEmpty(dq)){
        perror("DeQueue Underflow");
        return;
    }
    printf("Popped from front : %d\n",dq->arr[dq->front]);
    if(dq->front == dq->rear)
       dq->front = dq->rear = -1;
    else
       dq->front = (dq->front + 1)% MAX;
}

void popBack(struct DeQueue *dq){
    if(isEmpty(dq)){
        printf("DeQueue Underflow\n");
        return;
    }
    printf("Popped from back\n");

    if(dq->front == dq->rear)
       dq->front = dq->rear = -1;
    
    else
       dq->rear = (dq->rear - 1 + MAX) % MAX;
}

void display(struct DeQueue *dq){
    if(isEmpty(dq)){
        printf("DeQueue is empty\n");
        return;
    }
    printf("DeQueue elements : ");
    int i = dq->front;
    while(true){
        printf("%d ",dq->arr[i]);
        if(i==dq->rear)
           break;
        i = (i+1) % MAX;
    }
    printf("\n");
}

int main() {
    struct DeQueue dq;
    initDeQueue(&dq);

    pushBack(&dq, 10);
    pushBack(&dq, 20);
    pushFront(&dq, 5);
    pushFront(&dq, 1);
    pushBack(&dq, 30);

    display(&dq); // Expected Output: 1 5 10 20 30

    popFront(&dq); // Removes 1
    popBack(&dq);  // Removes 30

    display(&dq); // Expected Output: 5 10 20

    return 0;
}