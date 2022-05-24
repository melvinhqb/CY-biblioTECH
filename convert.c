#include "biblio.h"

// Convert an integer to its corresponding subject
//enter the ID of a type 
//
//  SCIENCE=1,
//  LITERATURE=2, 
//  ART=3, 
//  HISTORY=4
// return a string relating to the type 

char *ShowBookType(int a){

    switch(a){
        case SCIENCE:
            return SCIENCE_NAME;
        case LITERATURE:
            return LITERATURE_NAME;
        case ART:
            return ART_NAME;
        case HISTORY:
            return HISTORY_NAME;
        default:
            return "???";
    }

}

// Convert an integer to its corresponding state
// enter an integer 
// return a string relating to a state 

char *ShowBookStock(int a){

    switch(a){

        case OUT_OF_STOCK:
            return "Indisponible";

        default:
            return "Disponible";

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
// enter a string 

void ReplaceUnderscores(char *tab){

    int i = 0;

    while(tab[i] != '\0'){

        if(tab[i] == '_'){

            tab[i] = (char)ASCII_SPACE;

        }

        i++;

    }
    
}

/*
         _________________________.
        / _____________________  /|
       / / ___________________/ / |
      / / /| |               / /  |
     / / / | |              / / . |
    / / /| | |             / / /| |
   / / / | | |            / / / | |
  / / /  | | |           / / /| | |
 / /_/___| | |__________/ / / | | |
/________| | |___________/ /  | | |
| _______| | |__________ | |  | | |
| | |    | | |_________| | |__| | |
| | |    | |___________| | |____| |
| | |   / / ___________| | |_  / /
| | |  / / /           | | |/ / /
| | | / / /            | | | / /
| | |/ / /             | | |/ /
| | | / /              | | ' /
| | |/_/_______________| |  /
| |____________________| | /
|________________________|/

*/