#include <stdio.h>
#include <string.h>
#include <ctype.h>

char getCipherChar(char p, char k) {
    return ((p - 'a' + (k - 'a')) % 26) + 'a';
}

char getPlainChar(char c, char k) {
    return ((c - 'a' - (k - 'a') + 26) % 26) + 'a';
}

void processText(char *input, char *key, int mode) {
    char finalKey[1024];
    int textLen = strlen(input);
    int keyLen = strlen(key);

    for (int i = 0; i < textLen; i++) {
        if (!isalpha(input[i])) {
            printf("Invalid Message (only alphabetic characters allowed)\n");
            return;
        }
    }

    for (int i = 0; i < keyLen; i++) {
        if (!isalpha(key[i])) {
            printf("Invalid Key (only alphabetic characters allowed)\n");
            return;
        }
    }

    if (mode == 1) {
        for (int i = 0; i < keyLen; i++) {
            finalKey[i] = tolower(key[i]);
        }
        for (int i = keyLen, j = 0; i < textLen; i++, j++) {
            finalKey[i] = tolower(input[j]);
        }
        finalKey[textLen] = '\0';

        for (int i = 0; i < textLen; i++) {
            input[i] = getCipherChar(tolower(input[i]), finalKey[i]);
        }

        printf("Encrypted message: %s\n", input);
    } else if (mode == 2) {
        for (int i = 0; i < keyLen; i++) {
            finalKey[i] = tolower(key[i]);
        }

        for (int i = 0; i < textLen; i++) {
            char decrypted = getPlainChar(tolower(input[i]), finalKey[i]);
            input[i] = decrypted;
            finalKey[keyLen + i] = decrypted;
        }

        printf("Decrypted message: %s\n", input);
    }
}

int main() {
    char input[1024], key[1024];
    int action;
    printf("Autoclave Cipher\n");
       printf("1.Encrypt\n2. Decrypt\nSelect option: ");
    scanf("%d", &action);

    if (action != 1 && action != 2) {
        printf("Invalid option.\n");
        return 1;
    }

    printf("Input message: ");
    scanf("%s", input);

    printf("Enter key: ");
    scanf("%s", key);

    processText(input, key, action);
    return 0;
}
