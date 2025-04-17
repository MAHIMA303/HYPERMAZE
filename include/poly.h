#ifndef POLY_H
#define POLY_H

#include <stdint.h>   // For int16_t

#define N 512          // Degree of polynomial
#define MAX_DEGREE N   // For safety, matching N

typedef struct {
    int16_t coeffs[N];
    int degree;
} Polynomial;

Polynomial generate_random_poly(int min, int max);
Polynomial poly_multiply(Polynomial a, Polynomial b);
Polynomial generate_secret_poly();
Polynomial generate_error_poly();
void print_poly(Polynomial p);

#endif // POLY_H
