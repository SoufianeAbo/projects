#include <stdio.h>

// declare new function that checks if number is perfect
int perfectNumber(int a) {
    // check if number equals to 0
    if (a <= 0) {
        return 0;
    }

    // initialize divisors
    int divisors = 0;

    // find divisors and sum them up
    for (int i = 1; i < a; i++) {
        if (a % i == 0) {
            divisors += i;
        }
    }

    // check sum of divisors equal to number
    return divisors == a;
}

// initialize main
int main () {
    // declare variable
    int num;

    // ask for user input
    printf("Enter a number: \n");
    scanf("%d", &num);

    if (perfectNumber(num)) {
        // if number is perfect
        printf("%d is a perfect number.\n", num);
    } else {
        // if number isn't perfect
        printf("%d isn't a perfect number.\n", num);
    }
}