#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node* next;
};

struct Node* top = NULL;

void push(int val){
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if(newNode==NULL){
        perror("Stack Overflow\n");
        return;
    }
    newNode->data = val;
    newNode->next = NULL;
    top = newNode;
    printf("%d pushed into stack\n",val);
}

void pop(){
    if(top==NULL){
        perror("Stack Underflow\n");
        return;
    }
    struct Node* temp = top;
    printf("%d popped out from the stack\n",top->data);
    top = top->next;
    free(temp);
}

void peek(){
    if(top==NULL){
        printf("Stack is empty\n");
        return;
    }
    printf("Top element is %d\n",top->data);
}

void display(){
    if(top==NULL){
        printf("Stack is empty\n");
        return;
    }
    struct Node* temp = top;
    printf("Stack Elements : ");
    while(temp!=NULL){
        printf("%d ->",temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}
int main(){
    push(47);
    push(60);
    pop();
    push(402);
    push(13);
    display();
    return 0;
}