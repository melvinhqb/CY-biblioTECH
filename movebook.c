#include "biblio.h"

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

    char search[MAX_SIZE_TITLE];
    int check_size;
    int count = 0;
    int delay;
    int role;
    int verif;
    char choice[5];
    int user_choice;

    Book *search_book_stock = NULL;
    Book *search_book = NULL;

    int search_size_stock;
    int search_size;
    
    Book_tm *user_books = NULL;
    user_books = user->books;

    // Count how many books have the user

    for(int i=0;i<5;i++){

        if(user_books[i].id != 0){

            count++;

        }

    }

    // Verification of conditions of reservation

    verif = DelayCheck(user_books, count);

    role = user->role;

    if(verif == 0){

        printf("\nAu moins un de vos livres n'a pas ete rendu a temps !\n");
        printf("\nPour emprunter, veuillez le(s) rendre\n");
        return 0;

    }

    if((role == STUDENT && count == 3) || (role == TEACHER && count == 5)){

        printf("\nVous ne pouvez pas emprunter plus de %d livres !\n", count);
        return 0;
    }

    // Define the delay of reservation

    if(user->role == 1){

        delay = 120;

    }
    else{

        delay = 180;

    }

    // Make a research

    do{

        printf("\nRechercher (titre/auteur/matiere)\n>>>");

        check_size = UserInput(search, sizeof(search));

    }while(check_size != 1);

    search_book = SearchBooks(book, search, size, &search_size);
    search_book = SearchByStock(search_book, 1, search_size, &search_size);

    SortBooks(search_book, search_size);

    if(search_size > 0 && (int)search[0] != 0){
        printf("\nSuggestions :\n\n");
        for(int i=0;i<search_size;i++){
            int j = i+1;
            while(j < 1000){
                printf(" ");
                j = j*10;
            }
            printf("%d - ",i+1);
            ShowBookColor(search_book[i], search);
            printf("\n");

        }
    }
    else if(search_size > 0 && (int)search[0] == 0){
        printf("\nSuggestions :\n\n");

        for(int i=0;i<search_size;i++){
            int j = i+1;
            while(j < 1000){
                printf(" ");
                j = j*10;
            }
            printf("%d - ",i+1);
            ShowBook(search_book[i]);
            printf("\n");

        }

    }
    else{
        printf("\nAucun livre ne correcpond aux termes recherche !\n");
        return 0;
    }

    printf("\n\nChoisir numero\n>>>");

    user_choice = MenuChoice(choice, search_size);

    if(user_choice != 0){

        for(int i=0;i<size;i++){
                if(book[i].id == search_book[user_choice-1].id && book[i].stock != 0){

                    book[i].stock -= 1;
                    user_books[count].id = book[i].id;
                    user_books[count].time = time(NULL) + delay;

                    printf("\nLivre reserve avec succes !\n");

                    return 1;

                }
            }

    }
    
    printf("\nCe livre n'est pas disponible pour le moment !\n");
    return 0;

}

// Function that removes a book to a user file and the storage status to a book file

int ReturnBook(Book *book, User *user, int size){

    int count1 = 0;
    int role;

    char choice[3];
    int user_choice;

    Book_tm *user_books = NULL;
    user_books = user->books;

    for(int i=0;i<5;i++){

        if(user_books[i].id != 0){

            for(int j=0;j<size;j++){

                if(user_books[i].id == book[j].id){
                    if(count1 == 0){
                        printf("\nVos livres :\n\n");
                    }
                    printf("   %d - ", i+1);
                    ShowBook(book[j]);
                    printf("\n");
                    break;
                }
            }

            count1++;

        }

    }

    role = user->role;

    if((count1 == 0)){

        printf("\nVous ne pouvez pas retourner de livres !\n");
        return 0;
    }

    printf("\n\nChoisir numero\n>>>");

    user_choice = MenuChoice(choice, count1);

    if(user_choice != 0){

        for(int i=0;i<size;i++){
                if(book[i].id == user_books[user_choice-1].id ){

                    book[i].stock += 1;
                    for(int j=user_choice-1;j<4;j++){
                        user_books[j].id = user_books[j+1].id;
                        user_books[j].time = user_books[j+1].time;
                    }
                    user_books[4].id = 0;
                    user_books[4].time = 0;

                    printf("\nLivre rendu avec succes !\n");

                    return 1;

                }
            }

    }
    // printf("\nVous ne possedez pas ce livre !\n");

    return 0;

}