#include <stdio.h>
#include <ctype.h>
#include <string.h>

int modInverse(int keyA) {
    int validA[] = {1, 3, 5, 7, 9, 11, 15, 17, 19, 21, 23, 25};
    int invA[] =   {1, 9, 21,15, 3, 19, 7, 23, 11, 5, 17, 25};

    for (int i = 0; i < 12; i++) {
        if (validA[i] == keyA)
            return invA[i];
    }
    return -1;
}

void processAffine(char *msg, int a, int b, int mode) {
    char output[500];
    int i = 0, invA = modInverse(a);

    if (invA == -1 || b < 0 || b > 25) {
        printf("Invalid key values.\n");
        return;
    }

    while (msg[i]) {
        char c = msg[i];

        if (!isalpha(c)) {
            printf("Invalid Message\n");
            return;
        }

        if (mode == 1) {
            int val = islower(c) ? c - 'a' : c - 'A';
            output[i] = ((a * val + b) % 26) + 'A';
        } else {
            int base = isupper(c) ? 'A' : 'a';
            int val = c - base;
            output[i] = ((invA * (val - b + 26)) % 26) + 'a';
        }

        i++;
    }

    output[i] = '\0';
    printf("%s message: %s\n", mode == 1 ? "Encrypted" : "Decrypted", output);
}

int main() {
    char input[500];
    int opt, a, b;

    printf("Affine Cipher\n");
    printf("1. Encrypt\n2. Decrypt\nSelect option: ");
    scanf("%d", &opt);

    printf("Enter key 'a' (must be coprime with 26): ");
    scanf("%d", &a);
    printf("Enter key 'b' (0 <= b < 26): ");
    scanf("%d", &b);

    printf("Input message: ");
    scanf("%s", input);

    processAffine(input, a, b, opt);
    return 0;
}
