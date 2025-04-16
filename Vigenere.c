#include <stdio.h>
#include <string.h>
#include <ctype.h>

void convertToLower(char *str) {
    for (int i = 0; str[i]; i++) {
        if (isupper(str[i]))
            str[i] = tolower(str[i]);
    }
}

void handleVigenere(char *msg, char *key, int mode) {
    int msgLen = strlen(msg);
    int keyLen = strlen(key);

    for (int i = 0; i < msgLen; i++) {
        if (!islower(msg[i])) {
            printf("Invalid Message\n");
            return;
        }

        int shift = key[i % keyLen] - 'a';

        if (mode == 1)
            msg[i] = (msg[i] - 'a' + shift) % 26 + 'a';
        else
            msg[i] = (msg[i] - 'a' - shift + 26) % 26 + 'a';
    }

    printf("%s message: %s\n", mode == 1 ? "Encrypted" : "Decrypted", msg);
}

int main() {
    char input[500], cipherKey[100];
    int action;

    printf("Vigenere Cipher\n");
    printf("1. Encrypt\n2. Decrypt\nSelect option: ");
    scanf("%d", &action);

    printf("Input message: ");
    scanf("%s", input);
    printf("Enter key: ");
    scanf("%s", cipherKey);

    convertToLower(input);
    convertToLower(cipherKey);

    handleVigenere(input, cipherKey, action);
    return 0;
}
