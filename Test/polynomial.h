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

//manipulate_manipulation.c declarations
void add(polynomial *a, polynomial *b, polynomial *out);
void subtract(polynomial *a, polynomial *b, polynomial *out);
void multiply(polynomial *a, double double_coeff, polynomial *out);
void divide(polynomial *a, double double_coeff, polynomial *out);
void normalise(polynomial *a, polynomial *out);
int order(polynomial *a);

//create_delete_poly.c declarations
void initialisePolynomial(polynomial *a, int order);
void addCoeff(polynomial *a, double coeff[]);
void deletePolynomial(polynomial *a);
void checkSizes(polynomial *a);
void printPolynomial(polynomial *a);

#endif
