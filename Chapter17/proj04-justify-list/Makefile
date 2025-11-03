justify: justify.o word.o line.o
	gcc -o justify justify.o word.o line.o -g -O0

justify.o: justify.c word.h line.h
	gcc -c justify.c -g -O0

word.o: word.c word.h
	gcc -c word.c -g -O0

line.o: line.c line.h
	gcc -c line.c -g -O0

clean:
	rm *.o justify
