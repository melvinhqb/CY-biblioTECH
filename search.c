#include "biblio.h"

// Function that returns an array of books based on a book title
// Enter : the current books table, a string to compare, the size of tabBook and a counter for the new tab
// Return : a filter tab by title

Book *SearchByTitle(Book *tabBook, char *content, int size, int *count){

    Book *book = NULL;
    *count = 0;
    int c, c2;

    char *content_cpy = malloc(strlen(content)+1);
    Book *tabBook_cpy = malloc(size*sizeof(Book));

    RemoveUpperCase(content_cpy, content);

    for(int i=0;i<size;i++){

        RemoveUpperCase(tabBook_cpy[i].title, tabBook[i].title);
    }

    for(int i=0;i<size;i++){

        c2 = 0;

        while(tabBook_cpy[i].title[c2] != '\0'){

            c = 0;

            while(tabBook_cpy[i].title[c2] == content_cpy[c]){

                if(content_cpy[c] == '\0'){

                    *count += 1;
                    break;

                }

                c++;
                c2++;

            }

            if(content_cpy[c] == '\0' && tabBook_cpy[i].title[c2] != '\0'){

                *count += 1;
                break;

            }

            c2++;

        }   

    }

    book = malloc(*count*sizeof(Book));
    
    *count = 0;

    for(int i=0;i<size;i++){

        c2 = 0;

        while(tabBook_cpy[i].title[c2] != '\0'){

            c = 0;

            while(tabBook_cpy[i].title[c2] == content_cpy[c]){

                if(content_cpy[c] == '\0'){

                    book[*count] = tabBook[i];
                    *count += 1;
                    break;

                }

                c++;
                c2++;

            }

            if(content_cpy[c] == '\0' && tabBook_cpy[i].title[c2] != '\0'){

                book[*count] = tabBook[i];
                *count += 1;
                break;

            }

            c2++;

        }

    }

    return book;

}

// Function that returns an array of books based on a book author
// Enter : the current books table, a string to compare, the size of tabBook and a counter for the new tab
// Return : a filter tab by author

Book *SearchByAuthor(Book *tabBook, char *content, int size, int *count){

    Book *book = NULL;
    *count = 0;
    int c, c2;

    char *content_cpy = malloc(strlen(content)+1);
    Book *tabBook_cpy = malloc(size*sizeof(Book));

    RemoveUpperCase(content_cpy, content);

    for(int i=0;i<size;i++){

        RemoveUpperCase(tabBook_cpy[i].author, tabBook[i].author);
    }

    for(int i=0;i<size;i++){

        c2 = 0;

        while(tabBook_cpy[i].author[c2] != '\0'){

            c = 0;

            while(tabBook_cpy[i].author[c2] == content_cpy[c]){

                if(content_cpy[c] == '\0'){

                    *count += 1;
                    break;

                }

                c++;
                c2++;

            }

            if(content_cpy[c] == '\0' && tabBook_cpy[i].author[c2] != '\0'){

                *count += 1;
                break;

            }

            c2++;

        }   

    }

    book = malloc(*count*sizeof(Book));
    
    *count = 0;

    for(int i=0;i<size;i++){

        c2 = 0;

        while(tabBook_cpy[i].author[c2] != '\0'){

            c = 0;

            while(tabBook_cpy[i].author[c2] == content_cpy[c]){

                if(content_cpy[c] == '\0'){

                    book[*count] = tabBook[i];
                    *count += 1;
                    break;

                }

                c++;
                c2++;

            }

            if(content_cpy[c] == '\0' && tabBook_cpy[i].author[c2] != '\0'){

                book[*count] = tabBook[i];
                *count += 1;
                break;

            }

            c2++;

        }

    }

    return book;

}

// Function that returns an array of books based on a book type
// Enter : the current books table, a string to compare, the size of tabBook and a counter for the new tab
// Return : a filter tab by type

