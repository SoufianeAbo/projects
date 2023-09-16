#include <stdio.h>
int main () {
    // declare variables
    int a;
    int b;

    printf("Enter two integers: ");
    scanf("%d %d", &a, &b);

    // calculate
    printf("a + b is %d", a + b);
    printf("\na - b is %d", a - b);
    printf("\na * b is %d", a * b);
    printf("\na / b is %d", a / b);
    printf("\na % b is %d", a % b);
}