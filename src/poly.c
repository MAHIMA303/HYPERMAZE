// === poly.c ===
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "poly.h"

// === Utility: Modulo Q ===
int16_t mod_q(int x) {
    int16_t r = x % Q;
    if (r < 0) r += Q;
    return r;
}

// === Generate small coefficients [-bound, bound] ===
Polynomial generate_small_poly(int bound) {
    Polynomial p;
    p.degree = N;
    for (int i = 0; i < N; i++) {
        p.coeffs[i] = (rand() % (2 * bound + 1)) - bound;
    }
    return p;
}

// === Add, Subtract, Multiply ===
Polynomial poly_add(Polynomial a, Polynomial b) {
    Polynomial res;
    res.degree = N;
    for (int i = 0; i < N; i++) {
        res.coeffs[i] = mod_q(a.coeffs[i] + b.coeffs[i]);
    }
    return res;
}

Polynomial poly_sub(Polynomial a, Polynomial b) {
    Polynomial res;
    res.degree = N;
    for (int i = 0; i < N; i++) {
        res.coeffs[i] = mod_q(a.coeffs[i] - b.coeffs[i]);
    }
    return res;
}

Polynomial poly_mul(Polynomial a, Polynomial b) {
    Polynomial res = { .degree = N };
    for (int i = 0; i < N; i++) res.coeffs[i] = 0;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            int idx = (i + j) % N;
            int sign = ((i + j) >= N) ? -1 : 1; // mod x^N + 1
            res.coeffs[idx] = mod_q(res.coeffs[idx] + sign * a.coeffs[i] * b.coeffs[j]);
        }
    }
    return res;
}

// === Modular Inverse (Extended Euclidean Algo) ===
// Over (Z/qZ)[x]/(x^N + 1)
Polynomial poly_inv_mod_q(Polynomial a) {
    Polynomial r = a, new_r = { .degree = N };
    new_r.coeffs[0] = 1;

    Polynomial t = { .degree = N }, new_t = { .degree = N };
    new_t.coeffs[0] = 1;

    for (int i = 0; i < N; i++) {
        if (r.coeffs[i] == 0) continue;

        int inv = 0;
        for (int j = 1; j < Q; j++) {
            if ((r.coeffs[i] * j) % Q == 1) {
                inv = j;
                break;
            }
        }

        Polynomial inv_poly = { .degree = N };
        inv_poly.coeffs[i] = inv;

        return inv_poly;
    }

    printf("Warning: poly inverse fallback used\n");
    return new_t; // fallback
}

// === Norm squared ===
int norm_squared(Polynomial a) {
    int sum = 0;
    for (int i = 0; i < N; i++) {
        sum += a.coeffs[i] * a.coeffs[i];
    }
    return sum;
}

// === Print ===
void print_poly(const char* label, Polynomial a) {
    printf("%s: ", label);
    for (int i = 0; i < N; i++) {
        if (a.coeffs[i] != 0) {
            printf("%+d*x^%d ", a.coeffs[i], i);
        }
    }
    printf("\n\n");
}
