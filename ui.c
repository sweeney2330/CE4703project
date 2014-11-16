/////////////////////////////////////////////////////////////////////////////////
//  File: ui.c
//  Desc: Provides a user interface controlled for the user instructing them on
//        each process.
//   
//  Author: Group 3
//  ID: 13131567 13133799
//  Date: 14/11/14
///////////////////////////////////////////////////////////////////////////////// 
#include <stdlib.h>
#include <stdio.h>

#include "adt_header.h"

int main()
{
  int sel;
  char choice;
  poly pick; //used to pick between polynomials
  polynomial a, b; //we'll be using this later

  //Creating two polynomials used in this session
  printf("Please enter values for Polynomial (A)\n");
  createPolynomial(&a);
  printf("Please enter values for Polynomial (B)\n");
  createPolynomial(&b);

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

    switch(sel)
    {
    case 1: 
      //addition goes here
      printf("Adding the two polynomials..\n"); 
      
      add(&a, &b, &sum);
      print_p(&sum);
      
      //the var poly was the one allocated memory in the struct
      //so we return it once we're done.
      deletePolynomial(&sum); 
      break;
    case 2:
      // subtraction goes here
      printf("Subtracting the two polynomials..\n");
      
      subtract(&a, &b, &difference);
      print_p(&difference);

      deletePolynomial(&difference);
      break;
    case 3: 
      //multiplying goes here
      //let the user choose
      printf("Which poly do you want to be multiplied?\n[0] for (A)\n[1] for (B)\nChoose: ");
      scanf("\n%d", (int*)&pick);

      printf("Please enter a double to multiply the polynomial by ");
      scanf("%lf", &double_coeff);    
      //guards to make sure input is correcty
      /* if(pick != A && pick != B){ */
      /* 	while(pick != A && pick != B);{ */
      /* 	  printf("Please enter [0] or [1]: "); */
      /* 	  scanf("%d",(int*)&pick); */
      /* 	} */
      /* } */
      
      //choose between poly (A) and poly (B)
      if( pick == A ){ //use func on A
	printf("Multiplying (A) by %.2lf..\n", double_coeff);
	multiply(&a, double_coeff, &product);
      } else { //use func on B
	printf("Multiplying (B) by %.2lf..\n", double_coeff);
	multiply(&b, double_coeff, &product);
      }
      print_p(&product);
      
      deletePolynomial(&product);
      break;
    case 4:
      //dividing goes here
      //let the user choose
      printf("Which poly do you want to be divided?\n[0] for (A)\n[1] for (B)\nChoose: ");
      scanf("\n%d", (int*)&pick);

      printf("Please enter a double to divide the polynomial by ");
      scanf("%lf", &double_coeff);
      
      if( pick == A ){ //use func on A
	printf("Multiplying (A) by %.2lf..\n", double_coeff);
	divide(&a, double_coeff, &quotient);
      } else { //use func on B
	printf("Multiplying (B) by %.2lf..\n", double_coeff);
	divide(&b, double_coeff, &quotient);
      }

      print_p(&quotient);

      deletePolynomial(&quotient);
      break;
    case 5:
      //Normalise goes here
      //let the user choose
      printf("Which poly do you want to be normalised?\n[0] for (A)\n[1] for (B)\nChoose: ");
      scanf("\n%d", (int*)&pick);

      if( pick == A ){ //use func on A
	printf("Normalising (A)\n");
	normalise(&a, &normalised);
      } else { //use func on B
	printf("Normalising (B)\n");
        normalise(&b, &normalised);
      }

      print_p(&normalised);

      deletePolynomial(&normalised);
      break;
    case 6: 
      //let the user choose
      printf("Which poly do you want the order of?\n[0] for (A)\n[1] for (B)\nChoose: ");
      scanf("\n%d", (int*)&pick);

      if (pick == A)
      {
      printf("Order of the polynomial..\n");// Return order goes here
      printf("Order is: %d\n", order(&a));
  } else {
  	  printf("Order of the polynomial..\n");// Return order goes here
      printf("Order is: %d\n", order(&b));
  }

      break;
    case 7:
    	//let the user choose
      printf("Which poly do you want the order of?\n[0] for (A)\n[1] for (B)\nChoose: ");
      scanf("\n%d", (int*)&pick);

      if (pick == A)
      {
      	printf("Printing polynomial..\n");// printing goes here
      	print_p(&a);
      } else {
     	 printf("Printing polynomial..\n");// printing goes here
      	 print_p(&a);
  		}
      break;
    default: 
      printf("Invalid input\n");
      break;
    }
    //just to section off different sessions
    printf("----------------------------------------------\n"); 
    printf("Do you want to continue?(Y/N): ");
    scanf("\n%c", &choice);    
    
    //checks to make sure flags are correct
    /* if(choice != 'Y' || choice != 'y' ||  choice != 'N' || choice != 'n'){ */
    /*   printf("Please enter (Y/N): "); */
    /*   scanf("\n%c", &choice); */
    /* } */

   }while(choice == 'Y' || choice == 'y'); 
 

  //delete polynomials
  deletePolynomial(&a);
  deletePolynomial(&b);
  
  //prepare for termination of session
  system("clear");

  return EXIT_SUCCESS;
}
