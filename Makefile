exec: main.o input_functions.o display.o manage_files.o
	gcc *.o -o exec

main.o: main.c biblio.h
	gcc -c main.c -o main.o

input_functions.o: input_functions.c biblio.h
	gcc -c input_functions.c -o input_functions.o

display.o: display.c biblio.h
	gcc -c display.c -o display.o

manage_files.o: manage_files.c biblio.h
	gcc -c manage_files.c -o manage_files.o

clear:
ifneq ($(OS), Win32)
	del *.o
	del exec.exe
else
	rm *.o
	rm exec
endif