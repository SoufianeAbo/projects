#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>

#define MAX 100
#define TITLE 30

// initialize variables
int num = 0, currentYear, currentMonth, currentDay, isAdd = 0;
double DMY = 0;

// prototypes
char *Status(int a);
int Add(int a);
void Display(int a);
void BubbleSortID();
void BubbleSortAlp();
void BubbleSortDMY();
void mainMenu();
void CalculateDeadline(int a);
void Delete(int a);
void Edit(int a);

// to do list structure
struct todo
{
    int status;
    char title[TITLE], description[60];
    int id;

    struct deadline
    {
        int day, month, year;
        double dmy;
    } date;

} list[MAX];

// function to check whether you're currently in editing or adding
void Check(int a)
{
    if (isAdd == 0)
    {
        Edit(a);
    }
    else
    {
        Add(a);
    }
}

// calculate deadline function
void CalculateDeadline(int a)
{
    // if the current year is above current year or below or equals to zero, don't execute
    if (list[a].date.year < currentYear || list[a].date.year <= 0)
    {
        printf("Invalid year, try again.\n\n");
        // check
        Check(a);
        return 0;
        // check if month is above 12 or equals zero or below it
    }
    else if (list[a].date.month > 12 || list[a].date.month <= 0)
    {
        printf("Invalid month, try again.\n\n");
        // check
        Check(a);
        return 0;
        // check if day is below or equals zero
    }
    else if (list[a].date.day <= 0)
    {
        printf("Invalid day, try again.\n\n");
        // check
        Check(a);
        return 0;
    }
    else
    {
        // check if day is above 31 or equals to 31
        if (list[a].date.day >= 31)
        {
            // check current month
            switch (list[a].date.month)
            {
            case 2:
                // february, checking if leap year or not
                if (list[a].date.year % 400 == 0)
                {
                    // leap year
                    list[a].date.day = 29;
                }
                else if (list[a].date.year % 100 == 0)
                {
                    // not a leap year
                    list[a].date.day = 28;
                }
                else if (list[a].date.year % 4 == 0)
                {
                    // leap year
                    list[a].date.day = 29;
                }
                else
                {
                    // not a leap year
                    list[a].date.day = 28;
                }
                break;
            case 4:
                // april
                list[a].date.day = 30;
                break;
            case 6:
                // june
                list[a].date.day = 30;
                break;
            case 9:
                // september
                list[a].date.day = 30;
                break;
            case 11:
                // november
                list[a].date.day = 30;
                break;
            default:
                // any other month
                list[a].date.day = 31;
                break;
            }
        }
    }

    // make id the current number
    list[a].id = a;

    // convert the year, month, and day all to days
    list[a].date.dmy = 0;
    list[a].date.dmy += list[a].date.year * 365;
    list[a].date.dmy += list[a].date.month * 30;
    list[a].date.dmy += list[a].date.day;

    // check deadline being lower than current date
    if (DMY > list[a].date.dmy)
    {
        printf("Deadline is lower than current date. Try again.\n");
        Check(a);
        return 0;
    }
}

// function to add
int Add(int a)
{
    if (num > MAX) {
        // if number is above max
        printf("You've exceeded the max limit of tasks. Delete some.\n");

        // check whether or not we're looping
        switch (a)
        {
        case 0:
            // if we called add with 0, we'll return back to main menu
            mainMenu();
        case 1:
            // otherwise, keep looping
            return;
        }
    } else {
        // variable to make sure that we're in add mode
        isAdd = 1;

        // input title
        printf("Input a title for your task: \n");
        scanf(" %[^\n]", list[num].title);

        list[num].title[0] = toupper(list[num].title[0]);

        // input description
        printf("Input a description for your task: \n");
        scanf(" %[^\n]", list[num].description);

        // pick status
        printf("Pick a status:\n1. To Do\n2. In progress\n3. Done\n");
        scanf("%d", &list[num].status);

        // check if status is correct
        if (list[num].status > 3 || list[num].status <= 0)
        {
            printf("Invalid option, try again.\n\n");
            // go back to add if invalid
            Add(a);
            return 0;
        }

        // input deadline
        printf("Input a deadline (dd/mm/yyyy):\n");
        scanf("%d/%d/%d", &list[num].date.day, &list[num].date.month, &list[num].date.year);

        // call function to check if our deadline is correct
        CalculateDeadline(num);

        // created successfully
        printf("Task %s has been created successfully with an ID of ID%03d.\n\n", list[num].title, list[num].id);

        // make add variable back to 0 now that we've finished adding
        isAdd = 0;
        // increment number (the length of our array)
        num++;

        // check whether or not we're looping
        switch (a)
        {
        case 0:
            // if we called add with 0, we'll return back to main menu
            mainMenu();
        case 1:
            // otherwise, keep looping
            return;
        }
    }
}

