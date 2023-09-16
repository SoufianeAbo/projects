#include <stdio.h>

// function to check prime numbers
int Prime(int num) {
    // check if number is 0 or 1
    if (num <= 1) {
        return 0;
    }

    // function to check if prime
    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0) {
            return 0;
        }
    }

    return 1;
}

// main function
int main () {
    // declare variable
    int input;
    int result;

    // ask for user input
    printf("Input a number to check if it's prime or not: \n");
    scanf("%d", &input);

    result = Prime(input);

    // print result
    if (result == 0) {
        printf("The number isn't prime.\n");
    } else {
        printf("The number is prime.\n");
    }
}