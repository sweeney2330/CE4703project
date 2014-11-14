/////////////////////////////////////////////////////////////////////////////////
//  File: ui.c
//  Desc: Provides a user interface controlled for the user instructing them on
//        each process.
//   
//  Author: Ian Lodovica/Raj Shah
//  ID: 13131567
//  Date: 14/11/14
///////////////////////////////////////////////////////////////////////////////// 
#include <stdlib.h>
#include <stdio.h>

#include "adt_header.h"

int main()
{
  int sel;
  char choice;

  //initialize two polynomials
  polynomial a = {{-21,2,-83,44,5}, 5};
  polynomial b = {{14,3,2}, 3};


  //resultant polynomials from later manipulations
  polynomial sum, difference, product, quotient, normalised;
  double double_coeff;

  printf("--------------------------------\n");
  printf("MENU\n");
  printf("1. Add polynomials\n");
  printf("2. Subtract polynomials\n");
  printf("3. Multiply polynomial by scalar\n");
  printf("4. Divide polynomial by scalar\n");
  printf("5. Normalise polynomial\n");
  printf("6. Return order of polynomial\n");
  printf("7. Print polynomial\n");
  printf("--------------------------------\n");

  //print both polynomies
  printf("Poly A is: ");
  print_p(&a);
  printf("Poly B is: ");
  print_p(&b);
  printf("----------------------------------------------\n"); 

  do
  {
    printf("Enter selection: ");
    scanf("%d", &sel);
    getchar(); 

    switch(sel)
    {
    case 1: 
      //addition goes here
      printf("Adding the two polynomials..\n"); 
      
      sum = add(&a, &b);
      print_p(&sum);
      break;
    case 2:
      // subtraction goes here
      printf("Subtracting the two polynomials..\n");
      
      difference = subtract(&a, &b);
      print_p(&difference);
      break;
    case 3: 
      //multiplying goes here
      printf("Please enter a double to multiply the polynomial by ");
      scanf("%lf", &double_coeff);
      
      printf("Multiplying A by %.2lf..\n", double_coeff);
      
      product = multiply(&a, double_coeff);
      print_p(&product);
      break;
    case 4:
      //dividing goes here
      printf("Please enter a double to divide the polynomial by ");
      scanf("%lf", &double_coeff);
      
      printf("Dividing A by %.2lf..\n", double_coeff);
      
      quotient = divide(&a, double_coeff);
      print_p(&quotient);
      break;
    case 5:
      //Normalise goes here
      printf("Normalizing the polynomial..\n");

      normalised = normalise(&a);
      print_p(&normalised);
      break;
    case 6: 
      printf("Order of the polynomial..\n");// Return order goes here
      printf("Order is: %d\n", order(&a));
      break;
    case 7:
      printf("Printing polynomial..\n");// printing goes here
      break;
    default: 
      printf("Invalid input\n");
      break;
    }
    //just to section off different sessions
    printf("----------------------------------------------\n"); 
    printf("Do you want to continue?(Y/N): ");
    scanf("%c", &choice);    
    getchar();
    
  }while(choice == 'Y' || choice == 'y');

  //prepare for termination of session
  system("clear");

  return EXIT_SUCCESS;
}
