#include <stdio.h>
#include <math.h>

int main () {
    // declare variable
    double a, b, c;
    double delta;
    double an1, an2;

    // ask for user input
    printf("Enter a, b, and c coefficients: \n");
    scanf("%lf %lf %lf", &a, &b, &c);

    // calculate
    delta = (b * b) - 4 * (a * c);

    // check delta
    if (delta > 0) {
        // 2 answers
        an1 = (- b - sqrt(delta) / 2 * a);
        an2 = (- b + sqrt(delta) / 2 * a);
        // print result
        printf("First root is %lf and second root is %lf", an1, an2);
    } else if (delta == 0) {
        // 1 answer
        an1 = (- b / (2 * a));
        // print result
        printf("The root is %lf", an1);
    } else {
        printf("There are no real solutions to this equation");
    }
}