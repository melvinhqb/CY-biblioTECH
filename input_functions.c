#include "biblio.h"

/*****************************************************
                USER INPUT MANAGEMENT
*****************************************************/

// Empty the buffer after using the fgets() function

void EmptyBuffer(){

    int c = 0;

    while (c != '\n' && c != EOF){

        c = getchar();

    }

}

// Reads a string entered by the user, looks for the character \n and replaces it with \0

void ReadInput(char *c, int size){

    if(fgets(c, size, stdin) != NULL){

        char *lf = strchr(c, '\n');

        if(lf != NULL){

            *lf = '\0';

        }
        else{

            EmptyBuffer();

        }

    }

}

// Asks the user to choose from the main menu

int MainMenu(){

    int c;
    char choice[50];

    do{

        printf("\n1 - Se connecter\n");
        printf("2 - Creer un compte\n");
        printf(">>>");

        ReadInput(choice, sizeof(choice));

        c = (int) strtol (choice, NULL, 10);

        if(c != 1 && c != 2){
            printf("\nErreur de saisie, veuillez recommencer !\n");
        }
    
    }while(c != 1 && c != 2);

    return c;

}

// Create a user account and store the data in users.txt

void CreateAccount(char *name_file, User *tab, int *size){

    char login[50];
    char pswrd[50];
    char role[50];
    int cmp = 1;
    int c;
    FILE *file = NULL;
    
    do{

        printf("\nLogin\n>>>");
        ReadInput(login, sizeof(login));

        for(int i=0;i<*size;i++){

            cmp = strcmp(login, tab[i].login);

            if(cmp == 0){

                break;

            }

        }

        if(cmp == 0){

            printf("\nCe login est deja pris !\n");

        }

    }while(cmp == 0);

    cmp = 1;
    printf("\nMot de passe\n>>>");
    ReadInput(pswrd, sizeof(pswrd));
    Encode(pswrd, "clevigenere");

    do{

        printf("\nQuel est votre role ?\n");
        printf("1 - Etudiant\n");
        printf("2 - Professeur\n");
        printf(">>>");
        ReadInput(role, sizeof(role));
        c = (int) strtol (role, NULL, 10);

        if(c != 1 && c != 2){

            printf("\nErreur de saisie, veuillez recommencer !\n");

        }

    }while(c != 1 && c != 2);

    
    file = fopen(name_file, "a");
    fprintf(file, "%s %s %d 0 0 0 0 0\n", login, pswrd, c);
    fclose(file);
    printf("\nVotre compte est finalise !\n");

}