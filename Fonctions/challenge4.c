#include <stdio.h>

// max_2 function
int Max_2(int a, int b) {
    // check whether a or b is bigger
    if (a > b) {
        // if a is bigger, return a
        return a;
    } else {
        // if b is bigger, return b
        return b;
    }
}

// max_4 function
int Max_4(int a, int b, int c, int d) {
    // put into a variable after checking with max2 function a and b
    int maxNum1 = Max_2(a, b);
    // likewise here
    int maxNum2 = Max_2(c, d);

    // check if maxNum1 is bigger than maxNum2
    if (maxNum1 > maxNum2) {
        return maxNum1;
    } else {
        return maxNum2;
    }
}

// main
int main () {
    // declare variables
    int num1, num2, num3, num4;

    // ask for user input
    printf("Enter 4 numbers: \n");
    scanf("%d %d %d %d", &num1, &num2, &num3, &num4);

    // print max result
    printf("Your max number is: %d", Max_4(num1, num2, num3, num4));
}