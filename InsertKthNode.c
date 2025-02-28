#include<stdio.h>
#include<stdlib.h>
struct Node{
    int data;
    struct Node* next;
};

struct Node* createNode(int val){
    struct Node* newNode = malloc(sizeof(struct Node));
    if(newNode==NULL){
        printf("Memory allocation failed");
        return NULL;
    }
    newNode->data = val;
    newNode->next = NULL;
}

void insertAtKthPosition(struct Node** head,int val,int pos){
    struct Node* newNode = createNode(val);
    if(newNode==NULL)
        return;
    if(pos==1){
        newNode->next = *head;
        *head = newNode;
        return;
    }
    struct Node *temp = *head;
    int i = 1;
    while(i<pos-1 && temp!=NULL){
        temp = temp->next;
        i++;
    }
    if(temp==NULL){
        printf("%d position is out of bounds\n",pos);
        free(temp);
        return;
    }
    newNode->next = temp->next;
    temp->next = newNode;
    printf("%d is inserted at position %d\n",val,pos);
}

void printList(struct Node* head){
    while(head!=NULL){
        printf("%d->",head->data);
        head = head->next;
    }
    printf("NULL\n");
}

int main(){
    struct Node* head = NULL;
    insertAtKthPosition(&head,10,1);
    printList(head);
    insertAtKthPosition(&head,50,2);
    printList(head);
    insertAtKthPosition(&head,78,2);
    printList(head);
    insertAtKthPosition(&head,12,4);
    printList(head);
    return 0;
}