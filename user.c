#include "biblio.h"

void WelcomeMsg(char *login){

    int nb_spaces = (23-strlen(login))/2;
    printf("\n***********************************\n");
    for(int i=0;i<nb_spaces;i++){
        printf(" ");
    }
    printf("Bienvenue %s !\n",login);
    printf("***********************************\n");
    
}

// Create a user account and store the data in users.txt

void CreateAccount(char *name_file, int *size){

    char login[22];
    char pswrd[22];
    char role[3];

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

            DeleteSpaces(login);

            index = CompareTableUserLogin(tab, login, *size);

            if(index != -1){

                printf("\nCe login est deja pris !\n");

            }

        }
        else{

            printf("\nCe login est trop grand ! (20 caracteres max)\n");

        }

    }while(index != -1 || check_size != 1);

    check_size = 0;

    // Creating the user's password
    do{

        printf("\nMot de passe\n>>>");

        check_size = ReadInput(pswrd, sizeof(pswrd));

        if(check_size == 1){

            DeleteSpaces(pswrd);

        }
        else{

            printf("\nCe mot de passe est trop grand !  (20 caracteres max)\n");

        }

    }while(check_size != 1);

    Encode(pswrd, VIGENERE_KEY);

    check_size = 0;

    // Creating the user's role
    do{

        printf("\nQuel est votre role ?\n");
        printf("1 - Etudiant\n");
        printf("2 - Professeur\n");
        printf("3 - Administrateur\n");
        printf(">>>");

        check_size = ReadInput(role, sizeof(role));

        if(check_size != 1){

            printf("\nErreur de saisie, veuillez recommencer !\n");

        }
        else{

            c = (int) strtol (role, NULL, 10);

            if(c < 1 || c > NB_ROLE){

                printf("\nErreur de saisie, veuillez recommencer !\n");

            }

        }

    }while(c < 1 || c > NB_ROLE || check_size != 1);

    // Adds the data to a text file
    file = fopen(name_file, "a");
    fprintf(file, "%s %s %d 0 0 0 0 0 0 0 0 0 0\n", login, pswrd, c); // The zeros correspond to the locations of the books and their times
    fclose(file);
    *size += 1;
    printf("\nVotre compte est finalise !\n");

}

// Logging in to a user account

int ConnectAccount(User *tab, int *size){

    char login[22];
    char pswrd[22];

    int index;
    int cmp;
    int check_size = 0;

    // Check user's login
    do{

        printf("\nLogin\n>>>");
        check_size = ReadInput(login, sizeof(login));

        if(check_size == 1){

            DeleteSpaces(login);

            index = CompareTableUserLogin(tab, login, *size);

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

            DeleteSpaces(pswrd);
            Encode(pswrd, VIGENERE_KEY);
            cmp = strcmp(pswrd, tab[index].pswrd);

            if(cmp != 0){

                printf("\nMot de passe incorect !\n");
            }

        }

    }while(cmp != 0 || check_size != 1);

    return index; // Returns the corresponding line in the text file

}