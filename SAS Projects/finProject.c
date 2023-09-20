#include <stdio.h>
#include <string.h>

int num = 0, currentYear = 2023, currentMonth = 9, currentDay = 20, DMY = 0, isAdd = 0;

char* Status (int a);
int Add (int a);
void Display (int a);
void BubbleSortID ();
void BubbleSortAlp ();
void BubbleSortDMY ();
void mainMenu ();

struct todo {
    int status;
    char title[30], description[60];
    int id;

        struct deadline {
            int day, month, year;
            double dmy;
        } date;

} list[100];

void Check(int a) {
    if (isAdd = 0) {
        Edit(a);
    } else {
        Add(a);
    }
}

void CalculateDeadline(int a) {
    if (list[a].date.year < currentYear || list[a].date.year <= 0) {
    printf("Invalid year, try again.\n\n");
    Check(a);
    return 0;
    } else if (list[a].date.month > 12 || list[a].date.month <= 0) {
        printf("Invalid month, try again.\n\n");
        Check(a);
        return 0;
    } else if (list[a].date.day <= 0) {
        printf("Invalid day, try again.\n\n");
        Check(a);
        return 0;
    } else {
        if (list[a].date.day >= 31) {
            switch (list[a].date.month) {
                case 2:
                    if (list[a].date.year % 400 == 0) {
                        list[a].date.day = 29;
                    } else if (list[a].date.year % 100 == 0) {
                        list[a].date.day = 28;
                    } else if (list[a].date.year % 4 == 0) {
                        list[a].date.day = 29;
                    } else {
                        list[a].date.day = 28;
                    }
                    break;
                case 4:
                    list[a].date.day = 30;
                    break;
                case 6:
                    list[a].date.day = 30;
                    break;
                case 9:
                    list[a].date.day = 30;
                    break;
                case 11:
                    list[a].date.day = 30;
                    break;
                default:
                    list[a].date.day = 31;
                    break;
            }
        }
    }

    list[a].id = a;

    list[a].date.dmy = 0;
    list[a].date.dmy += list[a].date.year * 365;
    list[a].date.dmy += list[a].date.month * 30;
    list[a].date.dmy += list[a].date.day;

    if (DMY > list[a].date.dmy) {
        printf("Deadline is lower than current date. Try again.\n");
        Check(a);
        return 0;
    }
}

int Add(int a) {
    isAdd = 1;
    printf("Input a title for your task: \n");
    scanf(" %[^\n]", list[num].title);

    printf("Input a description for your task: \n");
    scanf(" %[^\n]", list[num].description);

    printf("Pick a status:\n1. To Do\n2. In progress\n3. Done\n");
    scanf("%d", &list[num].status);

    if (list[num].status > 3 || list[num].status <= 0) {
        printf("Invalid option, try again.\n\n");
        Add(a);
        return 0;
    }

    printf("Input a deadline (dd/mm/yyyy):\n");
    scanf("%d/%d/%d", &list[num].date.day, &list[num].date.month, &list[num].date.year);

    CalculateDeadline(num);

    printf("Task %s has been created successfully with an ID of ID%03d.\n\n", list[num].title, list[num].id);
    isAdd = 0;
    num++;

    switch (a) {
        case 0:
            mainMenu();
        case 1:
            return;
    }
}

