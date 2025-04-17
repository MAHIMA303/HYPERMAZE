// === verify.h ===
#ifndef VERIFY_H
#define VERIFY_H

#include "poly.h"
#include "sign.h"

int verify_signature(PublicKey pub, Polynomial message, Signature sig);

#endif