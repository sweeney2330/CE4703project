//////////////////////////////////////////////////////////////////////////////////
//  File: main.c
//  Desc: Provides a user interface controlled for the user instructing them on
//        each process.
//   
//  Author: Group 3
//  ID: 13131567
//  Date: 14/11/14
///////////////////////////////////////////////////////////////////////////////// 

/*
  Changelog
  16/11/14
  1)cut off all user interface and moved to a seperate file.
  
  15/11/14
  1)created enum for all cases in the menu
  2)removed redundant comments (ie. this prints x)
  3)made added modify polynomial to the menu
  4)allowed the user to choose which polynomial to manipulate
  5)added intro screen
 */

#include <stdlib.h>
#include <stdio.h>

#include "polynomial.h"

int main()
{
  //clean start
  system("clear");

  startScreen();

  menu();

  //All initial conditions have been set by now.
  //The two created polynomials are printed for the reference of the user.
  printf("Poly A is: ");
  printPolynomial(&a); //polynomial a declared in header
  printf("Poly B is: ");
  printPolynomial(&b); //polynomial b declared in header

  //controls all functions seen from the menu.
  selection();

  //reached the end of the session.
  system("clear");
  //returning the two polynomials to void
  deletePolynomial(&a);
  deletePolynomial(&b);
  
  return EXIT_SUCCESS;
}
