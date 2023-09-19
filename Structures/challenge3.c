#include <stdio.h>

// employee structure
struct Employee {
    char name[30];
    float hourlyWage;
    float hours;
};

// main function
int main () {
    // initialize first employee
    struct Employee em1;

    // ask for user input
    printf("Enter name of employee: \n");
    scanf("%s", em1.name);

    printf("Enter hourly salary: \n");
    scanf("%f", &em1.hourlyWage);

    printf("Enter hours worked: \n");
    scanf("%f", &em1.hours);

    // print name of employees
    printf("Name of employee: %s\nSalary total: %.2f", em1.name, em1.hourlyWage * em1.hours);
}