#include <stdio.h>
#include <string.h>

int main () {
    char string1[30];
    char string2[30];

    printf("Input first string: \n");
    scanf("%s", string1);

    printf("Input second string: \n");
    scanf("%s", string2);

    printf("The concatenated chain is: %s", strcat(string1, string2));
}