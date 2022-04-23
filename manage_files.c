#include "biblio.h"

/*****************************************************
                TEXT FILE MANAGEMENT
*****************************************************/

// Function that counts the number of lines in a text file

int FileSize(char *name_file){

    FILE *file = fopen(name_file, "r");
    char line[1000];
    int count = 0;

    if(file == NULL){
        printf("%s\n",strerror(errno));
        exit(1);
    }

    while(fgets(line, sizeof(line), file) != NULL){

        count++;

    }

    fclose(file);
    return count;

}

// Function that loads data from users.txt into an array structure

User *LoadUsers(char *name_file, int size){

    User *tab = NULL;
    FILE *file = fopen(name_file, "r");

    tab = malloc(size*sizeof(User));

    for(int i=0;i<size;i++){

        fscanf(file, "%s",tab[i].login);
        fscanf(file, "%s",tab[i].pswrd);
        fscanf(file, "%d",&tab[i].role);

        for(int j=0;j<5;j++){

            fscanf(file, "%d",&tab[i].books_id[j]);

        }

    }

    fclose(file);
    return tab;

}

// Function that loads data from book.txt into an array structure

Book *LoadBooks(char *name_file, int size){
    
    Book *tab = NULL;
    FILE *file = fopen(name_file, "r");

    tab = malloc(size*sizeof(Book));

    for(int i=0;i<size;i++){

        fscanf(file, "%s", tab[i].title);
        fscanf(file, "%s", tab[i].author);
        fscanf(file, "%d", &tab[i].id);
        fscanf(file, "%d", &tab[i].type);
        fscanf(file, "%d", &tab[i].stock);

    }

    fclose(file);
    return tab;

}