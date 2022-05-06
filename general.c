#include "biblio.h"

void AppMsg(){

    printf("\n***********************************\n");
    printf("     Application CY-biblioTech     \n");
    printf("***********************************\n");

}

void ByeMsg(){

    printf("\n***********************************\n");
    printf("             Au revoir             \n");
    printf("***********************************\n");

}

// Empty the buffer after using the fgets() function

void EmptyBuffer(){

    int c = 0;

    while (c != '\n' && c != EOF){

        c = getchar();

    }

}

// Reads a string entered by the user, looks for the character \n and replaces it with \0

int ReadInput(char *c, int size){

    if(fgets(c, size, stdin) != NULL){

        char *lf = strchr(c, '\n');

        if(lf != NULL){

            *lf = '\0';
            return 1;

        }
        else{

            EmptyBuffer();
            return 0;

        }

    }

}

// Removes spaces in a table of caracteres

void DeleteSpaces(char *tab){
    
    int i = 0, j = 0;

    while(tab[i] != '\0'){

        if(tab[i] != ' '){

            tab[j] = tab[i];
            j++;

        }

        i++;

    }

    tab[j] = '\0';
}

// Asks the user to choose from the main menu

int MainMenu(){

    int c = 0;
    int check_size = 0;

    char choice[3];

    do{

        printf("\n1 - Se connecter\n");
        printf("2 - Creer un compte\n");
        printf(">>>");
        
        check_size = ReadInput(choice, sizeof(choice));

        if(check_size != 1){

            printf("\nErreur de saisie, veuillez recommencer !\n");

        }
        else{

            c = (int) strtol (choice, NULL, 10);

            if(c != 1 && c != 2){

                printf("\nErreur de saisie, veuillez recommencer !\n");

            }

        }
    
    }while(c != 1 && c != 2 || check_size != 1);

    return c; // Returns 1 or 2

}

// Asks the user to choose from the second menu

int SecondMenu(int role){

    int n = 2;
    int c = 0;
    int check_size = 0;

    char choice[3];

    if(role == 3){

        n = 3;

    }

    do{

        printf("\n1 - Emprunter un livre\n");
        printf("2 - Rendre un livre\n");

        if(role == 3){

            printf("3 - Ajouter un livre\n");
            printf("4 - Retirer un livre\n");

        }

        printf("0 - Quitter\n");
        printf(">>>");

        check_size = ReadInput(choice, sizeof(choice));

        if(check_size != 1){

            printf("\nErreur de saisie, veuillez recommencer !\n");

        }
        else{

            c = (int) strtol (choice, NULL, 10);

            if(c < 0 || c > n){

                printf("\nErreur de saisie, veuillez recommencer !\n");

            }

        }
    
    }while(c < 0 || c > n || check_size != 1);

    return c;

}