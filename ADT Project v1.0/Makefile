#  File: Makefile
#  Desc: Makefile to organize compilation of source files with the main file being main.c.
#
#  Author: Group 3
#  Names: Ian Lodovica, Trevor McSweeney, Gearoid Cremin, Raj Shah
#  ID: 13131567 13133799 13153889 13104195
#  Date: 14/11/14
main: main.c polynomial.o arithmetic.o
	gcc -Wall -std=c99 -o main main.c polynomial.o arithmetic.o

polynomial.o: polynomial.c
	gcc -Wall -std=c99 -c polynomial.c

arithmetic.o: arithmetic.c
	gcc -Wall -std=c99 -c arithmetic.c
clean:
	rm *.o *~ *# main
