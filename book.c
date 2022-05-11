#include "biblio.h"

// Displays the characteristics of a book

void ShowBook(Book book){

    printf("\nTitre : %s\n",book.title);
    printf("Auteur : %s\n",book.author);
    printf("ID : %lli\n", book.id);
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
    time_t sec;
    struct tm time;
    char hm_time[sizeof "HH h MM"];
    char *title = NULL;
    char *author = NULL;
    
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

            for(int j=0;j<size;j++){

                if(user.books[i].id == book[j].id){

                    sec = user.books[i].time;
                    time=*localtime(&sec);
                    title = book[j].title;
                    author = book[j].author;

                    ReplaceUnderscores(title);
                    ReplaceUnderscores(author);

                    strftime(hm_time, sizeof hm_time, "%H h %M", &time);
                    
                    printf("%s de %s a rendre pour %s\n",title, author, hm_time);

                    ReplaceSpaces(title);
                    ReplaceSpaces(author);

                }

            }

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

            ReplaceSpaces(title);

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

            ReplaceSpaces(author);

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

            ReplaceSpaces(id);

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

    if(file == NULL){
        printf("%s\n",strerror(errno)); // Error message
        exit(1);
    }
    
    fprintf(file, "%s %s %s %d 1\n", title, author, id, c); // The number one correspond to the "in stock" state
    fclose(file);
    *size += 1;
    printf("\nLivre ajoute avec succes !\n");

}

// Function that adds a book to a user file and the storage status to a book file

User ReserveBook(Book *book, User user, int size){

    char title2[102];
    int check_size;
    int count1 = 0;
    int count2 = 0;
    int index;
    int delay;
    int role;

    Book_tm *user_books = NULL;
    user_books = user.books;

    for(int i=0;i<5;i++){
        if(user_books[i].id != 0){
            count1++;
        }
    }

    role = user.role;

    if((role == STUDENT && count1 == 3) || (role == TEACHER && count1 == 5)){

        printf("\nVous ne pouvez pas emprunter plus de %d livres !\n", count1);
        return user;
    }


    if(user.role == 1){
        delay = 120;
    }
    else{
        delay = 180;
    }

    printf("\nTitre\n>>>");

    check_size = ReadInput(title2, sizeof(title2));

    if(check_size == 1){

        ReplaceSpaces(title2);
        count2 = 0;

        for(int i=0; i<size; i++){

            if(strcmp(book[i].title, title2) == 0 && book[i].stock != 0){

                count2++;
                index = i;

            }

        }

        if(count2 == 0){

            printf("\nCe livre n'est pas disponible pour le moment !\n");

        }
        else if(count2 > 1){

            printf("\nLequel de ces livres voulez-vous ?\n>>>");

        }
        else{

            book[index].stock -= 1;
            user_books[count1].id = book[index].id;
            user_books[count1].time = time(NULL) + delay;

            printf("\nLivre reserve avec succes !\n");

        }

    }
    return user;

}