#include "biblio.h"

/*****************************************************
                USER INPUT MANAGEMENT
*****************************************************/

// Empty the buffer after using the fgets() function

void EmptyBuffer()
{
    int c = 0;
    while (c != '\n' && c != EOF)
    {
        c = getchar();
    }
}

// Asks the user to choose from the main menu

int MainMenu(){

    int c;
    char choice[50];

    printf("\n1 - Se connecter\n");
    printf("2 - Creer un compte\n");
    printf(">>>");

    if(fgets(choice, sizeof(choice), stdin) != NULL){

        c = (int) strtol (choice, NULL, 10);
        char *lf = strchr(choice, '\n');
        if(lf != NULL){
            *lf = '\0';
        }
        else{
            EmptyBuffer();
        }

    }

    return c;

}

