// for input and output
#include <stdio.h>
// create a variable globale for
int abc = 0;
int currentYear = 2023;
int id = 0;
// struct for adding all variables into one
struct Todo
{
    char Title[30];
    char description[100];
    int status;
    int dd, mm, yy;
    int plusieurs_tache;
};
// function for menu tableau
void call_menu()
{
    printf("|================|Todo List App|=================|\n");
    printf("|\t1. Ajouter une nouvelle tache\n");
    printf("|\t2. Ajouter plusieurs nouvelles taches\n");
    printf("|\t3. Afficher la liste de toutes les taches\n");
    printf("|\t4. Modifier une tache\n");
    printf("|\t5. Supprimer une tache par identifiant\n");
    printf("|\t6. Rechercher les Taches\n");
    printf("|\t7. Statistiques\n");
    printf("|\t8. Quite\n");
    printf("|================================================|\n \n");
    printf("Enter Your choice: ");
}
// function for status menu
void status()
{
    printf("----------------Pick A status---------------\n");

    printf("1- Todo\n");
    printf("2- Doing\n");
    printf("3- Done\n");
    printf("Enter Your choice: ");
}
int main()
{
    int choice;
    // Select what do you want
    int slc;
    struct Todo tach1[100];
    // while for loop menu
    while (1)
    {
        call_menu(); // call the function
        scanf("%d", &choice);
        // Switch menu
        switch (choice)
        {
        case 1:
            printf("Please Put the Title of Your Task: ");
            scanf("%s", tach1[abc].Title);
            printf("Please Put the description: ");
            getchar();
            gets(tach1[abc].description);
            // call the status function
            status();
            scanf("%d", &tach1[abc].status);
            // switch status
            switch (tach1[abc].status)
            {
            case 1:
                printf("Enter a deadline dd/mm/year: ");
                scanf("%d/%d/%d", &tach1[abc].dd, &tach1[abc].mm, &tach1[abc].yy);
                if (tach1[abc].yy < currentYear)
                {
                    printf("invalid year\n");
                }
                else
                {
                    abc++;
                }
                break;

            case 2:
                tach1[abc].plusieurs_tache = 1;
                do
                {
                    printf("Print How many Task Do you wants: ");
                    scanf("%d", &tach1[abc].plusieurs_tache);
                    if (tach1[abc].plusieurs_tache == 0)
                    {
                        printf("Its Imposible Please can you Enter How much Task do you Wants\n");
                    }
                    else
                    {
                        printf("Please Put the Title of Your Task: ");
                        scanf("%s", tach1[abc].Title);
                        printf("Please Put the description: ");
                        getchar();
                        gets(tach1[abc].description);
                        // call the status function
                        status();
                        scanf("%d", &tach1[abc].status);

                        printf("Enter a deadline dd/mm/year: ");
                        scanf("%d/%d/%d", &tach1[abc].dd, &tach1[abc].mm, &tach1[abc].yy);
                        if (tach1[abc].yy < currentYear)
                        {
                            printf("invalid year\n");
                        }
                        else
                        {
                            tach1[abc].plusieurs_tache = 1;
                            abc++;
                        }
                    }
                } while (tach1[abc].plusieurs_tache == 0);
                break;

            case 3:
                if (abc == 0)
                {
                    printf("no task right now\n");
                    printf("Please Can You Add New Task \n\n");
                    break;
                }
                else
                {
                    for (int i = 0; i < abc; i++)
                    {
                        printf("Title : %s\nDiscription : %s \nDeadline: %d/%d/%d\n\n",
                               tach1[i].Title,
                               tach1[i].description,
                               tach1[i].dd, tach1[i].mm, tach1[i].yy,
                               tach1[i].plusieurs_tache);
                    }
                }
                break;
            case 8:
                printf("You have A Good day");
                return 0;
                break;
            default:
                printf("This is Not in The menu\n\n");
                break;
            }
        }
    }
}