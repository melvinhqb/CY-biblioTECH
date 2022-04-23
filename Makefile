exec: main.o input_functions.o display.o
	gcc *.o -o exec

main.o: main.c biblio.h
	gcc -c main.c -o main.o

input_functions.o: input_functions.c biblio.h
	gcc -c input_functions.c -o input_functions.o

display.o: display.c biblio.h
	gcc -c display.c -o display.o

clear:
ifneq ($(OS), Win32)
	del *.o
	del exec.exe
else
	rm *.o
	rm exec
endif