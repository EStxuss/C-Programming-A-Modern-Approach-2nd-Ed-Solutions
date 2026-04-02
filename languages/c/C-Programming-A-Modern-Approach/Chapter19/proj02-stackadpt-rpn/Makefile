rpn: rpn-calc.o stack.o
	gcc -o rpn rpn-calc.o stack.o

rpn-calc.o: rpn-calc.c stack.h
	gcc -c rpn-calc.c

stack.o: stack.c stack.h
	gcc -c stack.c

clean:
	rm *.o rpn