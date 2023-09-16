#include <stdio.h>
int main () {
    // declare variable
    float ray;
    float result;
    float pi = 3.14159265359;

    // get user input
    printf("Enter a radius of a circle you want: ");
    scanf("%f", &ray);

    // calculate
    result = (2 * pi) * ray;

    // print result
    printf("\nThe circumference of your circle is %.2f", result);
}