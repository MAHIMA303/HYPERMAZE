// === main.c ===
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "keygen.h"
#include "sign.h"

int main() {
    srand(time(NULL));

    PublicKey pub;
    PrivateKey priv;

    printf("\n🦅 === FALCONIFIED HYPERMAZE KEYGEN START === 🦅\n");
    generate_keys(&pub, &priv);
    printf("✅ Key generation complete.\n");

    // Dummy message (for now)
    Polynomial message = generate_small_poly(5);
    print_poly("📝 Dummy Message", message);

    // Loop through all 4 challenge types
    for (int challenge = 0; challenge < 4; challenge++) {
        printf("\n🔐 Signing message with challenge type %d ...\n", challenge);
        Signature sig = sign_message(pub, priv, challenge, message);
    }

    printf("\n✅ All signatures generated with hypermaze logic!\n");
    return 0;
}
