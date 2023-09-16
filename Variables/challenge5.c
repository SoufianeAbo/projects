#include <stdio.h>
#include <math.h>
int main () {
    // declare variables
    double mx, my;
    double nx, ny;
    double result;
    double mnx;
    double mny;

    // take input
    printf("Enter 2 coordinates (X and Y) for point M: ");
    scanf("%lf %lf", &mx, &my);
    printf("\nEnter 2 coordinates (X and Y) for point N: ");
    scanf("%lf %lf", &nx, &ny);

    // calculate
    mnx = nx - mx;
    mny = ny - my;
    result = sqrt((mnx * mnx) + (mny * mny));

    // print result
    printf("The distance is %.2lf", result);
}