justify: justify.o line.o word.o
	gcc -o justify justify.o line.o word.o -g

justify.o: justify.c line.h word.h
	gcc -c justify.c -g

line.o:  line.c line.h
	gcc -c line.c -g

word.o: word.c word.h
	gcc -c word.c -g

clean: 
	rm *.o justify
