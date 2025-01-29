#include <stdio.h>
#define MAX 5

int queue[MAX], front = -1, rear = -1;

void enqueue(int value) {
    if (rear == MAX - 1) {
        printf("Queue is Full\n");
        return;
    }
    if (front == -1) front = 0;
    queue[++rear] = value;
    printf("Inserted %d\n", value);
}

void dequeue() {
    if (front == -1 || front > rear) {
        printf("Queue is Empty\n");
        return;
    }
    printf("Removed %d\n", queue[front++]);
    if (front > rear) front = rear = -1;  // Reset queue when empty
}

void display() {
    if (front == -1) {
        printf("Queue is Empty\n");
        return;
    }
    for (int i = front; i <= rear; i++)
        printf("%d ", queue[i]);
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
