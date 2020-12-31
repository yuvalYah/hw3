CC=gcc
AR=ar
FLAGS=-Wall -g -Wno-misleading-indentation

all: main
main: main.o isort.o txtfind.o
	$(CC) $(FLAGS)  main.o isort.o txtfind.o -o main
main.o: main.c isort.h  
	$(CC) $(FLAGS) -c main.c -o main.o
isort.o: isort.c isort.h
	$(CC) $(FLAGS) -c isort.c  -o isort.o
txtfind.o: txtfind.c txtfind.h
	$(CC) $(FLAGS) -c txtfind.c  -o txtfind.o



clean:
	rm -f *.o