// status function, we make it char* because it's a string
char *Status(int a)
{
    switch (a)
    {
    case 1:
        return "To Do";
    case 2:
        return "In Progress";
    case 3:
        return "Done";
    default:
        return "Unknown error";
    }
}

// print the task function so i don't have to keep typing it manually
void PrintTask(int a)
{
    printf("\n-------------------------------- TASK %03d Information --------------------------------\n", list[a].id);
    printf("| Task ID: %03d |\n", list[a].id);
    printf("|--------------------------\n");
    printf("| Title: %s \n", list[a].title);
    printf("| Description: %s \n", list[a].description);
    printf("| Deadline: %02d/%02d/%04d \n", list[a].date.day, list[a].date.month, list[a].date.year);
    printf("| Status: %s \n", Status(list[a].status));
    printf("------------------------------------------------------------------------------------\n");
}

void lowercase(char *str) {
    for (int i = 0; str[i]; i++) {
        str[i] = tolower(str[i]);
    }
}

// display function
void Display(int a)
{
    // found starts at 0 in case we return back
    int found = 0;

    // if num equals 0, that means no tasks has been added or been deleted to 0
    if (num == 0)
    {
        printf("There are no current tasks right now.\n\n");
        mainMenu();
        return 0;
    }
    else
    {
        // if display(0), then print all of our tasks normally
        if (a == 0)
        {
            for (int i = 0; i < num; i++)
            {
                PrintTask(i);
            }
        }
        else
        {
            // otherwise, keep looping all tasks below or equals to 3
            for (int i = 0; i < num; i++)
            {
                if ((list[i].date.dmy - DMY) <= 3)
                {
                    found = 1;
                    PrintTask(i);
                }
            }

            // if found is still at 0, none found
            if (found == 0)
            {
                printf("No tasks with 3 days deadline exists.\n");
                mainMenu();
                return 0;
            }
        }
        // call function
        mainMenu();
    }
}

void BubbleSortAlp()
{
    int i, j;
    // make a temporary variable to store our struct table
    struct todo temp;
    

    // bubble sort algorithm
    for (i = 0; i < num - 1; i++)
    {
        for (j = 0; j < num - i - 1; j++)
        {
            // compare if index j and index j+1 are both the same, if they aren't, swap
            if (strcmp(list[j].title, list[j + 1].title) > 0)
            {
                // permute
                temp = list[j];

                list[j] = list[j + 1];

                list[j + 1] = temp;
            }
        }
    }
}

void BubbleSortID()
{
    // make a temporary variable to store our struct table
    struct todo temp;

    // bubble sort algorithm
    for (int i = 0; i < num - 1; i++)
    {
        for (int j = 0; j < num - i - 1; j++)
        {
            // if index j's id is above index j+1's id, swap
            if (list[j].id > list[j + 1].id)
            {
                // permute
                temp = list[j];

                list[j] = list[j + 1];

                list[j + 1] = temp;
            }
        }
    }
}

void BubbleSortDMY()
{
    // make a temporary variable to store our struct table
    struct todo temp;

    // bubble sort algorithm
    for (int i = 0; i < num - 1; i++)
    {
        for (int j = 0; j < num - i - 1; j++)
        {
            // if index j's date conversion is above index j+1's date conversion, swap
            if (list[j].date.dmy > list[j + 1].date.dmy)
            {
                // permute
                temp = list[j];

                list[j] = list[j + 1];

                list[j + 1] = temp;
            }
        }
    }
}

