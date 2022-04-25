#include<stdio.h>
#include <stdlib.h>
#include <string.h>

#define VIGENERE_KEY "clevigenere"

typedef enum{STUDENT=1, TEACHER, ADMIN}Role;

typedef enum{SCIENCE=1, LITERATURE, ART, HISTORY}Type;

typedef enum{NO, YES}Stock;

typedef struct{
    char login[50];
    char pswrd[50];
    int role;
    int books_id[5];
}User;

typedef struct{
    char title[100];
    char author[50];
    int id;
    int type;
    int stock;
}Book;

// display.c functions

void WelcomeMsg();
void BookMsg(Book *book, User user, int size);
char *ShowBookType(int a);
char *ShowBookStock(int a);
void ShowBook(Book book);
void ShowBooks(Book *tab, int size);

// input_functions.c functions

void EmptyBuffer();
int ReadInput(char *c, int size);
void DeleteSpaces(char *tab);
int MainMenu();
void CreateAccount(char *name_file, int *size);
int ConnectAccount(User *tab, int *size);

// manage_files.c functions

int FileSize(char *name_file);
User *LoadUsers(char *name_file, int size);
Book *LoadBooks(char *name_file, int size);

// vignere.c functions

void Encode(char chaine[], char cle[]);
void Decode(char chaine[], char cle[]);