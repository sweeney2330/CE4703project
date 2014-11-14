/////////////////////////////////////////////////////////////////////////////////
//  File: adt_header.c
//  Desc: Contains all of the global functon calls/macros/declarations used
//   
//  Author: Ian Lodovica
//  ID: 13131567
//  Date: 14/11/14
///////////////////////////////////////////////////////////////////////////////// 
#ifndef POLY_H
#define POLY_H

typedef struct{
  double poly[5];
  int length;
}polynomial;

#define MAX(a, b) ((a)>=(b)?(a):(b))

//function declarations
polynomial add(polynomial *a, polynomial *b);
polynomial subtract(polynomial *a, polynomial *b);
polynomial multiply(polynomial *a, double double_coeff);
polynomial divide(polynomial *a, double double_coeff);
polynomial normalise(polynomial *a);
int order(polynomial *a);
void print_p(polynomial *a);

#endif
