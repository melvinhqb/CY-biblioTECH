#include "biblio.h"

/*****************************************************
                TEXT FILE MANAGEMENT
*****************************************************/

// Function that counts the number of lines in a text file

int FileSize(char *name_file){

    FILE *file = fopen(name_file, "r"); // Charge a text file
    char line[1000]; // Max number of characters per line
    int count = 0; // Counts the number of lines in a text file

    if(file == NULL){
        printf("%s\n",strerror(errno)); // Error message
        exit(1);
    }

    while(fgets(line, sizeof(line), file) != NULL){

        count++;

    }

    fclose(file);
    return count; // Return the number of lines in the text file

}

// Function that loads data from users.txt into an array structure

User *LoadUsers(char *name_file, int size){

    User *tab = NULL;
    FILE *file = fopen(name_file, "r"); // Open users.txt with read mode

    tab = malloc(size*sizeof(User));

    for(int i=0;i<size;i++){

        fscanf(file, "%s",tab[i].login); // Login
        fscanf(file, "%s",tab[i].pswrd); // Password
        fscanf(file, "%d",&tab[i].role); // Role (Student=1, Teacher=2 or Admin=3)

        for(int j=0;j<5;j++){

            fscanf(file, "%d",&tab[i].books_id[j]); // Book ID (int)

        }

    }

    fclose(file);
    return tab; // Return an users table

}

// Function that loads data from book.txt into an array structure

Book *LoadBooks(char *name_file, int size){
    
    Book *tab = NULL;
    FILE *file = fopen(name_file, "r"); // Open books.txt with read mode

    tab = malloc(size*sizeof(Book));

    for(int i=0;i<size;i++){

        fscanf(file, "%s", tab[i].title); // Title
        fscanf(file, "%s", tab[i].author); // Author
        fscanf(file, "%d", &tab[i].id); // Book ID
        fscanf(file, "%d", &tab[i].type); // Category (Science=1, Literature=2 ...)
        fscanf(file, "%d", &tab[i].stock); // Number of books available

    }

    fclose(file);
    return tab;  // Return a books table

}