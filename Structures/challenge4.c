#include <stdio.h>

// structure function
struct Student {
    char name[30];
    int age;
};

// main function
int main () {
    // initialize structure with array
    struct Student s[5];

    printf("Welcome to the student manager!\n");

    // for loop that keps printing every student from 1 to 5
    for (int i = 0; i < 5; i++) {
        printf("Add student %d's name: \n", i + 1);
        scanf("%s", s[i].name);

        printf("Add student %d's age: \n", i + 1);
        scanf("%d", &s[i].age);

        printf("Student added successfully!\n\n");
    }

    printf("List of students:\n");

    // print every single student from 1 to 5
    for (int i = 0; i < 5; i++) {
        printf("%d. Name: %s, Age: %d\n", i + 1, s[i].name, s[i].age);
    }
}