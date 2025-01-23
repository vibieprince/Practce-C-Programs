#include<stdio.h>
#include<stdlib.h>
#define SIZE 5
struct Node{
    int data;
    struct Node* prev;
    struct Node* next;
};
void mergeTwoSortedArray(int arr1[],int n,int arr2[],int m){
    int arr[n+m];
    int i=0,j=0,k=0;
    while(i<n && j<m){
        if(arr1[i]<arr2[j]){
           arr[k] = arr1[i];
           k++;
           i++;
        }
        else{
            arr[k] = arr2[j];
            k++;
            j++;
        }
    }
    // If still any array field is left
    while(i<n){
        arr[k]=arr[i];
        k++;
        i++;
    }
    while(j<m){
        arr[k] = arr[j];
        k++;
        j++;
    }
    // Print merged array 
    for(int i=0;i<n+m;i++){
        printf("%d ",arr[i]);
    }
    printf("/n");
}
void delete_in_DLL(struct Node**head,int pos){
    if(head==NULL)
        return;
    if(pos<=0){
        printf("Invalid Position\n");
        return;
    }
    struct Node* temp = *head;
    int i=1;
    while(temp!=NULL && i<pos){
        temp = temp->next;
        i++;
    }
    if(temp==NULL){
        printf("Position out of bounds\n");
        return;
    }
    if(temp==*head){
        *head = temp->next;
        if((*head)->next !=NULL)
           (*head)->prev = NULL;
    }
    else if(temp->next==NULL)
       temp->prev->next = NULL;
    else{
        temp->prev->next = temp->next;
        temp->next->prev = temp->prev;
    }
    printf("Node deleted with data %d ",temp->data);
    free(temp);
}
void TowerOfHanoi(int n,char A,char B,char C){
    if(n==1){
        printf("Move disk 1 from rod %c to rod %c\n",A,C);
        return;
    }
    TowerOfHanoi(n-1,A,B,C);
    printf("Move disk %d from rod %c to %c\n",n,A,C);
    TowerOfHanoi(n-1,B,C,A);
}
typedef struct Queue{
    int arr[SIZE];
    int front,rear;
}Queue;

void initQueue(Queue *q){
    q->front = -1;
    q->rear = -1;
}

void enqueue(Queue *q,int val){
    if(q->rear == SIZE-1){
        printf("Queue is full");
        return;
    }
    if(q->front==-1)
       q->front = 0;

    q->arr[++q->rear] = val;
    printf("%d enqueued to queue\n",val);
}

int dequeue(Queue *q){
    if(q->front == -1 || q->front > q->rear){
        printf("Queue is empty\n");
        return;
    }
    int val = q->arr[q->front++];
    if(q->front > q->rear)
        q->front = q->rear = -1;
    return val;
}

void display(Queue *q){
    if(q->front==-1){
        printf("Queue is empty\n");
        return;
    }
    printf("Queue : ");
    for(int i=q->front;i<=q->rear;i++)
       printf("%d ",q->arr[i]);
    printf("\n");
}

// Queue using linked list
typedef struct LQueue{
    int data;
    struct Node* next;
}Node;
typedef struct LQueue{
    Node* front;
    Node* rear;
}LQueue;

void initQueue(LQueue *q){
    q->front = q->rear = NULL;
}

void enqueue(LQueue *q,int val){
    Node *newNode = (Node*)malloc(sizeof(Node));
    if(!newNode){
        printf("Memory allocation failed");
        return;
    }
    newNode->data = val;
    newNode->next = NULL;

    if(q->rear == NULL){
        q->front = q->rear = newNode;
        printf("%d enqueued to queue\n",val);
        return;
    }

    q->rear->next = newNode;
    q->rear = newNode;
    printf("%d enqueued to queue\n",val);

}

int dequeue(LQueue *q){
    if(q->front == NULL){
        printf("Queue is empty\n");
        return -1;
    }
    Node *temp = q->front;
    int val = temp->data;
    q->front = q->front->next;

    if(q->front == NULL)
       q->rear = NULL;
    
    free(temp);
    return val;
}

void display(Queue *q){
    if(q->front == NULL){
        printf("Queue is empty\n");
        return;
    }
    Node *temp = q->front;
    printf("Queue : ");
    while(temp){
        printf("%d ",temp->data);
        temp = temp->next;
    }
    printf("\n");
}