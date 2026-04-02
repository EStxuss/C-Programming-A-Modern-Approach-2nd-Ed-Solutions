inventory: inventory.o readline.o qsort.o
	gcc -o inventory inventory.o readline.o qsort.o

inventory.o: inventory.c qsort.h readline.h
	gcc -c inventory.c

readline.o: readline.c readline.h
	gcc -c readline.c

qsort.o: qsort.c qsort.h
	gcc -c qsort.c
