// ==== keygen.h ====
#ifndef KEYGEN_H
#define KEYGEN_H
#include "poly.h"

typedef struct {
    Polynomial a;
    Polynomial commit;  // a*s + e
} PublicKey;

typedef struct {
    Polynomial s;
    Polynomial e;  // optional
} PrivateKey;

void generate_keys(PublicKey* pub, PrivateKey* priv);

#endif
