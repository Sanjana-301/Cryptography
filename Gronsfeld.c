#include <stdio.h>
#include <string.h>
#include <ctype.h>

void toLowercase(char *str) {
    for (int i = 0; str[i]; i++) {
        if (isupper(str[i]))
            str[i] = tolower(str[i]);
    }
}

void processGronsfeld(char *message, char *numKey, int mode) {
    int msgLen = strlen(message);
    int keyLen = strlen(numKey);

    for (int i = 0; i < msgLen; i++) {
        if (!islower(message[i])) {
            printf("Invalid Message\n");
            return;
        }

        int shift = numKey[i % keyLen] - '0';
        if (shift < 0 || shift > 9) {
            printf("Invalid key.\n");
            return;
        }

        if (mode == 1)
            message[i] = (message[i] - 'a' + shift) % 26 + 'a';
        else
            message[i] = (message[i] - 'a' - shift + 26) % 26 + 'a';
    }

    printf("%s message: %s\n", mode == 1 ? "Encrypted" : "Decrypted", message);
}

int main() {
    char input[500], key[100];
    int choice;

    printf("Gronsfeld Cipher\n");
    printf("1. Encrypt\n2. Decrypt\nSelect option: ");
    scanf("%d", &choice);

    printf("Input message: ");
    scanf("%s", input);
    printf("Enter key (digits only): ");
    scanf("%s", key);

    toLowercase(input);
    processGronsfeld(input, key, choice);
    return 0;
}
