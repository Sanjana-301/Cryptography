#include <stdio.h>
#include <string.h>
#include <ctype.h>

void encryptRoute(char *msg, int rows) {
    int len = strlen(msg);
    int cols = (len + rows - 1) / rows;
    char matrix[rows][cols];
    char result[500] = "";
    int idx = 0;

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            matrix[i][j] = (idx < len) ? msg[idx++] : 'x';
        }
    }

    for (int j = 0; j < cols; j++) {
        for (int i = 0; i < rows; i++) {
            strncat(result, &matrix[i][j], 1);
        }
    }

    printf("Encrypted message: %s\n", result);
}

void decryptRoute(char *msg, int rows) {
    int len = strlen(msg);
    int cols = (len + rows - 1) / rows;
    char matrix[rows][cols];
    char result[500] = "";
    int idx = 0;

    for (int j = 0; j < cols; j++) {
        for (int i = 0; i < rows; i++) {
            if (idx < len)
                matrix[i][j] = msg[idx++];
        }
    }

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            strncat(result, &matrix[i][j], 1);
        }
    }

    printf("Decrypted message: %s\n", result);
}

int main() {
    char message[100];
    int choice, key;

    printf("Route Cipher\n");
    printf("1. Encrypt\n2. Decrypt\nSelect option: ");
    scanf("%d", &choice);

    printf("Enter the message: ");
    scanf("%s", message);

    printf("Enter the key (number of rows): ");
    scanf("%d", &key);

    if (choice == 1)
        encryptRoute(message, key);
    else if (choice == 2)
        decryptRoute(message, key);
    else
        printf("Invalid option.\n");

    return 0;
}
