all: compress uncompress

compress: compress.o
	gcc -o compress compress.o

compress.o: compress.c
	gcc -c compress.c

uncompress: uncompress.o
	gcc -O0 -g -o uncompress uncompress.o

uncompress.o: uncompress.c
	gcc -O0 -g -c uncompress.c 

clean:
	rm *.o uncompress compress