test: test.c polynomial.o
	gcc -Wall -o test test.c polynomial.o

polynomial.o: polynomial.c
	gcc -Wall -std=c99 -c polynomial.c

clean:
	rm *.o *~ *#
