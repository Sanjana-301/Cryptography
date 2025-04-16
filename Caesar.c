#include <stdio.h>
#include <string.h>
#include <ctype.h>

void processText(char *input, int shift, int mode) {
    for (int i = 0; input[i]; i++) {
        char current = input[i];

        if (!isalnum(current)) {
            printf("Invalid Message\n");
            return;
        }

        if (isalpha(current)) {
            int base = islower(current) ? 'a' : 'A';
            input[i] = base + ((current - base + (mode == 1 ? shift : (26 - shift))) % 26);
        } else if (isdigit(current)) {
            input[i] = '0' + ((current - '0' + (mode == 1 ? shift : (10 - shift))) % 10);
        }
    }

    printf("%s message: %s\n", mode == 1 ? "Encrypted" : "Decrypted", input);
}

int main() {
    char input[500];
    int action, shift;

    printf("Caesar Cipher\n");
    printf("1.Encrypt\n2.Decrypt\nSelect option: ");
    scanf("%d", &action);

    if (action != 1 && action != 2) {
        printf("Invalid option.\n");
        return 1;
    }

    printf("Input message: ");
    scanf("%s", input);

    printf("Enter shift value: ");
    scanf("%d", &shift);

    processText(input, shift, action);
    return 0;
}
