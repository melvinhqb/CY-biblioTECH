#include "biblio.h"

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

    for(int i=0;i<MAX_SIZE_AUTHOR+3-strlen(book.author);i++){
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

    for(int i=0;i<MAX_SIZE_AUTHOR+3-strlen(book.author);i++){
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

                    printf("       ");
                    ShowBook(book[j]);

                    strftime(hm_time, sizeof hm_time, "%H h %M", &tm_time); // Display the hour and minutes of the localtime

                    for(int k=0;k<20-strlen(ShowBookType(book[j].type));k++){
                        printf(" ");
                    }

                    printf("a rendre pour %s", hm_time);

                    if(sec < time(NULL)){
                        printf(LATE_THM);
                        printf("    (en retard)");
                        printf(RESET_FONT);
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

// Display a table in the form of suggestions
// enter: tab of suggestion, its size and the element searched 


void ShowBookSuggestion(Book *search_book, int search_size, char *search){

    int j; 

    // if one or more sugegestions are found 

    if(search_size > 0 && (int)search[0] != 0){

        printf("\nSuggestions :\n\n");

        for(int i=0;i<search_size;i++){

            j = i+1;

            while(j < 1000){

                printf(" ");
                j = j*10;

            }

            printf("%d - ",i+1);
            ShowBookColor(search_book[i], search);
            printf("\n");

        }
    }

    // if the user doesn't anything in the search field 

    else if(search_size > 0 && (int)search[0] == 0){

        printf("\nSuggestions :\n\n");

        for(int i=0;i<search_size;i++){

            j = i+1;

            while(j < 1000){

                printf(" ");
                j = j*10;

            }

            printf("%d - ",i+1);
            ShowBook(search_book[i]);
            printf("\n");

        }

    }

    //if no suggestions is found

    else{

        printf("\nAuncun livre ne correspond a votre recherche !\n");

    }

}

void ShowBookSuggestionNoAccount(Book *book, int size){

    char search[MAX_SIZE_TITLE];

    int check_size;
    int user_choice, search_size;

    Book *search_book = NULL;
    Book_tm *user_books = NULL;

    // Ask user to make a search

    printf("\nRechercher (titre/auteur/matiere)\n");
    printf(ARROW);

    check_size = ReadInput(search, sizeof(search));

    if(check_size == 0){

        printf("\nAuncun livre ne correspond a votre recherche !\n");
        return;

    }

    ReplaceSpaces(search);

    // Filter books by previous search

    search_book = SearchBooks(book, search, size, &search_size);
    search_book = SearchByStock(search_book, 1, search_size, &search_size);

    if(search_size == 0){

        printf("\nAuncun livre ne correspond a votre recherche !\n");
        return;

    }

    // Asks the user to choose the type of sorting

    user_choice = SortMenu();

    switch(user_choice){

        case 2:
            qsort(search_book, search_size, sizeof(Book), AuthorCompare);
            break;
        case 3:
            qsort(search_book, search_size, sizeof(Book), TypeCompare);
            break;
        default:
            qsort(search_book, search_size, sizeof(Book), TitleCompare);

    }

    // Displays the filtered and sorted book table

    ShowBookSuggestion(search_book, search_size, search);

}