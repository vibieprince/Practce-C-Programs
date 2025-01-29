#include <stdio.h>
#define SIZE 5  // Define the maximum size of the queue

int queue[SIZE], front = -1, rear = -1;

// Function to insert an element in the circular queue
void enqueue(int value) {
    if ((rear + 1) % SIZE == front) {
        printf("Queue is Full! Cannot insert %d\n", value);
        return;
    }
    if (front == -1) // If queue is initially empty
        front = 0;
    
    rear = (rear + 1) % SIZE;
    queue[rear] = value;
    printf("%d inserted into the queue\n", value);
}

// Function to display the queue
void display() {
    if (front == -1) {
        printf("Queue is Empty!\n");
        return;
    }
    printf("Circular Queue: ");
    int i = front;
    while (1) {
        printf("%d ", queue[i]);
        if (i == rear)
            break;
        i = (i + 1) % SIZE;
    }
    printf("\n");
}

int main() {
    enqueue(10);
    enqueue(20);
    enqueue(30);
    enqueue(40);
    enqueue(50);
    
    display();

    // Trying to insert when queue is full
    enqueue(60);

    return 0;
}
