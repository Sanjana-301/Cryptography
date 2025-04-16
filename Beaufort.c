#include <stdio.h>
#include <ctype.h>
#include <string.h>

void processText(char *input, char *key, int mode) {
    int keyLength = strlen(key);
    for (int i = 0, j = 0; input[i] != '\0'; ++i) {
        char current = input[i];

        if (!isalpha(current)) {
            printf("Invalid Message\n");
            return;
        }

        if (isalpha(current)) {
            char keyChar = toupper(key[j % keyLength]) - 'A';

            if (mode == 1) {  
                if (isupper(current)) {
                    input[i] = (keyChar - (current - 'A') + 26) % 26 + 'A';
                }
                if (islower(current)) {
                    input[i] = (keyChar - (current - 'a') + 26) % 26 + 'a';
                }
            } else if (mode == 2) {  
                if (isupper(current)) {
                    input[i] = (keyChar - (current - 'A') + 26) % 26 + 'A';
                }
                if (islower(current)) {
                    input[i] = (keyChar - (current - 'a') + 26) % 26 + 'a';
                }
            }
            j++;
        }
    }

    printf("%s message: %s\n", mode == 1 ? "Encrypted" : "Decrypted", input);
}

int main() {
    char input[500], key[100];
    int action;

    printf("Beaufort Cipher\n");
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
