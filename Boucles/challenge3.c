#include <stdio.h>

int main () {
    // declare variables
    int i;
    int j = 0;
    int num;

    // ask for user input
    printf("Input a number to check if it's prime or not: \n");
    scanf("%d", &num);

    // check if number is 0 or 1
    if (num == 0 || num == 1) {
        printf("%d isn't prime", num);
        return 0;
    }

    // check if it's prime or not
    for (i = 2; i <= num / 2; i++) {
        if (num % i == 0) {
            j += 1;
        }     
    }

    // print based on j's value
    if (j > 0) {
            printf("%d isn't prime", num);
        } else {
            printf("%d is prime", num);
        }
}