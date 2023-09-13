#include <stdio.h>
int main () {
    // declare variables
    int a;
    int b;
    int c;
    int d;

    // take input
    printf("Enter 4 integers: ");
    scanf("%d %d %d %d", &a, &b, &c, &d);

    // calculate sum
    int sum = a + b + c + d;

    // print
    printf("\nThe calculated sum of these numbers is %d", sum);
    printf("\nThe average of this sum is %d", sum / 4);
}