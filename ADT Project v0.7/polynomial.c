/////////////////////////////////////////////////////////////////////////////////
//  File: polynomial.c
//  Desc: controls everything that happens to the polynomials at a memory level
//   
//  Author: Group 3
//  ID: 13131567 13133799 13153889 13104195
//  Date: 14/11/14
///////////////////////////////////////////////////////////////////////////////// 

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

  @param int size will allow correct allocation of memory for array
  @param double coeff[] the data given which stores the coefficients of the poly.

*/
void createPolynomial(polynomial *a, int size, double coeff[]){
  //allocates memory for the  array and structure
  //stored to the pointer *poly in struct. 
  a->poly = (double*)malloc(size * (sizeof(double)) ); 
  
  //if memory allocation failed it would return in a NULL
  //this executes when memory allocation is a success      
  if (a->poly == NULL){
    //no need to do anything as memory was not allocated
  }else {
    // memory allocated successfully
    a->length = size;
    
    //populate the polynomial
    for(int i = 0; i < a->length; i++){
      a->poly[i] = coeff[i]; 
    }
  }
  return;
}


/*
  delete the polynomial by accessing the address memory of the polynomials
  and returning it to void

  @param polynomial *a the polynomial to be deleted
 */
void deletePolynomial(polynomial *a){
  free(a->poly);
  a->poly = NULL;
  return;
}


/*
  Displays the all information of the polynomial

  @param polynomial *a address of the polynomial to be scanned
 */
pError checkSizes(polynomial *a){
  pError status = ok;
  if (a->poly != NULL ){
    printf("--------------------------------\n"); 
    printf("Length is %d\n", a->length);
    printf("Size of array is %d\n", a->length * sizeof(a->poly));
    printf("Size of structure is %d\n", sizeof(a));
    printf("Size of everything is %d\n" ,sizeof(a) + a->length*sizeof(a->poly));
    printf("--------------------------------\n");
  } else status = illegalPoly;
  
  return status;
}

/*
  Prints out the given polynomial

  @param polynomial *a address of the polynomial to be printed
 */
pError printPolynomial(polynomial *a){
  pError status = ok;

  if( a->poly != NULL ){
    int max_index = a->length - 1;

    for(int i = max_index; i >= 0; i--){
      if(a->poly[i] >= 0){
	printf("+");
      }
      printf("%.2lfx^%d ", a->poly[i], i);
    }
    printf("\n");

  } else status = illegalPoly;

  return status;
}

void verify(pError type){
  switch(type){
  
  case ok:
    //no need to do anything it's all good.
    break;
  case illegalPoly:
    printf("Error: Illegal Polynomial\n");
    break;
  case noMemory:
    printf("Error: Insufficient memory to allocate data\n");
    break;
  default:
    printf("Error: Something went wrong\n");
    break;
  }  
}
