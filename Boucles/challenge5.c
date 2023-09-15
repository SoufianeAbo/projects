#include <stdio.h>

int main () {
    // declare variables
    int a, b, c;

    // ask for user input
    printf("Please input a number to reverse: \n");
    scanf("%d", &a);

    // make sure b is 0 to not interfere with calculation
    b = 0;

    // calculate reversion
    while (a > 0) {
        // reverse
        c = a % 10;
        b = 10 * b + c;
        a = a / 10;
    }
    
    // print reversion
    printf("Your reversed number is: %d", b);
}