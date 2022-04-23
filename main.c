#include "biblio.h"

int main(){

    int choice;
    int sizeUser = FileSize("users.txt");
    int sizeBook = FileSize("books.txt");
    User *tabUser = LoadUsers("users.txt", sizeUser);
    Book *tabBook = LoadBooks("books.txt", sizeBook);

    WelcomeMsg();
    choice = MainMenu();

    if(choice == 1){

        // Demander à l'utilisateur de se connecter

    }

    else{

        // Demander à l'utilisateur de creer son identifiant
        CreateAccount("users.txt", tabUser, &sizeUser);

    }

    return 0;
}