#include <stdio.h>

// make structure
struct Person {
    char name[30];
    int age;    
};

// main function
int main () {
    struct Person s1;

    // ask for user input for name and age
    printf("Input a name: \n");
    scanf("%s", s1.name);

    printf("Input an age: \n");
    scanf("%d", &s1.age);

    // print name and age of s1
    printf("Name: %s\nAge: %d\n", s1.name, s1.age);
}