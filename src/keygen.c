// === keygen.c ===
#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include "keygen.h"
#include "poly.h"

#define BOUND 10     // max coeff for f, g, F, G
#define NORM_LIMIT 20000  // rejection threshold

// === Key generation ===
void generate_keys(PublicKey* pub, PrivateKey* priv) {
    srand(time(NULL));
    int valid = 0;

    while (!valid) {
        Polynomial f = generate_small_poly(BOUND);
        Polynomial g = generate_small_poly(BOUND);
        Polynomial F = generate_small_poly(BOUND);
        Polynomial G = generate_small_poly(BOUND);

        // Compute norms
        int norm_fg = norm_squared(f) + norm_squared(g);
        int norm_FG = norm_squared(F) + norm_squared(G);

        // Check invertibility of f mod q
        Polynomial f_inv = poly_inv_mod_q(f);

        // Compute h = g / f mod q
        Polynomial h = poly_mul(g, f_inv);

        // Safety check
        if (norm_fg < NORM_LIMIT && norm_FG < NORM_LIMIT) {
            // Store keys
            pub->h = h;
            priv->f = f;
            priv->g = g;
            priv->F = F;
            priv->G = G;
            valid = 1;
        }
    }

    // === Debug print ===
    print_poly("Public key h", pub->h);
    print_poly("Secret key f", priv->f);
    print_poly("Secret key g", priv->g);
    print_poly("Trapdoor F", priv->F);
    print_poly("Trapdoor G", priv->G);
}
