#include <stdio.h>

// Recursive function to calculate factorial
long long factorialRecursive(int n) {
    if (n == 0 || n == 1)
        return 1;
    return n * factorialRecursive(n - 1);
}

// Non-recursive (iterative) function to calculate factorial
long long factorialIterative(int n) {
    long long fact = 1;
    for (int i = 2; i <= n; i++)
        fact *= i;
    return fact;
}

// Driver function
int main() {
    int num;

    // Input from user
    printf("Enter a number: ");
    scanf("%d", &num);

    if (num < 0)
        printf("Factorial is not defined for negative numbers.\n");
    else {
        printf("Factorial of %d (Recursive) = %lld\n", num, factorialRecursive(num));
        printf("Factorial of %d (Iterative) = %lld\n", num, factorialIterative(num));
    }

    return 0;
}
