#include "biblio.h"

// Function that returns an array of books based on a book title

Book *SearchByTitle(Book *tabBook, char *content, int size, int *count){

    Book *book = NULL;
    *count = 0;
    int c, c2;

    for(int i=0;i<size;i++){

        c2 = 0;

        while(tabBook[i].title[c2] != '\0'){

            c = 0;

            while(tabBook[i].title[c2] == content[c]){

                if(content[c] == '\0'){

                    *count += 1;
                    break;

                }

                c++;
                c2++;

            }

            if(content[c] == '\0' && tabBook[i].title[c2] != '\0'){

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

        while(tabBook[i].title[c2] != '\0'){

            c = 0;

            while(tabBook[i].title[c2] == content[c]){

                if(content[c] == '\0'){

                    book[*count] = tabBook[i];
                    *count += 1;
                    break;

                }

                c++;
                c2++;

            }

            if(content[c] == '\0' && tabBook[i].title[c2] != '\0'){

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

    for(int i=0;i<size;i++){

        c2 = 0;

        while(tabBook[i].author[c2] != '\0'){

            c = 0;

            while(tabBook[i].author[c2] == content[c]){

                if(content[c] == '\0'){

                    *count += 1;
                    break;

                }

                c++;
                c2++;

            }

            if(content[c] == '\0' && tabBook[i].author[c2] != '\0'){

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

        while(tabBook[i].author[c2] != '\0'){

            c = 0;

            while(tabBook[i].author[c2] == content[c]){

                if(content[c] == '\0'){

                    book[*count] = tabBook[i];
                    *count += 1;
                    break;

                }

                c++;
                c2++;

            }

            if(content[c] == '\0' && tabBook[i].author[c2] != '\0'){

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

    printf("%d\n", *count); 

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

// Function that displays the search item in colour in relation to another item

void ShowWithColor(char *sentence, char *search){

    int c, c2;
    int a = 0;

    c2 = 0;

    while(sentence[c2] != '\0'){

        c = 0;

        while(sentence[c2] == search[c]){

            a++;

            if(search[c] == '\0'){

                printf("\033[%sm", "32");
                for(int i=0;i<c;i++){

                    printf("%c", search[i]);

                }
                printf("\033[%sm", "39");
                return;

            }

            c++;
            c2++;

        }

        if(search[c] == '\0' && sentence[c2] != '\0'){

            printf("\033[%sm", "32");
            for(int i=0;i<c;i++){

                    printf("%c", search[i]);

            }
            printf("\033[%sm", "39");
            a = 0;

        }
        else if(a != 0){
            for(int i=c2-a;i<c2;i++){
                if(i < (int)strlen(sentence)){
                    printf("%c", sentence[i]);
                }
                
            }
            a = 0;
        }
        else{
            if(c2 < (int)strlen(sentence)){
                printf("%c", sentence[c2]);
            }
            c2++;
        }        

    }

}