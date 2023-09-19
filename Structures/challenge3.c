#include <stdio.h>

struct Employee {
    char name[30];
    float hourlyWage;
    float hours;
};

int main () {
    struct Employee em1;

    printf("Enter name of employee: \n");
    scanf("%s", em1.name);

    printf("Enter hourly salary: \n");
    scanf("%f", &em1.hourlyWage);

    printf("Enter hours worked: \n");
    scanf("%f", &em1.hours);

    printf("Name of employee: %s\nSalary total: %.2f", em1.name, em1.hourlyWage * em1.hours);
}