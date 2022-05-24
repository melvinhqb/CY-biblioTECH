#include "biblio.h"

// Compare 2 Book.title
// Enter : 2 Book struct
// Return 0 if title1 == title 2

int TitleCompare(const void *p1, const void *p2){

    Book *point1 = (Book *)p1;
    Book *point2 = (Book *)p2;

    return strcmp(point1->title, point2->title);

}

// Compare 2 Book.author
// Enter : 2 Book struct
// Return 0 if author1 == author2

int AuthorCompare(const void *p1, const void *p2){

    Book *point1 = (Book *)p1;
    Book *point2 = (Book *)p2;

    return strcmp(point1->author, point2->author);

}

// Compare 2 Book.type
// Enter : 2 Book struct
// Return 0 if type1 == type2

int TypeCompare(const void *p1, const void *p2){

    Book *point1 = (Book *)p1;
    Book *point2 = (Book *)p2;
    char *ch_p1 = ShowBookType(point1->type);
    char *ch_p2 = ShowBookType(point2->type);

  return strcmp(ch_p1, ch_p2);

}