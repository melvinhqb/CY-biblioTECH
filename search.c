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

Book *MergesBooks(Book *tab1, Book *tab2, int size1, int size2, int *size3){

    Book *tab3 = NULL;
    *size3 = size1;

    printf("%d\n",*size3);

    for(int i=0; i<size2; i++){

        if(CompareTableBookId(tab1, tab2[i].id, size1) == -1){

            *size3 += 1;

        }

    }

    printf("%d\n",*size3);

    tab3 = malloc(*size3*sizeof(Book));
    for(int i=0;i<size1;i++){

        tab3[i] = tab1[i];

    }
    *size3 = size1;

    for(int i=0; i<size2; i++){

        if(CompareTableBookId(tab1, tab2[i].id, size1) == -1){
            printf("s\n");
            tab3[*size3] = tab2[i];
            *size3 += 1;

        }

    }


}