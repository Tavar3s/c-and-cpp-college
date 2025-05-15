#include <stdio.h>

int fibonnaci(int n) {
    if (n <= 1) return n; // Base case: fib(0) = 0, fib(1) = 1
    return fibonnaci(n - 1) + fibonnaci(n - 2); // Recursive case
}

int main() {
    int num;

    scanf("%d", &num);

    printf("%d\n", fibonnaci(num)); // Print the Fibonacci number
}