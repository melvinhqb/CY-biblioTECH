#include "biblio.h"

// Convert an integer to its corresponding subject

char *ShowBookType(int a){

    switch(a){
        case SCIENCE:
            return "Science";
        case LITERATURE:
            return "Litterature";
        case ART:
            return "Art";
        case HISTORY:
            return "Histoire";
        default:
            return "???";
    }

}

// Convert an integer to its corresponding state

char *ShowBookStock(int a){

    switch(a){

        case IN_STOCK:
            return "En stock";

        case OUT_OF_STOCK:
            return "Indisponible";

    }

}

// Replace spaces in a table of caracteres by underscores

void ReplaceSpaces(char *tab){

    int i = 0;

    while(tab[i] != '\0'){

        if(tab[i] == ' '){

            tab[i] = '_';

        }

        i++;

    }

}

// Replace underscores in a table of caracteres by spaces

void ReplaceUnderscores(char *tab){

    int i = 0;

    while(tab[i] != '\0'){

        if(tab[i] == '_'){

            tab[i] = (char)ASCII_SPACE;

        }

        i++;

    }
    
}