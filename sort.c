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