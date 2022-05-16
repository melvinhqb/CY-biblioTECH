#include "biblio.h"

// Displays the characteristics of a book

void ShowBook(Book book){

    ReplaceUnderscores(book.title);
    printf("%s ",book.title);
    ReplaceSpaces(book.title);

    ReplaceUnderscores(book.author);
    printf("de %s ",book.author);
    ReplaceSpaces(book.author);

    printf("(%s)\n", ShowBookStock(book.stock));

}

// Displays the characteristics of books in a table

void ShowBooks(Book *tab, int size){

    printf("\n");

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

int AddBook(char *name_file, Book *book, int *size){

    int check_size;
    Book new_book;
    char id_char[15];
    char type[3];
    long long c;
    char *ptr = NULL;
    int index;
    FILE *file = NULL;

    do{

        printf("\nTitre\n>>>");

        check_size = UserInput(new_book.title, sizeof(new_book.title));

    }while(check_size != 1);

    check_size = 0;

    do{

        printf("\nAuteur\n>>>");

        check_size = UserInput(new_book.author, sizeof(new_book.author));

    }while(check_size != 1);

    check_size = 0;

    do{

        printf("\nQuel est la categorie ?\n");
        printf("1 - Science\n");
        printf("2 - Litterature\n");
        printf("3 - Art\n");
        printf("4 - History\n");
        printf(">>>");

        new_book.type = MenuChoice(type, 4);

    }while(new_book.type == 0);

    check_size = 0;

   do{

        printf("\nIdentifiant (ISBN)\n>>>");

        check_size = ReadInput(id_char, sizeof(id_char));

        if(check_size == 1){

            for(int i=0;i<strlen(id_char);i++){

                if(id_char[i] < 48 || id_char[i] > 57){

                    printf("\nSeuls les chiffres sont acceptes !\n");
                    check_size = 0;
                    break;

                }

            }

            if(check_size == 1){

                new_book.id = (long long)strtoll(id_char, NULL, 10);
                index = CompareTableBook(book, new_book, *size);

                if(index == -2){

                    // Adds the data to a text file
                    file = fopen(name_file, "a");

                    if(file == NULL){

                        printf("%s\n",strerror(errno)); // Error message
                        exit(1);

                    }
                    
                    fprintf(file, "%s %s %lli %d 1\n", new_book.title, new_book.author, new_book.id, new_book.type); // The number one correspond to the "in stock" state
                    fclose(file);
                    *size += 1;

                    printf("\nLivre ajoute avec succes !\n");

                }
                else if(index == -3){

                    printf("\nCe livre existe sous un autre identifiant !\n");

                }
                else if(index == -1){

                    printf("\nCet identifiant est deja pris pour un autre livre !\n");

                }
                else{

                    book[index].stock += 1;
                    printf("\nLivre ajoute avec succes !\n");

                }

            }

        }
        else{

            printf("\nCet identifiant est trop grand ! (13 caracteres max)\n");

        }

    }while(check_size != 1);
    
    return index;

}

// Function that remove a book to a text file

void RemoveBook(Book *book, int size){

    int check_size;
    char id_char[15];
    int index;
    long long id;

    do{

        printf("\nIdentifiant (ISBN)\n>>>");

        check_size = ReadInput(id_char, sizeof(id_char));

        if(check_size == 1){

            ReplaceSpaces(id_char);
            id = (long long)strtoll(id_char, NULL, 10);
            index = CompareTableBookId(book, id, size);

            if(index != -1 && book[index].stock != 0){

                book[index].stock = 0;
                printf("\nLivre retire de la bibliotheque !\n");

            }
            else{

                printf("\nReference inconnue !\n");

            }

        }
        else{

            printf("\nCet identifiant est trop grand ! (13 caracteres max)\n");

        }

    }while(index == -1 || check_size != 1);

}

// Function that adds a book to a user file and the storage status to a book file

int ReserveBook(Book *book, User *user, int size){

    char search[102];
    char title2[102];
    int check_size;
    int count1 = 0;
    int count2 = 0;
    int index;
    int delay;
    int role;

    Book *search_book_title = NULL;
    Book *search_book_author = NULL;
    Book *search_book = NULL;
    int search_size_title;
    int search_size_author;
    int search_size;
    Book_tm *user_books = NULL;
    user_books = user->books;

    for(int i=0;i<5;i++){

        if(user_books[i].id != 0){

            count1++;

        }

    }

    role = user->role;

    if((role == STUDENT && count1 == 3) || (role == TEACHER && count1 == 5)){

        printf("\nVous ne pouvez pas emprunter plus de %d livres !\n", count1);
        return 0;
    }


    if(user->role == 1){

        delay = 120;

    }
    else{

        delay = 180;

    }

    do{

        printf("\nRechercher titre\n>>>");

        check_size = UserInput(search, sizeof(search));

    }while(check_size != 1);

    search_book_title = SearchByTitle(book, search, size, &search_size_title);
    //search_book_author = SearchByAuthor(book, search, size, &search_size_author);
    //search_book = MergesBooks(search_book_title, search_book_author, search_size_title, search_size_author, &search_size);

    if(search_size_title > 0){
        printf("\nCela peut vous interreser :\n");
        ShowBooks(search_book_title, search_size_title);
    }
    else{
        printf("\nAucun livre ne correcpond aux termes recherche !\n");
        return 0;
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

            return 1;

        }

    }
    else{

        printf("\nCe livre n'est pas disponible pour le moment !\n");

    }

    return 0;

}

// Function that removes a book to a user file and the storage status to a book file

int ReturnBook(Book *book, User *user, int size){

    char title2[102];
    int check_size;
    int count1 = 0;
    int count2 = 0;
    int index;
    int delay;
    int role;

    Book_tm *user_books = NULL;
    user_books = user->books;

    for(int i=0;i<5;i++){

        if(user_books[i].id != 0){

            count1++;

        }

    }

    role = user->role;

    if((count1 == 0)){

        printf("\nVous ne pouvez pas retourner de livres !\n");
        return 0;
    }

    printf("\nTitre\n>>>");

    check_size = ReadInput(title2, sizeof(title2));

    if(check_size == 1){

        ReplaceSpaces(title2);
        
        int indexbook;
        int indexuser;

        for(int i=0;i<size;i++){

            for(int j=0;j<count1;j++){

                if(strcmp(title2, book[i].title) == 0 && book[i].id == user->books[j].id){

                    book[i].stock += 1;

                    for(int k=j; k<4;k++){

                        user_books[k].id = user_books[k+1].id;
                        user_books[k].time = user_books[k+1].time;

                    }
                    
                    user_books[4].id = 0;
                    user_books[4].time = 0;

                    printf("\nLivre rendu avec succes !\n");
                    return 1;

                }

            }

        }

    }

    printf("\nVous ne possedez pas ce livre !\n");

    return 0;

}