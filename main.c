*
Main file for our CE4703 project
*/


#include <stdlib.h>
#include <stdio.h>

#include "polynomial.h"

int main()
{
  int i =0;
  int b = 0;
  int create = 1;
  int finished =1;
  polynomial test, ans,ans2;
  setupPolynomial(&test);
  polynomial add = {{4,5,6,7,8},5}; // This polynomial will be added to the user one as a test.
  printf("Do you wish to create a polynomial? (1=yes/0=no)  ");
  scanf("%d", &create);  
  if (create == 1)
    {
      printf("What is the degree of this polynomial?   ");
      scanf("%d", &finished);
      for(i=0;i<=finished;i++)
      {
	       printf("Please enter the coefficient of X^%d:   ",i);
	       scanf("%d", &b);
	       addCoefficient(i,b,&test);
      }
  }


    int sel;
    char choice;

  // menu here
    printf("\t\t\tMENU\n");
    printf("1. Add polynomials\n");
    printf("2. Subtract polynomials\n");
    printf("3. Multiply polynomial by scalar\n");
    printf("4. Divide polynomial by scalar\n");
    printf("5. Normalise polynomial\n");
    printf("6. Return order of polynomial\n");
    printf("7. Print polynomial\n");
    
    
    do
    {
      printf("Enter selection: ");
      scanf("%d", &sel);
      getchar(); 

      switch(sel)
      {
      case 1: // addition goes here *function calls*
        ans=  arithmatic(&test,&add, addition);
        printPolynomial(&ans);
        printf(" is the result of this addition\n");
        break;
      case 2: // subtraction goes here
        ans2=  arithmatic(&test,&add, subtract);
        printPolynomial(&ans2);
        printf(" is the result of this subtraction\n");
        break;
      case 3: // multiplying goes here
        break;
      case 4: // dividing goes here
        break;
      case 5: // Normalise goes here
        break;
      case 6: // Return order goes here
        break;
      case 7: // printing goes here
        break;

      default: printf("Invalid choice\n");
             
      break;
    }
    
    printf("Do you want to continue?(Y/N): ");
    scanf("%c", &choice);    
    getchar();
  
  if(choice == 'N' || choice == 'n')
      system("clear");
  }while(choice == 'Y' || choice == 'y');
  //system("clear");
  return EXIT_SUCCESS;
}
/*  printPolynomial(&test);
  printf(" is the polynomial entered by you \n");
  printPolynomial(&add);
  printf(" is the addition polynomial \n");
  ans=  arithmatic(&test,&add, addition);
  printPolynomial(&ans);
  printf(" is the result of this addition\n");
  ans2=  arithmatic(&test,&add, subtract);
  printPolynomial(&ans2);
  printf(" is the result of this subtraction\n");
  return EXIT_SUCCESS;
}

*/