// delete function
void Delete(int a)
{
    // initialize our variables
    int sel, found = 0;

    // loop through our entire array
    for (int i = 0; i < num; i++)
    {
        // if delete argument is the same as id
        if (a == list[i].id)
        {
            // found
            found = 1;

            // print our task, argument a which is the input user put in delete function
            PrintTask(a);

            // confirmation input
            printf("\n------------------- Task Deletion Confirmation -------------------\n");
            printf("| Option |           Description                                  \n");
            printf("|--------|---------------------------------------------------------\n");
            printf("|   1    | Yes, delete this task                                   \n");
            printf("|   2    | No, do not delete this task                             \n");
            printf("-------------------------------------------------------------------\n");
            printf("Task ID%03d %s has been selected.\n", list[a].id, list[a].title);
            printf("Are you sure you want to delete this task?\n");
            printf("Enter your choice: ");
            scanf("%d", &sel);

            // delete
            switch (sel)
            {
            // yes
            case 1:
                // make it so that loop starts at a
                for (int j = a; j < num; j++)
                {
                    // anything after a++ is put in a, for "deletion"
                    list[j] = list[j + 1];
                }

                // decrease number of array by 1
                num--;

                // deleted
                printf("ID%03d %s has been deleted.\n", list[a].id, list[a].title);
                mainMenu();
                return;
            // no
            case 2:
                mainMenu();
                return;
            // anything that isnt 1 or 2
            default:
                printf("Invalid option, try again.\n");
                mainMenu();
                return;
            }
        }
    }

    // if found is still 0 after that loop, then no task with that ID is found
    if (found == 0)
    {
        printf("No task with ID %03d found.", a);
        mainMenu();
        return 0;
    }
}

// edit function
void Edit(int a)
{
    int sel, found = 0;

    // same thing as delete, search through our entire array
    for (int i = 0; i < num; i++)
    {
        // if a is the same as id, then it's found
        if (a == list[i].id)
        {
            // found
            found = 1;

            // print our task
            PrintTask(a);

            // menu of selection
            printf("\n------------------- Task Modification Menu -------------------\n");
            printf("| Option |           Description                                \n");
            printf("|--------|-------------------------------------------------------\n");
            printf("|   1    | Modify description                                     \n");
            printf("|   2    | Modify status                                          \n");
            printf("|   3    | Modify deadline                                        \n");
            printf("|   4    | Go back                                               \n");
            printf("-------------------------------------------------------------\n");
            printf("Task ID%03d %s has been selected.\n", list[a].id, list[a].title);
            printf("Enter your choice: ");
            scanf("%d", &sel);

            switch (sel)
            {
            // modify description
            case 1:
                printf("Input a new description: \n");
                scanf("%[^\n]", list[a].description);
                PrintTask(a);
                mainMenu();
                break;
            // modify status
            case 2:
                printf("Pick a status:\n1. To Do\n2. In progress\n3. Done\n");
                scanf("%d", &list[a].status);

                // if status is anything above 3 or equals 0 or below 0, invalid
                if (list[a].status > 3 || list[a].status <= 0)
                {
                    printf("Invalid option, try again.\n\n");
                    Edit(a);
                    return 0;
                }
                else
                {
                    PrintTask(a);
                    mainMenu();
                }
                break;
            case 3:
                // edit deadline
                printf("Input a new deadline (dd/mm/yyyy):\n");
                scanf("%d/%d/%d", &list[a].date.day, &list[a].date.month, &list[a].date.year);
                CalculateDeadline(a);
                break;
            case 4:
                mainMenu();
                break;
            default:
                // invalid option
                printf("Invalid option, try again.");
                Edit(a);
                return 0;
                break;
            }
        }
    }

    // if found is still 0, then no task is found
    if (found == 0)
    {
        printf("No task with ID %03d found.\n", a);
        mainMenu();
        return 0;
    }
}

