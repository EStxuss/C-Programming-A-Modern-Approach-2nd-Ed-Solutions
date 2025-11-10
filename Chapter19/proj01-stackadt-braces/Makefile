bracesmatch: braces-match.o stack.o
	gcc -o bracesmatch braces-match.o stack.o

braces-match.o: braces-match.c stack.h
	gcc -c braces-match.c

stack.o: stack.c stack.h
	gcc -c stack.c

clean:
	rm *.o bracesmatch