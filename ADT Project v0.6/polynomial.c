/////////////////////////////////////////////////////////////////////////////////
//  File: polynomial.c
//  Desc: controls everything that happens to the polynomials at a memory level
//   
//  Author: Group 3
//  ID: 13131567
//  Date: 14/11/14
///////////////////////////////////////////////////////////////////////////////// 
/*
  Changelog
  
  24/11/14
  -Added various error checks
    1)Added error type for initialize polynomial
    2)Added error return for delete polynomial
    3)Added error check to printpolynomial
 */

/*
  Changelog
  
  15/11/14
  1)added a modify polynomial function
  2)made the checkSize() function more accurate in giving the actual sizes
  3)moved print_p() here and renamed to printPolynomial.

 */

#include <stdlib.h>
#include <stdio.h>

#include "polynomial.h"

/*
  Create an empty array with the correct assigned memory

  @param polynomial *a the poly to be created
  @param int size will allow correct allocation of memory for array
*/
pError initialisePolynomial(polynomial *a, int size){
  /* //the order of a polynomial when given an array is always */
  /* //n-1 where n is the size of the array. */
  /* int order = size - 1; */
  pError p = ok; //default state for error detection
  //allocates memory for the  array and structure
  //stored to the pointer *poly in struct. 
  a->poly = (double*)malloc(size * (sizeof(double)) ); 
  
  //if memory allocation failed it would return in a NULL
  //this executes when memory allocation is a success      
  if (a->poly == NULL)
    //no need to do anything as memory was not allocated
    p = noMemory;//lets the user know that allocation was not sucessful
  else {
    // memory allocated successfully
    a->length = size;
    
    //initialise array to be 0
    for( int i = 0; i < a->length; i++){
      a->poly[i] = 0;
    }
  }

  return p;
}

/*
  Create a polynomial with the use of dynamic arrays

  @param int order the highest order of the polynomial to be created
 
  @return a the polynomial created
*/
void addCoeff(polynomial *a, double coeff[]){
  //build the array
  for(int i = 0; i < a->length; i++){
      a->poly[i] = coeff[i];  
  }
   return;
}
/*
  delete the polynomial by accessing the address memory of the polynomials
  and returning it to void

  @param polynomial *a the polynomial to be deleted
 */
pError deletePolynomial(polynomial *a){
  pError p =ok; //Default state to say everything is ok
  if(a->poly != NULL) //Checks if the polynomial is already empty
    free(a->poly);
  else
    p = noData; //returns an error if the polynomial is already empty
  return p;
}


/*
  Displays the all information of the polynomial

  @param polynomial *a address of the polynomial to be scanned
 */
void checkSizes(polynomial *a){
  printf("--------------------------------\n"); 
  printf("Length is %d\n", a->length);
  printf("Size of array is %d\n", a->length * sizeof(a->poly));
  printf("Size of structure is %d\n", sizeof(a));
  printf("Size of everything is %d\n" ,sizeof(a) + a->length*sizeof(a->poly));
  printf("--------------------------------\n");

  return;
}

/*
  Prints out the given polynomial

  @param polynomial *a address of the polynomial to be printed
 */
pError printPolynomial(polynomial *a){
  pError p = ok;  
  if(a->poly == NULL)
    p=noData;
  else
    {
      int max_index = a->length - 1;
      
      for(int i = max_index; i >= 0; i--){
	if(a->poly[i] >= 0) printf("+");
	printf("%.2lfx^%d ", a->poly[i], i);
	printf("\n");
      }
    }
  return p;
}
