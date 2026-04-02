inventory: inventory.o readline.o qsort.o
	gcc -o inventory inventory.o readline.o qsort.o -g

inventory.o: inventory.c qsort.h readline.h
	gcc -c inventory.c -g -O0

readline.o: readline.c readline.h
	gcc -c readline.c -g -O0

qsort.o: qsort.c qsort.h
	gcc -c qsort.c -g -O0

clean:
	rm *.o inventory
