#include <stdio.h>
#include <string.h>
#include <ctype.h>

void toLower(char *str) {
    for (int i = 0; str[i]; i++)
        str[i] = tolower(str[i]);
}

void stripNonAlpha(char *str) {
    char clean[100];
    int j = 0;
    for (int i = 0; str[i]; i++) {
        if (isalpha(str[i]))
            clean[j++] = str[i];
    }
    clean[j] = '\0';
    strcpy(str, clean);
}

void encryptNGram(char *msg, int n) {
    char result[200] = "";
    int len = strlen(msg);
    for (int i = 0; i < len; i += n) {
        for (int j = i + n - 1; j >= i && j < len; j--) {
            strncat(result, &msg[j], 1);
        }
    }
    printf("Encrypted message: %s\n", result);
}

void decryptNGram(char *cipher, int n) {
    char result[200] = "";
    int len = strlen(cipher);
    for (int i = 0; i < len; i += n) {
        for (int j = i + n - 1; j >= i && j < len; j--) {
            strncat(result, &cipher[j], 1);
        }
    }
    printf("Decrypted message: %s\n", result);
}

int main() {
    char text[100];
    int choice, n;

    printf("N-Gram Cipher\n");
    printf("1. Encrypt\n2. Decrypt\nSelect option: ");
    scanf("%d", &choice);
    getchar();

    printf("Enter the message: ");
    fgets(text, sizeof(text), stdin);
    text[strcspn(text, "\n")] = '\0';

    printf("Enter N (group size): ");
    scanf("%d", &n);

    toLower(text);
    stripNonAlpha(text);

    if (choice == 1)
        encryptNGram(text, n);
    else if (choice == 2)
        decryptNGram(text, n);
    else
        printf("Invalid option.\n");

    return 0;
}
