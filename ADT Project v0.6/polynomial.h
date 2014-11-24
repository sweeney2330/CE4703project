/////////////////////////////////////////////////////////////////////////////////
//  File: polynomial.h
//  Desc: Contains all of the global functon calls/macros/declarations used
//   
//  Author: Group 3
//  ID: 13131567
//  Date: 14/11/14
///////////////////////////////////////////////////////////////////////////////// 
/*
  Changelog

  24/11/14
  1)Added enumeration type for pError, returns whether an operation was successful!
 */

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

typedef enum {ok,noMemory,noData} pError; //type to return whether an operation was a success

//manipulate_manipulation.c declarations
void add(polynomial *a, polynomial *b, polynomial *out);
void subtract(polynomial *a, polynomial *b, polynomial *out);
void multiply(polynomial *a, double double_coeff, polynomial *out);
void divide(polynomial *a, double double_coeff, polynomial *out);
void normalise(polynomial *a, polynomial *out);
int order(polynomial *a);

//create_delete_poly.c declarations
pError initialisePolynomial(polynomial *a, int order);
void addCoeff(polynomial *a, double coeff[]);
pError deletePolynomial(polynomial *a);
void checkSizes(polynomial *a);
pError printPolynomial(polynomial *a);

#endif
