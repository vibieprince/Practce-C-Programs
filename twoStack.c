#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10  // Define the total size of the array

struct TwoStacks {
    int arr[MAX_SIZE]; // Shared array for both stacks
    int top1;          // Top index for Stack 1
    int top2;          // Top index for Stack 2
};

// Initialize the two stacks
void initStacks(struct TwoStacks* stacks) {
    stacks->top1 = -1;         // Stack 1 starts from index 0
    stacks->top2 = MAX_SIZE;   // Stack 2 starts from the last index
}

// Push into Stack 1
void push1(struct TwoStacks* stacks, int value) {
    if (stacks->top1 + 1 < stacks->top2) {  // Check for space
        stacks->arr[++stacks->top1] = value;
    } else {
        printf("Stack Overflow: No space for Stack 1\n");
    }
}

// Push into Stack 2
void push2(struct TwoStacks* stacks, int value) {
    if (stacks->top1 + 1 < stacks->top2) {  // Check for space
        stacks->arr[--stacks->top2] = value;
    } else {
        printf("Stack Overflow: No space for Stack 2\n");
    }
}

// Pop from Stack 1
int pop1(struct TwoStacks* stacks) {
    if (stacks->top1 >= 0) {
        return stacks->arr[stacks->top1--];
    } else {
        printf("Stack Underflow: Stack 1 is empty\n");
        return -1;
    }
}

// Pop from Stack 2
int pop2(struct TwoStacks* stacks) {
    if (stacks->top2 < MAX_SIZE) {
        return stacks->arr[stacks->top2++];
    } else {
        printf("Stack Underflow: Stack 2 is empty\n");
        return -1;
    }
}

// Display both stacks
void display(struct TwoStacks* stacks) {
    printf("Stack 1: ");
    for (int i = 0; i <= stacks->top1; i++)
        printf("%d ", stacks->arr[i]);
    
    printf("\nStack 2: ");
    for (int i = MAX_SIZE - 1; i >= stacks->top2; i--)
        printf("%d ", stacks->arr[i]);
    
    printf("\n");
}

// Driver function
int main() {
    struct TwoStacks stacks;
    initStacks(&stacks);

    push1(&stacks, 10);
    push1(&stacks, 20);
    push1(&stacks, 30);
    
    push2(&stacks, 90);
    push2(&stacks, 80);
    push2(&stacks, 70);

    display(&stacks);

    printf("Popped from Stack 1: %d\n", pop1(&stacks));
    printf("Popped from Stack");
}