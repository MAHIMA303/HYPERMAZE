#include <stdio.h>
#include <time.h>
#include "keygen.h"
#include "poly.h"

int main() {
    PublicKey pub;
    PrivateKey priv;

    clock_t start, end;
    double cpu_time_used;

    // ⏱️ Start measuring time
    start = clock();

    generate_keys(&pub, &priv);

    // 🛑 Stop measuring time
    end = clock();
    cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;

    // 🧾 Output keys
    printf("===== Public Key =====\n");
    printf("N: "); print_poly(pub.commit);
    printf("v: "); print_poly(pub.v);
    printf("a: "); print_poly(pub.a);
    printf("b: "); print_poly(pub.b);

    printf("\n===== Private Key =====\n");
    printf("s: "); print_poly(priv.s);
    printf("x: "); print_poly(priv.x);
    printf("y: "); print_poly(priv.y);
    printf("X: "); print_poly(priv.X);
    printf("Y: "); print_poly(priv.Y);

    // ⏲️ Print time taken
    printf("\nKey Generation Time: %.6f seconds\n", cpu_time_used);

    return 0;
}