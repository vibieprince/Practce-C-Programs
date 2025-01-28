#include<stdio.h>
#include<stdbool.h> // For using bool return type in function
#include<string.h>
#define MAX 100

struct Stack{
    int arr[MAX];
    int top;
};

void initStack(struct Stack *s){
    s->top = -1;
}

bool isFull(struct Stack *s){
    return s->top == MAX-1;
}

bool isEmpty(struct Stack *s){
    return s->top == -1;
}

void push(struct Stack *s,int val){
    if(isFull(s)){
        perror("Stack overflow\n");
        return;
    }
    s->arr[++s->top] = val;
}

int pop(struct Stack *s){
    if(isEmpty(s)){
        perror("Stack undeflow\n");
        return -1;
    }
    return s->arr[s->top--];
}

void reverseString(char str[]){
    struct Stack s;
    initStack(&s);
    int n = strlen(str);

    for(int i=0;i<n;i++)
       push(&s,str[i]);
    
    for(int i=0;i<n;i++)
       str[i] = pop(&s);
}

int main(){
    char str[MAX];
    printf("Enter the string : ");
    gets(str);
    printf("Original String : %s\n",str);
    reverseString(str);
    printf("Reversed String : %s",str);
    return 0;
}