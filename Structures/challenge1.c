#include <stdio.h>

struct Person {
    char name[30];
    int age;    
};

int main () {
    struct Person s1;

    printf("Input a name: \n");
    scanf("%s", s1.name);

    printf("Input an age: \n");
    scanf("%d", &s1.age);

    printf("Name: %s\nAge: %d\n", s1.name, s1.age);
}