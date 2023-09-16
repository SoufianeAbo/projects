#include <stdio.h>
int main() {
    // declare variables
    char myfamName[15];
    char myName[15];
    int age;
    char gender;
    char phoneNum[15];

    printf("Your family name: \n");
    scanf("%s", &myfamName);
    printf("Your name: \n");
    scanf("%s", &myName);
    printf("Your age: \n");
    scanf("%d", &age);
    printf("Your gender (either M or F): \n");
    scanf(" %c", &gender);
    printf("Your phone number: +");
    scanf("%s", &phoneNum);

    printf("\nYour full name: %s %s\nYour age: %d\nYour gender: %c\nYour phone number: %s", myName, myfamName, age, gender, phoneNum);
    return 0;
}
