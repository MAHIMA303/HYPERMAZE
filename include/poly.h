// === poly.h ===
#ifndef POLY_H
#define POLY_H

#include <stdint.h>
#include <stdbool.h>

#define N 512
#define Q 12289

typedef struct {
    int16_t coeffs[N];
    int degree;
} Polynomial;

Polynomial generate_small_poly(int bound);
Polynomial poly_add(Polynomial a, Polynomial b);
Polynomial poly_sub(Polynomial a, Polynomial b);
Polynomial poly_mul(Polynomial a, Polynomial b);
Polynomial poly_mod_q(Polynomial a);
Polynomial poly_mod_phi(Polynomial a); // reduce mod x^N + 1
Polynomial poly_inv_mod_q(Polynomial a); // modular inverse of a mod (q, x^N + 1)
int norm_squared(Polynomial a);
void print_poly(const char* label, Polynomial a);

#endif
