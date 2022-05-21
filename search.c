#include "biblio.h"

// Function that returns an array of books based on a book title

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

Book *SearchByType(Book *tabBook, char *content, int size, int *count){

    char *cmp = malloc(20);
    int c, c2;
    Book *book = NULL;

    for(int i=0;i<size;i++){

        if(tabBook[i].type != 0){

            switch(tabBook[i].type){
                case SCIENCE:
                    cmp = SCIENCE_NAME;
                    break;
                case LITERATURE:
                    cmp = LITERATURE_NAME;
                    break;
                case ART:
                    cmp = ART_NAME;
                    break;
                case HISTORY:
                    cmp = HISTORY_NAME;
                    break;
            }

            c2 = 0;

            while(cmp[c2] != '\0'){

                c = 0;

                while(cmp[c2] == content[c]){

                    if(content[c] == '\0'){

                        *count += 1;
                        break;

                    }

                    c++;
                    c2++;

                }

                if(content[c] == '\0' && cmp[c2] != '\0'){

                    *count += 1;
                    break;

                }

                c2++;

            } 

        }

    }

    book = malloc(*count*sizeof(Book));
    
    *count = 0;

    for(int i=0;i<size;i++){

        if(tabBook[i].type != 0){

            switch(tabBook[i].type){
                case SCIENCE:
                    cmp = SCIENCE_NAME;
                    break;
                case LITERATURE:
                    cmp = LITERATURE_NAME;
                    break;
                case ART:
                    cmp = ART_NAME;
                    break;
                case HISTORY:
                    cmp = HISTORY_NAME;
                    break;
            }

            c2 = 0;

            while(cmp[c2] != '\0'){

                c = 0;

                while(cmp[c2] == content[c]){

                    if(content[c] == '\0'){

                        book[*count] = tabBook[i];
                        *count += 1;
                        break;

                    }

                    c++;
                    c2++;

                }

                if(content[c] == '\0' && cmp[c2] != '\0'){

                    book[*count] = tabBook[i];
                    *count += 1;
                    break;

                }

                c2++;

            } 

        }

    }

    return book;

}

Book *SearchByStock(Book *tabBook, int stock, int size, int *count){ // Stock = 0 (Unavailable) or Stock = 1 (Available)

    Book *book = NULL;
    *count = 0;

    for(int i=0;i<size;i++){

        if(tabBook[i].stock == 0 && stock == 0){

            *count += 1;

        }
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