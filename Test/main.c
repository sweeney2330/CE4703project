#include <stdlib.h>
#include <stdio.h>

#include "polynomial.h"

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
  //NOTE: second parameter of initalisePolynomial(poly1, size) 
  //      MUST match the test case arrays above.
  //////////////////////////////////////////////////////////////////  
  initialisePolynomial(&a, 3);
  addCoeff(&a, data1);
  
  initialisePolynomial(&b, 3);
  addCoeff(&b, data2);
  
  initialisePolynomial(&c, 7);
  addCoeff(&c, data3);
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
  printf("testing for normalising polynomialsy\n");
printf("--------------------------------------------------------------------------------\n");

  //test1
  printf("Polynomial (A): ");
  printPolynomial(&a);
  printf("Noramlised (A) =  "); 
  normalise(&a, &normal);
  printPolynomial(&normal);

  deletePolynomial(&normal);

  //test2
  printf("Polynomial (C): ");
  printPolynomial(&c);
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
  printf("Order: %d\n",  order(&a)); 
 
  //////////////////////////////////////////////////////////////////
  //delete original polynomials
  //end of testing.
  //////////////////////////////////////////////////////////////////
  deletePolynomial(&a);
  deletePolynomial(&b);
  deletePolynomial(&c);


  
  return EXIT_SUCCESS;
}

