#include <stdio.h>

int main () {
    // declare variables
    int num1, num2;
    int sum;

    // ask for user input
    printf("Enter 2 integers: \n");
    scanf("%d %d", &num1, &num2);

    // calculate sum
    sum = num1 + num2;

    // check if numbers are identical
    if (num1 == num2) {
        // triple the sum and print at the same time
        printf("Your sum is %d and got tripled to %d because your numbers are identical.", sum, sum * 3);
    } else {
        // print the sum only without tripling
        printf("Your sum is %d", sum);
    }
}