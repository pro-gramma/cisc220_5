udll.o: udll.c udll.h
	gcc -Wall -c udll.c

main.o: main.c
	gcc -Wall -c main.c

universalDoubleLinkeList: udll.o main.o
	gcc -Wall -o universalDoubleLinkeList udll.o main.o