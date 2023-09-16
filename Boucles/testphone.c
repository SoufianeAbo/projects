#include <stdio.h>

int main () {
    char telephone[10];

    printf("put your phone number here: \n");
    scanf("%s", telephone);

    if (telephone[1] == '6') {
        printf("you have phone number");
    } else if (telephone[1] == '5') {
        printf("you have fax");
    }
}