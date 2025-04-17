#ifndef NTT_H
#define NTT_H

#include "poly.h"  // ✅ Must come before using Polynomial

#define Q 12289
#define N 512

extern const int16_t omega[N];
extern const int16_t omega_inv[N];
extern int16_t psi[N];
extern int16_t psi_inv[N];

Polynomial ntt_multiply(Polynomial a, Polynomial b);

#endif