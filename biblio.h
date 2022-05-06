#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define USER_NAME_FILE "users.txt"
#define BOOK_NAME_FILE "books.txt"
#define VIGENERE_KEY "clevigenere"
#define NB_ROLE 3
#define NB_TYPE 4

typedef enum{STUDENT=1, TEACHER, ADMIN}Role;

typedef enum{SCIENCE=1, LITERATURE, ART, HISTORY}Type;

typedef enum{OUT_OF_STOCK, IN_STOCK}Stock;

typedef struct{
    int id;
    int time;
}Book_tm;

typedef struct{
    char login[50];
    char pswrd[50];
    int role;
    Book_tm books[5];
}User;

typedef struct{
    char title[100];
    char author[50];
    int id;
    int type;
    int stock;
}Book;

// general.c functions

void AppMsg();
void EmptyBuffer();
int ReadInput(char *c, int size);
void DeleteSpaces(char *tab);
int MainMenu();

// user.c functions

void WelcomeMsg(char *login);
void CreateAccount(char *name_file, int *size);
int ConnectAccount(User *tab, int *size);

// book.c functions

void ShowBook(Book book);
void ShowBooks(Book *tab, int size);
void BookMsg(Book *book, User user, int size);
void AddBook(char *name_file, int *size);

// convert.c functions

char *ShowBookType(int a);
char *ShowBookStock(int a);

// compare.c functions

int CompareTableUserLogin(User *tab, char *login, int size);
int CompareTableBookId(Book *tab, char *id, int size);

// manage_files.c functions

int FileSize(char *name_file);
User *LoadUsers(char *name_file, int size);
Book *LoadBooks(char *name_file, int size);

// vignere.c functions

void Encode(char chaine[], char cle[]);
void Decode(char chaine[], char cle[]);