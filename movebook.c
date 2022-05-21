#include "biblio.h"

// Function that add a book to a text file

int AddBook(char *name_file, Book *book, int *size){

    int check_size, index;
    char id_char[15];

    Book new_book;
    FILE *file = NULL;

    // Request user to enter a title

    do{

        printf("\nTitre\n");
        printf(ARROW);

        check_size = UserInput(new_book.title, sizeof(new_book.title));

    }while(check_size != 1);

    check_size = 0;

    // Request user to enter an author

    do{

        printf("\nAuteur\n");
        printf(ARROW);

        check_size = UserInput(new_book.author, sizeof(new_book.author));

    }while(check_size != 1);

    check_size = 0;

    // Request user to enter a type

    do{

        new_book.type = TypeMenu();

    }while(new_book.type == 0);

    check_size = 0;

    // Request user to enter an the ID Book

   do{

        printf("\nIdentifiant (ISBN)\n");
        printf(ARROW);

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

int RemoveBook(Book *book, int size){

    char search[MAX_SIZE_TITLE];
    char choice[5];

    int check_size, user_choice, search_size;

    Book *search_book = NULL;

    // Ask user to make a search

    printf("\nRechercher (titre/auteur/matiere)\n");
    printf(ARROW);

    check_size = UserInput(search, sizeof(search));

    if(check_size == 0){

        printf("\nAuncun livre ne correspond a votre recherche !\n");
        return 0;

    }

    // Filter books by previous search

    search_book = SearchBooks(book, search, size, &search_size);
    search_book = SearchByStock(search_book, 1, search_size, &search_size);

    if(search_size == 0){

        printf("\nAuncun livre ne correspond a votre recherche !\n");
        return 0;

    }

    // Asks the user to choose the type of sorting

    user_choice = SortMenu();

    switch(user_choice){

        case 2:
            qsort(search_book, search_size, sizeof(Book), AuthorCompare);
            break;
        case 3:
            qsort(search_book, search_size, sizeof(Book), TypeCompare);
            break;
        default:
            qsort(search_book, search_size, sizeof(Book), TitleCompare);

    }

    // Displays the filtered and sorted book table

    ShowBookSuggestion(search_book, search_size, search);

    // Asks the user to choose among the books

    printf("\nChoisir numero\n");
    printf(ARROW);

    user_choice = MenuChoice(choice, sizeof(choice), search_size);

    if(user_choice == 0){

        printf("\nErreur de saisie !\n");
        return 0;

    }

    // Update of the book table

    for(int i=0;i<size;i++){
        if(book[i].id == search_book[user_choice-1].id && book[i].stock != 0){

            book[i].stock = 0;

            printf("\nLivre retirer avec succes !\n");

            return 1;

        }
    }

}

// Function that adds a book to a user file and the storage status to a book file

int ReserveBook(Book *book, User *user, int size){

    char search[MAX_SIZE_TITLE];
    char choice[5];

    int check_size, count, delay, role;
    int verif, user_choice, search_size;

    Book *search_book = NULL;
    Book_tm *user_books = NULL;

    // Count how many books have the user

    count = 0;
    user_books = user->books;

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

    // Ask user to make a search


    printf("\nRechercher (titre/auteur/matiere)\n");
    printf(ARROW);

    check_size = UserInput(search, sizeof(search));

    if(check_size == 0){

        printf("\nAuncun livre ne correspond a votre recherche !\n");
        return 0;

    }

    // Filter books by previous search

    search_book = SearchBooks(book, search, size, &search_size);
    search_book = SearchByStock(search_book, 1, search_size, &search_size);

    if(search_size == 0){

        printf("\nAuncun livre ne correspond a votre recherche !\n");
        return 0;

    }

    // Asks the user to choose the type of sorting

    user_choice = SortMenu();

    switch(user_choice){

        case 2:
            qsort(search_book, search_size, sizeof(Book), AuthorCompare);
            break;
        case 3:
            qsort(search_book, search_size, sizeof(Book), TypeCompare);
            break;
        default:
            qsort(search_book, search_size, sizeof(Book), TitleCompare);

    }

    // Displays the filtered and sorted book table

    ShowBookSuggestion(search_book, search_size, search);

    // Asks the user to choose among the books

    printf("\nChoisir numero\n");
    printf(ARROW);

    user_choice = MenuChoice(choice, sizeof(choice), search_size);

    if(user_choice == 0){

        printf("\nErreur de saisie !\n");
        return 0;

    }

    // Update of the book table

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

// Function that removes a book to a user file and the storage status to a book file

int ReturnBook(Book *book, User *user, int size){

    int count, role, user_choice;
    char choice[3];
    time_t sec;
    struct tm tm_time;
    char hm_time[sizeof "HH h MM"];

    Book_tm *user_books = NULL;

    // Displays the books borrowed by a user

    count = 0;
    user_books = user->books;

    for(int i=0;i<5;i++){

        if(user_books[i].id != 0){

            for(int j=0;j<size;j++){

                if(user_books[i].id == book[j].id){
                    if(count == 0){
                        printf("\nVos livres :\n\n");
                    }

                    sec = user_books[i].time; // get timestamp
                    tm_time=*localtime(&sec); // convert timestamp in localtime

                    printf("   %d - ", i+1);
                    ShowBook(book[j]);

                    strftime(hm_time, sizeof hm_time, "%H h %M", &tm_time);

                    for(int k=0;k<20-strlen(ShowBookType(book[j].type));k++){
                        printf(" ");
                    }

                    printf("a rendre pour %s", hm_time);

                    if(user_books[i].time < time(NULL)){
                        printf(RED);
                        printf("    (en retard)");
                        printf(DFT);
                    }

                    printf("\n");
                    break;
                }
            }

            count++;

        }

    }

    role = user->role;

    if((count == 0)){

        printf("\nVous ne pouvez pas retourner de livres !\n");
        return 0;
    }

    // Asks the user to choose among the books

    printf("\nChoisir numero\n");
    printf(ARROW);

    user_choice = MenuChoice(choice, sizeof(choice), count);

    if(user_choice == 0){

        printf("\nErreur de saisie !\n");
        return 0;

    }

    // Update of the book table

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