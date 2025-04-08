#ifndef KEYGEN_H
#define KEYGEN_H

#include "poly.h"

typedef struct {
    Polynomial N, v, a, b;
} PublicKey;

typedef struct {
    Polynomial s, x, y, X, Y;
} PrivateKey;

void generate_keys(PublicKey* pub, PrivateKey* priv);

#endif
