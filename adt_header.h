/////////////////////////////////////////////////////////////////////////////////
//  File: adt_header.c
//  Desc: Contains all of the global functon calls/macros/declarations used
//   
//  Author: Group 3
//  ID: 13131567
//  Date: 14/11/14
///////////////////////////////////////////////////////////////////////////////// 
#ifndef POLY_H
#define POLY_H

//used to choose between polynomials in the UI
typedef enum {A, B} poly;

typedef struct{
  unsigned int length;
  double *poly;
}polynomial;

#define MAX(a, b) ((a)>=(b)?(a):(b))

//function declarations
void add(polynomial *a, polynomial *b, polynomial *out);
void subtract(polynomial *a, polynomial *b, polynomial *out);
void multiply(polynomial *a, double double_coeff, polynomial *out);
void divide(polynomial *a, double double_coeff, polynomial *out);
void normalise(polynomial *a, polynomial *out);
int order(polynomial *a);
void print_p(polynomial *a);

void initialise(polynomial *a, int size);
void createPolynomial(polynomial *a);
void deletePolynomial(polynomial *a);
void checkSizes(polynomial *a);
#endif
