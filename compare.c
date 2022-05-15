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

int CompareTableBookId(Book *tab, long long id, int size){
    
    for(int i=0;i<size;i++){

        if(id == tab[i].id){

            return i; // If ID is in tab

        }

    }

    return -1; // If ID is not in tab
}

// Compare a title with a title table

int CompareTableBookTitle(Book *tab, char *title, int size){

    for(int i=0;i<size;i++){

        if(strcmp(title, tab[i].title) == 0){

            return i; // If title is in tab

        }

    }

    return -1; // If title is not in tab

}

// Compare an author with an author table

int CompareTableBookAuthor(Book *tab, char *author, int size){

    for(int i=0;i<size;i++){
        if(strcmp(author, tab[i].author) == 0){
            return i; // If author is in tab

        }

    }

    return -1; // If author is not in tab

}

// Compare a type with a type table

int CompareTableBookType(Book *tab, int type, int size){

    for(int i=0;i<size;i++){

        if(tab[i].type == type){

            return i; // If type is in tab

        }

    }

    return -1; // If type is not in tab

}

// Compare a book with a book table

int CompareTableBook(Book *tab, Book book, int size){

    int index = CompareTableBookId(tab, book.id, size);
    int vrf_title;
    int vrf_author;
    int vrf_type;

    if(index != -1){

        vrf_title = strcmp(book.title, tab[index].title);
        vrf_author = strcmp(book.author, tab[index].author);

        if(vrf_title == 0 && vrf_author == 0 && tab[index].type == book.type){

            return index; // If book is in tab
            
        }

        return -1; // If ID already assigned to an other book

    }
    else{

        vrf_title = CompareTableBookTitle(tab, book.title, size);
        vrf_author = CompareTableBookAuthor(tab, book.author, size);
        vrf_type = CompareTableBookType(tab, book.type, size);

        if(vrf_title != -1 && vrf_author != -1 && vrf_type != -1){

            return -3; // If book already assigned to an other ID

        }

        return -2; // If book is not in tab

    }

}