#include <stdio.h>
#include "keygen.h"
#include "poly.h"

int main() {
    PublicKey pub;
    PrivateKey priv;

    generate_keys(&pub, &priv);

    printf("===== Public Key =====\n");
    printf("N: "); print_poly(pub.N);
    printf("v: "); print_poly(pub.v);
    printf("a: "); print_poly(pub.a);
    printf("b: "); print_poly(pub.b);

    printf("\n===== Private Key =====\n");
    printf("s: "); print_poly(priv.s);
    printf("x: "); print_poly(priv.x);
    printf("y: "); print_poly(priv.y);
    printf("X: "); print_poly(priv.X);
    printf("Y: "); print_poly(priv.Y);

    return 0;
}
