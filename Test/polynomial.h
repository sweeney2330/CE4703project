#ifndef TESTING_POLY
#define TESTING_POLY

typedef struct {
  int length;
  double *poly;
}polynomial;

void initialisePolynomial(polynomial *a, int order);
void addCoeff(polynomial *a, int coeff[]);
void printPolynomial(polynomial *a);


#endif
