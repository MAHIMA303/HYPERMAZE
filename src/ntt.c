#include "ntt.h"
#include "poly.h"

// Primitive 2N-th root of unity modulo Q
#define ROOT 3 // Example ω such that ω^N ≡ -1 mod Q

// Precomputed powers of ω and its inverse mod Q
static const int16_t omega[N] = {1, 3, 9, 10, 13, 5, 15, 11};       // ω^i mod Q
static const int16_t omega_inv[N] = {1, 6, 2, 7, 8, 12, 4, 14};    // ω^{-i} mod Q

// Compute modular inverse using Extended Euclidean Algorithm
int16_t modinv(int16_t a, int16_t q) {
    int16_t t = 0, newt = 1;
    int16_t r = q, newr = a;
    while (newr != 0) {
        int16_t quotient = r / newr;
        int16_t temp = t;
        t = newt;
        newt = temp - quotient * newt;
        temp = r;
        r = newr;
        newr = temp - quotient * newr;
    }
    return t < 0 ? t + q : t;
}

// Forward NTT
void ntt(int16_t a[N]) {
    for (int len = 1; len < N; len <<= 1) {
        for (int i = 0; i < N; i += 2 * len) {
            for (int j = 0; j < len; j++) {
                int16_t u = a[i + j];
                int16_t v = (omega[N / (2 * len) * j] * a[i + j + len]) % Q;
                a[i + j] = (u + v) % Q;
                a[i + j + len] = (u - v + Q) % Q;
            }
        }
    }
}

// Inverse NTT
void intt(int16_t a[N]) {
    for (int len = N / 2; len >= 1; len >>= 1) {
        for (int i = 0; i < N; i += 2 * len) {
            for (int j = 0; j < len; j++) {
                int16_t u = a[i + j];
                int16_t v = a[i + j + len];
                a[i + j] = (u + v) % Q;
                a[i + j + len] = ((u - v + Q) * omega_inv[N / (2 * len) * j]) % Q;
            }
        }
    }

    // Normalize (divide by N)
    int16_t inv_n = modinv(N, Q);
    for (int i = 0; i < N; i++) {
        a[i] = (a[i] * inv_n) % Q;
    }
}

// Pointwise multiplication
void pointwise_mul(int16_t r[N], const int16_t a[N], const int16_t b[N]) {
    for (int i = 0; i < N; i++) {
        r[i] = (a[i] * b[i]) % Q;
    }
}

// Wrapper for Polynomial type multiplication using NTT
Polynomial ntt_multiply(Polynomial a, Polynomial b) {
    int16_t A[N] = {0}, B[N] = {0}, R[N] = {0};
    Polynomial result;

    // Copy coefficients into arrays
    for (int i = 0; i < a.degree && i < N; i++) A[i] = a.coeffs[i];
    for (int i = 0; i < b.degree && i < N; i++) B[i] = b.coeffs[i];

    ntt(A);
    ntt(B);
    pointwise_mul(R, A, B);
    intt(R);

    // Fill result polynomial
    result.degree = N;
    for (int i = 0; i < N; i++) {
        result.coeffs[i] = R[i];
    }

    return result;
}