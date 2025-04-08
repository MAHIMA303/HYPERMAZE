#include <stdlib.h>
#include <time.h>
#include "keygen.h"
#include "poly.h"

void generate_keys(PublicKey* pub, PrivateKey* priv) {
    srand(time(NULL));

    Polynomial p = generate_random_poly(2, 10);   // Changed to degree 2
    Polynomial q = generate_random_poly(2, 10);
    pub->N = poly_multiply(p, q);

    Polynomial s = generate_random_poly(2, 5);
    Polynomial x = generate_random_poly(2, 5);
    Polynomial y = generate_random_poly(2, 5);
    Polynomial a = generate_random_poly(2, 5);
    Polynomial b = generate_random_poly(2, 5);

    Polynomial X = poly_multiply(x, x);
    Polynomial Y = poly_multiply(y, y);

    Polynomial v = generate_random_poly(2, 5);

    pub->v = v;
    pub->a = a;
    pub->b = b;

    priv->s = s;
    priv->x = x;
    priv->y = y;
    priv->X = X;
    priv->Y = Y;
}
