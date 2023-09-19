#include <stdio.h>
#include <math.h>

struct Point {
    float x;
    float y;
};

int main () {
    struct Point p1;
    struct Point p2;

    printf("Enter coordinates for first point (x1 y1): \n");
    scanf("%f %f", &p1.x, &p1.y);

    printf("Enter coordinates for second point (x2 y2): \n");
    scanf("%f %f", &p2.x, &p2.y);

    float dis = sqrt(((p2.x - p1.x) * (p2.x - p1.x)) + ((p2.y - p1.y) * (p2.y - p1.y)));

    printf("p1's x is %.2f, p1's y is %.2f\np2's x is %.2f, p2's y is %.2f\n", p1.x, p1.y, p2.x, p2.y);
    printf("Distance is %.5f", dis);
}