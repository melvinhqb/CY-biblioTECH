#include "biblio.h"

/*****************************************************
                DISPLAY FUNCTIONS
*****************************************************/

void AppMsg(){

    printf("\n***********************************\n");
    printf("     Application CY-biblioTech     \n");
    printf("***********************************\n");

}

void WelcomeMsg(char *login){

    int nb_spaces = (23-strlen(login))/2;
    printf("\n***********************************\n");
    for(int i=0;i<nb_spaces;i++){
        printf(" ");
    }
    printf("Bienvenue %s !\n",login);
    printf("***********************************\n");
    
}

// Displays the books borrowed by a user

void BookMsg(Book *book, User user, int size){

    int nb_books = 0;
    
    WelcomeMsg(user.login);

    for(int i=0;i<5;i++){

        if(user.books[i].id != 0){

            nb_books++;

        }
        else{

            break;

        }

    }
    
    if(nb_books != 0){

        printf("\nVous avez emprunte les livres suivants :\n");

        for(int i=0;i<nb_books;i++){

            int b_id = user.books[i].id - 1;
            
            time_t sec = user.books[i].time;
            struct tm time=*localtime(&sec);
            char hm_time[sizeof "HH h MM"];
            strftime(hm_time, sizeof hm_time, "%H h %M", &time);

            printf("%s  %s a rendre pour %s\n",book[b_id].title, book[b_id].author, hm_time);

        }

    }
    else{

        printf("\nVous avez actuellement aucun livre emprunte !\n");

    }
    
}

// Convert an integer to its corresponding subject

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

// Convert an integer to its corresponding state

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

        ShowBook(tab[i]); // Show the book n°i in *tab

    }

}