char* Status(int a) {
    switch (a) {
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

void PrintTask(int a) {
    printf("TASK ID%03d:\n\nTitle: %s\nDescription: %s\n", list[a].id, list[a].title, list[a].description);
    printf("Deadline: %02d/%02d/%04d\nStatus: %s\nID: %03d\n\n", list[a].date.day, list[a].date.month, list[a].date.year, Status(list[a].status), list[a].id);
}

void Display(int a) {
    int found = 0;

    if (num == 0) {
        printf("There are no current tasks right now.\n\n");
        mainMenu();
        return 0;
    } else {
        if (a == 0) {
            for (int i = 0; i < num; i++) {
                PrintTask(i);
            }
        } else {
            for (int i = 0; i < num; i++) {
                if ((list[i].date.dmy - DMY) <= 3) {
                    found = 1;
                    PrintTask(i);
                }
            }

            if (found == 0) {
                printf("No tasks with 3 days deadline exists.\n");
                mainMenu();
                return 0;
            }
        }
        mainMenu();
    }
}

void BubbleSortAlp () {
    struct todo temp;

    for (int i = 0; i < num - 1; i++) {
        for (int j = 0; j < num - i - 1; j++) {
            if (strcmp(list[j].title, list[j + 1].title) > 0) {
                temp = list[j];

                list[j] = list[j + 1];

                list[j + 1] = temp;
            }
        }
    }
}

void BubbleSortID () {
    struct todo temp;

    for (int i = 0; i < num - 1; i++) {
        for (int j = 0; j < num - i - 1; j++) {
            if (list[j].id > list[j + 1].id) {
                temp = list[j];

                list[j] = list[j + 1];

                list[j + 1] = temp;
            }
        }
    }
}

void BubbleSortDMY () {
    struct todo temp;

    for (int i = 0; i < num - 1; i++) {
        for (int j = 0; j < num - i - 1; j++) {
            if (list[j].date.dmy > list[j + 1].date.dmy) {
                temp = list[j];

                list[j] = list[j + 1];

                list[j + 1] = temp;
            }
        }
    }
}

void Delete(int a) {
    int sel, found;

    for (int i = 0; i < num; i++) {
        if (a == list[i].id) {
            found = 1;
            PrintTask(a);
            printf("Task ID%03d %s has been selected.\nAre you sure you want to delete this task?\n1. Yes\n2. No\n\n", list[a].id, list[a].title);
            scanf("%d", &sel);

            switch (sel) {
                case 1:
                    for (int j = a; j < num; j++) {
                        list[a] = list[a + 1];
                    }

                    num--;
                    
                    printf("ID%03d %s has been deleted.\n", list[a].id, list[a].title);
                    mainMenu();
                    return;
                case 2:
                    mainMenu();
                    return;
                default:
                    printf("Invalid option, try again.\n");
                    mainMenu();
                    return;
            }
        }
    }

    if (found == 0) {
        printf("No task with ID %03d found.", a);
        mainMenu();
        return 0;
    }

}

void Edit(int a) {
    int sel, found;

    for (int i = 0; i < num; i++) {
        if (a == list[i].id) {
            found = 1;
            PrintTask(a);
            printf("Task ID%03d %s has been selected.\n\n1. Modify description\n2. Modify status\n3. Modify deadline\n4. Go back\n\n", list[a].id, list[a].title);
            scanf("%d", &sel);

            switch (sel) {
                case 1:
                    printf("Input a new description: \n");
                    scanf(" %[^\n]", list[a].description);
                    PrintTask(a);
                    mainMenu();
                    break;
                case 2:
                    printf("Pick a status:\n1. To Do\n2. In progress\n3. Done\n");
                    scanf("%d", &list[a].status);

                    if (list[a].status > 3 || list[a].status <= 0) {
                        printf("Invalid option, try again.\n\n");
                        Edit(a);
                        return 0;
                    } else {
                        PrintTask(a);
                        mainMenu();
                    }
                    break;
                case 3:
                    printf("Input a new deadline (dd/mm/yyyy):\n");
                    scanf("%d/%d/%d", &list[a].date.day, &list[a].date.month, &list[a].date.year);
                    CalculateDeadline(a);
                    break;
                case 4:
                    break;
                default:
                    printf("Invalid option, try again.");
                    Edit(a);
                    return 0;
                    break;
            }
        }
    }

    if (found == 0) {
        printf("No task with ID %03d found.\n", a);
        mainMenu();
        return 0;
    }
}

int CalculateTasks (int a) {
    int complete, incomplete;

    for (int i = 0; i < num; i++) {
        if (list[i].status = 3) {
            complete++;
        } else {
            incomplete++;
        }
    }

    switch (a) {
        case 1:
            return complete;
        case 2:
            return incomplete;
        default:
            return 0;
    }
}

void mainMenu () {
    int sel;

    printf("Please select an option:\n1. Add a new task\n2. Add several tasks\n3. Display a list of all tasks\n4. Sort\n5. Show tasks with deadline\n6. Edit\n7. Delete\n8. Search\n9. Statistics\n\n");
    scanf("%d", &sel);

    switch (sel) {
        case 1:
            Add(0);
            break;
        case 2:
            int i;
            printf("Input how many tasks you want to add: \n");
            scanf("%d", &i);

            if (i == 0) {
                printf("Invalid option, try again.\n");
                mainMenu();
            } else {
                for (int j = 0; j < i; j++) {
                    printf("Add task %d:\n\n", j + 1);
                    Add(1);
                }

                printf("All tasks added successfully!\n");
                mainMenu();
            }
            break;
        case 3:
            Display(0);
            break;
        case 4:
            int sel2;

            if (num == 0) {
                printf("There are no current tasks right now.\n");
                mainMenu();
            } else {
                printf("How would you like to sort?\n1. Alphabetically\n2. By deadline\n3. ID\n4. Go back\n\n");
                scanf("%d", &sel2);

                switch (sel2) {
                    case 1:
                        BubbleSortAlp();
                        Display(0);
                        break;
                    case 2:
                        BubbleSortDMY();
                        Display(0);
                        break;
                    case 3:
                        BubbleSortID();
                        Display(0);
                        break;
                    case 4:
                        break;
                    default:
                        printf("Invalid option, try again.");
                        break;
                    }
                break;
            }
        case 5:
            Display(1);
            break;
        case 6:
            int sel3;

            printf("Input the ID of the task you want to edit: \n");
            scanf("%d", &sel3);
            Edit(sel3);
            break;
        case 7:
            int sel4;

            printf("Input the ID of the task you want to delete: \n");
            scanf("%d", &sel4);

            if (sel4 == num + 1) {
                printf("Deletion is not possible.\n");
                break;
            } else {
                Delete(sel4);
            }
        case 8:
            int sel5;

            printf("How would you like to search?\n1. By ID\n2. By title\n3. Go back\n\n");
            scanf("%d", &sel5);

            switch (sel5) {
                case 1:
                    int sel6, found = 0;

                    printf("Input ID for search: \n");
                    scanf("%d", &sel6);

                    for (int i = 0; i < num; i++) {
                        if (i == sel6) {
                            found = 1;
                            PrintTask(sel6);
                        }
                    }

                    if (found == 0) {
                        printf("No task with ID %03d found.", list[sel6].id);
                    }

                    break;
                case 2:
                    int sel7;

                    printf("Input title for search: \n");
                    scanf("%s", sel7);

                    for (int i = 0; i < num; i++) {
                        if (strcmp(sel7, list[i].title) == 0) {
                            found = 1;
                            PrintTask(sel6);
                        }
                    }

                    if (found == 0) {
                        printf("No task with ID %03d found.", list[sel6].id);
                    }

                    break;
                case 3:
                    break;
                default:
                    printf("Invalid option, try again.");
                    break;
            }
        case 9:
            int sel8;

            printf("Select an option:\n1. Display total number of tasks\n2. Display number of complete and incomplete tasks\n3. Display number of days remaining for each task\n\n");
            scanf("%d", &sel8);

            switch (sel8) {
                case 1:
                    printf("The total number of tasks are: %d\n", num);
                    break;
                case 2:
                    printf("The number of complete tasks are: %d\nThe number of incomplete tasks are: %d\n", CalculateTasks(1), CalculateTasks(2));
                    break;
                case 3:
                    for (int i = 0; i < num; i++) {
                        printf("TASK ID%03d:\nTitle: %s\nDescription: %s\nDays remaining: %d\n", list[i].id, list[i].title, list[i].description, list[i].date.dmy - DMY);
                    }
                    break;
                default:
                    printf("Invalid option, try again.");
                    mainMenu();
                    break;
            }
            mainMenu();
            break;
        default:
            printf("Invalid option, try again.\n");
            mainMenu();
            break;
    }
}

int main () {
    DMY += currentYear * 365;
    DMY += currentMonth * 30;
    DMY += currentDay;
    mainMenu();
    return 0;
}