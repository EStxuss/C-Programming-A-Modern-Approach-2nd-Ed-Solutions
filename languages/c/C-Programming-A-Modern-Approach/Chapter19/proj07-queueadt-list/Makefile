queueadt: queueclient.o queueADT.o
	gcc -o queueadt queueclient.o queueADT.o

queueclient.o: queueclient.c queueADT.h
	gcc -c queueclient.c

queueADT.o: queueADT.c queueADT.h
	gcc -c queueADT.c

clean: 
	rm *.o queueadt