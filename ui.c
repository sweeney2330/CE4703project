//////////////////////////////////////////////////////////////////////////////////
//  File: ui.c
//  Desc: stores all functions which produces the UI.
//   
//  Author: Group 3
//  ID: 13131567
//  Date: 16/11/14
///////////////////////////////////////////////////////////////////////////////// 
/*
  Changelog

  16/11/14
  1) Added option to check the size of a polynomial on the memory
  2) Renamed modify to recreate. Better describes what it does.

*/

#include <stdio.h>
#include <stdlib.h>

#include "polynomial.h"

void startScreen(){
  //Intro screen
  printf("*********************************************************\n");
  printf("*\tPolynomial creation and manipulation v0.4\t*\n");
  printf("*********************************************************\n\n");

  printf("*********************************************************\n");
  printf("*Description: Follow the instructions to manipulate\t*\n");
  printf("*             polynomials or get info about them.\t*\n");
  printf("*Authors:     Ian Lodovica, Trevor McSeeny, \t\t*\n");
  printf("*             Gearoid Cremin, Raj Shah\t\t\t*\n");
  printf("*********************************************************\n");
  //Creating two polynomials used in this session
  printf("Please enter values for Polynomial (A)\n");
  createPolynomial(&a);
  printf("--------------------------------\n");
  printf("Please enter values for Polynomial (B)\n");
  createPolynomial(&b);
  printf("--------------------------------\n");
  return;
}

void menu(){
  printf("  ****************************\n");
  printf("  *           MENU           *\n");
  printf("  ****************************\n");
  printf("1. Add polynomials\n");
  printf("2. Subtract polynomials\n");
  printf("3. Multiply polynomial by scalar\n");
  printf("4. Divide polynomial by scalar\n");
  printf("5. Normalise polynomial\n");
  printf("6. Return order of polynomial\n");
  printf("7. Print polynomial\n");
  printf("8. Recreate original polynomials\n");
  printf("9. Check sizes of a polynomial\n");
  printf("--------------------------------\n");

  return;
}

void selection(){
  //ignore at index[0] to bump enum to 1.there's likely a better alternative
  typedef enum {ignore, ADD, SUBTRACT, MULTIPLY, DIVIDE, NORMALISE, ORDER, PRINT,
		RECREATE, SIZE_CHECK} manipulate;
  //used to choose between polynomials in the UI
  typedef enum {A, B} poly;

  char proceed; //user input tells the program to keep going or terminate
  poly pick; //used to pick between polynomials
  manipulate operation; //flag use in menu

  //resultant polynomials from later manipulations
  polynomial sum, difference, product, quotient, normalised;
  double double_coeff;
  
  //series of case statements which controls the operation that will be performed.
  //cases are based off of the items on the menui() function.
  printf("--------------------------------\n");
  do
    {
      printf("Enter selection: ");
      scanf("%d", (int*)&operation);

      switch(operation)
	{
	case ADD:
	  printf("Adding the two polynomials..\n"); 
      
	  add(&a, &b, &sum);
	  printPolynomial(&sum);
      
	  //the var poly was the one allocated memory in the struct
	  //so we return it once we're done.
	  deletePolynomial(&sum); 
	  break;
	case SUBTRACT:
	  printf("Subtracting the two polynomials..\n");
          
	  subtract(&a, &b, &difference);
	  printPolynomial(&difference);

	  deletePolynomial(&difference);
	  break;
	case MULTIPLY: 
	  printf("Which poly do you want to be multiplied?\n[0] for (A)\n[1] for (B)\nChoose: ");
	  scanf("\n%d", (int*)&pick);

	  printf("Please enter a double to multiply the polynomial by ");
	  scanf("%lf", &double_coeff);    
      
	  //choose between poly (A) and poly (B)
	  if( pick == A ){ //use func on A
	    printf("Multiplying (A) by %.2lf..\n", double_coeff);
	    multiply(&a, double_coeff, &product);
	  } else { //use func on B
	    printf("Multiplying (B) by %.2lf..\n", double_coeff);
	    multiply(&b, double_coeff, &product);
	  }
	  printPolynomial(&product);
      
	  deletePolynomial(&product);
	  break;
	case DIVIDE:
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

	  printPolynomial(&quotient);

	  deletePolynomial(&quotient);
	  break;
	case NORMALISE:
	  printf("Which poly do you want to be normalised?\n[0] for (A)\n[1] for (B)\nChoose: ");
	  scanf("\n%d", (int*)&pick);

	  if( pick == A ){ //use func on A
	    printf("Normalising (A)\n");
	    normalise(&a, &normalised);
	  } else { //use func on B
	    printf("Normalising (B)\n");
	    normalise(&b, &normalised);
	  }

	  printPolynomial(&normalised);

	  deletePolynomial(&normalised);
	  break;
	case ORDER:
	  printf("Which poly do you want to check the order of?\n[0] for (A)\n[1] for (B)\nChoose: ");
	  scanf("\n%d", (int*)&pick);

	  if( pick == A ){ //use func on A
	    printf("Order of (A) is: %d\n", order(&a));
	  } else { //use func on B
	    printf("Order of (B) is: %d\n", order(&b));
	  }
	  
	  break;
	case PRINT:
	  printf("Which poly do you want to print?\n[0] for (A)\n[1] for (B)\nChoose: ");
	  scanf("\n%d", (int*)&pick);
      
	  printf("Printing polynomial..\n");
      
	  if( pick == A ){ //use func on A
	    printPolynomial(&a);
	  } else { //use func on B
	    printPolynomial(&b);
	  }
	  
	  break;
	case RECREATE:
	  //ask user to input which polynomial to modify
	  printf("Which poly do you want to recreate?\n[0] for (A)\n[1] for (B)\nChoose: ");
	  scanf("%d", (int*)&pick);
      	  //take chosen poly as parameter and re-create it.
	  if( pick == A ){ //use func on A
	    printf("Recreating (A)..\n");
	    recreate(&a);
	    printf("Poly(A) is now: ");
	    printPolynomial(&a);
	  } else { //use func on B
	    printf("Recreating (B)..\n");
	    recreate(&b);
	    printf("Poly(B) is now: ");
	    printPolynomial(&b);
	  }
	  
	  break;
	case SIZE_CHECK:
	  printf("Which poly do you want to check?\n[0] for (A)\n[1] for (B)\nChoose: ");
	  scanf("\n%d", (int*)&pick);

	  if( pick == A ){ //use func on A
	    printf("Checking size of (A)..\n");
	    checkSizes(&a);
	  } else { //use func on B
	    printf("Checking size of (B)..\n");
	    checkSizes(&b);
	  }

	  break;
	default: 
	  printf("Invalid input\n");
	  break;
	}

      //just to section off different sessions
      printf("----------------------------------------------\n"); 
      printf("Do you want to continue?(Y/N): ");
      scanf("\n%c", &proceed);    

      //checks to make sure flags are correct
      while((choice != 'Y' && choice != 'y') && (choice != 'N' && choice != 'n')){ 
	printf("Not Valid input, Please enter (Y/N): "); 
	scanf("\n%c", &choice); 
      } 

    }while(proceed == 'Y' || proceed == 'y'); 
 
  return;
}
