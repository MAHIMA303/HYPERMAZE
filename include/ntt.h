#ifndef NTT_H
#define NTT_H

#include <stdint.h>
#include "poly.h"

#define N 8
#define Q 17

void ntt(int16_t a[N]);
void intt(int16_t a[N]);
void pointwise_mul(int16_t r[N], const int16_t a[N], const int16_t b[N]);

// Add this line 👇 to expose the function
Polynomial ntt_multiply(Polynomial a, Polynomial b);

#endif