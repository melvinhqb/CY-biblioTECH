#include "biblio.h"

int main(){

    int choice;
    int index;
    int verif;
    int sizeUser = FileSize(USER_NAME_FILE);
    int sizeBook = FileSize(BOOK_NAME_FILE);

    AppMsg();

    do{

        choice = MainMenu(sizeUser);

        if(choice == 1){ // Connect Account

            Book *tabBook = LoadBooks(BOOK_NAME_FILE, sizeBook);
            User *tabUser = LoadUsers(USER_NAME_FILE, sizeUser);
            index = ConnectAccount(tabUser, sizeUser);
            WelcomeMsg(tabUser[index].login);
            BookMsg(tabBook, tabUser[index], sizeBook);

            do{

                choice = SecondMenu(tabUser[index].role);

                switch(choice){
                    case 1:
                        verif = ReserveBook(tabBook, &tabUser[index], sizeBook);
                        if(verif == 1){
                            WriteUser(USER_NAME_FILE, tabUser, sizeUser);
                            WriteBook(BOOK_NAME_FILE, tabBook, sizeBook);
                        }
                        break;
                    case 2:
                        verif = ReturnBook(tabBook, &tabUser[index], sizeBook);
                        if(verif == 1){
                            WriteUser(USER_NAME_FILE, tabUser, sizeUser);
                            WriteBook(BOOK_NAME_FILE, tabBook, sizeBook);
                        }
                        break;
                    case 3:
                        BookMsg(tabBook, tabUser[index], sizeBook);
                        break;
                    case 4:
                        choice = AddBook(BOOK_NAME_FILE, tabBook, &sizeBook);
                        if(choice == -2){
                            tabBook = LoadBooks(BOOK_NAME_FILE, sizeBook);
                        }
                        else{
                            WriteBook(BOOK_NAME_FILE, tabBook, sizeBook);
                        }
                        break;
                    case 5:
                        verif = RemoveBook(tabBook, sizeBook);
                        if(verif == 1){
                            WriteBook(BOOK_NAME_FILE, tabBook, sizeBook);
                        }
                        break;

                }

                choice = EndMenu();

            }while(choice != 0);

        }
        else if(choice == 2){ // Create Account

            CreateAccount(USER_NAME_FILE, &sizeUser);
            choice = EndMenu();

        }
        else if(choice == 3){

            Book *tabBook = LoadBooks(BOOK_NAME_FILE, sizeBook);
            ShowBookSuggestionNoAccount(tabBook, sizeBook);
            choice = EndMenu();

        }
        else{ // If Error Input

            choice = EndMenu();

        }
    
    }while(choice != 0);

    ByeMsg();
    return 0;
}