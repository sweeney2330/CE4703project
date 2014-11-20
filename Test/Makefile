main: main.c polynomial.o arithmetic.o
	gcc -Wall -std=c99 -o main main.c polynomial.o arithmetic.o

polynomial.o: polynomial.c
	gcc -Wall -std=c99 -c polynomial.c

arithmetic.o: arithmetic.c
	gcc -Wall -std=c99 -c arithmetic.c
clean:
	rm *.o *~ *# main
