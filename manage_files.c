#include "biblio.h"

// Function that counts the number of lines in a text file
// enter: the file that will be analyzed

int FileSize(char *name_file){

    FILE *file = NULL;
    char line[1000]; // Max number of characters per line
    int count = 0; // Counts the number of lines in a text file

    file = fopen(name_file, "r"); // load a text file

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

/*****************************************************
                TEXT FILE --TO-> TABLE
*****************************************************/

// Function that loads data from users.txt into an array structure
// Enter : the name of user text file and its size
// Return : A table of users

User *LoadUsers(char *name_file, int size){

    User *tab = NULL;
    FILE *file = NULL;

    file = fopen(name_file, "r"); // Open users.txt with read mode

    if(file == NULL){
        printf("%s\n",strerror(errno)); // Error message
        exit(1);
    }

    tab = malloc(size*sizeof(User));

    for(int i=0;i<size;i++){

        fscanf(file, "%s",tab[i].login); // Login
        fscanf(file, "%s",tab[i].pswrd); // Password
        fscanf(file, "%d",&tab[i].role); // Role (Student=1, Teacher=2 or Admin=3)

        for(int j=0;j<5;j++){

            fscanf(file, "%lli",&tab[i].books[j].id); // Book ID (int)
            fscanf(file, "%d",&tab[i].books[j].time); // Maximum time

        }

    }

    fclose(file);
    return tab; // Return an users table

}

// Function that loads data from book.txt into an array structure
// Enter : the name of book text file and its size
// Return : A table of books

Book *LoadBooks(char *name_file, int size){
    
    Book *tab = NULL;
    FILE *file = NULL;

    file = fopen(name_file, "r"); // Open books.txt with read mode

    if(file == NULL){
        printf("%s\n",strerror(errno)); // Error message
        exit(1);
    }

    tab = malloc(size*sizeof(Book));

    for(int i=0;i<size;i++){

        fscanf(file, "%s", tab[i].title); // Title
        fscanf(file, "%s", tab[i].author); // Author
        fscanf(file, "%lli", &tab[i].id); // Book ID
        fscanf(file, "%d", &tab[i].type); // Category (Science=1, Literature=2 ...)
        fscanf(file, "%d", &tab[i].stock); // Number of books available

    }

    fclose(file);
    return tab;  // Return a books table

}

/*****************************************************
                TABLE --TO-> TEXT FILE
*****************************************************/

// Writes a user table to a text file
// Enter : the name of user file, the current user table and its size

void WriteUser(char *name_file, User *tab, int size){

    char *login = NULL;
    char *pswrd = NULL;
    int role;
    long long book_id;
    int time;

    FILE *file = NULL;

    file = fopen(name_file, "w"); // Open books.txt with written mode

    if(file == NULL){
        printf("%s\n",strerror(errno)); // Error message
        exit(1);
    }

    for(int i=0;i<size;i++){
        login = tab[i].login;
        pswrd = tab[i].pswrd;
        role = tab[i].role;

        fprintf(file,"%s %s %d ", login, pswrd, role);

        book_id = tab[i].books[0].id;
        time = tab[i].books[0].time;

        fprintf(file,"%lli %d", book_id, time);

        for(int j=1;j<5;j++){
            book_id = tab[i].books[j].id;
            time = tab[i].books[j].time;

            fprintf(file," %lli %d", book_id, time);

        }

        fprintf(file,"\n");

    }

    fclose(file);

}

// Writes a book table to a text file
// Enter : the name of book file, the current book table and its size


void WriteBook(char *name_file, Book *tab, int size){

    char *title = NULL;
    char *author = NULL;
    long long id;
    int type;
    int stock;

    FILE *file = NULL;

    file = fopen(name_file, "w");

    if(file == NULL){
        printf("%s\n",strerror(errno)); // Error message
        exit(1);
    }

    for(int i=0;i<size;i++){
        title = tab[i].title;
        author = tab[i].author;
        id = tab[i].id;
        type = tab[i].type;
        stock = tab[i].stock;

        fprintf(file,"%s %s %lli %d %d\n", title, author, id, type, stock);

    }

    fclose(file);

}