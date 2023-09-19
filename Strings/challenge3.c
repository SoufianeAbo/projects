#include <stdio.h>
#include <string.h>

int main () {
    char string[30];

    printf("Input string: \n");
    scanf("%s", string);

    printf("The string in reverse is: %s", strrev(string));
}