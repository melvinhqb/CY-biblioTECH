#include "biblio.h"

int main(){

    int choice;
    int sizeUser = FileSize("users.txt");
    int sizeBook = FileSize("books.txt");
    Book *tabBook = LoadBooks("books.txt", sizeBook);

    WelcomeMsg();
    choice = MainMenu();

    if(choice == 1){

        User *tabUser = LoadUsers("users.txt", sizeUser);
        int index = ConnectAccount(tabUser, &sizeUser);
        BookMsg(tabBook, tabUser[index], sizeBook);
    }

    else{

        CreateAccount("users.txt", &sizeUser);

    }

    return 0;
}