Book *SearchByType(Book *tabBook, char *content, int size, int *count){

    Book *book = NULL;
    char *content_cpy = malloc(strlen(content));
    char **tabType = malloc(20*size);
    int c, c2;

    RemoveUpperCase(content_cpy, content);

    if(content_cpy[0] >= 97 && content_cpy[0] <= 122){

        content_cpy[0] -= 32;

    }

    for(int i=0;i<size;i++){

        switch(tabBook[i].type){

            case SCIENCE:
                tabType[i] = SCIENCE_NAME;
                break;
            case LITERATURE:
                tabType[i] = LITERATURE_NAME;
                break;
            case ART:
                tabType[i] = ART_NAME;
                break;
            case HISTORY:
                tabType[i] = HISTORY_NAME;
                break;
            default:
                tabType[i] = "???";

        }

    }

    for(int i=0;i<size;i++){

        c2 = 0;

        while(tabType[i][c2] != '\0'){

            c = 0;

            while(tabType[i][c2] == content_cpy[c]){

                if(content_cpy[c] == '\0'){

                    *count += 1;
                    break;

                }

                c++;
                c2++;

            }

            if(content_cpy[c] == '\0' && tabType[i][c2] != '\0'){

                *count += 1;
                break;

            }

            c2++;

        }   

    }

    book = malloc(*count*sizeof(Book));
    
    *count = 0;

    for(int i=0;i<size;i++){

        c2 = 0;

        while(tabType[i][c2] != '\0'){

            c = 0;

            while(tabType[i][c2] == content_cpy[c]){

                if(content_cpy[c] == '\0'){

                    book[*count] = tabBook[i];
                    *count += 1;
                    break;

                }

                c++;
                c2++;

            }

            if(content_cpy[c] == '\0' && tabType[i][c2] != '\0'){

                book[*count] = tabBook[i];
                *count += 1;
                break;

            }

            c2++;

        }

    }

    return book;

}

// Function that returns an array of books based on a book stoking state
// Enter : the current books table, an address of an integer (0 = Unvalaible 1 or + = Avalaible), the size of tabBook and a counter for the new tab
// Return : a filter tab by stocking state

Book *SearchByStock(Book *tabBook, int stock, int size, int *count){ // Stock = 0 (Unavailable) or Stock = 1 (Available)

    Book *book = NULL;
    *count = 0;

    for(int i=0;i<size;i++){

        // If the book is unavalaible

        if(tabBook[i].stock == 0 && stock == 0){

            *count += 1;

        }

        // If the book is avalaible

        else if(tabBook[i].stock != 0 && stock != 0){

            *count += 1;
        }

    }

    book = malloc(*count*sizeof(Book));

    *count = 0;

    for(int i=0;i<size;i++){

        if(tabBook[i].stock == 0 && stock == 0){

            book[*count] = tabBook[i];
            *count += 1;

        }
        else if(tabBook[i].stock != 0 && stock != 0){

            book[*count] = tabBook[i];
            *count += 1;
        }

    }

    return book;

}

// Function that merges two tables by removing duplicates
// Enter : 2 books tab and their sizes, the address of the new tab size
// Return : A merges tab of books

Book *MergesBooks(Book *tab1, Book *tab2, int size1, int size2, int *size3){

    Book *tab3 = NULL;
    *size3 = size1;
    int j;

    for(int i=0; i<size2; i++){

        if(CompareTableBookId(tab1, tab2[i].id, size1) == -1){

            *size3 += 1;

        }

    }

    tab3 = malloc(*size3*sizeof(Book));


    for(int i=0;i<size1;i++){

        tab3[i] = tab1[i];

    }

    j = size1;

    for(int i=0; i<size2; i++){

        if(CompareTableBookId(tab1, tab2[i].id, size1) == -1){

            tab3[j] = tab2[i];
            j++;

        }

    }

    return tab3;

}

// Search books by title, author and type
// Enter : the current books table, a string to compare, the size of tabBook and the address of the new tab
// Return : a filter tab by title

Book *SearchBooks(Book *book, char *search, int size, int *search_size){

    Book *search_book = NULL;
    Book *search_book_title = NULL;
    Book *search_book_author = NULL;
    Book *search_book_type = NULL;
    int search_size_title;
    int search_size_author;
    int search_size_type;

    search_book_title = SearchByTitle(book, search, size, &search_size_title);
    search_book_author = SearchByAuthor(book, search, size, &search_size_author);
    search_book_type = SearchByType(book, search, size, &search_size_type);
    search_book = MergesBooks(search_book_title, search_book_author, search_size_title, search_size_author, search_size);
    search_book = MergesBooks(search_book, search_book_type, *search_size, search_size_type, search_size);

    return search_book;

}