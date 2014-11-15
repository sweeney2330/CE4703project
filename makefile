exec: ui poly_print.c polynomial_manipulation.c create_delete_poly.c

all: $(exec)

ui: ui.c poly_print.o polynomial_manipulation.o create_delete_poly.o
	gcc -Wall -o test ui.c poly_print.o polynomial_manipulation.o create_delete_poly.o

create_delete_poly.o: create_delete_poly.c
	gcc -Wall -std=c99 -c create_delete_poly.c

poly_print.o: poly_print.c
	gcc -Wall -std=c99 -c poly_print.c

polynomial_manipulation.o: polynomial_manipulation.c
	gcc -Wall -std=c99 -c polynomial_manipulation.c

clean:
	rm $(exec) *~ *.o *#
