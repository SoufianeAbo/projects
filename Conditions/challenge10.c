/*
hello everyone, i've made a function that automatically changes 31 to 30 in months that has max days 30
if you want to remove the function, feel free to, i just thought of it as an extra
*/

#include <stdio.h>
#include <stdlib.h>

int main () {
    // declare variables
    int day, month, year;

    // ask for user input
    printf("Please input a day format (dd/mm/yyyy): \n");
    scanf("%d/%d/%d", &day, &month, &year);

    // check if day is above 31
    if (day > 31 || day <= 0) {
        // invalid response
        printf("Invalid day, please try again.");
        return 0;
    }

    // check if year is above 9999
    if (year > 9999 || year <= 0) {
        // print error
        printf("Invalid year, please try again.");
    }

    // check month
    switch (month) {
        case 1:
            printf("%d-January-%04d", day, year);
            break;
        case 2:
            if (day >= 29) {
                // function to check if it's a leap year
                if (year % 400 == 0) {
                    day = 29;
                    printf("%d-February-%04d", day, year);
                } else if (year % 100 == 0) {
                    day = 28;
                    printf("%d-February-%04d", day, year);
                } else if (year % 4 == 0) {
                    day = 29;
                    printf("%d-February-%04d", day, year);
                } else {
                    day = 28;
                    printf("%d-February-%04d", day, year);
                }
            }
            break;
        case 3:
            printf("%d-March-%04d", day, year);
            break;
        case 4:
            if (day == 31) {
                day--;
            }
            printf("%d-April-%04d", day, year);
            break;
         case 5:
            printf("%d-May-%04d", day, year);
            break;
        case 6:
            if (day == 31) {
                day--;
            }
            printf("%d-June-%04d", day, year);
            break;
        case 7:
            printf("%d-July-%04d", day, year);
            break;
        case 8:
             printf("%d-August-%04d", day, year);
            break;
        case 9:
            if (day == 31) {
                day--;
            }
            printf("%d-September-%04d", day, year);
            break;
        case 10:
            printf("%d-October-%04d", day, year);
            break;
        case 11:
            if (day == 31) {
                day--;
            }
            printf("%d-November-%04d", day, year);
            break;
        case 12:
            printf("%d-December-%04d", day, year);
            break;
        default:
            // if there's a month that isn't valid
            printf("Invalid month, please try again.");
            return 0;
        }
}