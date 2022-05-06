#include "biblio.h"

int main(){

    int choice;
    int sizeUser = FileSize(USER_NAME_FILE);
    int sizeBook = FileSize(BOOK_NAME_FILE);
    Book *tabBook = LoadBooks(BOOK_NAME_FILE, sizeBook);

    AppMsg();
    choice = MainMenu();

    if(choice == 1){

        User *tabUser = LoadUsers(USER_NAME_FILE, sizeUser);
        int index = ConnectAccount(tabUser, &sizeUser);
        BookMsg(tabBook, tabUser[index], sizeBook);
        choice = SecondMenu(tabUser[index].role);

        if(choice == 0){

            ByeMsg();

        }

    }

    else{

        CreateAccount(USER_NAME_FILE, &sizeUser);

    }

    return 0;
}