#include "biblio.h"

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


Book *MergesBooks(Book *tab1, Book *tab2, int size1, int size2, int *size3){

    Book *tab3 = NULL;
    *size3 = size1;

    for(int i=0; i<size2; i++){

        if(CompareTableBookId(tab1, tab2[i].id, size1) == -1){

            *size3 += 1;

        }

    }

    tab3 = malloc(*size3*sizeof(Book));


    for(int i=0;i<size1;i++){

        tab3[i] = tab1[i];

    }

    for(int i=size1; i<*size3; i++){

        if(CompareTableBookId(tab1, tab2[i-size1].id, size1) == -1){
            tab3[i] = tab2[i-size1];

        }

    }

    return tab3;

}