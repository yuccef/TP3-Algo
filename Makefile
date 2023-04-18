all: main main.o 

TP3.o: TP3.c TP3.h
	gcc -c TP3.c

main.o: main.c
	gcc -c main.c

main : main.c  TP3.c TP3.h 
	gcc -Wall -o main main.c TP3.c

debug: main.c TP3.c TP3.h
	gcc -g -Wall -o main main.c TP3.c
	gdb main

clean:
	rm -f *.o main
