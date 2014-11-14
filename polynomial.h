#ifndef polynomial_h_
#define polynomial_h_

#define SIZE 100

//Enum for addition or subtraction arithmetic
typedef enum {addition,subtract}operation;

//type definition for structure of the polynomial
typedef struct{
  double data[SIZE];
  int next; //Similar to stacking in the next
} polynomial; //this structure will hold the coefficients of the polynomial


//function declarations
void setupPolynomial (polynomial *p);
void addCoefficient(int order, double coefficient, polynomial *p);
polynomial arithmatic(polynomial *first, polynomial *second,operation a);
void scalarDivision(polynomial *poly);
void normalise(polynomial *poly);
void polynomialOrder(polynomial *poly);
void printPolynomial(polynomial *poly);


#endif
