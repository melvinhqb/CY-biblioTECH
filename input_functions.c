#include "biblio.h"

// Function that asks the user to choose from the main menu

int MainMenu(){

    int c;
    char choice[50];

    printf("\n1 - Se connecter\n");
    printf("2 - Creer un compte\n");
    printf(">>>");

    if(fgets(choice, sizeof(choice), stdin) != NULL){

        c = (int) strtol (choice, NULL, 10);  

    }

    return c;

}
