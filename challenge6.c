#include <stdio.h>
#include <math.h>
int main () {
    // declare variable
    float rad;
    float result;
    double pi = M_PI;

    // get user input
    printf("Enter a radius of a circle you want: ");
    scanf("%f", &rad);

    // calculate
    result = (2 * pi) * rad;

    // print result
    printf("\nThe circumference of your circle is %.2f", result);
}