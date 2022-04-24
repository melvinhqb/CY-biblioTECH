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

// Asks the user to choose from the main menu

int MainMenu(){

    int c;
    int check_size = 0;
    char choice[3];

    do{

        printf("\n1 - Se connecter\n");
        printf("2 - Creer un compte\n");
        printf(">>>");
        
        check_size = ReadInput(choice, sizeof(choice));

        c = (int) strtol (choice, NULL, 10);

        if(c != 1 && c != 2){
            printf("\nErreur de saisie, veuillez recommencer !\n");
        }
    
    }while(c != 1 && c != 2 || check_size != 1);

    return c;

}

// Create a user account and store the data in users.txt

void CreateAccount(char *name_file, User *tab, int *size){

    char login[22];
    char pswrd[22];
    char role[3];
    int cmp = 1;
    int c;
    int check_size = 0;
    FILE *file = NULL;
    
    do{

        printf("\nLogin\n>>>");
        check_size = ReadInput(login, sizeof(login));

        for(int i=0;i<*size;i++){

            cmp = strcmp(login, tab[i].login);

            if(cmp == 0){

                break;

            }

        }

        if(cmp == 0){

            printf("\nCe login est deja pris !\n");

        }

        else if(check_size != 1){

            printf("\nCe login est trop grand ! (20 caracteres max)\n");

        }

    }while(cmp == 0 || check_size != 1);

    check_size = 0;
    do{

        printf("\nMot de passe\n>>>");
        check_size = ReadInput(pswrd, sizeof(pswrd));

        if(check_size != 1){

            printf("\nCe mot de passe est trop grand !  (20 caracteres max)\n");

        }

    }while(check_size != 1);

    Encode(pswrd, "clevigenere");

    check_size = 0;

    do{

        printf("\nQuel est votre role ?\n");
        printf("1 - Etudiant\n");
        printf("2 - Professeur\n");
        printf(">>>");
        check_size = ReadInput(role, sizeof(role));
        c = (int) strtol (role, NULL, 10);

        if(c != 1 && c != 2){

            printf("\nErreur de saisie, veuillez recommencer !\n");

        }

    }while(c != 1 && c != 2 || check_size != 1);

    
    file = fopen(name_file, "a");
    fprintf(file, "%s %s %d 0 0 0 0 0\n", login, pswrd, c);
    fclose(file);
    printf("\nVotre compte est finalise !\n");

}