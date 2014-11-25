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

  @return status is ok if everything went fine else returns illegalPoly if one of
          the polynomials are invalid.

 */
pError add(polynomial *a, polynomial *b, polynomial *out){
  pError status = ok;
 
  if( a->poly != NULL && b->poly != NULL){
    //macro found in header, finds the two max
    int size = MAX(a->length, b->length);   
    double data[size];

    //loop through both polynomials, add each element
    for(int i = 0; i < size; i++){
      //check if each arrays are finished
      if( i < a->length && i < b->length){
	//store the sum of the current elements
	//in the new polynomial to be returned
	data[i] = a->poly[i] + b->poly[i];
      }else{
	//throw in whatever's left if one of the arrays are exhausted
	if( a->length > b->length){
	  data[i] = a->poly[i];
	}else data[i] = b->poly[i];
      }
    }
    createPolynomial(out, size, data);

  } else status = illegalPoly; //one of the poly returned NULL so we flag it.

  return status;
}

/*
  Subtract two polynomials. All assignments are done by pass by reference.
 
  @param polynomial *a address of the first polynomial
  @param polynomial *b address of the second  polynomial
  @param polynomial *out address of the resultant polynomial

 */
pError subtract(polynomial *a, polynomial *b, polynomial *out){
  pError status = ok;

  if( a->poly != NULL && b->poly != NULL){
    //initialise array with proper allocated memory
    int size = MAX(a->length, b->length);
    double data[size];

    //loop through both polynomials, subtract  each element
    for(int i = 0; i < size; i++){
      //check if each arrays are finished
      if( i < a->length && i < b->length){

	//store the sum of the current elements
	//in the new polynomial to be returned
	data[i] = a->poly[i] - b->poly[i];
      }else{
	//throw in whatever's left if one of the arrays are exhausted
	if( a->length > b->length){
	  data[i] = a->poly[i];
	}else data[i] = b->poly[i];
      }
    }
    createPolynomial(out, size, data);
  } else status = illegalPoly;
 
  return status;
}

/*
  Multiplies a polynomial by a double
 
  @param polynomial *a address of the polynomial
  @param double double_coeff used to multiply the polynomial
  @param polynomial *out address of the resultant polynomial

  @return status is ok if polynomial is valid else returns illegalPoly.
 */
pError multiply(polynomial *a, double double_coeff, polynomial *out){
  pError status = ok;
  
  if( a->poly != NULL){
    int size = a->length;
    double data[size];

    //loop through poly 'a' and each element 
    //multiplied by the double coeff
    for(int i = 0; i < a->length; i++){
      //at each iteration store the evaluation to result
      data[i] = (a->poly[i])*(double_coeff);
    }
    createPolynomial(out, size, data);
  } else status = illegalPoly;
  
  return status;
}

/*
  Divide a polynomial by a double

  @param polynomial *a address of the polynomial 'a'
  @param double_coeff used to divide the polynomial
  @param polynomial *out address of the resultant polynomial

  @return status is ok if polynomial is valid else returns illegalPoly.
 */
pError divide(polynomial *a, double double_coeff, polynomial *out){
  pError status = ok;
  
  if( a->poly != NULL ){
    int size = a->length;
    double data[size];

    //loop through poly 'a' and each element 
    //multiplied by the double coeff
    for(int i = 0; i < a->length; i++){
      //at each iteration store the evaluation to result
      data[i] = (a->poly[i])/(double_coeff);
    }
    createPolynomial(out, size, data);
  } else status = illegalPoly;
  
  return status;
}

/*
  Normalize a polynomial
  
  @param polynomial *a the address of the polynomial
  @param polynomial *out the address of the resultant polynomial
 
  @return status is ok if polynomial is valid else returns illegalPoly.
*/
pError normalise(polynomial *a, polynomial *out){
  pError status = ok;
  
  if( a->poly != NULL ){
  double norm;
  //find the max which will become the normalising coeff
  //loop will stop assigning values to the normal coeff
  //at higher orders if they are 0.
  for(int i = 0; i < a->length; i++){
    if(a->poly[i] != 0)
      norm = a->poly[i];
  }
  //use divide function from before :)
  divide(a, norm, out);
  } else status = illegalPoly;
 
  return status;
}


/*
  Order of the polynomial

  @param polynomial *a address of the polynomial
  @return the order of the polynomial
*/
pError getOrder(polynomial *a, int *order){
  pError status = ok;
  
  if( a->poly != NULL ){
    //length stores the length of the array rather than order so
    //we subtract one to give the right answer
    *order = a->length - 1;
  } else status = illegalPoly;

  return status;  
}
