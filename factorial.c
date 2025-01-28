#include<stdio.h>
long int recursiveFact(int num){
    if(num==0)
       return 1;
    return num * recursiveFact(num-1);
}
long int iterativeFact(int num){
    long int fact = 1;
    for(int i=2;i<=num;i++)
       fact *= i;
    return fact;
}
int main(){
    int num;
    printf("Enter the number : ");
    scanf("%d",&num);
    printf("Factorial of %d is %ld\n",num,recursiveFact(num));
    printf("Factorial of %d is %ld",num,iterativeFact(num));
    return 0;
}