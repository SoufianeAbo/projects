#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main () {
    // seed randomness
    srand(time(NULL));

    // initialize variable with randomness
    int randomWeek = (rand() % 7) + 1;

    // display days depending on variable
    switch (randomWeek) {
        case 1:
            printf("Monday");
            break;
        case 2:
            printf("Tuesday");
            break;
        case 3:
            printf("Wednesday");
            break;
        case 4:
            printf("Thursday");
            break;
        case 5:
            printf("Friday");
            break;
        case 6:
            printf("Saturday");
            break;
        case 7:
            printf("Sunday");
            break;
        default:
    }
}