#include <stdio.h>

int main () {
    // declare variables
    int i = 1;
    int j;

    while (i <= 7) {
        // add spaces
        j = 0;
        while (j <= (7 - i))
        {
            printf(" ");
            j++;
        }

        j = 0;
        // add stars
        while (j < (2 * i - 1)) {
            printf("*");
            j++;
        }   

        printf("\n");
        i++;
    }
    return 0;
}