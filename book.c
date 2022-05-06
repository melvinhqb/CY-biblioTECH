#include "biblio.h"

// Displays the characteristics of a book

void ShowBook(Book book){

    printf("\nTitre : %s\n",book.title);
    printf("Auteur : %s\n",book.author);
    printf("ID : %d\n", book.id);
    printf("Categorie : %s\n", ShowBookType(book.type));
    printf("Stock : %s\n\n", ShowBookStock(book.stock));

}

// Displays the characteristics of books in a table

void ShowBooks(Book *tab, int size){

    printf("\n***********************************\n");

    for(int i=0;i<size;i++){

        ShowBook(tab[i]); // Show the book n°i in *tab

    }

}

// Displays the books borrowed by a user

void BookMsg(Book *book, User user, int size){

    int nb_books = 0;
    
    WelcomeMsg(user.login);

    for(int i=0;i<5;i++){

        if(user.books[i].id != 0){

            nb_books++;

        }
        else{

            break;

        }

    }
    
    if(nb_books != 0){

        printf("\nVous avez emprunte les livres suivants :\n");

        for(int i=0;i<nb_books;i++){

            int b_id = user.books[i].id - 1;
            
            time_t sec = user.books[i].time;
            struct tm time=*localtime(&sec);
            char hm_time[sizeof "HH h MM"];
            strftime(hm_time, sizeof hm_time, "%H h %M", &time);

            printf("%s  %s a rendre pour %s\n",book[b_id].title, book[b_id].author, hm_time);

        }

    }
    else{

        printf("\nVous avez actuellement aucun livre emprunte !\n");

    }
    
}

// Function that add a book to a text file

void AddBook(char *name_file, int *size){

    char title[102];
    char author[52];
    char id[15];
    char type[3];
    char stock[3];

    int cmp = 1;
    int c = 0;
    int index = 0;
    int check_size = 0;

    FILE *file = NULL;
    Book *tab = LoadBooks(name_file, *size);

    // Creating the books's title
    do{

        printf("\nTitre\n>>>");

        check_size = ReadInput(title, sizeof(title));

        if(check_size == 1){

            DeleteSpaces(title);

        }
        else{

            printf("\nCe titre est trop grand ! (100 caracteres max)\n");

        }

    }while(check_size != 1);

    check_size = 0;

    // Creating the books's author
    do{

        printf("\nAuteur\n>>>");

        check_size = ReadInput(author, sizeof(author));

        if(check_size == 1){

            DeleteSpaces(author);

        }
        else{
            
            printf("\nCe nom est trop grand ! (50 caracteres max)\n");

        }

    }while(check_size != 1);

    check_size = 0;

    // Creating the book's type

    do{

        printf("\nQuel est la categorie ?\n");
        printf("1 - Science\n");
        printf("2 - Litterature\n");
        printf("3 - Art\n");
        printf("4 - History\n");
        printf(">>>");

        check_size = ReadInput(type, sizeof(type));

        if(check_size != 1){

            printf("\nErreur de saisie, veuillez recommencer !\n");

        }
        else{

            c = (int) strtol (type, NULL, 10);

            if(c < 1 || c > NB_TYPE){

                printf("\nErreur de saisie, veuillez recommencer !\n");

            }

        }

    }while(c < 1 || c > NB_TYPE || check_size != 1);

    check_size = 0;

    // Creating the book's ID

    do{

        printf("\nIdentifiant (ISBN)\n>>>");

        check_size = ReadInput(id, sizeof(id));

        if(check_size == 1){

            DeleteSpaces(id);

            index = CompareTableBookId(tab, id, *size);

            if(index != -1){

                printf("\nCet identifiant est deja pris !\n");

            }

        }
        else{

            printf("\nCet identifiant est trop grand ! (13 caracteres max)\n");

        }

    }while(index != -1 || check_size != 1);

    // Adds the data to a text file
    file = fopen(name_file, "a");
    fprintf(file, "%s %s %s %d 1\n", title, author, id, c); // The number one correspond to the "in stock" state
    fclose(file);
    *size += 1;
    printf("\nLivre ajoute avec succes !\n");

}