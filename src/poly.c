// ==== poly.c ====
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "poly.h"
#include "params.h"  // ✅ Make sure this is here!


Polynomial generate_random_poly(int min, int max) {
    Polynomial poly;
    for (int i = 0; i < N; i++) {
        poly.coeffs[i] = (rand() % (max - min + 1)) + min;
    }
    return poly;
}

Polynomial generate_secret_poly(int bound) {
    Polynomial poly;
    for (int i = 0; i < N; i++) {
        poly.coeffs[i] = (rand() % (2 * bound + 1)) - bound;
    }
    return poly;
}

Polynomial generate_error_poly(int bound) {
    Polynomial poly;
    for (int i = 0; i < N; i++) {
        poly.coeffs[i] = (rand() % (2 * bound + 1)) - bound;
    }
    return poly;
}

Polynomial poly_multiply(Polynomial a, Polynomial b) {
    Polynomial result = { .degree = N - 1 };
    for (int i = 0; i < N; i++) result.coeffs[i] = 0;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (i + j < N) {
                result.coeffs[i + j] += a.coeffs[i] * b.coeffs[j];
                result.coeffs[i + j] %= Q;
            }
        }
    }
    return result;
}

void print_poly(Polynomial p) {
    for (int i = N - 1; i >= 0; i--) {
        if (p.coeffs[i] != 0) {
            if (i != N - 1) printf(" + ");
            printf("%d*x^%d", p.coeffs[i], i);
        }
    }
    printf("\n");
}

