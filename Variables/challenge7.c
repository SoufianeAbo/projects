#include <stdio.h>
int main () {
    // declare variable
    int num;
    int dig1, dig2, dig3;

    // ask for user input
    printf("Enter a 3 digit number: ");
    scanf("%d", &num);

    // check if number is above or below 3 digits
    if (num > 100 && num < 999) {
        // reverse digits with modulo

        // take last digit of number
        dig1 = num % 10;

        // take middle digit of number and use a calculation to remove decimal number
        dig2 = ((num / 10) % 10);

        // take first digit of number
        dig3 = num / 100;

        // print everything together
        printf("Your reversed number is %d%d%d", dig1, dig2, dig3);

    } else {
        // output error message
        printf("\nDigit must be between 100 and 999");
    }
}