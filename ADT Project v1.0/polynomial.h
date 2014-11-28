/////////////////////////////////////////////////////////////////////////////////
//  File: polynomial.h
//  Desc: Contains all of the public functon calls/macros/declarations used
//   
//  Author: Group 3
//  Names: Ian Lodovica, Trevor McSweeney, Gearoid Cremin, Raj Shah
//  ID: 13131567 13133799 13153889 13104195
//  Date: 14/11/14
///////////////////////////////////////////////////////////////////////////////// 
#ifndef POLY_H
#define POLY_H

//macro used to shorthand max expressions.
#define MAX(a, b) ((a)>=(b)?(a):(b))

//used to detect if polynomial is valid or not
typedef enum {FALSE, TRUE} flag;

//used to detect if any errors occured. 
typedef enum {ok, noMemory, illegalDelete, illegalPoly_math, illegalPoly_print} pError;
 
//the structure used for every polynomial created.
typedef struct{
  int length; //size of the polynomial. note this is not the order
  flag valid; //flag which determines whether the polynomial is valid or not
  double *coeff; //this stores the coefficients of the polynomial
}polynomial;

//manipulate_manipulation.c declarations
pError add(polynomial *a, polynomial *b, polynomial *out);
pError subtract(polynomial *a, polynomial *b, polynomial *out);
pError multiply(polynomial *a, double double_coeff, polynomial *out);
pError divide(polynomial *a, double double_coeff, polynomial *out);
pError normalise(polynomial *a, polynomial *out);
int getOrder(polynomial *a);

//create_delete_poly.c declarationsy
void createPolynomial(polynomial *a, int size, double coeff[]);
void deletePolynomial(polynomial *a);
pError printPolynomial(polynomial *a);

#endif
