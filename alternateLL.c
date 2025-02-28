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
struct Node* createAlternate(struct Node* head){
    if(head==NULL)
        return NULL;
    struct Node* newHead = NULL;
    struct Node* temp = head;
    int index = 0;

    while(temp!=NULL){
        if(index%2==0)
           insertAtEnd(&newHead,temp->data);
        temp = temp->next;
        index++;
    }
    return newHead;
}

void printList(struct Node* head){
    struct Node* temp = head;
    while(temp!=NULL){
        printf("%d->",temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main(){
    struct Node* head = NULL;
    struct Node* newHead = NULL;

    insertAtEnd(&head,10);
    insertAtEnd(&head,40);
    insertAtEnd(&head,46);
    insertAtEnd(&head,16);
    insertAtEnd(&head,24);

    printf("Original Linked List : ");
    printList(head);

    newHead = createAlternate(head);

    printf("New Linked List with alternate elements\n");

    printList(newHead);

    return 0;
}