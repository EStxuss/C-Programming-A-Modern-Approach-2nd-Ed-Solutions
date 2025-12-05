inventory: inventory.o readline.o qsort.o
	gcc -O0 -g -o inventory inventory.o readline.o qsort.o

inventory.o: inventory.c qsort.h readline.h
	gcc -O0 -g -c inventory.c

readline.o: readline.c readline.h
	gcc -O0 -g -c readline.c

qsort.o: qsort.c qsort.h
	gcc -O0 -g -c qsort.c

clean:
	rm *.o inventory