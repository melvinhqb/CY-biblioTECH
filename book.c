#include "biblio.h"

int DelayCheck(Book_tm *my_books, int size){

    for(int i=0;i<size;i++){

        if(my_books[i].time < time(NULL)){

            return 0;

        }

    }

    return 1;

}

// Displays the characteristics of a book
// enter the data book 

void ShowBook(Book book){

    ReplaceUnderscores(book.title);
    printf("%s ",book.title);
    ReplaceSpaces(book.title);

    for(int i=0;i<MAX_SIZE_TITLE+3-strlen(book.title);i++){
        printf(" ");
    }

    ReplaceUnderscores(book.author);
    printf("de %s ",book.author);
    ReplaceSpaces(book.author);

    for(int i=0;i<55-strlen(book.author);i++){
        printf(" ");
    }

    printf("%s", ShowBookType(book.type));

}

// Displays the characteristics of a book with some color on the selectionned content 
// enter the data book and a string that will be colored (this string must be diiferent from NULL )

void ShowBookColor(Book book, char *content){

    ReplaceUnderscores(content);

    ReplaceUnderscores(book.title);
    ShowWithColor(book.title, content);
    ReplaceSpaces(book.title);

    for(int i=0;i<MAX_SIZE_TITLE+3-strlen(book.title);i++){ // readable formatting of a book 
        printf(" ");
    }

    ReplaceUnderscores(book.author);
    printf("de ");
    ShowWithColor(book.author, content);
    ReplaceSpaces(book.author);

    for(int i=0;i<55-strlen(book.author);i++){
        printf(" ");
    }
    ShowWithColor(ShowBookType(book.type), content);

    ReplaceSpaces(content);

}

// Displays the characteristics of books in a table
// enter a tab of books and its size 
// call ShowBook() as amny times as are books in tab book  

void ShowBooks(Book *tab, int size){

    printf("\n");

    for(int i=0;i<size;i++){

        ShowBook(tab[i]); // Show the book n°i in *tab
        printf("\n");

    }

}

void ShowBooksColor(Book *tab, char *content, int size){

    printf("\n");

    for(int i=0;i<size;i++){

        ShowBookColor(tab[i], content); // Show the book n°i in *tab
        printf("\n");

    }

} 

// Displays the books borrowed by an user
// enter global book tab ,its size,  the current user


void BookMsg(Book *book, User user, int size){

    int nb_books = 0;
    time_t sec;
    struct tm tm_time;
    char hm_time[sizeof "HH h MM"];
    char *title = NULL;
    char *author = NULL;

    for(int i=0;i<5;i++){ // count the number of books borrowed by the current user

        if(user.books[i].id != 0){

            nb_books++;

        }
        else{

            break;

        }

    }
    
    if(nb_books != 0){

        printf("\nVous avez emprunte les livres suivants :\n\n");

        for(int i=0;i<nb_books;i++){

            for(int j=0;j<size;j++){

                if(user.books[i].id == book[j].id){
                    
                    sec = user.books[i].time; // get timestamp
                    tm_time=*localtime(&sec); // convert timestamp in localtime
                    title = book[j].title;
                    author = book[j].author;

                    ShowBook(book[j]);

                    strftime(hm_time, sizeof hm_time, "%H h %M", &tm_time); // Display the hour and minutes of the localtime

                    for(int k=0;k<20-strlen(ShowBookType(book[j].type));k++){
                        printf(" ");
                    }
                    
                    printf("a rendre pour %s", hm_time);

                    if(sec < time(NULL)){
                        printf("\033[%sm", "31");
                        printf("    (en retard)");
                        printf("\033[%sm", "39");
                    }

                    printf("\n");

                }

            }

        }

    }
    else{

        printf("\nVous avez actuellement aucun livre emprunte !\n");

    }
    
}