// function to calculate complete and incomplete tasks
int CalculateTasks(int a)
{
    int complete = 0, incomplete = 0;

    // keep looping through array
    for (int i = 0; i < num; i++)
    {
        // if status is 3 (done), complete
        if (list[i].status == 3)
        {
            complete++;
            // if status is anything other than 3, incomplete
        }
        else
        {
            incomplete++;
        }
    }

    // at the end, depending on what CalculateTasks is, print
    switch (a)
    {
    case 1:
        // if switch(1), print all complete tasks
        return complete;
    case 2:
        // if switch(2), print all incomplete tasks
        return incomplete;
    default:
        return 0;
    }
}

// function for mainMenu
void mainMenu()
{
    // selection variable
    int sel;

    // print our menu
    printf("\n------------------------- Task Management Menu -------------------------\n");
    printf("| Option |                 Description                                \n");
    printf("|--------|-------------------------------------------------------------\n");
    printf("|   1    | Add a new task                                               \n");
    printf("|   2    | Add several tasks                                           \n");
    printf("|   3    | Display a list of all tasks                                 \n");
    printf("|   4    | Sort                                                        \n");
    printf("|   5    | Show tasks with a deadline                                  \n");
    printf("|   6    | Edit                                                        \n");
    printf("|   7    | Delete                                                      \n");
    printf("|   8    | Search                                                      \n");
    printf("|   9    | Statistics                                                  \n");
    printf("|   10   | Exit                                                        \n");
    printf("------------------------------------------------------------------------\n");
    printf("Enter your choice: ");
    scanf("%d", &sel);

    // selection
    switch (sel)
    {
    // add new task
    case 1:
        Add(0);
        break;
    // add several tasks
    case 2:
        int i;
        // ask for user input on how many tasks they want to add
        printf("Input how many tasks you want to add: \n");
        scanf("%d", &i);

        // if they input 0, then nothing will be added
        if (i <= 0)
        {
            printf("Invalid option, try again.\n");
            mainMenu();
        }
        else
        {
            // keep looping to add tasks
            for (int j = 0; j < i; j++)
            {
                printf("Add task %d:\n\n", j + 1);
                Add(1);
            }

            // print that all tasks are added
            printf("All tasks added successfully!\n");
            mainMenu();
        }
        break;
    // display normally
    case 3:
        Display(0);
        break;
    // sort
    case 4:
        int sel2;

        // if number is 0, then no tasks right now
        if (num == 0)
        {
            printf("There are no current tasks right now.\n");
            mainMenu();
        }
        else
        {
            // ask for user input in sorting
            printf("\n------------------- Sort Options -------------------\n");
            printf("| Option |           Description                  \n");
            printf("|--------|-----------------------------------------\n");
            printf("|   1    | Alphabetically                          \n");
            printf("|   2    | By deadline                             \n");
            printf("|   3    | ID                                      \n");
            printf("|   4    | Go back                                 \n");
            printf("---------------------------------------------------\n");
            printf("Enter your choice: ");
            scanf("%d", &sel2);

            switch (sel2)
            {
            case 1:
                // sort alphabetically, then display
                BubbleSortAlp();
                Display(0);
                break;
            case 2:
                // sort through deadline, then display
                BubbleSortDMY();
                Display(0);
                break;
            case 3:
                // sort through id, then display
                BubbleSortID();
                Display(0);
                break;
            case 4:
                mainMenu();
                break;
            default:
                // if no input is added then invalid
                printf("Invalid option, try again.");
                break;
            }
            break;
        }
    // display everything that has 3 days deadline
    case 5:
        Display(1);
        break;
    // edit
    case 6:
        int sel3;

        // ask for user input
        printf("Input the ID of the task you want to edit: \n");
        scanf("%d", &sel3);
        // edit function the task
        Edit(sel3);
        break;
    // delete
    case 7:
        int sel4;

        // ask for user input
        printf("Input the ID of the task you want to delete: \n");
        scanf("%d", &sel4);

        // if the selection is above array, then they can't delete
        if (sel4 == num + 1)
        {
            printf("Deletion is not possible.\n");
            break;
        }
        else
        {
            // delete the id they asked for
            Delete(sel4);
        }
    // search
    case 8:
        int sel5, found = 0;

        // ask for user input
        printf("\n------------------- Search Options -------------------\n");
        printf("| Option |           Description                     \n");
        printf("|--------|--------------------------------------------\n");
        printf("|   1    | By ID                                      \n");
        printf("|   2    | By title                                   \n");
        printf("|   3    | Go back                                    \n");
        printf("------------------------------------------------------\n");
        printf("Enter your choice: ");
        scanf("%d", &sel5);

        switch (sel5)
        {
        // by id
        case 1:
            int sel6;

            // ask for user input
            printf("Input ID for search: \n");
            scanf("%d", &sel6);

            // keep looping through entire array
            for (int i = 0; i < num; i++)
            {
                if (i == sel6)
                {
                    // if found, print sel6
                    found = 1;
                    PrintTask(sel6);
                }
            }

            // if not found, then an id with that task doesn't exist
            if (found == 0)
            {
                printf("No task with ID %03d found.", list[sel6].id);
            }

            break;
        // by title
        case 2:
            int sel7;

            // ask for user input
            printf("Input title for search: \n");
            scanf("%s", sel7);

            // loop through entire array
            for (int i = 0; i < num; i++)
            {
                // compare sel7 and title of the id, if it's 0 then it's the same
                if (strcmp(sel7, list[i].title) == 0)
                {
                    // found, print
                    found = 1;
                    PrintTask(sel7);
                }
            }

            // if still not found, then no task like this exist
            if (found == 0)
            {
                printf("No task with ID %03d found.", list[sel6].id);
            }

            break;
        case 3:
            mainMenu();
            break;
        default:
            // if nothing exists, then invalid
            printf("Invalid option, try again.");
            break;
        }
    // statistics
    case 9:
        int sel8;

        // ask for user input
        printf("\n------------------- Statistics -------------------\n");
        printf("| Option |           Description                \n");
        printf("|--------|---------------------------------------\n");
        printf("|   1    | Display total number of tasks        \n");
        printf("|   2    | Display number of complete and       \n");
        printf("|        | incomplete tasks                     \n");
        printf("|   3    | Display number of days remaining     \n");
        printf("|        | for each task                        \n");
        printf("-------------------------------------------------\n");
        printf("Enter your choice: ");
        scanf("%d", &sel8);

        switch (sel8)
        {
        // total number of tasks
        case 1:
            // just print our variable num, pretty much
            printf("The total number of tasks are: %d\n", num);
            break;
        // total number of complete tasks
        case 2:
            // find it through our calculatetasks function
            printf("The number of complete tasks are: %d\nThe number of incomplete tasks are: %d\n", CalculateTasks(1), CalculateTasks(2));
            break;
        // days remaining for each task
        case 3:
            // loop through our entire array and keep printing each task
            for (int i = 0; i < num; i++)
            {
                // print days remaining by subtracting it
                printf("TASK ID%03d:\nTitle: %s\nDescription: %s\nDays remaining: %.0lf\n\n", list[i].id, list[i].title, list[i].description, list[i].date.dmy - DMY);
            }
            break;
        default:
            // if no option is the same as our number, print invalid
            printf("Invalid option, try again.");
            mainMenu();
            break;
        }
        // go back to mainmenu
        mainMenu();
        break;
    // exit
    case 10:
        exit(0);
        break;
    default:
        // if number isn't the same, invalid
        printf("Invalid option, try again.\n");
        return;
        break;
    }
}

int main()
{
    time_t current_time;
    struct tm *time_info;

    time(&current_time);
    time_info = localtime(&current_time);

    // calculate our DMY by taking our currentyear, currentmonth, and currentday
    currentYear = time_info->tm_year + 1900;
    currentMonth = time_info->tm_mon + 1;
    currentDay = time_info->tm_mday;

    DMY += currentYear * 365;
    DMY += currentMonth * 30;
    DMY += currentDay;

    time(&current_time);
    time_info = localtime(&current_time);

    // mainmenu
    mainMenu();
    return 0;
}