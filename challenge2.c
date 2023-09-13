#include <stdio.h>
int main() {
    // degree variable
    float degree;

    // input temperature
    printf("Please input your temperature: ");
    scanf("%f", &degree);

    // convert to celsius
    float cel = (degree - 32) * 5 / 9;
    printf("\nYour temperature in Celsius is %.2f,", cel);

    // conditions
    if (cel < 7) {
        printf(" and it's very cold.");
    } else if (cel < 16) {
        printf(" and it's cold.");
    } else if (cel < 30) {
        printf(" and it's hot.");
    } else {
        printf(" and it's very hot.");
    }
}
