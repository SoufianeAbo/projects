#include <stdio.h>

int main () {
    // declare variable
    int avg;

    // ask for user input
    printf("Input your average mark: \n");
    scanf("%d", &avg);

    // check for conditions
    if (avg < 10) {
        // student fails the test
        printf("You have failed the test.");
    } else if (avg >= 10 && avg < 12) {
        // student receives a pass
        printf("Your mark is: Passable");
    } else if (avg >= 12 && avg < 14) {
        // student receives assez bien
        printf("Your mark is: Assez Bien");
    } else if (avg >= 14 && avg < 16) {
        // student receives mention bien
        printf("Your mark is: Mention Bien");
    } else {
        // student receives tres bien
        printf("Your mark is: Tres Bien");
    }
}