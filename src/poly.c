#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "poly.h"

Polynomial generate_random_poly(int degree, int max_val) {
    Polynomial p;
    p.degree = degree;
    for (int i = 0; i <= degree; i++) {
        p.coeffs[i] = (rand() % (2 * max_val + 1)) - max_val;
    }
    return p;
}

Polynomial poly_multiply(Polynomial a, Polynomial b) {
    Polynomial result;
    result.degree = a.degree + b.degree;

    for (int i = 0; i <= MAX_DEGREE; i++) {
        result.coeffs[i] = 0;
    }

    for (int i = 0; i <= a.degree; i++) {
        for (int j = 0; j <= b.degree; j++) {
            if (i + j <= MAX_DEGREE)
                result.coeffs[i + j] += a.coeffs[i] * b.coeffs[j];
        }
    }

    return result;
}

void print_poly(Polynomial p) {
    printf("Polynomial: ");
    int printed = 0;
    for (int i = p.degree; i >= 0; i--) {
        if (p.coeffs[i] != 0) {
            if (printed && p.coeffs[i] > 0) printf(" + ");
            else if (p.coeffs[i] < 0) printf(" - ");

            int coeff = abs(p.coeffs[i]);
            if (i == 0) printf("%d", coeff);
            else if (i == 1) printf("%d*x", coeff);
            else printf("%d*x^%d", coeff, i);

            printed = 1;
        }
    }
    if (!printed) printf("0");
    printf("\n");
}
