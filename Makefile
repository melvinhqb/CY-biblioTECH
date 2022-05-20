EXEC = exec
HEADER = biblio.h
SRC = main.c general.c user.c book.c convert.c compare.c manage_files.c vigenere.c search.c sort.c movebook.c
OBJ = $(SRC:.c=.o)

all: $(OBJ)
	gcc *.o -o $(EXEC)

%.o: %.c $(HEADER)
	gcc -c $< -o $@

clean:
	rm -f *.o

mrproper: clean
	rm -f $(EXEC)

help:
	@echo "help     : Show this help"
	@echo "all      : Compiles all files"
	@echo "clean    : Deletes object files"
	@echo "mrproper : Deletes object files and the executable"