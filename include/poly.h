#ifndef POLY_H
#define POLY_H

#define MAX_DEGREE 10

typedef struct {
    int coeffs[MAX_DEGREE + 1];
    int degree;
} Polynomial;

Polynomial generate_random_poly(int degree, int max_val);
Polynomial poly_multiply(Polynomial a, Polynomial b);
void print_poly(Polynomial p);

#endif
