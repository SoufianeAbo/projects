// challenge 9 is literally challenge 7 i think
#include <stdio.h>

int main () {
    // add variable
    char ch;
    int i;

    // ask for user input
    printf("Input your character: \n");
    scanf(" %c", &ch);

    // convert character to ascii
    i = (int) ch;

    // print characters and ascii conversion
    printf("Your character is %c\nYour character converted to ASCII is %d\n", ch, i);

    // check whether or not the input is a character, then check if it's uppercase or lowercase
    if (i >= 65 && i <= 90) {
        // uppercase
        printf("Your character is uppercase.");
    } else if (i >= 97 && i <= 122) {
        // lowercase
        printf("Your character is lowercase.");
    } else {
        // not a character
        printf("This character is not a letter.");
    }
}