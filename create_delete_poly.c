/////////////////////////////////////////////////////////////////////////////////
//  File: create_delete_poly.c
//  Desc: creates and deletes polynomials at request
//   
//  Author: Group 3
//  ID: 13131567
//  Date: 14/11/14
///////////////////////////////////////////////////////////////////////////////// 
#include <stdlib.h>
#include <stdio.h>

#include "adt_header.h"

/*
  Create an empty array with the correct assigned memory

  @param polynomial *a the poly to be created
  @param int size will allow correct allocation of memory for array
 */
void initialise(polynomial *a, int size){
  //allocates memory for the struct as well as the size of the array
  //stored to the pointer *poly in struct. 
  a->poly = (double*)malloc(sizeof(polynomial) + size*(sizeof(double))); 
  a->length = size;

  return;
}

/*
  Create a polynomial with the use of dynamic arrays

  @param int order the highest order of the polynomial to be created
 
  @return a the polynomial created
*/
void createPolynomial(polynomial *a){
  /* typedef enum {TRUE, FALSE} flag; */
  /* flag is_integer = TRUE;  */
  /* char extra; */
  int n;
  printf("Enter the order of the polynomial ");
  
  scanf("%d", &n);
  //scanf() can return 0, 1, EOF. Error pops up if not success (1)
  /* if(scanf("\n%d", &n) != 1){   */
  /*     printf("Please input an integer "); */
  /*     while(getchar() != '\n'); */
  /*     scanf("\n%d\n", &n); */
  /* } */

  //initialised with abs(n) to turn negative inputs to positive
  initialise(a, abs(n));

  //size checks
  checkSizes(a);

  printf("Enter your coeffs:\n");
  //if memory allocation failed it would return in a NULL
  //this executes when memory allocation is a success
  if(a->poly != NULL){
    //build the array
    for(int i = 0; i <= abs(n); i++){
      //takes in the input as the coeff to be added to the array
      //the +i is there to move our pointer to the next 'double' block
      //which was allocated with malloc
      printf("x^[%d]: ", i);
      scanf("%lf", a->poly+i);

    }
  }
  return;
}


void deletePolynomial(polynomial *a){
  free(a->poly);
}

void checkSizes(polynomial *a){
  printf("--------------------------------\n");
  printf("Length is %d\n", a->length);
  printf("Size of array is %d\n", a->length * sizeof(double));
  printf("Size of structure is %d\n", sizeof(polynomial));
  printf("Size of everything is %d\n" ,sizeof(polynomial) + a->length*sizeof(double));
  printf("--------------------------------\n");
}

