/////////////////////////////////////////////////////////////////////////////////
//  File: polynomial.h
//  Desc: Contains all of the global functon calls/macros/declarations used
//   
//  Author: Group 3
//  ID: 13131567 13133799 13153889 13104195
//  Date: 14/11/14
///////////////////////////////////////////////////////////////////////////////// 

/*
  Changelog

  15/11/14
  1)changed most operational functions to return void as well as taking
    another parameter *polynomial *out to accomodate changes in the functions.

 */

#ifndef POLY_H
#define POLY_H

#define MAX(a, b) ((a)>=(b)?(a):(b))


typedef struct{
  int length;
  double *poly;
}polynomial;

typedef enum {ok, noMemory, illegalPoly} pError;

//manipulate_manipulation.c declarations
pError add(polynomial *a, polynomial *b, polynomial *out);
pError subtract(polynomial *a, polynomial *b, polynomial *out);
pError multiply(polynomial *a, double double_coeff, polynomial *out);
pError divide(polynomial *a, double double_coeff, polynomial *out);
pError normalise(polynomial *a, polynomial *out);
pError getOrder(polynomial *a, int *order);

//create_delete_poly.c declarationsy
void createPolynomial(polynomial *a, int size, double coeff[]);
void deletePolynomial(polynomial *a);
pError checkSizes(polynomial *a);
pError printPolynomial(polynomial *a);
void verify(pError type);

#endif
