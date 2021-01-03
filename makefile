CC=gcc
AR=ar
FLAGS=-Wall -g

all: isort txtfind
isort: isort.o
	$(CC) $(FLAGS) isort.o -o isort
txtfind: txtfind.o
	$(CC) $(FLAGS) txtfind.o -o txtfind
isort.o: isort.c isort.h
	$(CC) $(FLAGS) -c isort.c  -o isort.o
txtfind.o: txtfind.c txtfind.h
	$(CC) $(FLAGS) -c txtfind.c  -o txtfind.o



clean:
	rm -f *.o
