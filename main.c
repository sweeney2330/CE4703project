#include <stdlib.h>
#include <stdio.h>

#include "polynomial.h"
/*
  Changlog
  -Modified test cases to reflect other changes i.e. returning a result
 */
int main(){ 
  polynomial a, b, c, sum, difference, product, quotient, normal;
  double coeff;
  
  //these will be converted into dynamic arrays later on.
  //they just store the coeffs to be used for the polynomials.
  double data1[3] =  {-204, 2, 340};
  double data2[3] = {5.2, -2, 4};
  double data3[7]= {5.0, 2.0, 20, 0, 5, 2, 40.2};

  //clear the screen to focus on this single session's tests
  system("clear");

  //////////////////////////////////////////////////////////////////
  //creating base polynomials we'll be using for the entirity of
  //these test cases.
  //
  //NOTE: createPolynomial function must be given polynomial pointer 
  // , order and the coefficient data in the form specified above
  //////////////////////////////////////////////////////////////////  
  pError p = ok;

  p=createPolynomial(&a, 3,data1);
  
  p=createPolynomial(&b, 3,data2);
  
  p=createPolynomial(&c, 7,data3);
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
  sum = add(&a, &b);
  printPolynomial(&sum);

  //subtract
  printf("A - B =  ");
  difference = subtract(&a, &b);
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
  sum = add(&a, &c);
  printPolynomial(&sum);

  printf("A - C =  ");
  difference = subtract(&a, &c);
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
  product = multiply(&a, coeff);
  printPolynomial(&product);

  //divide
  printf("C / %.2lf =  ", coeff);
  quotient = divide(&c, coeff);
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
  normal = normalise(&a);
  printPolynomial(&normal);

  deletePolynomial(&normal);

  //test2  
  printf("Noramlised (C) =  "); 
  normal = normalise(&c);
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
  printf("Order: %d\n",  order(&a)); 
 
  //////////////////////////////////////////////////////////////////
  //delete original polynomials
  //end of testing.
  //////////////////////////////////////////////////////////////////
  deletePolynomial(&a);
  deletePolynomial(&b);
  deletePolynomial(&c);

  errorPrint(p);
  return EXIT_SUCCESS;
}

 
