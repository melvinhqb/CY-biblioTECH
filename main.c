#include "biblio.h"

int main(){

    int choice;
    int index;
    int sizeUser = FileSize(USER_NAME_FILE);
    int sizeBook = FileSize(BOOK_NAME_FILE);

    AppMsg();
    choice = MainMenu(sizeUser);

    if(choice == 1){

        Book *tabBook = LoadBooks(BOOK_NAME_FILE, sizeBook);
        User *tabUser = LoadUsers(USER_NAME_FILE, sizeUser);
        index = ConnectAccount(tabUser, &sizeUser);
        BookMsg(tabBook, tabUser[index], sizeBook);

        do{

            choice = SecondMenu(tabUser[index].role);

            switch(choice){
                case 1:
                    tabUser[index] = ReserveBook(tabBook, tabUser[index], sizeBook);
                    WriteUser(USER_NAME_FILE, tabUser, sizeUser);
                    WriteBook(BOOK_NAME_FILE, tabBook, sizeBook);
                    break;
                case 3:
                    AddBook(BOOK_NAME_FILE, &sizeBook);
                    Book *tabBook = LoadBooks(BOOK_NAME_FILE, sizeBook);
                    break;
                default:
                    printf("\nCette fonction est indisponible pour le moment !\n");
            }

            choice = EndMenu();

        }while(choice != 0);

    }

    else{

        CreateAccount(USER_NAME_FILE, &sizeUser);

    }

    ByeMsg();
    return 0;
}