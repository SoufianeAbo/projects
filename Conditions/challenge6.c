#include <stdio.h>

int main () {
    // declare variable
    int number;

    // check user input
    printf("Input a number of your choice: \n");
    scanf("%d", &number);

    // check if it's negative or positive
    if (number < 0) {
        // negative
        printf("Your number is negative.");
    } else if (number > 0) {
        // positive
        printf("Your number is positive.");
    } else {
        // zero
        printf("Your number is zero.");
    }
}