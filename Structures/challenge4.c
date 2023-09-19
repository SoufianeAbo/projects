#include <stdio.h>

struct Student {
    char name[30];
    int age;
};

int main () {
    struct Student s[5];

    printf("Welcome to the student manager!\n");

    for (int i = 0; i < 5; i++) {
        printf("Add student %d's name: \n", i + 1);
        scanf("%s", s[i].name);

        printf("Add student %d's age: \n", i + 1);
        scanf("%d", &s[i].age);

        printf("Student added successfully!\n\n");
    }

    printf("List of students:\n");

    for (int i = 0; i < 5; i++) {
        printf("%d. Name: %s, Age: %d\n", i + 1, s[i].name, s[i].age);
    }
}