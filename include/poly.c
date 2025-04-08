// src/poly.c
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "poly.h"

Polynomial generate_random_poly() {
    Polynomial p;
    for (int i = 0; i < POLY_DEGREE; i++) {
        p.coeffs[i] = rand() % MODULUS;
    }
    return p;
}

Polynomial poly_add(Polynomial a, Polynomial b) {
    Polynomial result;
    for (int i = 0; i < POLY_DEGREE; i++) {
        result.coeffs[i] = (a.coeffs[i] + b.coeffs[i]) % MODULUS;
    }
    return result;
}

Polynomial poly_multiply(Polynomial a, Polynomial b) {
    Polynomial result = {0};
    for (int i = 0; i < POLY_DEGREE; i++) {
        for (int j = 0; j < POLY_DEGREE; j++) {
            int idx = (i + j) % POLY_DEGREE;
            result.coeffs[idx] = (result.coeffs[idx] + a.coeffs[i] * b.coeffs[j]) % MODULUS;
        }
    }
    return result;
}

void print_poly(Polynomial p) {
    printf("[ ");
    for (int i = 0; i < POLY_DEGREE; i++) {
        printf("%d ", p.coeffs[i]);
    }
    printf("]\n");
}
