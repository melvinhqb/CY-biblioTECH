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

        do{

            choice = SecondMenu(tabUser[index].role);

            switch(choice){
                case 3:
                    AddBook(BOOK_NAME_FILE, &sizeBook);
                    break;
                default:
                    printf("\nCette fonction est indisponible pour le moment !\n");
            }

            choice = EndMenu();

            if(choice == 1){

                User *tabUser = LoadUsers(USER_NAME_FILE, sizeUser);

            }

        }while(choice != 0);

    }

    else{

        CreateAccount(USER_NAME_FILE, &sizeUser);

    }

    ByeMsg();
    return 0;
}