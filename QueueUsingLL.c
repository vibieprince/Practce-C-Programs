#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node *front = NULL, *rear = NULL;

void enqueue(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;
    if (rear == NULL) front = rear = newNode;
    else {
        rear->next = newNode;
        rear = newNode;
    }
    printf("Inserted %d\n", value);
}

void dequeue() {
    if (front == NULL) {
        printf("Queue is Empty\n");
        return;
    }
    struct Node* temp = front;
    printf("Removed %d\n", front->data);
    front = front->next;
    free(temp);
    if (front == NULL) rear = NULL;  // Reset queue when empty
}

void display() {
    if (front == NULL) {
        printf("Queue is Empty\n");
        return;
    }
    struct Node* temp = front;
    while (temp) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    enqueue(10);
    enqueue(20);
    enqueue(30);
    display();
    dequeue();
    display();
    return 0;
}
