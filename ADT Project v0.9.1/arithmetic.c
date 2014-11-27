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
//  ID: 13131567 13133799 13153889 13104195
//  Date: 27/11/14
///////////////////////////////////////////////////////////////////////////////// 
#include <stdio.h>
#include "polynomial.h"

//'private' functions
void verify(pError type);

/*
  Add two polynomials. The function makes sure that the output polynomial will have
  the correct size. (ie. the biggest of the two input poly). The resulting polynomial is
  sent back to where the output polynomial was declared through pass by reference.  

  @param polynomial *a address of the first polynomial
  @param polynomial *b address of the second polynomial
  @param polynomial *out address of the resultant polynomial

  @return status is ok if everything went fine else returns illegalPoly_math if one of
  the polynomials are invalid.
*/
pError add(polynomial *a, polynomial *b, polynomial *out){
  pError status = ok;
  
  //only run if polynomials are valid
  if( a->valid == TRUE && b->valid == TRUE){
    //sets up the array of coefficients that will be passed to the createPoly func.    
    int size = MAX(a->length, b->length);   
    double data[size];

    //loop through both polynomials, add each element
    for(int i = 0; i < size; i++){
      //check if each arrays are finished
      if( i < a->length && i < b->length){
	//store the sum of the current elements
	//in the new polynomial to be returned
	data[i] = a->coeff[i] + b->coeff[i];
      }else{
	//throw in whatever's left if one of the arrays are exhausted
	if( a->length > b->length){
	  data[i] = a->coeff[i];
	}else data[i] = b->coeff[i];
      }
    }
    createPolynomial(out, size, data); //creates the polynomial
  } else  {
    status = illegalPoly_math; //poly is invalid, return error
    out->valid = FALSE;
  }
  verify(status); //checks if any errors need to be printed.
  return status;
}

/*
  Subtract two polynomials. The function makes sure that the output polynomial will have
  the correct size. (ie. the biggest of the two input poly). The resulting polynomial is
  sent back to where the output polynomial was declared through pass by reference.  
 
  @param polynomial *a address of the first polynomial
  @param polynomial *b address of the second  polynomial
  @param polynomial *out address of the resultant polynomial

  @return status is ok if everything went fine else returns illegalPoly_math if one of
  the polynomials are invalid.

*/
pError subtract(polynomial *a, polynomial *b, polynomial *out){
  pError status = ok;
   
  //only run if polynomials are valid
  if( a->valid == TRUE && b->valid == TRUE){
    //sets up the array of coefficients that will be passed to the createPoly func.
    int size = MAX(a->length, b->length); //we check the max size to remove boundry errors.
    double data[size];

    //loop through both polynomials, subtract  each element
    for(int i = 0; i < size; i++){
      //check if each arrays are finished
      if( i < a->length && i < b->length){

	//store the sum of the current elements
	//in the new polynomial to be returned
	data[i] = a->coeff[i] - b->coeff[i];
      }else{
	//throw in whatever's left if one of the arrays are exhausted
	if( a->length > b->length){
	  data[i] = a->coeff[i];
	}else data[i] = b->coeff[i];
      }
    }
    createPolynomial(out, size, data); //creates the polynomial.
  } else {
    status = illegalPoly_math; //poly is invalid, return error
    out->valid = FALSE;
  }

  verify(status); //check if any errors need to be printed
  return status;
}

/*
  Multiplies a polynomial by a double. The double is passed in by the user
 
  @param polynomial *a address of the polynomial
  @param double double_coeff used to multiply the polynomial
  @param polynomial *out address of the resultant polynomial

  @return status is ok if polynomial is valid else returns illegalPoly_math.
*/
pError multiply(polynomial *a, double double_coeff, polynomial *out){
  pError status = ok;
  
  if( a->valid == TRUE){
    //sets up the array of coefficients that will be passed to the createPoly func.
    int size = a->length;
    double data[size];

    //loop through poly 'a' and each element 
    //multiplied by the double coeff
    for(int i = 0; i < a->length; i++){
      //at each iteration store the evaluation to result
      data[i] = (a->coeff[i])*(double_coeff);
      //stop 0 from being printed as negitive
      if (double_coeff < 0 && a->coeff[i] == 0)
      {
      	data[i] = 0;
      }
    }
    createPolynomial(out, size, data);
  } else{
    status = illegalPoly_math; //poly is invalid, return error
    out->valid = FALSE;
  }

  verify(status); //check if any errors need to be printed   
  return status;
}

/*
  Divide a polynomial by a double. The double is passed in by the user.

  @param polynomial *a address of the polynomial 'a'
  @param double_coeff used to divide the polynomial
  @param polynomial *out address of the resultant polynomial

  @return status is ok if polynomial is valid else returns illegalPoly_math.
*/
pError divide(polynomial *a, double double_coeff, polynomial *out){
  pError status = ok;
  
  //run only if the polynomial is valid.
  if( a->valid == TRUE ){
    //sets up the array of coefficients that will be passed to the createPoly func.
    int size = a->length; 
    double data[size];

    //loop through poly 'a' and each element 
    //multiplied by the double coeff
    for(int i = 0; i < a->length; i++){
      //at each iteration store the evaluation to result
      data[i] = (a->coeff[i])/(double_coeff);
      //stop 0 from being printed as negitive
      if (double_coeff < 0 && a->coeff[i] == 0)
      {
      	data[i] = 0;
      }
    }
    createPolynomial(out, size, data); 
  } else {
    status = illegalPoly_math; //poly is invalid, return error
    out->valid = FALSE;
  }

  verify(status);  //check if ay erros need to be printed
  return status;
}

/*
  Normalize a polynomial. Finds the highest order with a non-zero
  coefficient and divides across the entire polynomial with it.
  
  @param polynomial *a the address of the polynomial
  @param polynomial *out the address of the resultant polynomial
 
  @return status is ok if polynomial is valid else returns illegalPoly_math.
*/
pError normalise(polynomial *a, polynomial *out){
  pError status = ok;
  
  //run only if polynomial is valid.
  if( a->valid == TRUE ){
    double norm;
    //find the max which will become the normalising coeff
    //loop will stop assigning values to the normal coeff
    //at higher orders if they are 0.
    for(int i = 0; i < a->length; i++){
      if(a->coeff[i] != 0.0)
		norm = a->coeff[i]; //this eventually becomes the normalising factor
    }

    //use divide function from before :)
    divide(a, norm, out);
  } else {
    status = illegalPoly_math; //poly is invalid, return error
    out->valid = FALSE;
  }
  
  verify(status); //check if any errors need to be printed.
  return status;
}


/*
  Returns the order of polynomial

  @param polynomial *a address of the polynomial

  @return the order of the polynomial
*/
int getOrder(polynomial *a){
  //return correct order only if poly is valid.
  if( a->valid == TRUE ){
    //length stores the length of the array rather than order so
    //we subtract one to give the right answer
    int max_order = a->length - 1 ;
    
    //start from the highest perceived order and work backwards until it finds
    //a non-zero coeff which will become the highest order.
    while(a->coeff[max_order] == 0){
      max_order--;
    }
    return max_order;
  }  
  return 0; //returns a default of 0 for the order  
}
