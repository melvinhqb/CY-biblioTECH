exec: main.o general.o user.o book.o convert.o compare.o manage_files.o vigenere.o
	gcc *.o -o exec

main.o: main.c biblio.h
	gcc -c main.c -o main.o

general.o: general.c biblio.h
	gcc -c general.c -o general.o

user.o: user.c biblio.h
	gcc -c user.c -o user.o

book.o: book.c biblio.h
	gcc -c book.c -o book.o

convert.o: convert.c biblio.h
	gcc -c convert.c -o convert.o

compare.o: compare.c biblio.h
	gcc -c compare.c -o compare.o

manage_files.o: manage_files.c biblio.h
	gcc -c manage_files.c -o manage_files.o

vigenere.o: vigenere.c biblio.h
	gcc -c vigenere.c -o vigenere.o

clear:
ifneq ($(OS), Win32)
	del *.o
	del exec.exe
else
	rm *.o
	rm exec
endif