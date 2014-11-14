/*
File that contains all the functions that interact with the polynomials
*/

#include <stdlib.h>
#include <stdio.h>
#include "polynomial.h"


void createPolynomial (polynomial *p)
{
/*This function will create a polynomial or delete it
 *TODO: Add code to delete the polynomial
 */
//	for(i=0;i<100;i++)
//	{
//		p->data[i]=0;
//	}
 p->next = 0;
 int i;
 int order;
 int coeff;
 printf("What is the order of this polynomial?   ");
 scanf("%d", &order);
 for(i=0;i<=order;i++)
   {
     printf("Please enter the coefficient of X^%d:   ",i);
     scanf("%d", &coeff);
     addCoefficient(i,coeff,p);
   }
}
void addCoefficient(int order, double coefficient, polynomial *p) // this function is more of an "add coefficient" than it is create polynomial
/* Without knowing how to store the array, this function will just take a coefficient
 * and the assiciated degree and give place it in the stack in the orders location.
 */
{
  p->data[order]=  coefficient;
  if(p->next < order)// next being changed to store the order of the polynomial
    {
      p->next = order;
    }
}
polynomial arithmatic(polynomial *first, polynomial *second,operation a) 
{
  /*
   *Biggest problem with the aritmatic is the "Stack" that we use can have
   *"garbage" values stored in elements that are not given values. To account
   *for this . However in the final function we will probably have to account 
   *for this even if we have arrays that do not have garbage values to avoid 
   *an out of bounds element.
   */
  int i =0;
  int highest =  first->next; //stores highest degree to tell addition where to stop
  int lowestHigh = second->next; //stores lower degrees highest degree to tell it where it does not exist
  polynomial answer;
  answer.next = highest;
  if(second->next>first->next) 
    {
      highest = second-> next;
      lowestHigh = first->next;
    }
    if(a==addition)
    {
      for(i=0;i<=highest;i++)
      {
  if(i<=lowestHigh) answer.data[i]= first->data[i]+second->data[i];  //handles elements that have values
  else if(i>lowestHigh && first->next>second->next) answer.data[i]= first->data[i]; //handles elements where first + second = first
  else answer.data[i] = second->data[i]; // handles elements where first + second = second
      }
    }
    else
    {
      for(i=0;i<=highest;i++)
      {
  if(i<=lowestHigh) answer.data[i]= (first->data[i]-second->data[i]);  //handles elements that have values
  else if(i>lowestHigh && first->next>second->next) answer.data[i]= first->data[i]; //handles elements where first + second = first
  else answer.data[i] = (-1)*second->data[i]; // handles elements where first + second = second
      }
    }
  return answer;
}

void scalarMultiplication(polynomial *poly, double s)
{
  
}
void normalise(polynomial *poly)
{

}
void polynomialOrder(polynomial *poly)
{

}
void printPolynomial(polynomial *poly)
/*
 * Simply for loops through the data array printing out the
 * Elements apporiately.
 */
{
  int i =0;
  for(i=0;i<=poly->next;i++)
  {
    if(i==poly->next) printf("%.21f*X^%d \n", poly->data[i],i);
    else printf("%.2lf*X^%d+", poly->data[i],i);
  }
}
