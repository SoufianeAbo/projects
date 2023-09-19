#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int mainMenu();
int PrintStudent(int a);
void SortByAge();

// initialize global variables
int num = 0;
int nextId = 0;
int currentYear = 2023;

// structure for student
struct Student
{
    char name[50];
    int day, month, year, id;
    int age;
};

// initialize a max
struct Student student[100];

void Create()
{
    // name
    printf("Input full name of student: \n");
    scanf("%s", &student[num].name);

    // age
    printf("Input date of birth (dd/mm/yyyy): \n");
    scanf("%d/%d/%d", &student[num].day, &student[num].month, &student[num].year);

    if (student[num].year > currentYear || student[num].year <= 0) {
        printf("Invalid year, try again.\n");
        Create();
    } else if (student[num].month > 12 || student[num].month <= 0) {
        printf("Invalid month, try again.\n");
        Create();
    } else if (student[num].day <= 0) {
        printf("Invalid day, day cannot be 0 or lower.");
        Create();
    } else {
        if (student[num].day >= 31) {
            switch (student[num].month) {
                case 2:
                    if ((student[num].year % 400 == 0) || (student[num].year % 4 == 0 && student[num].year % 100 != 0)) {
                        student[num].day = 29;
                    } else {
                        student[num].day = 28;
                    }
                case 4:
                    student[num].day = 30;
                    break;
                case 6:
                    student[num].day = 30;
                    break;
                case 9:
                    student[num].day = 30;
                    break;
                case 11:
                    student[num].day = 30;
                    break;
                default:
                    student[num].day = 31;
                    break;
            }
        }
    }

    // id is nextid
    student[num].id = nextId;

    // calculate age
    student[num].age = currentYear - student[num].year;

    // print creation
    printf("%s has been created with an ID of SIDN %03d\n", student[num].name, student[num].id);

    // increment variables
    nextId++;
    num++;
    mainMenu();
}

// print every student function
void Check()
{
    // if num is 0 then no student exist yet
    if (num == 0)
    {
        printf("Empty\n");
        mainMenu();
    }
    else
    {
        int i, j;

        struct Student temp;

        for (i = 0; i < num - 1; i++)
        {
            for (j = 0; j < num - i - 1; j++)
            {
                if (student[j].id > student[j + 1].id)
                {
                    temp = student[j];

                    student[j] = student[j + 1];

                    student[j + 1] = temp;
                }
            }
        }

        // loops as long as num is bigger than i
        PrintStudent(-1);

        mainMenu();
    }
}

int PrintStudent(int a) {
    if (a = -1) {
        for (int i = 0; i < num; i++) {
            printf("%s, %d, SID: %03d, DoB: %02d/%02d/%03d\n", student[i].name, student[i].age, student[i].id, student[i].day, student[i].month, student[i].year);
        }
    } else {
        printf("%s, %d, SID: %03d, DoB: %02d/%02d/%03d\n", student[a].name, student[a].age, student[a].id, student[a].id, student[a].month, student[a].year);
    }
}

void Sort()
{
    int sel;

    printf("How would you like to print the menu?\n1. By ID\n2. By age\n\n");
    scanf("%d", &sel);

    switch (sel)
    {
    case 1:
        Check();
        break;
    case 2:
        if (num == 0)
        {
            printf("Empty\n");
            mainMenu();
        } else {
            SortByAge();
            PrintStudent(-1);
        }
        break;
    default:
        printf("Invalid option.");
        Sort();
        break;
    }

    mainMenu();
}

void SortByAge() {
    int i, j;

    struct Student temp;

    for (i = 0; i < num - 1; i++)
    {
        for (j = 0; j < num - i - 1; j++)
        {
            if (student[j].age > student[j + 1].age)
            {
                temp = student[j];

                student[j] = student[j + 1];

                student[j + 1] = temp;
            }
        }
    }
}

// search function
void Select()
{
    // initialize variables
    int search = 0;
    bool found = false;

    // ask for user input
    printf("Enter the ID to search for: \n");
    scanf("%d", &search);

    // loops to keep searching until it finds the variable that is equal to the search
    for (int i = 0; i < num; i++)
    {
        if (search == student[i].id)
        {
            found = true;
            PrintStudent(-1);
            mainMenu();
        }
    }

    // if found isn't true then prints this
    if (!found)
    {
        printf("A student with the SIDN%03d does not exist.", search);
        mainMenu();
    }
}

void Statistics() {
    int sel;
    float sum;

    printf("Pick an option:\n1. Youngest student\n2. Oldest student\n3. Average age\n\n");
    scanf("%d", &sel);

    switch (sel) {
        case 1:
            if (num == 0) {
                printf("Empty\n");
            } else {
                SortByAge();
                PrintStudent(0);
            }
            mainMenu();
            break;
        case 2:
            if (num == 0) {
                printf("Empty\n");
            } else {
                SortByAge();
                PrintStudent(num);
            }
            mainMenu();
            break;
        case 3:
            if (num == 0) {
                printf("Empty\n");
            } else {
                for (int i = 0; i < num; i++) {
                    sum += student[i].age;
                }

                printf("The average age for this class is %.2f\n", sum / (float)num);
            }
            mainMenu();
            break;
        default:
            printf("Invalid option, try again.\n");
            Statistics();
    }
}

// main menu function
int mainMenu()
{
    // initialize variables
    int sel;

    // print menu
    printf("\nSelect:\n1. Create\n2. Select\n3. Check\n4. Statistics\n5. Exit\n");
    scanf("%d", &sel);

    // condition for menu
    switch (sel)
    {
    case 1:
        Create();
        break;
    case 2:
        Select();
        break;
    case 3:
        Sort();
        break;
    case 4:
        Statistics();
        break;
    case 5:
        exit(0);
    default:
        printf("Invalid option, try again.");
        break;
    }
}

// main function
int main()
{
    mainMenu();
    return 0;
}