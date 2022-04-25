#include "biblio.h"

/*****************************************************
                DISPLAY FUNCTIONS
*****************************************************/

void WelcomeMsg(){

    printf("\n***********************************\n");
    printf("     Application CY-biblioTech     \n");
    printf("***********************************\n");
    
}

// Displays the books borrowed by a user

void BookMsg(Book *book, User user, int size){

    int nb_books = 0;
    printf("\nBienvenue %s !\n",user.login);

    for(int i=0;i<5;i++){

        if(user.books_id[i] != 0){

            nb_books++;

        }
        else{

            break;

        }

    }
    
    if(nb_books != 0){

        printf("Vous avez emprunte les livres suivants :\n");

        for(int i=0;i<nb_books;i++){

            int b_id = user.books_id[i] - 1;

            printf("%s  %s\n",book[b_id].title, book[b_id].author);

        }

    }
    else{

        printf("Vous avez actuellement aucun livre emprunte !\n");

    }
    
}

char *ShowBookType(int a){

    switch(a){
        case SCIENCE:
            return "Science";
        case LITERATURE:
            return "Litterature";
        case ART:
            return "Art";
        case HISTORY:
            return "Histoire";
        default:
            return "???";
    }

}

char *ShowBookStock(int a){

    switch(a){

        case YES:
            return "En stock";

        case NO:
            return "Indisponible";

    }

}

// Displays the characteristics of a book

void ShowBook(Book book){

    printf("\nTitre : %s\n",book.title);
    printf("Auteur : %s\n",book.author);
    printf("ID : %d\n", book.id);
    printf("Categorie : %s\n", ShowBookType(book.type));
    printf("Stock : %s\n\n", ShowBookStock(book.stock));

}

// Displays the characteristics of books in a table

void ShowBooks(Book *tab, int size){

    printf("\n***********************************\n");

    for(int i=0;i<size;i++){

        ShowBook(tab[i]);

    }

}