#include "biblio.h"

// Function that returns the integer choice in a user's menu
// Enter : input from user choise and of the current menu
// return the choise (1,2,3,... ,max ) or 0 if error 

int MenuChoice(char *choice, int size_choice, int max){

    int check_size;
    int c = 0;

    check_size = ReadInput(choice, size_choice);

    if(check_size != 1){

        printf("\nErreur de saisie !\n");
        return 0;

    }
    else if(choice[1] != '\0' && ((int)choice[1] < 48 || (int)choice[1] > 57)){

        printf("\nErreur de saisie !\n");
        return 0;

    }

    c = (int)strtol(choice, NULL, 10);

    if(c < 1 || c > max){
        
        printf("\nErreur de saisie !\n");
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

    printf("\n1 - Se connecter\n");
    printf("2 - Creer un compte\n");
    printf("%s(Tapez 1 ou 2)%s\n", ITALIC, RESET_FONT);
    printf(ARROW);
    
    user_choice = MenuChoice(choice, sizeof(choice), 2);

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

    printf("\n1 - Emprunter un livre\n");
    printf("2 - Rendre un livre\n");
    printf("3 - Afficher mes livres\n");

    if(role == TEACHER){

        printf("4 - Ajouter un livre\n");
        printf("5 - Retirer un livre\n");
        nb_choice += 2;

    }

    printf(ARROW);

    user_choice = MenuChoice(choice, sizeof(choice), nb_choice);

    return user_choice;

}

// Asks the user to choose from the end menu
// function to make a choise ( leave or  continue) after have made an function
// return 0 or  1 according to the user choise

int EndMenu(){

    int c = 0;
    int user_choice = 0;

    char choice[3];

    printf("\n1 - Continuer\n");
    printf("2 - Quitter %s(par defaut)%s\n", ITALIC, RESET_FONT);
    printf(ARROW);
    
    user_choice = MenuChoice(choice, sizeof(choice), 2);

    if(user_choice == 1){

        return 1;

    }
    else if(user_choice == 2){

        return 0;

    }
    else{

        user_choice = EndMenu();

    }

}

// Ask the user to choose from the sort menu

int SortMenu(){

    int user_choice;
    char choice[3];

    printf("\nType de tri :\n\n");
    printf("1 - Par titre %s(par defaut)%s\n", ITALIC, RESET_FONT);
    printf("2 - Par auteur\n");
    printf("3 - Par categorie\n");
    printf(ARROW);

    user_choice = MenuChoice(choice, sizeof(choice), 3);

    return user_choice;

}

// Ask the user to choose from the type menu

int TypeMenu(){

    int user_choice;
    char choice[3];

    printf("\nQuel est la categorie ?\n");
    printf("1 - Science\n");
    printf("2 - Litterature\n");
    printf("3 - Art\n");
    printf("4 - History\n");
    printf(ARROW);

    user_choice = MenuChoice(choice, sizeof(choice), 4);

    return user_choice;

}