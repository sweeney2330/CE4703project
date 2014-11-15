/////////////////////////////////////////////////////////////////////////////////
//  File: poly_print.c
//  Desc: prints the polynomial given
//   
//  Author: Group 3
//  ID: 13131567
//  Date: 14/11/14
///////////////////////////////////////////////////////////////////////////////// 
#include <stdio.h>
#include <stdlib.h>

#include "adt_header.h"


void print_p(polynomial *a){
  for(int i = 0; i <= a->length; i++){
    printf("%.2lfx^%d ", a->poly[i], i);
  }
  printf("\n");
}
