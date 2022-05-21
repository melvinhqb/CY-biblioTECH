#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <errno.h>
#include <unistd.h>

#define USER_NAME_FILE "users.txt"
#define BOOK_NAME_FILE "books.txt"

#define VIGENERE_KEY "CYTECHLIBRARY"

#define SHOW_ECHO "stty echo"
#define HIDE_ECHO "stty -echo"

#define RED "\e[0;31m"
#define GRN "\e[0;32m"
#define YEL "\e[0;33m"
#define ITALIC "\e[3m"
#define REVERSE "\e[7m"
#define RESET_FONT "\e[0m"

#define SUGGEST_THM GRN
#define LATE_THM RED
#define ARROW YEL">>> "RESET_FONT

#define SCIENCE_NAME "Sciences"
#define LITERATURE_NAME "Litterature"
#define ART_NAME "Art"
#define HISTORY_NAME "Histoire"

#define NB_ROLE 2
#define NB_TYPE 4
#define ASCII_SPACE 32

#define MAX_SIZE_LOGIN 20
#define MAX_SIZE_PSWRD 20
#define MAX_SIZE_TITLE 80
#define MAX_SIZE_AUTHOR 50

typedef enum{STUDENT=1, TEACHER}Role;

typedef enum{SCIENCE=1, LITERATURE, ART, HISTORY}Type;

typedef enum{OUT_OF_STOCK, IN_STOCK}Stock;

typedef struct{
    long long id;
    int time;
}Book_tm;

typedef struct{
    char login[MAX_SIZE_LOGIN+2];
    char pswrd[MAX_SIZE_LOGIN+2];
    int role;
    Book_tm books[5];
}User;

typedef struct{
    char title[MAX_SIZE_TITLE+2];
    char author[MAX_SIZE_AUTHOR+2];
    long long id;
    int type;
    int stock;
}Book;

// general.c

void AppMsg();
void ByeMsg();
void EmptyBuffer();
int ReadInput(char *c, int size);
int UserInput(char *input, int size);
int DelayCheck(Book_tm *my_books, int size);
void ShowWithColor(char *sentence, char *search);
void RemoveUpperCase(char *strcopy, char *str);

// menu.c

int MenuChoice(char *choice, int size_choice, int max);
int MainMenu(int nb_users);
int SecondMenu(int role);
int EndMenu();
int SortMenu();
int TypeMenu();

// user.c

void ShowUser(User user);
void ShowUsers(User *tab, int size);
void WelcomeMsg(char *login);
void CreateAccount(char *name_file, int *size);
int ConnectAccount(User *tab, int size);

// book.c

void ShowBook(Book book);
void ShowBookColor(Book book, char *content);
void ShowBooks(Book *tab, int size);
void ShowBooksColor(Book *tab, char *content, int size);
void BookMsg(Book *book, User user, int size);
void ShowBookSuggestion(Book *search_book, int search_size, char *search);

// movebook.c

int AddBook(char *name_file, Book *book, int *size);
int RemoveBook(Book *book, int size);
int ReserveBook(Book *book, User *user, int size);
int ReturnBook(Book *book, User *user, int size);

// convert.c

char *ShowBookType(int a);
char *ShowBookStock(int a);
void ReplaceSpaces(char *tab);
void ReplaceUnderscores(char *tab);

// compare.c

int CompareTableUserLogin(User *tab, char *login, int size);
int CompareTableBookId(Book *tab, long long id, int size);
int CompareTableBookTitle(Book *tab, char *title, int size);
int CompareTableBookAuthor(Book *tab, char *author, int size);
int CompareTableBookType(Book *tab, int type, int size);
int CompareTableBook(Book *tab, Book book, int size);

// manage_files.c

int FileSize(char *name_file);
User *LoadUsers(char *name_file, int size);
Book *LoadBooks(char *name_file, int size);
void WriteUser(char *name_file, User *tab, int size);
void WriteBook(char *name_file, Book *tab, int size);

// vignere.c

void Encode(char chaine[], char cle[]);
void Decode(char chaine[], char cle[]);

// search.c

Book *SearchByTitle(Book *tabBook, char *content, int size, int *count);
Book *SearchByAuthor(Book *tabBook, char *content, int size, int *count);
Book *SearchByType(Book *tabBook, char *content, int size, int *count);
Book *SearchByStock(Book *tabBook, int stock, int size, int *count);
Book *SearchBooks(Book *book, char *search, int size, int *search_size);
Book *MergesBooks(Book *tab1, Book *tab2, int size1, int size2, int *size3);

// sort.c

int TitleCompare(const void *p1, const void *p2);
int AuthorCompare(const void *p1, const void *p2);
int TypeCompare(const void *p1, const void *p2);