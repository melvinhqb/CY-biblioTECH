#include "biblio.h"

int TitleCompare(const void *p1, const void *p2){

    Book *point1 = (Book *)p1;
    Book *point2 = (Book *)p2;

    return strcmp(point1->title, point2->title);

}

int AuthorCompare(const void *p1, const void *p2){

    Book *point1 = (Book *)p1;
    Book *point2 = (Book *)p2;

    return strcmp(point1->author, point2->author);

}

int TypeCompare(const void *p1, const void *p2){

    Book *point1 = (Book *)p1;
    Book *point2 = (Book *)p2;
    char *ch_p1 = ShowBookType(point1->type);
    char *ch_p2 = ShowBookType(point2->type);

  return strcmp(ch_p1, ch_p2);
}

void SortBooks(Book *book, int size){

    int user_choice;
    char choice[3];

    printf("\nType de tri :\n\n");
    printf("1 - Par titre\n");
    printf("2 - Par auteur\n");
    printf("3 - Par categorie\n");

    printf("\nChoisir numero\n>>>");

    user_choice = MenuChoice(choice, 3);

    switch(user_choice){

        case 1:
            qsort(book, size, sizeof(Book), TitleCompare);
            break;
        case 2:
            qsort(book, size, sizeof(Book), AuthorCompare);
            break;
        case 3:
            qsort(book, size, sizeof(Book), TypeCompare);
            break;

    }

}