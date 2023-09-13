#include <stdio.h>
int main() {
    // declare variables
    char myfamName[15];
    char myName[15];
    int age;
    char gender;
    char phoneNum[15];

    printf("Your family name: ");
    scanf("%s", &myfamName);
    printf("\nYour name: ");
    scanf("%s", &myName);
    printf("\nYour age: ");
    scanf("%d", &age);
    printf("\nYour gender (either M or F): ");
    scanf(" %c", &gender);
    printf("\nYour phone number: +");
    scanf("%s", &phoneNum);

    printf("%s, %s, %d, %c, %s", myfamName, myName, age, gender, phoneNum);
    return 0;
}