#include <stdio.h>
#include <string.h>

char quantNum[30] = "", prixNum[30] = "", nomNum[30] = "";
int sel;

void quantite() {
    if (strlen(quantNum) == 0) {
        printf("Error, you haven't added a quantity yet.\n");
    } else {
        printf("Quantity: %s\n", quantNum);
    }
}

void prix() {
    if (strlen(prixNum) == 0) {
        printf("Error, you haven't added a price yet.\n");
    } else {
        printf("Price: %s\n", prixNum);
    }
}

void nom() {
    if (strlen(nomNum) == 0) {
        printf("Error, you haven't added a name yet.\n");
    } else {
        printf("Name: %s\n", nomNum);
    }
}

void registers() {
    switch (sel) {
        case 1:
            printf("Input a quantity\n");
            scanf("%s", quantNum);
            break;
        
        case 2:
            printf("Input a price\n");
            scanf("%s", prixNum);
            break;

        case 3:
            printf("Input a name\n");
            scanf("%s", nomNum);
            break;
    }
}

void result() {
    switch (sel) {
        case 1:
            quantite();
            break;
        case 2:
            prix();
            break;
        case 3:
            nom();
            break;
    }
}

int main() {
    int exit = 0;
    while (!exit) {
        mainMenu();
        printf("Do you want to continue (1 for yes, 0 for no): ");
        scanf("%d", &exit);
    }
    return 0;
}

void mainMenu() {
    printf("\nSelect your menu:\n1. Quantite\n2. Prix\n3. Nom\n\n");
    scanf("%d", &sel);

    switch (sel) {
        case 1:
            result();
            break;
        case 2:
            result();
            break;
        case 3:
            result();
            break;
        default:
            printf("Invalid, try again.\n");
            break;
    }
}
