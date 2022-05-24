#include "biblio.h"

void AppMsg(){

    printf("\n***********************************\n");
    printf("     Application CY-biblioTech     \n");
    printf("***********************************\n");

}

void ByeMsg(){

    printf("\n***********************************\n");
    printf("             Au revoir             \n");
    printf("***********************************\n");

}

// Empty the buffer after using the fgets() function

void EmptyBuffer(){

    int c = 0;

    while (c != '\n' && c != EOF){

        c = getchar();

    }

}

// Reads a string entered by the user, looks for the character \n and replaces it with \0
// use the string entered by the user and the max size allowed 
// return 1 if size of the string is ok also 0

int ReadInput(char *c, int size){

    char *position = NULL;
    // read the string form the keybroad 
    if(fgets(c, size, stdin) != NULL){ // input error check

        position = strchr(c, '\n');

        if(position != NULL){

            *position = '\0';
            return 1;

        }
        else{

            EmptyBuffer(); // empty the buffer else 
            return 0;

        }

    }

}

// Function that removes spaces from a char* and returns 1 if its size is correct
// use the string entered by the user and the max size allowed 
// return 1 if size of the string is ok also 0


int UserInput(char *input, int size){

    int check_size;

    check_size = ReadInput(input, size);

    if(check_size == 0){

        printf("\nErreur de saisie ! (%d caractere max)\n", size-2);
        return 0;

    }
    else if((int)input[0] == 0){

        printf("\nErreur de saisie !\nLe champ est vide.\n");
        return 0;

    }

    for(int i=0;i<strlen(input);i++){

        if((int)input[i] < 32 || (int)input[i] > 126){

            printf("\nErreur de saisie !\nNe pas utiliser de caracteres speciaux comme les accents.\n");
            return 0;

        }
    }

    ReplaceSpaces(input); // text processing 
    return check_size;

}

// Check if the current user is overdue for the return of their books

int DelayCheck(Book_tm *my_books, int size){

    for(int i=0;i<size;i++){

        if(my_books[i].time < time(NULL)){

            return 0;

        }

    }

    return 1;

}

// Function that displays the search item in colour in relation to another item

void ShowWithColor(char *sentence, char *search){

    int c, c2;
    int a = 0;

    c2 = 0;

    char *sentence_cpy = malloc(strlen(sentence));
    char *search_cpy = malloc(strlen(search));

    RemoveUpperCase(sentence_cpy, sentence);
    RemoveUpperCase(search_cpy, search);

    while(sentence[c2] != '\0'){

        c = 0;

        while(sentence_cpy[c2] == search_cpy[c]){

            a++;

            if(search[c] == '\0'){

                printf(SUGGEST_THM);
                for(int i=c2-c;i<c2;i++){

                    printf("%c", sentence[i]);

                }
                printf(RESET_FONT);
                return;

            }

            c++;
            c2++;

        }

        if(search_cpy[c] == '\0' && sentence_cpy[c2] != '\0'){

            printf(SUGGEST_THM);
            for(int i=c2-c;i<c2;i++){

                printf("%c", sentence[i]);

            }
            printf(RESET_FONT);
            a = 0;

        }
        else if(a != 0){
            for(int i=c2-a;i<c2;i++){
                if(i < (int)strlen(sentence)){
                    printf("%c", sentence[i]);
                }
                
            }
            a = 0;
        }
        else{
            if(c2 < (int)strlen(sentence)){
                printf("%c", sentence[c2]);
            }
            c2++;
        }        

    }

}

void RemoveUpperCase(char *strcopy, char *str){

    strcopy = strcpy(strcopy, str);

    for(int i=0;i<strlen(strcopy);i++){

        if((int)strcopy[i] >= 65 && (int)strcopy[i] <= 90){

            strcopy[i] += 32;

        }

    }
}

int SecurePswrd(char *pswrd){

    int size = strlen(pswrd);
    int maj = 0;
    int min = 0;
    int num = 0;
    int car = 0;
    char c;

    for(int i=0;i<size;i++){

        c = pswrd[i];

        if(c >= 48 && c <= 57){
            num++;
        }
        else if(c >= 65 && c <= 90){
            maj++;
        }
        else if(c >= 97 && c <= 122){
            min++;
        }
        else{
            car++;
        }

    }

    if(size >= MIN_CARACT_PSWRD && maj >= MIN_UPPERCASE_PSWRD && min >= MIN_LOWERCASE_PSWRD && num >= MIN_NUMBER_PSWRD && car >= MIN_SPECAR_PSWRD){

        return 1;

    }

    printf("\nMot de passe trop fragile !\n");
    printf("Le mot de passe doit contenir au minimum :\n");

    if(size < MIN_CARACT_PSWRD){
        printf(RED);
    }
    else{
        printf(GRN);
    }
    printf("%d caracteres%s\n", MIN_CARACT_PSWRD, RESET_FONT);

    if(maj < MIN_UPPERCASE_PSWRD){
        printf(RED);
    }
    else{
        printf(GRN);
    }
    printf("%d majuscule%s\n", MIN_UPPERCASE_PSWRD, RESET_FONT);

    if(min < MIN_LOWERCASE_PSWRD){
        printf(RED);
    }
    else{
        printf(GRN);
    }
    printf("%d minuscule%s\n", MIN_LOWERCASE_PSWRD, RESET_FONT);

    if(num < MIN_NUMBER_PSWRD){
        printf(RED);
    }
    else{
        printf(GRN);
    }
    printf("%d chiffre%s\n", MIN_NUMBER_PSWRD, RESET_FONT);
    if(car < MIN_SPECAR_PSWRD){
        printf(RED);
    }
    else{
        printf(GRN);
    }
    printf("%d caractere special%s\n", MIN_SPECAR_PSWRD, RESET_FONT);


    return 0;

}