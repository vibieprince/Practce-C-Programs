#include<stdio.h>
#include<stdlib.h>

struct Node1{
    int data;
    struct Node* next;
};

void push(struct Node1** top,int val){
    struct Node1* newNode = (struct Node1*)malloc(sizeof(struct Node1));
    if(!newNode){
        perror("Memory allocation failed");
        return;
    }   
    newNode->data = val;
    newNode->next = *top;
    *top = newNode;
    printf("%d pushed to stack\n",val);
}

int pop(struct Node1**top){
    if(*top==NULL){
        printf("Stack is empty\n");
        return -1;
    }
    struct Node1* temp = *top;
    int poppedVal = temp->data;
    *top = (*top)->next;
    free(temp);
    return poppedVal;
}

int peek(struct Node1* top){
    if(top==NULL){
        printf("Stack underflow");
        return -1;
    }
    return top->data;
}

int isEmpty(struct Node1* top){
    return top==NULL;
}

void display(struct Node1* top){
    if(top==NULL){
        perror("stack is empty");
        return;
    }
    struct Node1* temp = top;
    while(temp!=NULL){
        printf("%d ",temp->data);
        temp = temp->next;
    }
    printf("/n");
}

struct Node{
    float coeff;
    int expo;
    struct Node* next;
};

void addpoly(struct Node* head1,struct Node* head2){
    struct Node*poly1,*poly2,*head3;
    poly1 = head1;
    poly2 = head2;
    head3 = NULL;
    while(poly1!=NULL && poly2!=NULL){
        if(poly1->expo == poly2->expo){
            head3 = insert(head3,poly1->coeff+poly2->coeff,poly1->expo);
            poly1 = poly1->next;
            poly2 = poly2->next;
        }
        else if(poly1->expo > poly2->expo){
            head3 = insert(head3,poly1->coeff,poly1->expo);
            poly1 = poly1->next;
        }
        else if(poly2->expo > poly1->expo){
            head3 = insert(head3,poly2->coeff,poly2->expo);
            poly2 = poly2->next;
        }
        while(poly1!=NULL){
            head3 = insert(head3,poly1->coeff,poly1->expo);
            poly1 = poly1->next;
        }
        while(poly2!=NULL){
            head3 = insert(head3,poly2->coeff,poly2->expo);
            poly2 = poly2->next;
        }
    }
}

struct Node* insert(struct Node** poly,int coeff,int expo){
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if(*poly==NULL)
       *poly = newNode;
    else{
        struct Node* temp = *poly;
        while(temp->next!=NULL)
            temp = temp->next;
        temp->next = newNode;
    }
}

struct Node2{
    int data;
    struct Node2* next;
};

struct Node* createNode(int val){
    struct Node2* newNode = (struct Node2*)malloc(sizeof(struct Node2));
    newNode->data = val;
    newNode->next = NULL;
    return newNode;
}

void insertAfter(struct Node2* prevNode,int val){
    if(prevNode==NULL){
        printf("Previous Node cannot be NULL");
        return;
    }
    struct Node2* newNode = createNode(val);
    newNode->next = prevNode->next;
    prevNode->next = newNode;
}