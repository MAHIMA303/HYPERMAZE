// ==== main.c ====
#include <stdio.h>
#include "keygen.h"
#include "poly.h"

int main() {
    PublicKey pub;
    PrivateKey priv;

    generate_keys(&pub, &priv);

    printf("Public Key (a):\n");
    print_poly(pub.a);

    printf("Public Commitment (a*s + e):\n");
    print_poly(pub.commit);

    printf("Private Secret s:\n");
    print_poly(priv.s);

    return 0;
}