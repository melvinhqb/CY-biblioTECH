#include "biblio.h"

// Compare a login with a login table

int CompareTableUserLogin(User *tab, char *login, int size){
    
    for(int i=0;i<size;i++){

        if(strcmp(login, tab[i].login) == 0){

            return i; // If login is in tab

        }

    }

    return -1; // If login is not in tab
}

// Compare an ID with an ID table

int CompareTableBookId(Book *tab, char *id, int size){
    
    for(int i=0;i<size;i++){

        if((int)strtol(id, NULL, 10) == tab[i].id){

            return i; // If login is in tab

        }

    }

    return -1; // If login is not in tab
}