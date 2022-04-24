#include "biblio.h"

int main(){

    int choice;
    int sizeUser = FileSize("users.txt");
    int sizeBook = FileSize("books.txt");
    Book *tabBook = LoadBooks("books.txt", sizeBook);

    WelcomeMsg();
    choice = MainMenu();

    if(choice == 1){

        // Demander à l'utilisateur de se connecter
        ConnectAccount("users.txt", &sizeUser);

    }

    else{

        // Demander à l'utilisateur de creer son identifiant
        CreateAccount("users.txt", &sizeUser);

    }

    return 0;
}