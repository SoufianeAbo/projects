#include <stdio.h>

int main () {
    // declare variable
    int num = 0;
    int i;

    // ask for user input
    printf("Input a number that you'd like to see the multiplication table of: \n");
    scanf("%d", &num);

    // while loop
    while (i <= 10) {
        printf("%d * %d = %d\n", num, i, num * i);
        i++;
    }
}