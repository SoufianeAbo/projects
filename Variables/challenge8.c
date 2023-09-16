#include <stdio.h>
#include <math.h>

int main () {
    // declare variable
    int number;

    // check for input
    printf("Input a number to convert to octal and hexadecimal: \n");
    scanf("%d", &number);

    // print
    printf("In octal: %o\nIn hex: %x", number, number);
}