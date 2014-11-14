/*
 *Main file for our CE4703 project
*/

#include <stdlib.h>
#include <stdio.h>

#include "polynomial.h"

int main()
{
/*{
  int i =0;
  int b = 0;
  int create = 1;
  int finished =1;
  polynomial test, ans,ans2;
  setupPolynomial(&test);
  polynomial add = {{4.0,5.0,6.0,7.0,8.0},5}; // This polynomial will be added to the user one as a test.
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
*/

    int sel;
    char choice;

  // menu here
    printf("\t\t\tMENU\n");
    printf("1. Create a polynomial\n");
    printf("2. Add polynomials\n");
    printf("3. Subtract polynomials\n");
    printf("4. Multiply polynomial by scalar\n");
    printf("5. Divide polynomial by scalar\n");
    printf("6. Normalise polynomial\n");
    printf("7. Return order of polynomial\n");
    printf("8. Print polynomial\n");
    
    
    do
    {
      printf("Enter selection: ");
      scanf("%d", &sel);
      getchar(); 
      polynomial ans,ans2;
      polynomial poly1;
      polynomial poly2 = {{4.0,5.0,6.0,7.0,8.0},5};
      switch(sel)
      {
      case 1: //creating a polynomial goes here
	createPolynomial(&poly1);
	printPolynomial(&poly1);
	printf("is the polynomial you created\n");
	break;
      case 2: // addition goes here *function calls*
	ans =arithmatic(&poly1,&poly2,addition);
        printPolynomial(&ans);
        printf(" is the result of this addition\n");
        break;
      case 3: // subtraction goes here
	ans2=  arithmatic(&poly1,&poly2, subtract);
        printPolynomial(&ans2);
        printf(" is the result of this subtraction\n");
        break;
      case 4: // multiplying goes here
        break;
      case 5: // dividing goes here
        break;
      case 6: // Normalise goes here
        break;
      case 7: // Return order goes here
        break;
      case 8: // printing goes here
        break;

      default: printf("Invalid choice\n");
             
      break;
      }
      printf("Do you want to continue?(Y/N): ");
      getchar();
      scanf("%c", &choice);    
      if(choice == 'N' || choice == 'n')
	system("clear");
    }while(choice == 'Y' || choice == 'y');
    //system("clear");
    return EXIT_SUCCESS;
}
