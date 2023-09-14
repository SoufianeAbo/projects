#include <stdio.h>

int main () {
    // declare variable
    char letter;

    // ask for user input
    printf("Please enter your character: \n");  
    scanf("%c", &letter);

    // check if character is a vowel through switches
    switch (letter) {
        // if the character is a vowel, execute this code
        case 'A': case 'E': case 'I': case 'O': case 'U':
        case 'a': case 'e': case 'i': case 'o': case 'u':

            printf("Your character is a vowel.");
            break;

        // if the character isn't a vowel, execute this code
        default:
            printf("Your character is a consonant.");
    }
}