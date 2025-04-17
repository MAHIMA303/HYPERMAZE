// === keygen.h ===
#ifndef KEYGEN_H
#define KEYGEN_H

#include "poly.h"

typedef struct {
    Polynomial h;  // Public key: h = g/f mod q
} PublicKey;

typedef struct {
    Polynomial f, g;     // Secret key small polynomials
    Polynomial F, G;     // Extended basis (trapdoor)
} PrivateKey;

void generate_keys(PublicKey* pub, PrivateKey* priv);

#endif
