/////////////////////////////////////////////////////////////////////////////////
//  File: polynomial_manipulation.c
//  Desc: Stores all functions to manipulate the polynomial(s)
//        1) Addition
//        2) Subtraction
//        3) Multiplication
//        4) Division
//        5) Normalization
//        6) Order
//  Author: Ian Lodovica
//  ID: 13131567
//  Date: 14/11/14
///////////////////////////////////////////////////////////////////////////////// 
#include <stdio.h>
#include "adt_header.h"

/*
  Add two polynomials

  @param polynomial *a address of the first polynomial
  @param polynomial *b address of the second polynomial
  
  @return sum the sum of the two polynomials
 */
polynomial add(polynomial *a, polynomial *b){
  //find the highest order of each polynomial
  //will be used to control loops later on
  int a_length = a->length;
  int b_length = b->length;
  
  //max of the two lengths assigned to sum's length because
  //it's a combination of the two polynomials.
  polynomial sum;
  sum.length = MAX(a_length, b_length);

  //variables to be used while calculating the sum of two coeffs
  //at each iteration
  int current_a;
  int current_b;

  //loop through both polynomials, add each element
  for(int i = 0; i < sum.length; i++){
    //store current value of the polynomial
    current_a = a->poly[i];
    current_b = b->poly[i];

    //store the sum of the current elements
    //in the new polynomial to be returned
    sum.poly[i] = current_a + current_b;
  }
  return sum;
}

/*
  Subtract two polynomials
 
  @param polynomial *a address of the first polynomial
  @param polynomial *b address of the second  polynomial
 
  @return the difference of the two polynomials
 */
polynomial subtract(polynomial *a, polynomial *b){
  //find the highest order of each polynomial
  //will be used to control loops later on
  int a_length = a->length;
  int b_length = b->length;
  
  //max of the two lengths assigned to sum's length because
  //it's a combination of the two polynomials.
  polynomial difference;
  difference.length = MAX(a_length, b_length);

  //variables to be used while calculating the difference of two coeffs
  //at each iteration
  int current_a;
  int current_b;

  //loop through both polynomials, add each element
  for(int i = 0; i < difference.length; i++){
    //store current value of the poly coeff
    current_a = a->poly[i];
    current_b = b->poly[i];

    //store the difference of the current elements
    //in the new polynomial to be returned
    difference.poly[i] = current_a - current_b;
  }
  return difference;
}

/*
  Multiplies a polynomial by a double
 
  @param polynomial *a address of the polynomial
  @param double double_coeff used to multiply the polynomial

  @return result multiple of the original polynomial
 */
polynomial multiply(polynomial *a, double double_coeff){
  //initialize the resulting polynomial.
  polynomial result;
  result.length = a->length;

  int current_a;
  //loop through poly 'a' and each element 
  //multiply by the double coeff
  for(int i = 0; i <result.length; i++){
    //store current value of poly coeff
    current_a = a->poly[i];

    //at each iteration store the evaluation to result
    result.poly[i] = (current_a)*(double_coeff);
  }
  return result;
}

/*
  Divide a polynomial by a double

  @param polynomial *a address of the polynomial 'a'
  @param double_coeff used to divide the polynomial

  @return result the original polynomial divided across by double_coeff
 */
polynomial divide(polynomial *a, double double_coeff){
  //initialize the resulting polynomial.
  polynomial result;
  result.length = a->length;

  int current_a;
  //loop through poly 'a' and each element 
  //divided by the double coeff
  for(int i = 0; i <result.length; i++){
    //store current value of poly coeff
    current_a = a->poly[i];

    //at each iteration store the evaluation to result
    result.poly[i] = (current_a)/(double_coeff);
  }
  return result;
}

/*
  Normalize a polynomial
  
  @param polynomial *a the address of the polynomial

  @return the normalized polynomial
 */
polynomial normalise(polynomial *a){
  //set the max before hand to compare
  int max = a->poly[0];
  
  //initialize the resulting polynomial
  polynomial result;
  result.length = a->length;
  
  //used to keep track of current coeff
  int current_a;
  //find the max which will become the normalising coeff
  for(int i = 1; i <= result.length; i++){
    current_a = a->poly[i];
    max = MAX(max, current_a);
  }
  //use divide function from before :)
  result = divide(a, max);

  return result;
}

/*
  Order of the polynomial

  @param polynomial *a address of the polynomial

  @return the order of the polynomial
*/
int order(polynomial *a){
  return a->length-1;
}
