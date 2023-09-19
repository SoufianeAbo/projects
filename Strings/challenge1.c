#include <stdio.h>
#include <string.h>

int main () {
    char string[30];
    printf("Input a string: \n");
    scanf("%s", string);

    printf("String's length is %d", strlen(string));
}