// === sign.c ===
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include "sign.h"
#include "poly.h"
#include "keygen.h"

// Gaussian-like noise
Polynomial random_noise_poly(int bound) {
    Polynomial r = generate_small_poly(bound);
    return r;
}

// Maze-based wrapping (for challenge 01 and 10)
Polynomial maze_wrap(Polynomial x, Polynomial pub_h, int challenge_type) {
    Polynomial result = x;
    if (challenge_type == 1) {
        // Horizontal hyperbola: reveal x, compute y
        result = poly_mul(x, x);  // x^2
    } else if (challenge_type == 2) {
        // Vertical hyperbola: reveal y, compute x
        result = poly_add(x, pub_h);  // twist with public key
    }
    return result;
}

// Signature generation
Signature sign_message(PublicKey pub, PrivateKey priv, int challenge_type, Polynomial message) {
    Signature sig;
    sig.challenge_type = challenge_type;

    // Step 1: Generate random r like Falcon
    Polynomial r = random_noise_poly(5);

    // Step 2: Hash -> challenge scalar (simplified as int here)
    int c = rand() % 3 + 1;

    // Step 3: Compute s1, s2 based on challenge
    if (challenge_type == 0 || challenge_type == 3) {
        // Standard Falcon-style s = r + c * s
        sig.s1 = poly_add(r, priv.f);
        sig.s2 = poly_add(r, priv.g);
    }
    else if (challenge_type == 1) {
        // Horizontal hyperbola path
        Polynomial x = poly_add(r, priv.f); // simulated x
        Polynomial y = maze_wrap(x, pub.h, 1);
        sig.s1 = x;
        sig.s2 = y;
    }
    else if (challenge_type == 2) {
        // Vertical hyperbola path
        Polynomial y = poly_add(r, priv.g); // simulated y
        Polynomial x = maze_wrap(y, pub.h, 2);
        sig.s1 = x;
        sig.s2 = y;
    }

    // Debug print
    printf("\n🌀 Maze-Wrapped Signature (Challenge %d)\n", challenge_type);
    print_poly("Signature Part s1", sig.s1);
    print_poly("Signature Part s2", sig.s2);

    return sig;
}
