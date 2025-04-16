#include <stdio.h>
#include <string.h>
#include <ctype.h>

void augustCipher(char *msg, int mode) {
    for (int i = 0; msg[i]; i++) {
        char ch = msg[i];

        if (!isalnum(ch)) {
            printf("Invalid Message\n");
            return;
        }

        if (isalpha(ch)) {
            int base = islower(ch) ? 'a' : 'A';
            int shift = mode == 1 ? 1 : 25; // 25 is effectively -1 mod 26
            msg[i] = base + ((ch - base + shift) % 26);
        } else if (isdigit(ch)) {
            int shift = mode == 1 ? 1 : 9; // 9 is effectively -1 mod 10
            msg[i] = '0' + ((ch - '0' + shift) % 10);
        }
    }

    printf("%s message: %s\n", mode == 1 ? "Encrypted" : "Decrypted", msg);
}

int main() {
    char input[500];
    int option;

    printf("August Cipher\n");
    printf("1. Encrypt\n2. Decrypt\nSelect option: ");
    scanf("%d", &option);

    if (option != 1 && option != 2) {
        printf("Invalid option.\n");
        return 1;
    }

    printf("Input message: ");
    scanf("%s", input);

    augustCipher(input, option);
    return 0;
}
