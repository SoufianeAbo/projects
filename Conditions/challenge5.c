#include <stdio.h>

int main () {
    // declare variables
    double year;
    int sel;

    // grab user input
    printf("Input your year: \n");
    scanf("%lf", &year);

    // make menu
    while (1) {
        // grab user input
        printf("\nSelect your conversion:\n1. Months\n2. Days\n3. Hours\n4. Minutes\n5. Seconds\n6. Exit\n\n");
        scanf("%d", &sel);

        switch (sel) {
            case 1:
                // convert to months
                printf("Your year, converted to months is %.0lf\n", year * 12);
                break;
            
            case 2:
                // convert to days
                printf("Your year, converted to days is %.0lf\n", year * 365);
                break;

            case 3:
                // convert to hours
                printf("Your year, converted to hours is %.0lf\n", year * 8760);
                break;
            
            case 4:
                // convert to minutes
                printf("Your year, converted to minutes is %.0lf\n", year * 525600);
                break;
            
            case 5:
                // convert to seconds
                printf("Your year, converted to seconds is %.0lf\n", year * 31556952);
                break;

            case 6:
                // exit the program
                return 0;

            default:
                // print invalid input
                printf("Invalid input. Please try again. \n");
                break;
        }
    }
}