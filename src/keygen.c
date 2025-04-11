#include <stdlib.h>
#include <time.h>
#include "keygen.h"
#include "poly.h"
#include "ntt.h"

void generate_keys(PublicKey* pub, PrivateKey* priv) {
    srand(time(NULL));

    // Use degree = N - 1 for NTT compatibility
    Polynomial p = generate_random_poly(N - 1, 10);   
    Polynomial q = generate_random_poly(N - 1, 10);

    Polynomial s = generate_random_poly(N - 1, 5);
    Polynomial x = generate_random_poly(N - 1, 5);
    Polynomial y = generate_random_poly(N - 1, 5);
    Polynomial a = generate_random_poly(N - 1, 5);
    Polynomial b = generate_random_poly(N - 1, 5);

    // NTT-based polynomial multiplication
    pub->commit = ntt_multiply(p, q);
    Polynomial X = ntt_multiply(x, x);
    Polynomial Y = ntt_multiply(y, y);

    Polynomial v = generate_random_poly(N - 1, 5);

    // Assign to public and private keys
    pub->v = v;
    pub->a = a;
    pub->b = b;

    priv->s = s;
    priv->x = x;
    priv->y = y;
    priv->X = X;
    priv->Y = Y;
}