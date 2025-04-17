// === sign.h ===
#ifndef SIGN_H
#define SIGN_H

#include "poly.h"
#include "keygen.h"

typedef struct {
    Polynomial s1;
    Polynomial s2;
    int challenge_type;  // 00, 01, 10, 11
} Signature;

Signature sign_message(PublicKey pub, PrivateKey priv, int challenge_type, Polynomial message);

#endif
