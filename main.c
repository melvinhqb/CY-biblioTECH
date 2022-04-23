#include "biblio.h"

int main(){

    int choice;

    WelcomeMsg();
    choice = MainMenu();

    while(choice != 1 && choice != 2){

        printf("\nErreur de saisie, veuillez recommencer !\n");
        choice = MainMenu();

    }

    if(choice == 1){

        // Demander à l'utilisateur de se connecter

    }

    else{

        // Demander à l'utilisateur de creer son identifiant

    }

    return 0;
}