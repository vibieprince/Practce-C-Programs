#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX 100  // Maximum string length

// Stack structure
struct Stack {
    int top;
    char arr[MAX];
};

// Initialize stack
void initStack(struct Stack* s) {
    s->top = -1;
}

// Check if stack is empty
int isEmpty(struct Stack* s) {
    return s->top == -1;
}

// Push operation
void push(struct Stack* s, char value) {
    if (s->top == MAX - 1) {
        printf("Stack Overflow!\n");
        return;
    }
    s->arr[++(s->top)] = value;
}

// Pop operation
char pop(struct Stack* s) {
    if (isEmpty(s)) {
        printf("Stack Underflow!\n");
        return '\0';
    }
    return s->arr[(s->top)--];
}

// Function to reverse a string using stack
void reverseString(char str[]) {
    struct Stack s;
    initStack(&s);
    
    int len = strlen(str);

    // Push all characters onto stack
    for (int i = 0; i < len; i++)
        push(&s, str[i]);

    // Pop characters to get them in reverse order
    for (int i = 0; i < len; i++)
        str[i] = pop(&s);
}

int main() {
    char str[MAX];

    printf("Enter a string: ");
    gets(str);  // Read input string

    reverseString(str);

    printf("Reversed string: %s\n", str);

    return 0;
}
