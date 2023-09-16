#include <stdio.h>

// main function
int main() {
    // declare variables
    int rows;

    // ask for user input
    printf("Input the number of rows: \n");
    scanf("%d", &rows);

    // loop
    for (int i = 0; i < rows; i++) {
        // triangle starts at 1, so we start with 1
        int num = 1;

        // new loop that calculates numbers
        for (int j = 0; j <= i; j++) {
            // prints number
            printf("%d", num);

            // add a space if j is below i to seperate the numbers
            if (j < i) {
                printf(" ");
            }

            // calculate number based on binomial formula
            int newNum = num * (i - j) / (j + 1);
            num = newNum;
        }

        printf("\n");
    }

    return 0;
}