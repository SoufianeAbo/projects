#include <stdio.h>

// calculate until 0
int pgcd(int a, int b) {
    // recursion function
    if (b != 0) {
        // go back
        pgcd(b, a % b);
    } else {
        // return a value
        return a;
    }
}

// main function
int main() {
    // declare variables
    int num1, num2;

    // ask user input
    printf("Please input 2 integers: \n");
    scanf("%d %d", &num1, &num2);

    // display
    printf("The PGCD of your two integers is: %d", pgcd(num1, num2));
}