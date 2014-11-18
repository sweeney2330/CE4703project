main: main.c arithmetic.o polynomial.o ui.o
	gcc -Wall -o test main.c arithmetic.o polynomial.o ui.o

arithmetic.o: arithmetic.c
	gcc -Wall -std=c99 -c arithmetic.c

polynomial.o: polynomial.c
	gcc -Wall -std=c99 -c polynomial.c

ui.o: ui.c
	gcc -Wall -c ui.c
clean:
	rm test *~ *.o *#

