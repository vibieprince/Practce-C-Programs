#include<stdio.h>
#include<stdlib.h>
struct Node{
    int data;
    struct Node* next;
};
struct Node* createNode(int val){
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if(newNode==NULL){
        perror("Memory allocation failed\n");
        return NULL;
    }
    newNode->data = val;
    newNode->next = NULL;
    return newNode;
}
void insertAtEnd(struct Node** head,int val){
    struct Node* newNode = createNode(val);
    if(*head==NULL){
        *head = newNode;
        return;
    }
    struct Node* temp = *head;
    while(temp->next !=NULL)
        temp = temp->next;
    temp->next = newNode;
}
void reversePrint(struct Node* head){
    if(head==NULL){
        printf("NULL");
        return;
    }
    reversePrint(head->next);
    printf("<-%d",head->data);
}
int main(){
    struct Node* head = NULL;

    insertAtEnd(&head,10);
    insertAtEnd(&head,40);
    insertAtEnd(&head,46);
    insertAtEnd(&head,16);
    insertAtEnd(&head,24);

    printf("Reversed List : ");
    reversePrint(head);

    return 0;
}