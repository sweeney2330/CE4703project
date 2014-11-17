/////////////////////////////////////////////////////////////////////////////////
//  File: arithmetic.c
//  Desc: Stores all functions to manipulate the polynomial(s)
//        1) Addition
//        2) Subtraction
//        3) Multiplication
//        4) Division
//        5) Normalization
//        6) Order
//
//  Author: Group 3
//  ID: 13131567
//  Date: 14/11/14
///////////////////////////////////////////////////////////////////////////////// 
#include <stdio.h>

#include "polynomial.h"

/*
  Add two polynomials. All assignments are done by pass by reference.

  @param polynomial *a address of the first polynomial
  @param polynomial *b address of the second polynomial
  @param polynomial *out address of the resultant polynomial

 */
void add(polynomial *a, polynomial *b, polynomial *out){
  //initialise array with proper allocated memory
  //macro found in header, finds the two max
  int size = MAX(a->length, b->length);
  initialise(out, size);


  //loop through both polynomials, add each element
  for(int i = 0; i <= size; i++){
    //check if each arrays are finished
    if( i <= a->length && i <= b->length){

      //store the sum of the current elements
      //in the new polynomial to be returned
      out->poly[i] = a->poly[i] + b->poly[i];
    }else{
      //throw in whatever's left if one of the arrays are exhausted
      if( a->length > b->length){
	out->poly[i] = a->poly[i];
      }else{
	out->poly[i] = b->poly[i];
      }
    }
  }

  return;
}

/*
  Subtract two polynomials. All assignments are done by pass by reference.
 
  @param polynomial *a address of the first polynomial
  @param polynomial *b address of the second  polynomial
  @param polynomial *out address of the resultant polynomial

 */
void subtract(polynomial *a, polynomial *b, polynomial *out){
  //initialise array with proper allocated memory
  int size = MAX(a->length, b->length);
  initialise(out, size);


  //loop through both polynomials, subtract  each element
  for(int i = 0; i <= size; i++){
    //check if each arrays are finished
    if( i <= a->length && i <= b->length){

      //store the sum of the current elements
      //in the new polynomial to be returned
      out->poly[i] = a->poly[i] - b->poly[i];
    }else{
      //throw in whatever's left if one of the arrays are exhausted
      if( a->length > b->length){
	out->poly[i] = a->poly[i];
      }else{
	out->poly[i] = b->poly[i];
      }
    }
  }

  return;
}

/*
  Multiplies a polynomial by a double
 
  @param polynomial *a address of the polynomial
  @param double double_coeff used to multiply the polynomial
  @param polynomial *out address of the resultant polynomial
 */
void multiply(polynomial *a, double double_coeff, polynomial *out){
  //initialize poly array with correct memory allocation
  initialise(out, a->length);

  int current_a;
  //loop through poly 'a' and each element 
  //multiplied by the double coeff
  for(int i = 0; i <= a->length; i++){
    //store current value of poly coeff
    current_a = a->poly[i];

    //at each iteration store the evaluation to result
    out->poly[i] = (current_a)*(double_coeff);
  }
  
  return;
}

/*
  Divide a polynomial by a double

  @param polynomial *a address of the polynomial 'a'
  @param double_coeff used to divide the polynomial
  @param polynomial *out address of the resultant polynomial
 */
void divide(polynomial *a, double double_coeff, polynomial *out){
  //initialize poly array with correct memory allocation
  initialise(out, a->length);

  int current_a;
  //loop through poly 'a' and each element 
  //diveded by the double coeff
  for(int i = 0; i <= a->length; i++){
    //store current value of poly coeff
    current_a = a->poly[i];

    //at each iteration store the evaluation to the 
    //corresponding address for the poly array
    out->poly[i] = (current_a)/(double_coeff);
  }
  
  return;
}

/*
  Normalize a polynomial
  
  @param polynomial *a the address of the polynomial
  @param polynomial *out the address of the resultant polynomial
 */
void normalise(polynomial *a, polynomial *out){
  initialise(out, a->length);

  //set the max before hand to compare
  int max = a->poly[0];  
  
  //find the max which will become the normalising coeff
  for(int i = 1; i <= a->length; i++){
    max = MAX(max, a->poly[i]);
  }

  //use divide function from before :)
  divide(a, max, out);

  return;
}


/*
  Order of the polynomial

  @param polynomial *a address of the polynomial
  @return the order of the polynomial
*/
int order(polynomial *a){
  return a->length;
}
