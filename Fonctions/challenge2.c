#include <stdio.h>

// sum function
int Sum(int a, int b) {
    // calculate and return it at the same time
    return a + b;
}

// main function
int main () {
    int num1, num2;

    // ask for user input
    printf("Input 2 integers: \n");
    scanf("%d %d", &num1, &num2);
    printf("%d", Sum(num1, num2));
}