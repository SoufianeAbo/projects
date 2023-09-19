#include <stdio.h>
#include <math.h>

// structure of point for both p1 and p2
struct Point {
    float x;
    float y;
};

// main function
int main () {
    // initialize p1 and p2 both
    struct Point p1;
    struct Point p2;

    // ask for user input for both coordinates
    printf("Enter coordinates for first point (x1 y1): \n");
    scanf("%f %f", &p1.x, &p1.y);

    printf("Enter coordinates for second point (x2 y2): \n");
    scanf("%f %f", &p2.x, &p2.y);

    // calculate based on euclidean distance 2d formula
    float dis = sqrt(((p2.x - p1.x) * (p2.x - p1.x)) + ((p2.y - p1.y) * (p2.y - p1.y)));

    // print distance
    printf("p1's x is %.2f, p1's y is %.2f\np2's x is %.2f, p2's y is %.2f\n", p1.x, p1.y, p2.x, p2.y);
    printf("Distance is %.5f", dis);
}