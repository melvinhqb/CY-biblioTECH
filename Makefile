EXEC = exec
HEADER = biblio.h
SRC = main.c general.c user.c book.c convert.c compare.c manage_files.c vigenere.c
OBJ = $(SRC:.c=.o)

all: $(OBJ)
	gcc *.o -o $(EXEC)

%.o: %.c $(HEADER)
	gcc -c $< -o $@

clean:
ifneq ($(OS), Win32)
	del *.o
else
	rm *.o
endif

mrproper: clean
ifneq ($(OS), Win32)
	del exec.exe
else
	rm exec
endif