/////////////////////////////////////////////////////////////////////////////////
//  File: polynomial.c
//  Desc: Controls everything that happens to the polynomials at a memory level.
//        This involves:
//        1) Creating/Deleting polynomials
//        2) Printing polynomials  
//        3) Checking for errors
//
//  Author: Group 3
//  ID: 13131567 13133799 13153889 13104195
//  Date: 14/11/14
///////////////////////////////////////////////////////////////////////////////// 
#include <stdlib.h>
#include <stdio.h>
#include "polynomial.h"

//'private' functions
void verify(pError type);

/*
  Create an empty array with the correct assigned memory and specified coeff. 
  This also sets the 'is valid flag' of the polynomial to TRUE if successful.

  @param int size will allow correct allocation of memory for array
  @param double coeff[] the data given which stores the coefficients of the poly.

*/
void createPolynomial(polynomial *a, int size, double coeff[]){
  pError status = ok;
  //calloc used as it automatically initialises the unassign memory locations to 0.
  //especially useful when using a dynamic array.
  a->coeff = (double*)calloc(size , (sizeof(double))); 
                   
  //if memory allocation failed it would return in a NULL
  //this executes when memory allocation is a success      
  if (a->coeff == NULL){
    //no need to do anything as memory was not allocated
    status = noMemory;
  }else {
    status = ok;
    // memory allocated successfully
    a->length = size; //set the length of the array to the given size
    a->valid = TRUE; //set the flag to TRUE due to successful memory allocation

    //populate the polynomial
    for(int i = 0; i < a->length; i++){
      a->coeff[i] = coeff[i]; 
    }
  }
  
  verify(status);
  return;
}


/*
  Delete the polynomial by accessing the memory address of the polynomials
  and returning it to void. Other attributes from the poly structure are also
  set back to 'initial' values.

  @param polynomial *a the polynomial to be deleted
 */
void deletePolynomial(polynomial *a){
  //if the polynomial is valid then run
  if(a->valid == TRUE){
    free(a->coeff); //free allocated memory
    a->coeff = NULL; //assign NULL for good measure (can still acess if this is ommited, odd)
    a->valid = FALSE; //set the flag to FALSE as the poly is NULL now.
    a->length = 0; //just to have a clean delete, probably not needed.
  }
  return;
}


/*
  Prints out the given polynomial

  @param polynomial *a address of the polynomial to be printed

  @return prints out an error message if polynomial is invalid, else prints out
          the polynomial with the highest degree first.
 */
pError printPolynomial(polynomial *a){
  pError status = ok;

  //if the polynomial is valid then run
  if( a->valid == TRUE ){
    int max_index = a->length - 1;

    //print the polynomial with the highest order first
    for(int i = max_index; i >= 0; i--){
      if(a->coeff[i] >= 0){
	printf("+"); //print out a + sign if a number is positive
      }
      printf("%.2lfx^%d ", a->coeff[i], i); //prints out the coeff and order
    }
    printf("\n"); //skip a line once finished.

  } else status = illegalPoly_print; //polynomial is invalid so we set the flag.

  verify(status); //check the status and print an error message if needed
  return status;
}

/*
  This function checks the error type that's passed as a parameter and determines which
  error message to print out using a switch/case statement.

  @param pError type the type of error passed. the list is defined in the header file.
 */
void verify(pError type){
  switch(type){
  
  case ok:
    //no need to do anything it's all good.
    break;
  case illegalPoly_math: //error from arithmetic.c
    printf("Error: Arithmetic operation failed. One or more illegal polynomials.\n");
    break;
  case illegalPoly_print: //error from print function
    printf("Error: Print operation failed. Illegal polynomial.\n");
    break;
  case noMemory: //comes from createPolynomial(). only happens when using potatoes.
    printf("Error: Insufficient memory to allocate data.\n");
    break;
  default: //for when the user tries modifies the error list. please don't.
    printf("Error: Something horribly went wrong.\n");
    break;
  }  
}
