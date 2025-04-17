// === verify.c ===
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "verify.h"
#include "poly.h"

// Hyperbola check: ((x - R1)^2)/a^2 - ((y - R2)^2)/b^2 ≈ 1
int check_hyperbola(Polynomial x, Polynomial y, int a, int b, int r1, int r2) {
    double x_val = x.coeffs[0] - r1;
    double y_val = y.coeffs[0] - r2;

    double lhs = (x_val * x_val) / (a * a);
    double rhs = (y_val * y_val) / (b * b);

    double result = lhs - rhs;
    return (fabs(result - 1.0) < 0.5); // Accept if approx equals 1
}

int verify_signature(PublicKey pub, Polynomial message, Signature sig) {
    Polynomial s1 = sig.s1;
    Polynomial s2 = sig.s2;

    printf("\n🔎 Verifying Signature (Challenge %d)\n", sig.challenge_type);

    if (sig.challenge_type == 0 || sig.challenge_type == 3) {
        // Dummy check: norm limit
        int norm = norm_squared(s1) + norm_squared(s2);
        if (norm < 20000) {
            printf("✅ Signature Verified: Norm valid.\n");
            return 1;
        } else {
            printf("❌ Signature Rejected: Norm too large.\n");
            return 0;
        }
    }

    if (sig.challenge_type == 1 || sig.challenge_type == 2) {
        int r1 = 3, r2 = 5;
        int a = r1 % Q;
        int b = r2 % Q;

        int ok = check_hyperbola(s1, s2, a, b, r1, r2);
        if (ok) {
            printf("✅ Hyperbola Check Passed.\n");
            return 1;
        } else {
            printf("❌ Hyperbola Check Failed.\n");
            return 0;
        }
    }

    printf("❌ Unknown challenge type.\n");
    return 0;
}