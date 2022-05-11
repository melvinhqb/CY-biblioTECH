EXEC = exec
HEADER = biblio.h
SRC = main.c general.c user.c book.c convert.c compare.c manage_files.c vigenere.c
OBJ = $(SRC:.c=.o)

ifdef OS
	RM = del
	NUL = >nul 2>&1
else
   	ifeq ($(shell uname), Linux)
      	RM = rm -f
   	endif
endif

all: $(OBJ)
	gcc *.o -o $(EXEC)

%.o: %.c $(HEADER)
	gcc -c $< -o $@

clean:
	$(RM) *.o $(NUL)

mrproper: clean
	$(RM) $(EXEC).exe $(NUL)

help:
	@echo help     : Show this help
	@echo all      : Compiles all files
	@echo clean    : Deletes object files
	@echo mrproper : Deletes object files and the executable