// ==== keygen.c ====
#include <stdlib.h>
#include <time.h>
#include "keygen.h"
#include "poly.h"
#include "ntt.h"

void generate_keys(PublicKey* pub, PrivateKey* priv) {
    srand(time(NULL));

    // Step 1: Public parameter
    Polynomial a = generate_random_poly(0, Q);

    // Step 2: Small secret and error
    Polynomial s = generate_secret_poly(3);
    Polynomial e = generate_error_poly(3);

    // Step 3: Commitment
    Polynomial as = ntt_multiply(a, s);
    Polynomial commit;
    for (int i = 0; i < N; i++) {
        commit.coeffs[i] = (as.coeffs[i] + e.coeffs[i]) % Q;
    }

    // Store keys
    pub->a = a;
    pub->commit = commit;

    priv->s = s;
    priv->e = e;
}
