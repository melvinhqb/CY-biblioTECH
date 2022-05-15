#include "biblio.h"

int main(){

    int choice;
    int index;
    int sizeUser = FileSize(USER_NAME_FILE);
    int sizeBook = FileSize(BOOK_NAME_FILE);

    AppMsg();

    do{

        choice = MainMenu(sizeUser);

        if(choice == 1){

            Book *tabBook = LoadBooks(BOOK_NAME_FILE, sizeBook);
            User *tabUser = LoadUsers(USER_NAME_FILE, sizeUser);
            index = ConnectAccount(tabUser, &sizeUser);
            WelcomeMsg(tabUser[index].login);
            BookMsg(tabBook, tabUser[index], sizeBook);

            do{

                choice = SecondMenu(tabUser[index].role);

                switch(choice){
                    case 1:
                        tabUser[index] = ReserveBook(tabBook, tabUser[index], sizeBook);
                        WriteUser(USER_NAME_FILE, tabUser, sizeUser);
                        WriteBook(BOOK_NAME_FILE, tabBook, sizeBook);
                        break;
                    case 2:
                        tabUser[index] = ReturnBook(tabBook, tabUser[index], sizeBook);
                        WriteUser(USER_NAME_FILE, tabUser, sizeUser);
                        WriteBook(BOOK_NAME_FILE, tabBook, sizeBook);
                        break;
                    case 3:
                        BookMsg(tabBook, tabUser[index], sizeBook);
                        break;
                    case 4:
                        choice = AddBook(BOOK_NAME_FILE, tabBook, &sizeBook);
                        if(choice < 0){
                            tabBook = LoadBooks(BOOK_NAME_FILE, sizeBook);
                        }
                        else{
                            WriteBook(BOOK_NAME_FILE, tabBook, sizeBook);
                        }
                        break;
                    case 5:
                        RemoveBook(tabBook, sizeBook);
                        WriteBook(BOOK_NAME_FILE, tabBook, sizeBook);
                        break;
                    default:
                        printf("\nCette fonction est indisponible pour le moment !\n");
                }

                choice = EndMenu();

            }while(choice != 0);

        }

        else if(choice == 2){

            CreateAccount(USER_NAME_FILE, &sizeUser);
            choice = EndMenu();

        }
    
    }while(choice != 0);

    ByeMsg();
    return 0;
}