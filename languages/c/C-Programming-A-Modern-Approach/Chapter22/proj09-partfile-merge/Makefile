merge: merge.o
	gcc -O0 -g -o merge merge.o

merge.o: merge.c inventory.h
	gcc -O0 -g -c merge.c

clean:
	rm *.o merge