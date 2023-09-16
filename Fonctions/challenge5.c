#include <stdio.h>

// permute function
void Permute(int a, int b) {
    // declare variable
    int temp;

    // permute
    temp = a;
    a = b;
    b = temp;

    // print
    printf("a is now %d and b is now %d", a, b);
}

int main () {
    // declare variable
    int num1, num2;

    // ask for user input
    printf("Please input number a and number b: \n");
    scanf("%d %d", &num1, &num2);

    // call function
    printf("a is %d and b is %d\n", num1, num2);
    Permute(num1, num2);
}