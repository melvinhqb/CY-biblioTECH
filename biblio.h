#include<stdio.h>
#include <stdlib.h>
#include <string.h>

typedef enum{STUDENT=1, TEACHER, ADMIN}Role;

typedef enum{SCIENCE, LITERATURE, ART, HISTORY}Type;

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
char *ShowBookType(int a);
char *ShowBookStock(int a);
void ShowBook(Book book);
void ShowBooks(Book *tab, int size);

// input_functions.c functions

void EmptyBuffer();
int ReadInput(char *c, int size);
int MainMenu();
void CreateAccount(char *name_file, User *tab, int *size);

// manage_files.c functions

int FileSize(char *name_file);
User *LoadUsers(char *name_file, int size);
Book *LoadBooks(char *name_file, int size);

// vignere.c functions

void Encode(char chaine[], char cle[]);
void Decode(char chaine[], char cle[]);