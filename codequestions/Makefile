# Makefile

default: listdemo

list.o: list.c list.h
	gcc -c list.c -o list.o

main.o: main.c
	gcc -c main.c -o main.o

listdemo: list.o main.o
	gcc -o listdemo list.o main.o 

clean:
	rm -f *.o
	rm -f listdemo