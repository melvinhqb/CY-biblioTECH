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

    char *lf = NULL;

    if(fgets(c, size, stdin) != NULL){

        lf = strchr(c, '\n');

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

// Function that removes spaces from a char* and returns 1 if its size is correct

int UserInput(char *input, int size){

    int check_size;

    check_size = ReadInput(input, size);

    if(check_size == 1){

            ReplaceSpaces(input);

    }
    else{

        printf("\nCe champ saisie est trop grand ! (%d caracteres max)\n", size-2);

    }

    return check_size;

}

// Function that returns the integer choice in a user's menu

int MenuChoice(char *choice, int max){

    int check_size;
    int c = 0;

    check_size = ReadInput(choice, 4);

    if(check_size != 1){

        printf("\nErreur de saisie, veuillez recommencer !\n");
        return 0;

    }
    else if(choice[1] != '\0' && ((int)choice[1] < 48 || (int)choice[1] > 57)){

        printf("\nErreur de saisie, veuillez recommencer !\n");
        return 0;

    }

    c = (int)strtol(choice, NULL, 10);

    if(c < 1 || c > max){

        printf("\nErreur de saisie, veuillez recommencer !\n");
        return 0;

    }

    return c;

}

// Asks the user to choose from the main menu

int MainMenu(int nb_users){

    int c = 0;
    int user_choice = 0;

    char choice[3];

    if(nb_users == 0){
        printf("\nCreer un compte\n");
        return 2;
    }

    do{

        printf("\n1 - Se connecter\n");
        printf("2 - Creer un compte\n");
        printf(">>>");
        
        user_choice = MenuChoice(choice, 2);
    
    }while(user_choice == 0);

    return user_choice; // Returns 1 or 2

}

// Asks the user to choose from the second menu

int SecondMenu(int role){

    int c = 0;
    int user_choice = 0;
    int nb_choice = 3;

    char choice[3];

    do{

        printf("\n1 - Emprunter un livre\n");
        printf("2 - Rendre un livre\n");
        printf("3 - Afficher mes livres\n");

        if(role == TEACHER){

            printf("4 - Ajouter un livre\n");
            printf("5 - Retirer un livre\n");
            nb_choice += 2;

        }

        printf(">>>");

        user_choice = MenuChoice(choice, nb_choice);
    
    }while(user_choice == 0);

    return user_choice;

}

// Asks the user to choose from the end menu

int EndMenu(){

    int c = 0;
    int user_choice = 0;

    char choice[3];

    do{

        printf("\n1 - Continuer\n");
        printf("2 - Quitter\n");
        printf(">>>");
        
        user_choice = MenuChoice(choice, 2);
    
    }while(user_choice == 0);

    if(user_choice == 2){

        return 0;

    }

    return user_choice;

}