#include <stdio.h>

int main () {
    // declare variable
    int num;

    // ask for user input
    printf("Please enter your number: ");
    scanf("%d", &num);

    // check if number is even or odd
    if (num == 0) {
        printf("The number is neither.");
    } else if (num % 2 == 0) {
        printf("The number is even.");
    } else {
        printf("The number is odd.");
    }
}