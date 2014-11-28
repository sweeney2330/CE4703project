/////////////////////////////////////////////////////////////////////////////////
//  File: main.c
//  Desc: main file to run the program and initiate test cases
//   
//  Author: Group 3
//  Names: Ian Lodovica, Trevor McSweeney, Gearoid Cremin, Raj Shah
//  ID: 13131567 13133799 13153889 13104195
//  Date: 24/11/14
///////////////////////////////////////////////////////////////////////////////// 
#include <stdlib.h>
#include <stdio.h>
#include "polynomial.h"

int main(){ 
  //test cases
  polynomial a, b, c, d, e, f; 
  
  //result of arithmetic operations
  polynomial sum, sum2, difference, product, quotient, normal;
  
  //used as dividing/multiplying factor in later polynomials
  double scalar;

  //these will be converted into dynamic arrays later on.
  //they just store the coeffs to be used for the polynomials.
  double data1[3] = {20, -4, 0};
  double data2[3] = {5, 5, 5};
  double data3[7] = {5.0, 2.0, 20, 0, 5, 2, 0};
  double data4[5] = {48, 92, 74, -20, -66.96};
  double data5[5] = {-48, -92, -74, 20,  66.96};

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
  createPolynomial(&e, 5, data4);
  createPolynomial(&f, 5, data5);


  printf("*************************************************************************\n");
  printf("*\tTEST MAIN FOR POLYNOMIALS IMPLEMENTED USING DYNAMIC ARRAYS\t*\n");
  printf("*\tEach test case does the following:\t\t\t\t* \n");
  printf("*\t(1) Arithmetic operation\t\t\t\t\t*\n");
  printf("*\t(2) Print the result\t\t\t\t\t\t*\n");
  printf("*\t(3) Delete the result from memory\t\t\t\t*\n");
  printf("*************************************************************************\n");


  printf("-------------------------------------------------------------------------------------------------\n");
  printf("These are the starting polynomials which will be used for the later operations\n");
  printf("-------------------------------------------------------------------------------------------------\n");
  printf("Polynomial (A): ");
  printPolynomial(&a);
  printf("Polynomial (B): ");
  printPolynomial(&b);
  printf("Polynomial (C): ");
  printPolynomial(&c);
  printf("Attempting to print an invalid polynomial..\n");
  printf("Polynomial (D): ");
  printPolynomial(&d);
  printf("Polynomial (E): ");
  printPolynomial(&e);
  printf("Polynomial (F): ");
  printPolynomial(&f);

  //////////////////////////////////////////////////////////////////
  //testing add/subtract polynomials of same length
  //////////////////////////////////////////////////////////////////
  printf("-------------------------------------------------------------------------------------------------\n");
  printf("testing addition/subtraction on polynomials\n");
  printf("-------------------------------------------------------------------------------------------------\n");
  printf("Polynomial (A): ");
  printPolynomial(&a);
  printf("Polynomial (B): ");
  printPolynomial(&b); 
  printf("Polynomial (C): ");
  printPolynomial(&c);
  printf("Polynomial (E): ");
  printPolynomial(&e);
  printf("Polynomial (F): ");
  printPolynomial(&f);
  
  printf("\nExpected A + B = 5.00x^2 + 1.00x^1 + 25.00x^0\n");
  printf("Expected E + F = 0.00x^4 + 0.00x^3 + 0.00x^2 + 0.00x^1 + 0.00x^0\n");
  printf("Expected A + C = 0.00x^6 + 2.00x^5 + 5.00x^4 + 0.00x^3 + 20.00x^2 - 2.00x^1 + 25.00x^0 \n");
  printf("Expected A - B = 5.00x^2 - 9.00x^1 + 15.00x^0\n");
  printf("Expected A - C = 0.00x^6 + 2.00x^5 + 5.00x^4 + 0.00x^3 - 20.00x^2 - 6.00x^1 + 15.00x^0\n");

  printf("\nTesting...\n");
  
  //test1
  printf("A + B =  ");
  add(&a, &b, &sum);
  printPolynomial(&sum);
  deletePolynomial(&sum);

  //test2 - additive inverse case
  printf("E + F =  ");
  add(&e, &f, &sum2);
  printPolynomial(&sum2);     
  deletePolynomial(&sum2);
  
  //test3
  printf("A + C =  ");
  add(&a, &c, &sum);
  printPolynomial(&sum);
  deletePolynomial(&sum);

  //test4 
  printf("A - B =  ");
  subtract(&a, &b, &difference);
  printPolynomial(&difference);
  deletePolynomial(&difference);

  //test5
  printf("A - C =  ");
  subtract(&a, &c, &difference);
  printPolynomial(&difference);
  deletePolynomial(&difference);

  //testing delete on non-existent polynomials
  printf("Attempting to delete non-existent poly(sum) multiple times. Don't freak out.\n");
  deletePolynomial(&sum);
  deletePolynomial(&sum2);
  deletePolynomial(&difference);

  //////////////////////////////////////////////////////////////////
  //testing multiplcation/division by a scalar  
  //////////////////////////////////////////////////////////////////
  printf("-------------------------------------------------------------------------------------------------\n");
  printf("testing multiplcation/division by a scalar\n");
  printf("-------------------------------------------------------------------------------------------------\n");
  printf("Polynomial (A): ");
  printPolynomial(&a);
  printf("Polynomial (B): ");
  printPolynomial(&b);
  printf("Polynomial (C): ");
  printPolynomial(&c);
  
  scalar = 5.0;

  printf("\nExpected A * 5.00 = 0.00x^2 - 20.00x^1 + 100.00x^0\n");
  printf("Expected B * 0.20 = 1.00x^2 + 1.00x^1 + 1.00x^0\n");
  printf("Expected C / 5.00 = 0.00x^6 + 0.40x^5 + 1.00x^4 + 0.00x^3 + 4.00x^2 + 0.40x^1 + 1.00x^0\n");
  
  printf("\nTesting...\n");

  //test1
  printf("A * %.2lf =  ", scalar);
  multiply(&a, scalar, &product);
  printPolynomial(&product);
  deletePolynomial(&product);

  //test2
  printf("B * %.2lf =  ", 1.0/scalar);
  multiply(&b, 1.0/scalar, &product);
  printPolynomial(&product);
  deletePolynomial(&product);

  //test3
  printf("C / %.2lf =  ", scalar);
  divide(&c, scalar, &quotient);
  printPolynomial(&quotient);
  deletePolynomial(&quotient);
  
  
  //////////////////////////////////////////////////////////////////
  //testing for normalising polynomials
  //////////////////////////////////////////////////////////////////
  printf("-------------------------------------------------------------------------------------------------\n");
  printf("testing for normalising polynomials\n");
  printf("-------------------------------------------------------------------------------------------------\n");
  printf("Polynomial (A): ");
  printPolynomial(&a);
  printf("Polynomial (B): ");
  printPolynomial(&b);
  printf("Polynomial (C): ");
  printPolynomial(&c);
  
  printf("\nExpected Noramlised (A) = + 0.00x^2 + 1.00x^1 - 5.00x^0\n");
  printf("Expected Normalised (B) = + 1.00x^2 + 1.00x^1 + 1.00x^0\n");
  printf("Expected Noramlised (C) = + 0.00x^6 + 1.00x^5 + 2.50x^4 + 0.00x^3 + 10.00x^2 + 1.00x^1 + 2.50x^0\n");

  printf("\nTesting...\n");

  //test1
  printf("Noramlised (A) =  "); 
  normalise(&a, &normal);
  printPolynomial(&normal);
  deletePolynomial(&normal);

  //test2
  printf("Normalised (B) =  ");
  normalise(&b, &normal);
  printPolynomial(&normal);
  deletePolynomial(&normal);

  //test3  
  printf("Noramlised (C) =  "); 
  normalise(&c, &normal);
  printPolynomial(&normal);
  deletePolynomial(&normal);

  //////////////////////////////////////////////////////////////////
  //testing for order of poly
  //////////////////////////////////////////////////////////////////
  printf("-------------------------------------------------------------------------------------------------\n");
  printf("testing for order of poly (note: default order = 0)\n");
  printf("-------------------------------------------------------------------------------------------------\n");
  
  printf("Expected Order of Polynomial (A): 1\n"); // CHECK!
  printf("Expected Order of Polynomial (C): 5\n"); // CHECK!

  printf("\nTesting...\n");

  //test1
  printf("Polynomial (A): ");
  printPolynomial(&a);
  printf("Order: %d\n", getOrder(&a));

  //test2
  printf("Polynomial (C): ");
  printPolynomial(&c);
  printf("Order: %d\n", getOrder(&c));

  //////////////////////////////////////////////////////////////////
  //testing operations with invalid polynomials
  //////////////////////////////////////////////////////////////////

  printf("-------------------------------------------------------------------------------------------------\n");
  printf("testing for operations with invalid polynomials\n");
  printf("-------------------------------------------------------------------------------------------------\n");
  printf("Polynomial (D) is an invalid polynomial.\nAny operations involving Polynomial (D) should result in an error message.\n");
  printf("Polynomial (A): ");
  printPolynomial(&a);
  printf("Polynomial (D): ");
  printPolynomial(&d);
  
  

  //ADDITION SUBTRACTION
  printf("-------------------------------------------------------------------------------------------------\n");
  printf("ADD/SUBTRACT\n");

  //test1
  printf("\nA + D =  ");
  add(&a, &d, &sum);
  printPolynomial(&sum);
  deletePolynomial(&sum);

  //test2
  printf("A - D =  ");
  subtract(&a, &d, &difference);
  printPolynomial(&difference);
  deletePolynomial(&difference);
 
  //these polynomials were never created as the above operations return an error
  //this will cause deletePolynomial to give a warning to the user.
 
 
  //MULTIPLCATION DIVISION
  printf("-------------------------------------------------------------------------------------------------\n");
  printf("MULTIPLY/DIVIDE\n");
  
  scalar = 5;
 
  //test1
  printf("\nD * %.2lf =  ", scalar);
  multiply(&d, scalar, &product);
  printPolynomial(&product);
 
  //test2
  printf("D / %.2lf =  ", scalar);
  divide(&d, scalar, &quotient);
  printPolynomial(&quotient);
 
  deletePolynomial(&product);
  deletePolynomial(&quotient); //quotient delete should return an error as it was never created
 
 
  //NORMALISATION
  printf("-------------------------------------------------------------------------------------------------\n");
  printf("NORMALISE\n");

  //test1
  printf("\nNoramlised (A) =  ");
  normalise(&a, &normal);
  printPolynomial(&normal);
  deletePolynomial(&normal);
 
  //test2  
  printf("Noramlised (D) =  ");
  normalise(&d, &normal);
  printPolynomial(&normal);
  deletePolynomial(&normal); //will return a warning

  
  //////////////////////////////////////////////////////////////////
  //end of testing.
  //delete original polynomials.
  //////////////////////////////////////////////////////////////////
  
  deletePolynomial(&a);
  deletePolynomial(&b);
  deletePolynomial(&c);
  deletePolynomial(&e);
  deletePolynomial(&f);
  
  printf("******************\n");
  printf("* END OF TESTING *\n");
  printf("******************\n");
 
  return EXIT_SUCCESS;
}

 
