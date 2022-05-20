#include "biblio.h"
// show login and the pwd of an user 
// enter : an user 
void ShowUser(User user){

    Decode(user.pswrd, VIGENERE_KEY);

    printf("\nLogin : %s\n",user.login);
    printf("Mot de passe : %s\n\n",user.pswrd);

    Encode(user.pswrd, VIGENERE_KEY);

}

// Displays the characteristics of books in a table
// enter: a tab of user and this size 

void ShowUsers(User *tab, int size){

    printf("\n***********************************\n");

    for(int i=0;i<size;i++){

        ShowUser(tab[i]); // Show the book n°i in *tab

    }

}

// display a personalized message afte the conncetion into the book manager 
// enter current user login 

void WelcomeMsg(char *login){

    int nb_spaces = (MAX_SIZE_LOGIN + 3 - strlen(login))/2;

    printf("\n***********************************\n");

    for(int i=0;i<nb_spaces;i++){

        printf(" ");

    }

    ReplaceUnderscores(login);
    
    printf("Bienvenue %s !\n",login);
    printf("***********************************\n");

    ReplaceSpaces(login);
    
}

// Create a user account and store the data in users.txt
// enter: the name of user txt backup and the current number of user into this file   

void CreateAccount(char *name_file, int *size){

    char login[MAX_SIZE_LOGIN + 2];
    char pswrd[MAX_SIZE_PSWRD + 2];
    char char_role[3];
    int role;

    int cmp = 1;
    int c = 0;
    int index = 0;
    int check_size = 0;

    FILE *file = NULL;
    User *tab = LoadUsers(name_file, *size);
    
    // Creating the user's login
    do{

        printf("\nLogin\n>>>");

        check_size = ReadInput(login, sizeof(login));

        if(check_size == 1){

            ReplaceSpaces(login);

            index = CompareTableUserLogin(tab, login, *size);

            if(index != -1){

                printf("\nCe login est deja pris !\n");

            }

        }
        else{

            printf("\nCe login est trop grand ! (%d caracteres max)\n", MAX_SIZE_LOGIN);

        }

    }while(index != -1 || check_size != 1);

    check_size = 0;

    // Creating the user's password
    do{

        printf("\nMot de passe\n>>>");

        check_size = ReadInput(pswrd, sizeof(pswrd));

        if(check_size == 1){

            ReplaceSpaces(pswrd);

        }
        else{

            printf("\nCe mot de passe est trop grand !  (%d caracteres max)\n", MAX_SIZE_PSWRD);

        }

    }while(check_size != 1);

    Encode(pswrd, VIGENERE_KEY);

    check_size = 0;

    // Creating the user's role
    do{

        printf("\nQuel est votre role ?\n");
        printf("1 - Etudiant\n");
        printf("2 - Professeur\n");
        printf(">>>");

        role = MenuChoice(char_role, NB_ROLE);

    }while(role == 0);

    // Adds the data to a text file
    file = fopen(name_file, "a");

    if(file == NULL){
        printf("%s\n",strerror(errno)); // Error message
        exit(1);
    }
    
    fprintf(file, "%s %s %d 0 0 0 0 0 0 0 0 0 0\n", login, pswrd, role); // The zeros correspond to the locations of the books and their times
    fclose(file);
    *size += 1;
    printf("\nVotre compte est finalise !\n");

}

// Logging in to a user account
// enter : the global data user tab and this size 

int ConnectAccount(User *tab, int size){

    char login[MAX_SIZE_LOGIN + 2];
    char pswrd[MAX_SIZE_PSWRD + 2];

    int index;
    int cmp;
    int check_size = 0;

    // Check user's login
    do{

        printf("\nLogin\n>>>");
        check_size = ReadInput(login, sizeof(login));

        if(check_size == 1){

            ReplaceSpaces(login);

            index = CompareTableUserLogin(tab, login, size);

        }

        if(index == -1 || check_size != 1){

                printf("\nCet utilisateur n'existe pas !\n");

        }

    }while(index == -1 || check_size != 1);

    // Check user's password
    do{

        printf("\nMot de passe\n>>>");
        check_size = ReadInput(pswrd, sizeof(pswrd));

        if(check_size != 1){
            
            printf("\nMot de passe incorect !\n");
        }
        else{

            ReplaceSpaces(pswrd);
            Encode(pswrd, VIGENERE_KEY);
            cmp = strcmp(pswrd, tab[index].pswrd);

            if(cmp != 0){

                printf("\nMot de passe incorect !\n");
            }

        }

    }while(cmp != 0 || check_size != 1);

    return index; // Returns the corresponding line in the text file

}