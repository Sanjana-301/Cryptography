#include <stdio.h>
#include <string.h>
#include <ctype.h>

void atbashTransform(char *msg) {
    for (int i = 0; msg[i]; i++) {
        char ch = msg[i];

        if (!isalpha(ch)) {
            printf("Invalid Message\n");
            return;
        }

        if (islower(ch)) {
            msg[i] = 'z' - (ch - 'a');
        } else if (isupper(ch)) {
            msg[i] = 'Z' - (ch - 'A');
        }
    }
}

int main() {
    char input[500];
    int mode;

    printf("Atbash Cipher\n");
    printf("1. Encrypt\n2. Decrypt\nSelect option: ");
    scanf("%d", &mode);

    if (mode != 1 && mode != 2) {
        printf("Invalid option.\n");
        return 1;
    }

    printf("Input message: ");
    scanf("%s", input);

    atbashTransform(input);

    if (isalpha(input[0])) {
        printf("%s message: %s\n", mode == 1 ? "Encrypted" : "Decrypted", input);
    }

    return 0;
}
