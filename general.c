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
// use the string entered by the user and the max size allowed 
// return 1 if size of the string is ok also 0

int ReadInput(char *c, int size){

    char *position = NULL;
    // read the string form the keybroad 
    if(fgets(c, size, stdin) != NULL){ // input error check

        position = strchr(c, '\n');

        if(position != NULL){

            *position = '\0';
            return 1;

        }
        else{

            EmptyBuffer(); // empty the buffer else 
            return 0;

        }

    }

}

// Function that removes spaces from a char* and returns 1 if its size is correct
// use the string entered by the user and the max size allowed 
// return 1 if size of the string is ok also 0


int UserInput(char *input, int size){

    int check_size;

    check_size = ReadInput(input, size);

    if(check_size == 1){

            ReplaceSpaces(input); // text processing 

    }
    else{

        printf("\nCe champ saisie est trop grand ! (%d caracteres max)\n", size-2);
        // explain the error to the user

    }

    return check_size;

}

// Function that returns the integer choice in a user's menu
// Enter : input from user choise and of the current menu
// return the choise (1,2,3,... ,max ) or 0 if error 

int MenuChoice(char *choice, int max){

    int check_size;
    int c = 0;

    check_size = ReadInput(choice, 5);

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
// first interface  after ./exec
// this function is mainly a display function 
// nb_users of user form txt archive
//return user choise 

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
// this function is mainly a display function 
// this function is the main interface into the book manager 
// enter the role of the user (student or teacher)
//return user choise 


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
// function to make a choise ( leave or  continue) after have made an function
// return 0 or  1 according to the user choise

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