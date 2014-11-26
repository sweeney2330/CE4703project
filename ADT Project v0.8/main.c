/////////////////////////////////////////////////////////////////////////////////
//  File: main.c
//  Desc: main file to run the program and initiate test cases
//   
//  Author: Group 3
//  ID: 13131567 13133799 13153889 13104195
//  Date: 24/11/14
///////////////////////////////////////////////////////////////////////////////// 
#include <stdlib.h>
#include <stdio.h>

#include "polynomial.h"

int main(){ 
  polynomial a, b, c, sum, difference, product, quotient, normal;
  double coeff;

  //these will be converted into dynamic arrays later on.
  //they just store the coeffs to be used for the polynomials.
  double data1[3] = {20, -4, 0};
  double data2[3] = {5.2, -2, 0};
  double data3[7] = {5.0, 2.0, 20, 0, 5, 2, 0};

  //clear the screen to focus on this single session's tests
  system("clear");

  //////////////////////////////////////////////////////////////////
  //creating base polynomials we'll be using for the entirity of
  //these test cases.
  //
  //NOTE: second parameter of initalisePolynomial(poly, size) 
  //      MUST match the test case arrays above.
  //////////////////////////////////////////////////////////////////  
  createPolynomial(&a, 3, data1);
  createPolynomial(&b, 3, data2);
  createPolynomial(&c, 7, data3);

  printf("--------------------------------------------------------------------------------\n");
  printf("These are the starting polynomials which will be used for the later operations\n");
  printf("--------------------------------------------------------------------------------\n");
  printf("Polynomial (A): ");
  printPolynomial(&a);
  printf("Polynomial (B): ");
  printPolynomial(&b);
  printf("Polynomial (C): ");
  printPolynomial(&c);

  //////////////////////////////////////////////////////////////////
  //testing add/subtract polynomials of same length
  //////////////////////////////////////////////////////////////////
  printf("--------------------------------------------------------------------------------\n");
  printf("testing add/subtract polynomials of same length\n");
  printf("--------------------------------------------------------------------------------\n");
  printf("Polynomial (A): ");
  printPolynomial(&a);
  printf("Polynomial (B): ");
  printPolynomial(&b);

  //add
  printf("A + B =  ");
  add(&a, &b, &sum);
  printPolynomial(&sum);

  //subtract
  printf("A - B =  ");
  subtract(&a, &b, &difference);
  printPolynomial(&difference);

  deletePolynomial(&sum);
  deletePolynomial(&difference);

  //////////////////////////////////////////////////////////////////
  //testing add/subtract polynomials of different length  
  //////////////////////////////////////////////////////////////////
  printf("--------------------------------------------------------------------------------\n");
  printf("testing add/subtract polynomials of different length\n");
  printf("--------------------------------------------------------------------------------\n");
  printf("Polynomial (A): ");
  printPolynomial(&a);

  printf("Polynomial (C): ");
  printPolynomial(&c);

  printf("A + C =  ");
  add(&a, &c, &sum);
  printPolynomial(&sum);

  printf("A - C =  ");
  subtract(&a, &c, &difference);
  printPolynomial(&difference);

  deletePolynomial(&sum);
  deletePolynomial(&difference);

  //////////////////////////////////////////////////////////////////
  //testing multiplcation/division by a scalar  
  //////////////////////////////////////////////////////////////////
  printf("--------------------------------------------------------------------------------\n");
  printf("testing multiplcation/division by a scalar\n");
  printf("--------------------------------------------------------------------------------\n");
  printf("Polynomial (A): ");
  printPolynomial(&a);
  printf("Polynomial (C): ");
  printPolynomial(&c);

  coeff = 5;
  //multiply
  printf("A * %.2lf =  ", coeff);
  multiply(&a, coeff, &product);
  printPolynomial(&product);

  //divide
  printf("C / %.2lf =  ", coeff);
  divide(&c, coeff, &quotient);
  printPolynomial(&quotient);

  deletePolynomial(&product);
  deletePolynomial(&quotient);

  //////////////////////////////////////////////////////////////////
  //testing for normalising polynomials
  //////////////////////////////////////////////////////////////////
  printf("--------------------------------------------------------------------------------\n");
  printf("testing for normalising polynomials\n");
  printf("--------------------------------------------------------------------------------\n");
  printf("Polynomial (A): ");
  printPolynomial(&a);
  printf("Polynomial (C): ");
  printPolynomial(&c);
  
  //test1
  printf("Noramlised (A) =  "); 
  normalise(&a, &normal);
  printPolynomial(&normal);

  deletePolynomial(&normal);

  //test2  
  printf("Noramlised (C) =  "); 
  normalise(&c, &normal);
  printPolynomial(&normal);

  deletePolynomial(&normal);

  //////////////////////////////////////////////////////////////////
  //testing for order of poly
  //////////////////////////////////////////////////////////////////
  printf("--------------------------------------------------------------------------------\n");
  printf("testing for order of poly\n");
  printf("--------------------------------------------------------------------------------\n");
  printf("Polynomial (A): ");
  printPolynomial(&a);
  printf("Order: %d\n", getOrder(&a)); 
 
  //////////////////////////////////////////////////////////////////
  //delete original polynomials
  //end of testing.
  //////////////////////////////////////////////////////////////////
  deletePolynomial(&a);
  deletePolynomial(&b);
  deletePolynomial(&c);

  return EXIT_SUCCESS;
}

 
