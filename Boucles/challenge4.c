#include <stdio.h>

int main () {
    // declare variable
    int num; 
    int sum = 0;
    int max = 0;

    // print
    printf("Please input numbers (you can stop the program with 0): \n");

    // loops until i becomes 10
    do
    {
        // ask for user input
        scanf("%d", &num);

        // check if number is below 100
        if (num <= 100 && num >= 0) {
            // add sum
            sum += num;
            
            // function to check number
            if (num > max) {
                max = num;
            }
        } else {
            // print invalid
            printf("Print another positive number less than or equal to 100: \n");
        }
        
    } while (num != 0);

    // print out sum and max
    printf("Your sum is %d.\nYour max number is %d.", sum, max);
    
}