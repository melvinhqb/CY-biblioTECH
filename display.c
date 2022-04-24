#include "biblio.h"

/*****************************************************
                DISPLAY FUNCTIONS
*****************************************************/

void WelcomeMsg(){

    printf("\n***********************************\n");
    printf("     Application CY-biblioTech     \n");
    printf("***********************************\n");
    
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